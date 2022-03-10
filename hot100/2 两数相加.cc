
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode;
    ListNode *head = dummy;
    int flag = 0;
    while (l1 != nullptr && l2 != nullptr) {
      int val = l1->val + l2->val + flag;
      flag = val / 10;
      ListNode *node = new ListNode(val % 10);
      head->next = node;
      head = node;
      l1 = l1->next;
      l2 = l2->next;
    }
    while (l1 != nullptr) {
      int val = l1->val + flag;
      flag = val / 10;
      ListNode *node = new ListNode(val % 10);
      head->next = node;
      head = node;
      l1 = l1->next;
    }
    while (l2 != nullptr) {
      int val = l2->val + flag;
      flag = val / 10;
      ListNode *node = new ListNode(val % 10);
      head->next = node;
      head = node;
      l2 = l2->next;
    }
    if (flag) {
      ListNode *node = new ListNode(flag);
      head->next = node;
    }
    return dummy->next;
  }
};