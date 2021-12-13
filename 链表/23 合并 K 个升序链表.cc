#include <vector>
#include <queue>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/// @brief 给出 K 个升序的链表，合并成一个升序链表

/// @brief 分治，两两合并
class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.size() == 0)
      return nullptr;
    return merge(lists, 0, lists.size() - 1);
  }
  ListNode *merge(vector<ListNode *> &lists, int start, int end) {
    if (start == end)
      return lists[start];
    int mid = (start + end) / 2;
    auto left = merge(lists, start, mid);
    auto right = merge(lists, mid + 1, end);
    auto res = mergeTwo(left, right);
    return res;
  }
  // 合并两个链表
  ListNode *mergeTwo(ListNode *left, ListNode *right) {
    ListNode *dummy = new ListNode(0);
    ListNode *head = dummy;
    while (left && right) {
      if (left->val < right->val) {
        head->next = left;
        head = left;
        left = left->next;
      } else {
        head->next = right;
        head = right;
        right = right->next;
      }
    }
    while (left) {
      head->next = left;
      head = left;
      left = left->next;
    }
    while (right) {
      head->next = right;
      head = right;
      right = right->next;
    }
    return dummy->next;
  }
};

/// @brief 使用小顶堆
/// 每次从堆上 pop 出一个结点加入到输出的链表中，如果该节点还有 next 节点，那么继续加入到堆中
class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    auto cmp = [](ListNode *lhs, ListNode *rhs) { return rhs->val < lhs->val; };
    priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> que(cmp);
    for (auto head : lists) {
      if (head)
        que.push(head);
    }
    ListNode *dummy = new ListNode(0);
    ListNode *head = dummy;
    while (!que.empty()) {
      ListNode *node = que.top();
      que.pop();
      head->next = node;
      head = node;
      if (node->next)
        que.push(node->next);
    }
    return dummy->next;
  }
};