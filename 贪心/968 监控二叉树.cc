#include <vector>
using namespace std;

/// 给定一个二叉树，我们在树的节点上安装摄像头. 节点上的每个摄影头都可以监视其父对象、自身及其直接子对象
/// 计算监控树的所有节点所需的最小摄像头数量

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

/// 按照后续遍历的方式遍历二叉树节点，对于每一个节点，判断其左右孩子的状态
/// 0 表示没有被监控，1 表示被监控，2 表示安装了摄像头
/// 1. 如果子节点有一个 0，那么该节点需要安装摄像头，即状态是 2
/// 2. 如果子节点有有一个 2，那么该节点的状态就是被监控，即 1
/// 3. 如果两个子节点都是 1，那么说明子节点都被监控了，那么该节点的状态就是 0，即需要被它的父节点监控
class Solution {
public:
  int res = 0;
  // 贪心策略：自底向上，尽量由上面的节点安装摄像头监控下面的节点
  int minCameraCover(TreeNode *root) {
    // 如果二叉树的根节点返回的状态是 0，说明本来打算让 root
    // 的父节点来安装摄像头监视的 但是 root
    // 已经没有父节点了，因此需要自己安装摄像头
    if (post_order(root) == 0)
      res++;
    return res;
  }
  // 0 表示未被监视，1 表示被监视，2 表示安装了摄像头
  int post_order(TreeNode *root) {
    if (root == nullptr)
      return 1;
    int left = post_order(root->left);
    int right = post_order(root->right);
    // 子节点都被监视了，那么父节点应该被它的的父节点监视，即让它的父节点安装摄像头
    if (left == 1 && right == 1)
      return 0;
    // 有一个子节点没有被监视，那么父节点应该安装摄像头
    if (left == 0 || right == 0) {
      res++;
      return 2;
    }
    // 有一个子节点安装摄像头了，那么父节点的状态应该是被监视
    if (left == 2 || right == 2)
      return 1;
    return -1;
  }
};