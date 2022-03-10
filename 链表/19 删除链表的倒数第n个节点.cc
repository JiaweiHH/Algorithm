// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *dummy = new ListNode;
    dummy->next = head;
    ListNode *node1 = dummy, *node2 = dummy;
    for (int i = 0; i < n; ++i)
      node2 = node2->next;
    while (node2->next) {
      node2 = node2->next;
      node1 = node1->next;
    }
    node1->next = node1->next->next;
    return dummy->next;
  }
};