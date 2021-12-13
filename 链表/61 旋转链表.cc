struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/// @brief 给定一个链表，旋转链表，将链表中的每个节点向右移动 k 个位置


/// @brief 链表每次向右移动一个位置，相当于头节点往后退一个位置
/// 所以首先把头节点往后退的步数转化为头节点前进的步数，即 n - k % n
/// 1. 如果说 k % n == 0，相当于头节点不需要动，直接返回 head
/// 2. 否则的话，记录最后 head 移动到的位置，然后将前驱节点的 next 指针设置为 null，
///    并且将原来链表中最后一个节点的 next 指针设置为原来的第一个节点
/// @return 返回移动后的节点指针
class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (k == 0 || head == nullptr)
      return head;
    // 计算节点的数量
    int n = 0;
    ListNode *tmp = head;
    ListNode *last = nullptr; // 记录最后一个节点
    while (tmp) {
      ++n;
      last = tmp;
      tmp = tmp->next;
    }
    // 每一次旋转相当于后退一步，转化为前进的步数. 
    // k % n 是化简之后的后退步数，n - k % n 是前进的步数
    int ahead = n - k % n;
    if (ahead == n) // 说明不需要任何旋转
      return head;
    ListNode *prev = nullptr;
    tmp = head;
    for (int i = 0; i < ahead; ++i) {
      prev = tmp;
      tmp = tmp->next;
    }
    last->next = head;
    prev->next = nullptr;
    head = tmp;
    return head;
  }
};