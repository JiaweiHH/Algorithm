#include <unordered_set>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

template <int> class Solution;

/// 哈希表
template <> class Solution<1> {
public:
  bool hasCycle(ListNode *head) {
    unordered_set<ListNode *> st;
    while (head) {
      if (st.count(head))
        return true;
      st.insert(head);
      head = head->next;
    }
    return false;
  }
};

/// 快慢指针
template <> class Solution<2> {
public:
  bool hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return false;
    ListNode *slow = head, *fast = head->next;
    while (slow != nullptr && fast && fast->next) {
      if (slow == fast)
        return true;
      slow = slow->next;
      fast = fast->next->next;
    }
    return false;
  }
};