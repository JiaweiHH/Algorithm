struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *dummy = new ListNode(-1), *tmp = dummy;
    while (head) {
      while (head && head->next && head->next->val == head->val) {
        int val = head->val;
        while (head && head->val == val)
          head = head->next;
      }
      tmp->next = head;
      tmp = head;
      if (head)
        head = head->next;
    }
    return dummy->next;
  }
};