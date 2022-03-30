// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

template <int> class Solution;

/// 递归
template <> class Solution<1> {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    if (!list1)
      return list2;
    if (!list2)
      return list1;
    if (list1->val < list2->val) {
      list1->next = mergeTwoLists(list1->next, list2);
      return list1;
    } else {
      list2->next = mergeTwoLists(list2->next, list1);
      return list2;
    }
    return nullptr;
  }
};

/// 迭代
template <> class Solution<2> {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *dummy = new ListNode(-1), *prev = dummy;
    while (list1 && list2) {
      if (list1->val < list2->val) {
        prev->next = list1;
        list1 = list1->next;
      } else {
        prev->next = list2;
        list2 = list2->next;
      }
      prev = prev->next;
    }
    if (list1)
      prev->next = list1;
    else
      prev->next = list2;
    return dummy->next;
  }
};