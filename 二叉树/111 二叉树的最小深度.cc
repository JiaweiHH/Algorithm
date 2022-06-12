#include <queue>
using namespace std;

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

/// 广搜
template <> class Solution<1> {
public:
  int minDepth(TreeNode *root) {
    if (root == nullptr)
      return 0;
    queue<TreeNode *> que;
    que.push(root);
    int res = 0;
    while (!que.empty()) {
      ++res;
      int len = que.size();
      for (int i = 0; i < len; ++i) {
        TreeNode *node = que.front();
        que.pop();
        if (!node->left && !node->right)
          return res;
        if (node->left)
          que.push(node->left);
        if (node->right)
          que.push(node->right);
      }
    }
    return 0;
  }
};

/// 递归
template <> class Solution<2> {
public:
  int minDepth(TreeNode *root) {
    if (root == nullptr)
      return 0;
    int l = minDepth(root->left), r = minDepth(root->right);
    if (l == 0)
      return r + 1;
    if (r == 0)
      return l + 1;
    return min(l, r) + 1;
  }
};