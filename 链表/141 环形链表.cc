#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    if (head == nullptr)
      return false;
    ListNode *pA = head, *pB = head->next;
    while (pB && pB->next && pA != pB) {
      pA = pA->next;
      pB = pB->next->next;
    }
    return pA == pB;
  }
};