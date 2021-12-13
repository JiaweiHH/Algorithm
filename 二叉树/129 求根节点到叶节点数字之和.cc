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

/// @brief 给定一棵二叉树求根节点到叶节点组成的数组之和，例如 [1,2,3]
/// 可以得到数字 12 和 13，因此答案是 25

template <int> class Solution;

/// @brief 非递归深度优先搜索
/// 使用两个栈，第一个栈存放树的节点，第二个栈存放遍历到当前节点时候的值，每次从两个栈中弹出一个值
/// 当某一个节点是叶节点时，将栈中的值加到最后结果中
template <> class Solution<1> {
public:
  int sumNumbers(TreeNode *root) {
    if (root == nullptr)
      return 0;
    stack<TreeNode *> stk;
    stack<int> value;
    int sum = 0, cur = 0;
    while (!stk.empty() || root) {
      while (root != nullptr) {
        cur = cur * 10 + root->val;
        stk.push(root);
        value.push(cur);
        root = root->left;
      }
      auto node = stk.top();
      stk.pop();
      cur = value.top();
      value.pop();
      if (!node->left && !node->right) {
        sum += cur;
      }
      root = node->right;
    }
    return sum;
  }
};

/// @brief 递归深度优先搜索
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

/// @brief 广度优先搜索
/// 思路同方法一类似，使用两个队列，第一个存放当前元素，第二个存放遍历到该元素时的值
/// 每次从两个队列中弹出一个元素，当该元素是叶节点时，将值累加到最后结果
template <> class Solution<3> {
public:
  int sumNumbers(TreeNode *root) {
    if (!root)
      return 0;
    queue<TreeNode *> tree_que;
    queue<int> val_que;
    int sum = 0, cur = 0;
    tree_que.push(root);
    val_que.push(root->val);
    while (!tree_que.empty()) {
      auto node = tree_que.front();
      tree_que.pop();
      cur = val_que.front();
      val_que.pop();
      if (node->left) {
        tree_que.push(node->left);
        val_que.push(cur * 10 + node->left->val);
      }
      if (node->right) {
        tree_que.push(node->right);
        val_que.push(cur * 10 + node->right->val);
      }
      if (!node->left && !node->right)
        sum += cur;
    }
    return sum;
  }
};