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

class Solution {
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