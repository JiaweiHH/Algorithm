#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return nullptr;
    ListNode *slow = head, *fast = head->next;
    while (slow != fast) {
      if (fast == nullptr || fast->next == nullptr)
        return nullptr;
      slow = slow->next;
      fast = fast->next->next;
    }
    slow = head;
    fast = fast->next;
    while (slow != fast) {
      slow = slow->next;
      fast = fast->next;
    }
    return slow;
  }
};