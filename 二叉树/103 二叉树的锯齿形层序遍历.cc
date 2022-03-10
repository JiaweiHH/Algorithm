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
    if (!root)
      return {};
    vector<vector<int>> res;
    queue<TreeNode *> q;
    q.push(root);
    int len = 1;
    bool flag = false;
    while (!q.empty()) {
      int tmpLen = 0;
      vector<int> curr;
      for (int i = 0; i < len; ++i) {
        TreeNode *node = q.front();
        q.pop();
        curr.push_back(node->val);
        if (node->left) {
          tmpLen++;
          q.push(node->left);
        }
        if (node->right) {
          tmpLen++;
          q.push(node->right);
        }
      }
      if (flag)
        reverse(curr.begin(), curr.end());
      res.push_back(curr);
      flag = !flag;
      len = tmpLen;
    }
    return res;
  }
};