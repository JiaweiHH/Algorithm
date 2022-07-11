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

/// @brief 哈希映射记录每个节点的父节点，然后从 p, q 出发哈希表记录路径上的节点
template <> class Solution<1> {
public:
  void dfs(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &map,
           TreeNode *parent) {
    if (root == nullptr)
      return;
    map[root] = parent;
    dfs(root->left, map, root);
    dfs(root->right, map, root);
  }
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    unordered_map<TreeNode *, TreeNode *> map;
    dfs(root, map, nullptr);
    unordered_set<TreeNode *> st;
    while (p) {
      st.insert(p);
      p = map[p];
    }
    while (q) {
      if (st.count(q))
        return q;
      q = map[q];
    }
    return nullptr;
  }
};

/// 后序遍历递归
template <> class Solution<2> {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == p || root == q || root == nullptr)
      return root;
    // root 左右子树查找 p 和 q 节点
    TreeNode *left = lowestCommonAncestor(root->left, p, q),
             *right = lowestCommonAncestor(root->right, p, q);
    // 1. left == nullptr, right == nullptr -> root 子树没有 p 和 q
    // 2. left or right != nullptr -> root 子树包含其中一个节点，返回 root 表示
    //    root 是其中一个节点的父节点
    // 3. left && right -> root 的子树中两个节点都找到了，则 root
    //    就是它们的公共祖先
    if (!left)
      return right;
    if (!right)
      return left;
    return root;
  }
};