#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

template <int> class Solution;

/// 哈希 + 迭代
template <> class Solution<1> {
public:
  Node *copyRandomList(Node *head) {
    Node *dummy = new Node(-1), *prev = dummy;
    unordered_map<Node *, Node *> map;
    Node *cur = head;
    while (cur) {
      Node *node = new Node(cur->val);
      prev->next = node;
      prev = node;
      map.insert({cur, node});
      cur = cur->next;
    }
    prev = dummy->next;
    while (head) {
      prev->random = map[head->random];
      head = head->next;
      prev = prev->next;
    }
    return dummy->next;
  }
};

/// 哈希 + 递归
template <> class Solution<2> {
public:
  unordered_map<Node *, Node *> map;
  Node *copyRandomList(Node *head) {
    if (head == nullptr)
      return nullptr;
    if (!map.count(head)) {
      Node *node = new Node(head->val);
      map[head] = node;
      node->next = copyRandomList(head->next);
      node->random = copyRandomList(head->random);
      return node;
    }
    return map[head];
  }
};

/// 节点拆分链接
template <> class Solution<3> {
public:
  Node *copyRandomList(Node *head) {
    if (head == nullptr)
      return nullptr;
    Node *dummy = new Node(-1), *tag = head;
    while (head) {
      Node *node = new Node(head->val);
      Node *next = head->next;
      head->next = node;
      node->next = next;
      head = next;
    }
    head = tag;
    while (head) {
      if (head->random)
        head->next->random = head->random->next;
      head = head->next->next;
    }
    head = tag;
    Node *prev = nullptr, *res = head->next;
    while (head) {
      if (prev) {
        prev->next->next = head->next;
        prev->next = head;
      }
      prev = head;
      head = head->next->next;
    }
    prev->next = nullptr;
    return res;
  }
};