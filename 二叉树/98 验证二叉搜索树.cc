#include <stack>
#include <vector>
using namespace std;

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

template <int> class Solution;

/// 后序遍历
template <> class Solution<1> {
public:
  struct Type {
    int min_val;
    int max_val;
    bool valid;
  };
  bool isValidBST(TreeNode *root) {
    Type res = dfs(root);
    return res.valid;
  }
  Type dfs(TreeNode *root) {
    if (root == nullptr)
      return {0, 0, true};
    Type left = dfs(root->left);
    Type right = dfs(root->right);
    if (left.valid && right.valid) {
      if (root->left && root->val <= left.max_val)
        return {0, 0, false};
      if (root->right && root->val >= right.min_val)
        return {0, 0, false};
      Type tmp;
      tmp.min_val = root->left == nullptr ? root->val : left.min_val;
      tmp.max_val = root->right == nullptr ? root->val : right.max_val;
      tmp.valid = true;
      return tmp;
    }
    return {0, 0, false};
  }
};

/// 中序遍历
template <> class Solution<2> {
public:
  bool valid = true;
  int lastVal = INT_MIN;
  bool firstNode = true;
  bool isValidBST(TreeNode *root) {
    inorder(root);
    return valid;
  }
  void inorder(TreeNode *root) {
    if (!valid)
      return;
    if (root->left)
      inorder(root->left);
    if (root->val <= lastVal && !firstNode) {
      valid = false;
      return;
    }
    firstNode = false;
    lastVal = root->val;
    if (root->right)
      inorder(root->right);
  }
};

/// 中序遍历（迭代）
template <> class Solution<3> {
public:
  bool isValidBST(TreeNode *root) {
    int lastVal = INT_MIN;
    bool firstNode = true;
    stack<TreeNode *> stk;
    while (!stk.empty() || root) {
      while (root) {
        stk.push(root);
        root = root->left;
      }
      TreeNode *node = stk.top();
      stk.pop();
      if (node->val <= lastVal && !firstNode)
        return false;
      firstNode = false;
      lastVal = node->val;
      if (node->right)
        root = node->right;
    }
    return true;
  }
};