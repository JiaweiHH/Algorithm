#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/// @brief 给出一个链表 head 和一个整数 k，要求将链表分割为 k 部分。
/// 每部分的长度尽可能相等：任意两部分的长度差距不能超过 1，这 k 部分应该按照链表中出现的顺序排列，
/// 并且排在前面的部分的长度应该大于或等于排在后面部分的长度

/// @brief
/// 1. 计算链表长度 count
/// 2. 计算每部分平均长度 avg = count / k，以及余数 remain = count % k
/// 3. 循环 k 次，每次看 remain 是不是等于 0，如果不是 0，那么这次循环包含的节点数是 avg + 1。
///    每次循环结束 remain--，并断开这部分与链表的连接
class Solution {
public:
  vector<ListNode *> splitListToParts(ListNode *head, int k) {
    if (head == nullptr)
      return vector<ListNode *>(k, nullptr);
    int count = 0;
    for (ListNode *cur = head; cur != nullptr; cur = cur->next)
      ++count;

    vector<ListNode *> res;
    int avg = count / k, remain = count % k, length;
    ListNode *prev = nullptr;
    for (int i = 0; i < k; ++i) {
      length = remain > 0 ? avg + 1 : avg;
      res.push_back(head);
      while (length-- && head) {
        prev = head;
        head = head->next;
      }
      prev->next = nullptr;
      remain--;
    }
    return res;
  }
};