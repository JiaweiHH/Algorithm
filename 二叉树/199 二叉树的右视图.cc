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

template <int> class Solution;

/// 层序遍历
template <> class Solution<1> {
public:
  vector<int> rightSideView(TreeNode *root) {
    if (root == nullptr)
      return {};
    vector<int> res;
    queue<TreeNode *> q;
    q.push(root);
    int len = 1;
    while (!q.empty()) {
      int tmp_len = 0;
      for (int i = 0; i < len; ++i) {
        TreeNode *node = q.front();
        q.pop();
        if (node->left) {
          q.push(node->left);
          ++tmp_len;
        }
        if (node->right) {
          q.push(node->right);
          ++tmp_len;
        }
        if (i == len - 1)
          res.push_back(node->val);
      }
      len = tmp_len;
    }
    return res;
  }
};

/// 深搜
template <> class Solution<2> {
public:
  vector<int> res;
  vector<int> rightSideView(TreeNode *root) {
    dfs(root, 1);
    return res;
  }
  void dfs(TreeNode *root, int depth) {
    if (root == nullptr)
      return;
    if (res.size() < depth)
      res.push_back(root->val);
    dfs(root->right, depth + 1);
    dfs(root->left, depth + 1);
  }
};