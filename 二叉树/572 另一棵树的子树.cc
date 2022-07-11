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
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == nullptr && q == nullptr)
      return true;
    if (!p || !q || p->val != q->val)
      return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
  bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    if (subRoot == nullptr)
      return true;
    if (root == nullptr && subRoot)
      return false;
    // 找到 root->val == subRoot->val 的节点，然后判断这两棵树是不是相同的
    if (root->val == subRoot->val && isSameTree(root, subRoot))
      return true;
    // root->val != subRoot->val 或者 root 和 subRoot 不相同, 继续判断 root
    // 的左右子树
    return isSubtree(root->left, subRoot) | isSubtree(root->right, subRoot);
  }
};