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
  vector<vector<int>> levelOrder(TreeNode *root) {
    if (root == nullptr)
      return {};
    vector<vector<int>> res;
    queue<TreeNode *> que;
    que.push(root);
    int len = 1;
    while (!que.empty()) {
      vector<int> tmp;
      int tmp_len = 0;
      for (int i = 0; i < len; ++i) {
        TreeNode *node = que.front();
        que.pop();
        tmp.push_back(node->val);
        if (node->left) {
          que.push(node->left);
          tmp_len++;
        }
        if (node->right) {
          que.push(node->right);
          tmp_len++;
        }
      }
      len = tmp_len;
      if (tmp.size() > 0)
        res.push_back(tmp);
    }
    return res;
  }
};