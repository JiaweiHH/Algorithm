#include <queue>
#include <unordered_map>
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

template <> class Solution<1> {
public:
  vector<vector<int>> res;
  vector<vector<int>> pathSum(TreeNode *root, int target) {
    vector<int> curr;
    dfs(root, curr, target, 0);
    return res;
  }
  void dfs(TreeNode *root, vector<int> &curr, int target, int sum) {
    if (root == nullptr)
      return;
    curr.push_back(root->val);
    if (!root->left && !root->right && sum + root->val == target)
      res.push_back(curr);
    dfs(root->left, curr, target, sum + root->val);
    dfs(root->right, curr, target, sum + root->val);
    curr.pop_back();
  }
};

template <> class Solution<2> {
public:
  vector<vector<int>> pathSum(TreeNode *root, int target) {
    if (root == nullptr)
      return {};
    vector<vector<int>> res;
    queue<pair<TreeNode *, int>> q;
    unordered_map<TreeNode *, TreeNode *> map;
    q.push({root, root->val});
    map[root] = nullptr;
    while (!q.empty()) {
      TreeNode *node = q.front().first;
      int sum = q.front().second;
      q.pop();
      if (node->left) {
        q.push({node->left, sum + node->left->val});
        map[node->left] = node;
      }
      if (node->right) {
        q.push({node->right, sum + node->right->val});
        map[node->right] = node;
      }
      if (!node->left && !node->right && sum == target) {
        vector<int> path = getPath(map, node);
        res.push_back(path);
      }
    }
    return res;
  }
  vector<int> getPath(unordered_map<TreeNode *, TreeNode *> &map,
                      TreeNode *root) {
    vector<int> res;
    while (map.count(root)) {
      res.push_back(root->val);
      root = map[root];
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
