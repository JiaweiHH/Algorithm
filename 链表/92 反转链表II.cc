
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

template <int> class Solution;

/// 直接反转
template <> class Solution<1> {
public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    ListNode *dummy = new ListNode;
    dummy->next = head;
    ListNode *tmp = head, *prev = dummy;
    for (int i = 1; i < left; ++i) {
      prev = tmp;
      tmp = tmp->next;
    }
    reverse(prev, right - left + 1);
    return dummy->next;
  }
  void reverse(ListNode *dummy, int num) {
    ListNode *cur = dummy->next, *prev = nullptr;
    for (int i = 1; i <= num; ++i) {
      ListNode *tmp = cur->next;
      cur->next = prev;
      prev = cur;
      cur = tmp;
    }
    dummy->next->next = cur;
    dummy->next = prev;
  }
};

/// 头插法
template <> class Solution<2> {
public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *prev = dummy, *curr = head;
    for (int i = 1; i < left; ++i) {
      prev = curr;
      curr = curr->next;
    }
    for (int i = 0; i < right - left; ++i) {
      ListNode *next = prev->next;
      prev->next = curr->next;
      curr->next = prev->next->next;
      prev->next->next = next;
    }
    return dummy->next;
  }
};

/// 递归
template <> class Solution<3> {
public:
  ListNode *successor = nullptr;
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    if (left == 1)
      return reverseN(head, right);
    ListNode *last = reverseBetween(head->next, left - 1, right - 1);
    head->next = last;
    return head;
  }
  ListNode *reverseN(ListNode *head, int right) {
    if (right == 1) {
      successor = head->next;
      return head;
    }
    ListNode *last = reverseN(head->next, right - 1);
    head->next->next = head;
    head->next = successor;
    return last;
  }
};