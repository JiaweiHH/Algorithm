#include <stack>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/// @brief 给你两个非空链表表示两个非负整数，数字的最高位位于链表开始的位置，
/// 每个节点只存储一个数字，计算这两个数相加

template <int>
class Solution {};

/// @brief 先翻转两个链表，然后逐位相加
template <> class Solution<1> {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    l1 = reverse(l1);
    l2 = reverse(l2);
    int count = 0, len1 = 0, len2 = 0;
    ListNode *prev = nullptr, *res = l1;
    while (l1 && l2) {
      l1->val += l2->val + count;
      if (l1->val >= 10) {
        l1->val -= 10;
        count = 1;
      } else {
        count = 0;
      }
      prev = l1;
      l1 = l1->next;
      l2 = l2->next;
    }
    if (l2 != nullptr) {
      ListNode *tmp = l2;
      prev->next = l2;
      while (l2) {
        l2->val += count;
        if (l2->val >= 10) {
          l2->val -= 10;
          count = 1;
        } else {
          count = 0;
        }
        prev = l2;
        l2 = l2->next;
      }
    } else if (l1 != nullptr) {
      while (l1) {
        l1->val += count;
        if (l1->val >= 10) {
          l1->val -= 10;
          count = 1;
        } else {
          count = 0;
        }
        prev = l1;
        l1 = l1->next;
      }
    }
    if (count) {
      ListNode *node = new ListNode(count);
      prev->next = node;
    }
    return reverse(res);
  }
  ListNode *reverse(ListNode *head) {
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

/// @brief 使用栈
template <> class Solution<2> {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    stack<int> stack_1, stack_2;
    while (l1) {
      stack_1.push(l1->val);
      l1 = l1->next;
    }
    while (l2) {
      stack_2.push(l2->val);
      l2 = l2->next;
    }
    ListNode *res = nullptr;
    int carry = 0;
    while (!stack_1.empty() || !stack_2.empty()) {
      int a = stack_1.empty() ? 0 : stack_1.top();
      int b = stack_2.empty() ? 0 : stack_2.top();
      if (!stack_1.empty())
        stack_1.pop();
      if (!stack_2.empty())
        stack_2.pop();
      int val = a + b + carry;
      carry = val / 10;
      val %= 10;
      ListNode *node = new ListNode(val);
      node->next = res;
      res = node;
    }
    if (carry) {
      ListNode *node = new ListNode(carry);
      node->next = res;
      res = node;
    }
    return res;
  }
};