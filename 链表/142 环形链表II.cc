#include <vector>
using namespace std;

/// @brief 如果需要计算环中节点的数量，在找到环的入口之后，
/// 快慢指针一起从入口出发，再次相遇的时候，
/// 「快指针走过的节点数量 - 慢指针走过的节点数量」就是环的节点数量

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    if (head == nullptr)
      return nullptr;
    ListNode *pA = head, *pB = head->next;
    while (pB && pB->next && pA != pB) {
      pA = pA->next;
      pB = pB->next->next;
    }
    if (pA != pB)
      return nullptr;
    pA = head, pB = pB->next;
    while (pA != pB) {
      pA = pA->next;
      pB = pB->next;
    }
    return pA;
  }
};