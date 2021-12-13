
// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// 通过后续遍历从 root 最底下的子树开始判断和 subRoot 是否相等
// 一旦 root 树中，已经判断和 subRoot 相等了，那么就直接返回减少时间复杂度
class Solution {
public:
  bool res = false;
  bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    dfs(root, subRoot); // 准确的说是后续遍历
    return res;
  }
  void dfs(TreeNode *root, TreeNode *subRoot) {
    // 已经判断出和 subRoot 相等了，那么直接返回
    if (root == nullptr || res == true)
      return;
    dfs(root->left, subRoot);
    dfs(root->right, subRoot);
    res |= isIdentical(root, subRoot);
  }
  bool isIdentical(TreeNode *root, TreeNode *subRoot) {
    if (!root && !subRoot)
      return true;
    if (!root)
      return false;
    if (!subRoot)
      return false;
    bool value_equal = root->val == subRoot->val;
    bool left_equal = false, right_equal = false;
    if (value_equal) {
      left_equal = isIdentical(root->left, subRoot->left);
      right_equal = isIdentical(root->right, subRoot->right);
    } else {
      return false;
    }
    return left_equal & right_equal;
  }
};

// 官方解法 1，深搜暴力
// 时间复杂度 O(st), 空间复杂度 O(max{ds, dt})
// 我感觉空间复杂度应该是 O(ds)
class Solution_1 {
public:
  bool check(TreeNode *o, TreeNode *t) {
    if (!o && !t) {
      return true;
    }
    if ((o && !t) || (!o && t) || (o->val != t->val)) {
      return false;
    }
    return check(o->left, t->left) && check(o->right, t->right);
  }

  bool dfs(TreeNode *o, TreeNode *t) {
    if (!o) {
      return false;
    }
    return check(o, t) || dfs(o->left, t) || dfs(o->right, t);
  }

  bool isSubtree(TreeNode *s, TreeNode *t) { return dfs(s, t); }
};

// 官方 2
// 分别求出 s 和 t 的前序遍历，然后判断 s 的前序遍历串中是否包含 t 的前序遍历串
// 判断的时候可以使用 KMP 算法
// 这种方法时间复杂度变为 O(s + t), 空间复杂度也是 O(s + t)

// 官方 3，总体思路是计算每棵子树的 hash 值，通过哈希值判断是否相等