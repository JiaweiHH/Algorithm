#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  void reorderList(ListNode *head) {
    ListNode *slow = head, *fast = head->next;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode *node = reverse(slow->next);
    slow->next = nullptr;
    while (node && head) {
      ListNode *next_head = head->next, *next_node = node->next;
      node->next = head->next;
      head->next = node;
      head = next_head;
      node = next_node;
    }
  }
  ListNode *reverse(ListNode *head) {
    ListNode *dummy = new ListNode(-1);
    while (head) {
      ListNode *next = head->next;
      head->next = dummy->next;
      dummy->next = head;
      head = next;
    }
    return dummy->next;
  }
};