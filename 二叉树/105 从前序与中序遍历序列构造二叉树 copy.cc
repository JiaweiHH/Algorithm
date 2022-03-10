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
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.size() == 0)
      return nullptr;
    auto it = find(inorder.begin(), inorder.end(), preorder[0]);
    vector<int> pre_left, pre_right, in_left, in_right;
    for (auto new_it = inorder.begin(); new_it != it; ++new_it)
      in_left.push_back(*new_it);
    for (auto new_it = it + 1; new_it != inorder.end(); ++new_it)
      in_right.push_back(*new_it);
    for (int i = 1; i <= in_left.size(); ++i)
      pre_left.push_back(preorder[i]);
    for (int i = in_left.size() + 1; i < preorder.size(); ++i)
      pre_right.push_back(preorder[i]);
    TreeNode *left = buildTree(pre_left, in_left);
    TreeNode *right = buildTree(pre_right, in_right);
    TreeNode *root = new TreeNode(preorder[0]);
    root->left = left;
    root->right = right;
    return root;
  }
};

template <> class Solution<2> {
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    return build(preorder, inorder, 0, preorder.size() - 1, 0,
                 inorder.size() - 1);
  }
  TreeNode *build(const vector<int> &preorder, const vector<int> &inorder,
                  int pre_start, int pre_end, int in_start, int in_end) {
    if (pre_start > pre_end)
      return nullptr;
    int root_val = preorder[pre_start];
    auto in_it = find(inorder.begin() + in_start, inorder.begin() + in_end + 1,
                      root_val);
    int position = in_it - inorder.begin();
    int left_size = position - in_start;
    TreeNode *root = new TreeNode(root_val);
    root->left = build(preorder, inorder, pre_start + 1, pre_start + left_size,
                       in_start, position - 1);
    root->right = build(preorder, inorder, pre_start + left_size + 1, pre_end,
                        position + 1, in_end);
    return root;
  }
};