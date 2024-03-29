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

/// 使用栈的迭代
template <> class Solution<1> {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    stack<TreeNode *> stk;
    while (!stk.empty() || root) {
      while (root) {
        stk.push(root);
        root = root->left;
      }
      TreeNode *node = stk.top();
      stk.pop();
      res.push_back(node->val);
      root = node->right;
    }
    return res;
  }
};

/// Morris 遍历
template <> class Solution<2> {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    while (root) {
      if (root->left != nullptr) {
        TreeNode *prev = root->left;
        while (prev->right)
          prev = prev->right;
        prev->right = root;
        // tmp 用来断开 root 和 root->left，防止之后循环遍历
        TreeNode *tmp = root;
        root = root->left;
        tmp->left = nullptr;
      } else {
        res.push_back(root->val);
        root = root->right;
      }
    }
    return res;
  }
};

/// Morris 不修改 left 指针
template <> class Solution<3> {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    while (root) {
      if (root->left) {
        TreeNode *node = root->left;
        while (node->right && node->right != root) {
          node = node->right;
        }
        if (node->right == nullptr) {
          node->right = root;
          root = root->left;
        } else {
          res.push_back(root->val);
          node->right = nullptr;
          root = root->right;
        }
      } else {
        res.push_back(root->val);
        root = root->right;
      }
    }
    return res;
  }
};