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

/// @brief 队列迭代
template <> class Solution<1> {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    queue<TreeNode *> que;
    if (root)
      que.push(root);
    while (!que.empty()) {
      int len = que.size();
      vector<int> vec;
      for (int i = 0; i < len; ++i) {
        TreeNode *node = que.front();
        que.pop();
        vec.push_back(node->val);
        if (node->left)
          que.push(node->left);
        if (node->right)
          que.push(node->right);
      }
      res.emplace_back(std::move(vec));
    }
    return res;
  }
};

/// @brief 前序遍历递归
template <> class Solution<2> {
public:
  vector<vector<int>> res;
  void dfs(TreeNode *root, int depth) {
    if (root == nullptr)
      return;
    // 通过 res.size() 判断是 emplace 一个新的 vector<> 还是直接使用
    if (res.size() > depth)
      res[depth].push_back(root->val);
    else
      res.push_back({root->val});
    dfs(root->left, depth + 1);
    dfs(root->right, depth + 1);
  }
  vector<vector<int>> levelOrder(TreeNode *root) {
    // 携带二叉树深度信息
    dfs(root, 0);
    return res;
  }
};