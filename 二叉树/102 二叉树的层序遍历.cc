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

/// 迭代
template <> class Solution<1> {
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

/// 递归
template <> class Solution<2> {
public:
  vector<vector<int>> res;
  vector<vector<int>> levelOrder(TreeNode *root) {
    dfs(root, 0);
    return res;
  }
  void dfs(TreeNode *root, int level) {
    if (root == nullptr)
      return;
    if (res.size() == level)
      res.push_back({root->val});
    else
      res[level].push_back(root->val);
    dfs(root->left, level + 1);
    dfs(root->right, level + 1);
  }
};