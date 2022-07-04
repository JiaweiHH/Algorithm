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
  ListNode *swapPairs(ListNode *head) {
    ListNode *dummy = new ListNode(-1), *prev = dummy;
    while (head) {
      ListNode *next = head;
      for (int i = 0; i < 2 && head; ++i) {
        ListNode *tmp = head->next;
        head->next = prev->next;
        prev->next = head;
        head = tmp;
      }
      prev = next;
    }
    return dummy->next;
  }
};