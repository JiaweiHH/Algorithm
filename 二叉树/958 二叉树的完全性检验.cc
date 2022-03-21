#include <queue>
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
  bool isCompleteTree(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    int prev = root->val;
    while (!q.empty()) {
      TreeNode *node = q.front();
      q.pop();
      if (node->left) {
        if (prev == -1)
          return false;
        prev = node->left->val;
        q.push(node->left);
      } else {
        prev = -1;
      }
      if (node->right) {
        if (prev == -1)
          return false;
        prev = node->left->val;
        q.push(node->right);
      } else {
        prev = -1;
      }
    }
    return true;
  }
};