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
  int res = INT_MIN;
  int maxPathSum(TreeNode *root) {
    dfs(root);
    return res;
  }
  int dfs(TreeNode *root) {
    if (root == nullptr)
      return 0;
    int left = dfs(root->left);
    int right = dfs(root->right);
    res = max(res, max({root->val, root->val + left, root->val + right,
                        root->val + left + right}));
    return max({root->val, root->val + left, root->val + right});
  }
};