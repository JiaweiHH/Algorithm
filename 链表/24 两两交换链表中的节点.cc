// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/// @brief 给定一个链表，两两交换其中相邻节点，返回交换后的链表

class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return head;
    ListNode *res = head->next;
    // prev 记录每一轮交换后，对于下一轮来说的前驱节点
    ListNode *prev = nullptr;
    while (head) {
      ListNode *tmp0 = head->next;
      // tmp0 == nullptr 说明这一轮只有一个节点，可以直接退出
      if (tmp0) {
        // tmp1 记录下一轮的开始节点
        ListNode *tmp1 = tmp0->next;
        // 交换节点位置
        head->next = tmp1;
        tmp0->next = head;
        // 如果上一轮有记录前驱节点，那么前驱节点的后继节点需要更改
        if (prev)
          prev->next = tmp0;
        prev = head;
        head = head->next;
      } else
        break;
    }
    return res;
  }
};