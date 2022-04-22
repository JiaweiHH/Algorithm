struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

template <int> class Solution;

/// 二叉树遍历（中序 Morris）
template <> class Solution<1> {
public:
  int countNodes(TreeNode *root) {
    int res = 0;
    while (root) {
      if (root->left) {
        TreeNode *node = root->left;
        while (node->right && node->right != root)
          node = node->right;
        if (node->right == nullptr) {
          node->right = root;
          root = root->left;
        } else {
          ++res;
          node->right = nullptr;
          root = root->right;
        }
      } else {
        root = root->right;
        ++res;
      }
    }
    return res;
  }
};

/// 以最后一层元素的范围作为边界，进行二分查找
template <> class Solution<2> {
public:
  int countNodes(TreeNode *root) {
    int h = 0;
    TreeNode *tmp = root;
    while (tmp) {
      ++h;
      tmp = tmp->left;
    }
    if (h <= 1)
      return h;
    int l = 1 << (h - 1), r = (1 << h) - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (exists(root, mid, h))
        l = mid + 1;
      else
        r = mid - 1;
    }
    return r;
  }
  bool exists(TreeNode *root, int n, int h) {
    int bits = 1 << (h - 2);
    while (root != nullptr && bits > 0) {
      if (bits & n)
        root = root->right;
      else
        root = root->left;
      bits >>= 1;
    }
    return root != nullptr;
  }
};