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

// 对比第 198 题，现在的房屋是呈现为一棵二叉树，相邻的结点不能同时选择

// dfs + dp
// 对于每一个节点 node 来说，有两种情况
// 1. 选择该节点的值，那么此时就不能选择它的左右孩子
// 2. 不选择该节点的值，那么左右孩子都可以考虑选择或者不选择
// dfs 先遍历 node 的左右子树，获取到左右子树选择或者不选择能达到的最优值
// 然后根据获取的结果，来计算 node 的最优值
// 层层向上，最后计算出 root 的最优值
class Solution {
public:
  int rob(TreeNode *root) {
    auto pair = dfs(root);
    return max(pair.first, pair.second);
  }
  // pair::first 表示选择该节点能得到的最优值
  // pair::second 表示不选择该节点能得到的最优值
  std::pair<int, int> dfs(TreeNode *root) {
    if (root == nullptr)
      return {0, 0};
    auto p_left = dfs(root->left);
    auto p_right = dfs(root->right);
    // 选择节点 root，那么它的左右孩子就不能选择
    int choose = root->val + p_left.second + p_right.second;
    // 不选择 root，左右结点既可以选也可以不选，那么该节点能获取的最大值就是
    // max(选择或者不选择左结点)+max(选择或者不选择右结点)
    int not_choose =
        max(p_left.first, p_left.second) + max(p_right.first, p_right.second);
    return {choose, not_choose};
  }
};