#include <stack>
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

/// 前序遍历展开
template <> class Solution<1> {
public:
  void flatten(TreeNode *root) {
    stack<TreeNode *> stk;
    vector<TreeNode *> list;
    while (!stk.empty() || root) {
      while (root) {
        list.push_back(root);
        stk.push(root);
        root = root->left;
      }
      TreeNode *node = stk.top();
      stk.pop();
      root = node->right;
    }
    TreeNode *prev = nullptr;
    for (int i = 0; i < list.size(); ++i) {
      if (prev) {
        prev->left = nullptr;
        prev->right = list[i];
      }
      prev = list[i];
    }
  }
};

/// 前序遍历的第二种写法
template <> class Solution<2> {
public:
  void flatten(TreeNode *root) {
    if (root == nullptr)
      return;
    stack<TreeNode *> stk;
    stk.push(root);
    TreeNode *prev = nullptr;
    while (!stk.empty()) {
      TreeNode *node = stk.top();
      stk.pop();
      if (prev) {
        prev->left = nullptr;
        prev->right = node;
      }
      if (node->right)
        stk.push(node->right);
      if (node->left)
        stk.push(node->left);
      prev = node;
    }
  }
};

/// 使用前驱节点展开
template <> class Solution<3> {
public:
  void flatten(TreeNode *root) {
    TreeNode *cur = root;
    while (cur) {
      if (cur->left) {
        TreeNode *next = cur->left;
        while (next->right) {
          next = next->right;
        }
        next->right = cur->right;
        cur->right = cur->left;
        cur->left = nullptr;
      }
      cur = cur->right;
    }
  }
};