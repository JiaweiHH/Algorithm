#include <unordered_map>
#include <unordered_set>
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

/// 哈希
template <> class Solution<1> {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    unordered_map<TreeNode *, TreeNode *> map;
    dfs(root, map, nullptr);
    unordered_set<TreeNode *> st;
    while (p != nullptr) {
      st.insert(p);
      p = map[p];
    }
    while (q != nullptr) {
      if (st.count(q))
        return q;
      q = map[q];
    }
    return nullptr;
  }
  void dfs(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &map,
           TreeNode *parent) {
    if (root == nullptr)
      return;
    map[root] = parent;
    dfs(root->left, map, root);
    dfs(root->right, map, root);
  }
};

/// 后序遍历递归
template <> class Solution<2> {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == nullptr)
      return nullptr;
    if (root == p || root == q)
      return root;
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if (left && right)
      return root;
    if (left)
      return left;
    if (right)
      return right;
    return nullptr;
  }
};