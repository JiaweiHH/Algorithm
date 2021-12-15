#include <stack>
#include <unordered_map>
#include <vector>

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

/// @brief
/// 给出一颗二叉树和一个整数目标和，找出所有根节点到叶子节点路径总和等于给定目标和的路径

/// @brief DFS
/// 时间复杂度：O(n^2)，空间复杂度：O(n)
class Solution {
public:
  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    vector<vector<int>> res;
    stack<TreeNode *> stk_node;
    stack<int> stk_value;
    unordered_map<TreeNode *, TreeNode *> map; // 记录每个节点的父节点
    int cur = 0;
    TreeNode *tmp_node = nullptr;
    while (!stk_node.empty() || root) {
      while (root) {
        if (tmp_node)
          map[root] = tmp_node;
        cur += root->val;
        stk_node.push(root);
        stk_value.push(cur);
        tmp_node = root;
        root = root->left;
      }

      auto node = stk_node.top();
      stk_node.pop();
      cur = stk_value.top();
      stk_value.pop();

      // 记录当前的路径
      if (cur == targetSum && !node->left && !node->right) {
        getRes(node, res, map);
      }

      tmp_node = node;
      root = node->right;
    }
    return res;
  }
  void getRes(TreeNode *node, vector<vector<int>> &res,
              unordered_map<TreeNode *, TreeNode *> &map) {
    vector<int> tmp_res;
    while (node) {
      tmp_res.emplace(tmp_res.begin(), node->val);
      node = map[node];
    }
    res.push_back(tmp_res);
  }
};