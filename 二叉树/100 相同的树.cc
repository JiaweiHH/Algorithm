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
    // 两颗🌲都为空
    if (p == nullptr && q == nullptr)
      return true;
    // 其中一棵🌲不为空或者两个节点的值不相等
    if ((!p && q) || (p && !q) || (p->val != q->val))
      return false;
    // 继续判断 p 和 q 的左右子树是不是相同的
    return isSameTree(p->left, q->left) & isSameTree(p->right, q->right);
  }
};