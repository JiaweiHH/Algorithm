#include <climits>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/// @brief 对一个单链表进行插入排序

/// @brief 直接根据数组的插入排序思路来
class Solution {
public:
  ListNode *insertionSortList(ListNode *head) {
    ListNode *dummy = new ListNode(INT_MIN);
    dummy->next = head;
    ListNode *prev = head;
    head = head->next;
    while (head) {
      ListNode *cur_prev = nullptr, *cur;
      for (cur = dummy; cur->val < head->val && cur != head;
           cur_prev = cur, cur = cur->next)
        ;
      if (cur == head) {
        prev = head;
        head = head->next;
      } else {
        ListNode *next = head->next;
        head->next = cur;
        cur_prev->next = head;
        prev->next = next;
        head = next;
      }
    }
    return dummy->next;
  }
};