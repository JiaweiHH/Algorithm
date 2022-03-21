// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

template <int> class Solution;

/// 迭代
template <> class Solution<1> {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *dummy = new ListNode(-1), *prev = dummy;
    dummy->next = head;
    int count = 1;
    while (head) {
      if (count % k == 0) {
        ListNode *next = head->next;
        head->next = nullptr;
        ListNode *node = reverse(prev->next);
        ListNode *tmp = prev->next;
        prev->next = node;
        prev = tmp;
        prev->next = next;
        head = next;
      } else {
        head = head->next;
      }
      ++count;
    }
    return dummy->next;
  }
  ListNode *reverse(ListNode *head) {
    ListNode *prev = nullptr;
    while (head) {
      ListNode *next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }
    return prev;
  }
};

/// 递归
template <> class Solution<2> {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *left = head, *right = head;
    int n = k;
    while (n--) {
      if (right == nullptr)
        return head;
      right = right->next;
    }
    ListNode *node = reverse(left, right);
    left->next = reverseKGroup(right, k);
    return node;
  }
  ListNode *reverse(ListNode *left, ListNode *right) {
    ListNode *dummy = new ListNode(-1), *tmp = left;
    ;
    while (left != right) {
      ListNode *next = left->next;
      left->next = dummy->next;
      dummy->next = left;
      left = next;
    }
    return dummy->next;
  }
};