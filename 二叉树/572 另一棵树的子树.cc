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
  bool is_same(TreeNode *root, TreeNode *subRoot) {
    if (root == nullptr && subRoot == nullptr)
      return true;
    if ((!root && subRoot) || (root && !subRoot) || (root->val != subRoot->val))
      return false;
    return is_same(root->left, subRoot->left) &&
           is_same(root->right, subRoot->right);
  }
  bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    if (root == nullptr && subRoot == nullptr)
      return true;
    if (root == nullptr && subRoot)
      return false;
    if (root->val == subRoot->val && is_same(root, subRoot))
      return true;
    return isSubtree(root->left, subRoot) | isSubtree(root->right, subRoot);
  }
};