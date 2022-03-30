#include <string>
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

class Solution {
public:
  unordered_map<string, int> map;
  vector<TreeNode *> vec;
  vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
    string tmp = dfs(root);
    return vec;
  }
  string dfs(TreeNode *root) {
    if (root == nullptr)
      return "#";
    string left = dfs(root->left), right = dfs(root->right);
    string res = left + "," + right + "," + to_string(root->val);
    if (map[res]++ == 1)
      vec.push_back(root);
    return res;
  }
};