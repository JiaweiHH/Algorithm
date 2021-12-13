#include <unordered_set>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/// @brief 给出两个链表头节点，找出它们相交的第一个节点

class Solution {
public:
    /// @brief 采用哈希表保存第一个链表的所有节点，然后一个一个判断第二个链表中的节点是否存在于哈希表中
    /// 时间复杂度：O(m + n)
    /// 空间复杂度：O(m)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      unordered_set<ListNode *> s;
      while (headA != nullptr) {
        s.insert(headA);
        headA = headA->next;
      }
      while (headB != nullptr) {
        if (s.find(headB) != s.end())
          return headB;
        headB = headB->next;
      }
      return nullptr;
    }

    /// @brief 创建两个指针 pA 和 pB，初始时 pA 指向 headA，pB 指向 headB，然后两个指针每次循环前进一个节点，
    /// 如果 pA 变为 nullptr，则 pA 从 head B 重新开始，同理 pB 变为 nullptr 就从 headA 重新开始
    /// 1. 如果两个链表相交，那么最后 pA 和 pB 走过的距离是 a + b + c，
    ///    a 是 headA 不相交的节点个数，b 是 headB 不相交的节点个数，c 是它们之间相交的节点个数。
    ///    并且会在交点处相遇
    /// 2. 如果两个链表不相交，那么 pA 和 pB 最后走过的距离是 m + n，
    ///    m 是 headA 节点的个数，n 是 headB 节点的个数。
    ///    并且最后 pA 和 pB 都是 nullptr
    ListNode *getIntersectionNode_1(ListNode *headA, ListNode *headB) {
      if (headA == nullptr || headB == nullptr)
        return nullptr;
      ListNode *pA = headA, *pB = headB;
      while (pA != pB) {
        pA = pA == nullptr ? headB : pA->next;
        pB = pB == nullptr ? headA : pB->next;
      }
      return pA;
    }
};