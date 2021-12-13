// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/// @brief 移除一个链表中所有节点值为 val 的元素

class Solution {
public:
    /// @brief 很简单，只需要注意使用 dummy 节点即可
    ListNode* removeElements(ListNode* head, int val) {
      ListNode *dummy = new ListNode();
      dummy->next = head;
      ListNode *prev = dummy;
      while(head){
        if (head->val == val) {
          prev->next = head->next;
          head->next = nullptr;
          head = prev->next;
        } else {
          prev = head;
          head = head->next;
        }
      }
      return dummy->next;
    }
};

class Solution_1 {
public:
    /// @brief 递归方式，终止条件是 head 为空，每次更新 head->next
    ListNode* removeElements(ListNode* head, int val) {
      if (head == nullptr)
        return nullptr;
      head->next = removeElements(head->next, val);
      return head->val == val ? head->next : head;
    }
};