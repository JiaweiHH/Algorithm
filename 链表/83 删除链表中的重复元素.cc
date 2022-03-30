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
    ListNode *dummy = new ListNode(-1), *tmp = head;
    dummy->next = head;
    while (head) {
      ListNode *tmp = head;
      while (head && head->val == tmp->val)
        head = head->next;
      tmp->next = head;
      tmp = head;
    }
    return dummy->next;
  }
};