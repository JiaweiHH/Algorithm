// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/// @brief 将链表的奇数节点放在所有的偶数节点前面

/// @brief odd 每个跳跃一个节点连接，even 每次连接 odd->next
/// 最后将 odd 的最后一个节点与 even 的第一个节点连接在一起
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
      if (head == nullptr || head->next == nullptr)
        return head;
      ListNode *odd = head, *even = head->next;
      ListNode *dummy = new ListNode();
      dummy->next = even;
      while (odd && odd->next) {
        odd->next = odd->next->next;
        // 这里判断是为了在节点个数为偶数的时候不会访问空指针
        if (odd->next)
          odd = odd->next;
        // even 每次都连接 odd 的 next 节点，该节点一定是偶数节点
        even->next = odd->next;
        // even 移动到下一个偶数节点
        even = even->next;
      }
      odd->next = dummy->next;
      return head;
    }

    /// 相同的思路，但是没有前面写的这么繁琐
    ListNode* oddEvenList_opt(ListNode* head) {
      if (head == nullptr || head->next == nullptr)
        return head;
      ListNode *odd = head, *even = head->next, *evenHead = head->next;
      // 由于 even 是走在前面的，所以对 even 进行判断
      while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
      }
      odd->next = evenHead;
      return head;
    }
};