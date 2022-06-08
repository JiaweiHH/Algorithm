#include <queue>
using namespace std;

class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

template <int> class Solution;

/// 使用队列层序遍历
template <> class Solution<1> {
public:
  Node *connect(Node *root) {
    if (root == nullptr)
      return nullptr;
    queue<Node *> que;
    que.push(root);
    while (!que.empty()) {
      int len = que.size();
      for (int i = 0; i < len; ++i) {
        Node *node = que.front();
        que.pop();
        if (node->left)
          que.push(node->left);
        if (node->right)
          que.push(node->right);
        node->next = i == len - 1 ? nullptr : que.front();
      }
    }
    return root;
  }
};

/// O(1) 空间复杂度
template <> class Solution<2> {
public:
  Node *connect(Node *root) {
    Node *node = root;
    Node *next_start = nullptr, *prev = nullptr;
    while (node) {
      if (node->left) {
        if (prev == nullptr)
          next_start = node->left;
        else
          prev->next = node->left;
        prev = node->left;
      }
      if (node->right) {
        if (prev == nullptr)
          next_start = node->right;
        else
          prev->next = node->right;
        prev = node->right;
      }
      if (node->next == nullptr) {
        node = next_start;
        next_start = nullptr;
        prev = nullptr;
      } else {
        node = node->next;
      }
    }
    return root;
  }
};