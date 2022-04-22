#include <stack>
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

class Solution {
public:
  int kthSmallest(TreeNode *root, int k) {
    stack<TreeNode *> stk;
    while (!stk.empty() || root) {
      while (root) {
        stk.push(root);
        root = root->left;
      }
      TreeNode *node = stk.top();
      stk.pop();
      if (--k == 0)
        return node->val;
      if (node->right)
        root = node->right;
    }
    return -1;
  }
};