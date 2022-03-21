#include <queue>
#include <string>
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

class Codec {
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    if (root == nullptr)
      return "";
    queue<TreeNode *> q;
    string res;
    q.push(root);
    res.append(to_string(root->val));
    while (!q.empty()) {
      TreeNode *node = q.front();
      q.pop();

      res.push_back(',');
      if (node->left) {
        res.append(to_string(node->left->val));
        q.push(node->left);
      } else {
        res.push_back('.');
      }

      res.push_back(',');
      if (node->right) {
        res.append(to_string(node->right->val));
        q.push(node->right);
      } else {
        res.push_back('.');
      }
    }
    return res;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    if (data.empty())
      return nullptr;
    int idx = data.find_first_of(',');
    TreeNode *root = new TreeNode(stoi(data.substr(0, idx)));
    queue<TreeNode *> q;
    q.push(root);
    ++idx;
    while (idx < data.size()) {
      TreeNode *node = q.front();
      q.pop();
      build_left_and_right(node, idx, data, q);
    }
    return root;
  }
  void build_left_and_right(TreeNode *root, int &idx, const string &data,
                            queue<TreeNode *> &q) {
    // 左节点
    if (data[idx] == '.') {
      root->left = nullptr;
      ++idx;
    } else {
      int num = 0, tag = 0;
      while (data[idx] != ',') {
        if (data[idx] == '-')
          tag = 1;
        else
          num = num * 10 + data[idx] - '0';
        ++idx;
      }
      if (tag)
        num = -num;
      root->left = new TreeNode(num);
      q.push(root->left);
    }
    ++idx;
    if (idx == data.size())
      return;
    // 右节点
    if (data[idx] == '.') {
      root->right = nullptr;
      ++idx;
    } else {
      int num = 0, tag = 0;
      while (idx != data.size() && data[idx] != ',') {
        if (data[idx] == '-')
          tag = 1;
        else
          num = num * 10 + data[idx] - '0';
        ++idx;
      }
      if (tag)
        num = -num;
      root->right = new TreeNode(num);
      q.push(root->right);
    }
    if (idx != data.size())
      ++idx;
  }
};