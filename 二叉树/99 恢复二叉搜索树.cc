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

/// 中序遍历按顺序保存节点
template <> class Solution<1> {
public:
  void recoverTree(TreeNode *root) {
    vector<TreeNode *> vec;
    stack<TreeNode *> stk;
    while (!stk.empty() || root) {
      while (root) {
        stk.push(root);
        root = root->left;
      }
      TreeNode *node = stk.top();
      stk.pop();
      vec.push_back(node);
      if (node->right)
        root = node->right;
    }
    int l = 0, r = vec.size() - 1;
    for (int i = 0; i < vec.size() - 1; ++i) {
      if (vec[i]->val > vec[i + 1]->val) {
        l = i;
        break;
      }
    }
    for (int i = vec.size() - 1; i >= 1; --i) {
      if (vec[i]->val < vec[i - 1]->val) {
        r = i;
        break;
      }
    }
    swap(vec[l]->val, vec[r]->val);
  }
};

/// Morris 遍历，不需要保存中间节点
template <> class Solution<2> {
public:
  void recoverTree(TreeNode *root) {
    TreeNode *prev = nullptr, *first = nullptr, *second = nullptr;
    while (root) {
      if (root->left) {
        TreeNode *node = root->left;
        while (node->right && node->right != root) {
          node = node->right;
        }
        if (node->right == nullptr) {
          node->right = root;
          root = root->left;
        } else {
          node->right = nullptr;
          if (prev && prev->val > root->val) {
            if (!first)
              first = prev;
            second = root;
          }
          prev = root;
          root = root->right;
        }
      } else {
        if (prev && prev->val > root->val) {
          if (!first)
            first = prev;
          second = root;
        }
        prev = root;
        root = root->right;
      }
    }
    swap(first->val, second->val);
  }
};