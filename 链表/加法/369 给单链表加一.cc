// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/// @brief 给出一个单链表表示一个整数，链表的头部是该整数的高位，链表的尾部是该整数的低位。现在要求给这个整数加一

/// @brief 先对链表进行翻转，然后从头节点开始加一，
/// 如果出现最后一次进位的时候 cur 已经是 nullptr 了，则 new 一个节点。
/// 完成之后再对链表进行翻转一次
class Solution {
public:
  ListNode *plusOne(ListNode *head) {
    head = reverse(head);
    ListNode *cur = head, *prev = nullptr;
    int count = 1;
    while (cur) {
      if (cur->val + count == 10) {
        cur->val = 0;
        prev = cur;
        cur = cur->next;
      } else {
        cur->val += count;
        count = 0;
        break;
      }
    }
    if (count) {
      ListNode *node = new ListNode(count);
      prev->next = node;
    }
    head = reverse(head);
    return head;
  }
  ListNode *reverse(ListNode *head) {
    if (head == nullptr)
      return nullptr;
    ListNode *prev = nullptr;
    while (head) {
      ListNode *tmp = head->next;
      head->next = prev;
      prev = head;
      head = tmp;
    }
    return prev;
  }
};

/// @brief 找出最靠右的不是 9 的节点，将该节点的值加一，然后将该节点之后的所有节点的值改为 0
/// note：需要一个哨兵节点，初始记录不是 9 的节点为该哨兵节点，这样可以保证总是有不是 9 的节点存在1
class Solution {
public:
  ListNode *plusOne(ListNode *head) {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *not_nine = dummy;
    while (head) {
      if (head->val != 9)
        not_nine = head;
      head = head->next;
    }
    not_nine->val += 1;
    while (not_nine->next) {
      not_nine->next->val = 0;
      not_nine = not_nine->next;
    }
    return dummy->val == 1 ? dummy : dummy->next;
  }
};