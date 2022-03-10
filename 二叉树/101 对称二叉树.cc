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

template <int> class Solution;

template <> class Solution<1> {
public:
  bool isSymmetric(TreeNode *root) { return isSame(root->left, root->right); }
  bool isSame(TreeNode *root1, TreeNode *root2) {
    if ((!root1 && root2) || (root1 && !root2))
      return false;
    if (!root1 && !root2)
      return true;
    bool left = isSame(root1->left, root2->right);
    bool right = isSame(root1->right, root2->left);
    if (left && right)
      return root1->val == root2->val;
    return false;
  }
};

template <> class Solution<2> {
public:
  bool isSymmetric(TreeNode *root) { return isSame(root->left, root->right); }
  bool isSame(TreeNode *root1, TreeNode *root2) {
    queue<TreeNode *> que;
    que.push(root1);
    que.push(root2);
    while (!que.empty()) {
      TreeNode *node1 = que.front();
      que.pop();
      TreeNode *node2 = que.front();
      que.pop();
      if (!node1 && !node2)
        continue;
      if ((!node1 && node2) || (node1 && !node2) || (node1->val != node2->val))
        return false;
      que.push(node1->left);
      que.push(node2->right);
      que.push(node2->left);
      que.push(node1->right);
    }
    return true;
  }
};