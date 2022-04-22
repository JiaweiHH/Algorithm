struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *partition(ListNode *head, int x) {
    ListNode *dummy = new ListNode(-1);
    ListNode *pA = dummy, *pB = head, *prev = nullptr;
    ListNode *tmp = nullptr;
    while (pB) {
      if (pB->val < x) {
        pA->next = pB;
        pA = pA->next;
        if (prev) {
          prev->next = pB->next;
          pB->next = nullptr;
          pB = prev->next;
        } else {
          ListNode *next = pB->next;
          pB->next = nullptr;
          pB = next;
        }
      } else {
        if (tmp == nullptr)
          tmp = pB;
        prev = pB;
        pB = pB->next;
      }
    }
    pA->next = tmp;
    return dummy->next;
  }
};