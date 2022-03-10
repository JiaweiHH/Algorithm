// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

template <int> class Solution;

template <> class Solution<1> {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *cur = head, *prev = nullptr;
    while (cur) {
      ListNode *tmp = cur->next;
      cur->next = prev;
      prev = cur;
      cur = tmp;
    }
    return prev;
  }
};

template <> class Solution<2> {
public:
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return head;
    ListNode *node = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return node;
  }
};