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
  int widthOfBinaryTree(TreeNode *root) {
    queue<pair<TreeNode *, uint64_t>> que;
    que.push({root, 1});
    int len = 1;
    uint64_t res = 0;
    while (!que.empty()) {
      int tmp_len = 0;
      res = max(res, que.back().second - que.front().second + 1);
      for (int i = 0; i < len; ++i) {
        TreeNode *node = que.front().first;
        uint64_t pos = que.front().second;
        que.pop();
        if (node->left) {
          que.push({node->left, pos * 2});
          ++tmp_len;
        }
        if (node->right) {
          que.push({node->right, pos * 2 + 1});
          ++tmp_len;
        }
      }
      len = tmp_len;
    }
    return res;
  }
};