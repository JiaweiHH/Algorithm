// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/// @brief 直接给出链表中带删除的节点，删除这个节点，注意不能访问到这个节点之前的节点

/// @brief 将后面的节点的值向前移动一个位置
class Solution {
public:
    void deleteNode(ListNode* node) {
      ListNode *prev;
      while(node->next) {
        node->val = node->next->val;
        prev = node;
        node = node->next;
      }
      prev->next = nullptr;
      delete node;
    }
};

/// @brief 将删除节点的值设为后一个节点的值，然后更改 node->next = node->next->next
class Solution_1 {
public:
    void deleteNode(ListNode* node) {
      node->val = node->next->val;
      node->next = node->next->next;
    }
};