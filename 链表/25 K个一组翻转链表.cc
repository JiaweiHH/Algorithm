// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

template <int> class Solution;

/// @brief 迭代
template <> class Solution<1> {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *dummy = new ListNode(-1), *prev = dummy;
    ListNode *cur = head;
    // 计算链表长度
    int len = 0;
    while (cur) {
      ++len;
      cur = cur->next;
    }
    // 头插法. 只要链表长度大于等于 k 或者 head != nullptr 就继续遍历
    while (head && len >= k) {
      ListNode *node = head;
      for (int i = 0; i < k && head; ++i) {
        ListNode *tmp = head->next;
        head->next = prev->next;
        prev->next = head;
        head = tmp;
      }
      len -= k;
      prev = node;
    }
    prev->next = head;
    return dummy->next;
  }
};

/// @brief 递归
template <> class Solution<2> {
public:
  ListNode *reverse(ListNode *left, ListNode *right) {
    ListNode *dummy = new ListNode(-1);
    while (left != right) {
      ListNode *tmp = left->next;
      left->next = dummy->next;
      dummy->next = left;
      left = tmp;
    }
    return dummy->next;
  }
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
};