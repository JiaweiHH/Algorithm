#include <queue>
#include <stack>

using namespace std;

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

/// 非递归深度优先搜索
template <> class Solution<1> {
public:
  int sumNumbers(TreeNode *root) {
    stack<pair<TreeNode *, int>> stk;
    int res = 0, cur = 0;
    while (!stk.empty() || root) {
      while (root) {
        cur = cur * 10 + root->val;
        stk.push({root, cur});
        root = root->left;
      }
      TreeNode *node = stk.top().first;
      cur = stk.top().second;
      stk.pop();
      if (!node->right && !node->left)
        res += cur;
      if (node->right)
        root = node->right;
    }
    return res;
  }
};

/// 递归深度优先搜索
template <> class Solution<2> {
public:
  int res = 0;
  int sumNumbers(TreeNode *root) {
    int cur = 0;
    if (root)
      dfs(root, cur);
    return res;
  }
  void dfs(TreeNode *root, int &cur) {
    cur = cur * 10 + root->val;
    if (root->left)
      dfs(root->left, cur);
    if (root->right)
      dfs(root->right, cur);
    if (!root->left && !root->right) {
      res += cur;
    }
    cur = (cur - root->val) / 10;
  }
};

/// 广搜
template <> class Solution<3> {
public:
  int sumNumbers(TreeNode *root) {
    int res = 0;
    queue<pair<TreeNode *, int>> q;
    q.push({root, root->val});
    while (!q.empty()) {
      TreeNode *node = q.front().first;
      int val = q.front().second;
      q.pop();
      if (node->left)
        q.push({node->left, val * 10 + node->left->val});
      if (node->right)
        q.push({node->right, val * 10 + node->right->val});
      if (!node->left && !node->right)
        res += val;
    }
    return res;
  }
};