// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

template <int> class Solution;

/// 翻转链表判断
template <> class Solution<1> {
public:
  bool isPalindrome(ListNode *head) {
    ListNode *slow = head, *fast = head->next;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode *node1 = head, *node2 = reverse(slow->next);
    while (node2) {
      if (node1->val != node2->val)
        return false;
      node1 = node1->next;
      node2 = node2->next;
    }
    return true;
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

/// 递归判断
template <> class Solution<2> {
public:
  ListNode *node;
  bool isPalindrome(ListNode *head) {
    node = head;
    return palindrome(head);
  }
  bool palindrome(ListNode *head) {
    if (head == nullptr)
      return true;
    bool val = palindrome(head->next);
    val = val && (node->val == head->val);
    node = node->next;
    return val;
  }
};