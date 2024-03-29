struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (head == nullptr)
      return nullptr;
    int len = 0;
    ListNode *cur = head;
    while (cur) {
      ++len;
      cur = cur->next;
    }
    k = k % len;
    if (k == 0)
      return head;
    ListNode *pA = head, *pB = head;
    for (int i = 0; i < k; ++i)
      pB = pB->next;
    while (pB->next) {
      pA = pA->next;
      pB = pB->next;
    }
    ListNode *res = pA->next;
    pA->next = nullptr;
    pB->next = head;
    return res;
  }
};