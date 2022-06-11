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
  bool is_same(TreeNode *t1, TreeNode *t2) {
    if (!t1 && !t2)
      return true;
    if ((!t1 && t2) || (t1 && !t2) || (t1->val != t2->val))
      return false;
    return is_same(t1->left, t2->left) & is_same(t1->right, t2->right);
  }
  bool checkSubTree(TreeNode *t1, TreeNode *t2) {
    if (t1 == nullptr && t2 == nullptr)
      return true;
    if (t1 == nullptr && t2 != nullptr)
      return false;
    if (t1->val == t2->val && is_same(t1, t2))
      return true;
    return checkSubTree(t1->left, t2) | checkSubTree(t1->right, t2);
  }
};