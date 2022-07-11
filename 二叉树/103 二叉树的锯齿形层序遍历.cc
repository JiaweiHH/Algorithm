#include <queue>
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
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> res;
    queue<TreeNode *> que;
    if (root)
      que.push(root);
    bool tag = true;
    while (!que.empty()) {
      int len = que.size();
      vector<int> tmp;
      for (int i = 0; i < len; ++i) {
        TreeNode *node = que.front();
        que.pop();
        tmp.push_back(node->val);
        if (node->left)
          que.push(node->left);
        if (node->right)
          que.push(node->right);
      }
      if (!tag)
        reverse(tmp.begin(), tmp.end());
      res.push_back(tmp);
      tag = !tag;
    }
    return res;
  }
};