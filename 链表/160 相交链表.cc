#include <unordered_set>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/// @brief 给出两个链表头节点，找出它们相交的第一个节点

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      unordered_set<ListNode *> s;
      while (headA != nullptr) {
        s.insert(headA);
        headA = headA->next;
      }
      while (headB != nullptr) {
        if (s.find(headB) != s.end())
          return headB;
        headB = headB->next;
      }
      return nullptr;
    }

    ListNode *getIntersectionNode_1(ListNode *headA, ListNode *headB) {
      if (headA == nullptr || headB == nullptr)
        return nullptr;
      ListNode *pA = headA, *pB = headB;
      while (pA != pB) {
        pA = pA == nullptr ? headB : pA->next;
        pB = pB == nullptr ? headA : pB->next;
      }
      return pA;
    }
};