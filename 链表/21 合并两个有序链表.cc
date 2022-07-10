// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

template <int> class Solution;

/// @brief 递归
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
      list2->next = mergeTwoLists(list1, list2->next);
      return list2;
    }
    return nullptr;
  }
};

/// @brief 迭代
template <> class Solution<2> {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *dummy = new ListNode(-1), *curr = dummy;
    while (list1 && list2) {
      if (list1->val < list2->val) {
        curr->next = list1;
        list1 = list1->next;
      } else {
        curr->next = list2;
        list2 = list2->next;
      }
      curr = curr->next;
    }
    if (list1)
      curr->next = list1;
    else
      curr->next = list2;
    return dummy->next;
  }
};

/// @brief 去除重复元素
template <> class Solution<3> {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *dummy = new ListNode(-1), *curr = dummy;
    while (list1 && list2) {
      if (list1->val < list2->val) {
        ListNode *tmp = list1->next;
        if (list1->val != curr->val) {
          curr->next = list1;
          curr = curr->next;
          curr->next = nullptr;
        }
        list1 = tmp;
      } else {
        ListNode *tmp = list2->next;
        if (list2->val != curr->val) {
          curr->next = list2;
          curr = curr->next;
          curr->next = nullptr;
        }
        list2 = tmp;
      }
    }
    while (list1) {
      ListNode *tmp = list1->next;
      if (list1->val != curr->val) {
        curr->next = list1;
        curr = curr->next;
        curr->next = nullptr;
      }
      list1 = tmp;
    }
    while (list2) {
      ListNode *tmp = list2->next;
      if (list2->val != curr->val) {
        curr->next = list2;
        curr = curr->next;
        curr->next = nullptr;
      }
      list2 = tmp;
    }
    return dummy->next;
  }
};