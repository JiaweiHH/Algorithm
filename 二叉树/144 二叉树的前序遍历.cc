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

template <> class Solution<1> {
public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> res;
    stack<TreeNode *> stk;
    while (!stk.empty() || root) {
      while (root) {
        res.push_back(root->val);
        stk.push(root);
        root = root->left;
      }
      TreeNode *node = stk.top();
      stk.pop();
      root = node->right;
    }
    return res;
  }
};

template <> class Solution<2> {
public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> res;
    if (root == nullptr)
      return res;
    stack<TreeNode *> stk;
    stk.push(root);
    while (!stk.empty()) {
      TreeNode *node = stk.top();
      stk.pop();
      res.push_back(node->val);
      if (node->right)
        stk.push(node->right);
      if (node->left)
        stk.push(node->left);
    }
    return res;
  }
};