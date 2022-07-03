#include <queue>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

template <int> class Solution;

/// @brief 归并排序
template <> class Solution<1> {
public:
  ListNode *findMiddle(ListNode *head) {
    ListNode *slow = head, *fast = head->next;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }
  ListNode *merge_sort(ListNode *head) {
    if (head->next == nullptr)
      return head;
    ListNode *node = findMiddle(head);
    ListNode *tmp = node->next;
    node->next = nullptr;
    ListNode *left = merge_sort(head), *right = merge_sort(tmp);
    ListNode *dummy = new ListNode(-1), *prev = dummy;
    while (left && right) {
      if (left->val < right->val) {
        prev->next = left;
        left = left->next;
      } else {
        prev->next = right;
        right = right->next;
      }
      prev = prev->next;
    }
    while (left) {
      prev->next = left;
      left = left->next;
      prev = prev->next;
    }
    while (right) {
      prev->next = right;
      right = right->next;
      prev = prev->next;
    }
    return dummy->next;
  }
  // O(nlogn), O(1)
  ListNode *sortList(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return head;
    return merge_sort(head);
  }
};

/// 迭代归并排序
template <> class Solution<2> {
public:
  ListNode *merge(ListNode *head1, ListNode *head2) {
    ListNode *dummy = new ListNode(0), *tmp = dummy;
    while (head1 && head2) {
      if (head1->val < head2->val) {
        tmp->next = head1;
        head1 = head1->next;
      } else {
        tmp->next = head2;
        head2 = head2->next;
      }
      tmp = tmp->next;
    }
    if (head1)
      tmp->next = head1;
    else
      tmp->next = head2;
    return dummy->next;
  }
  ListNode *sortList(ListNode *head) {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    int length = 0;
    while (head) {
      length++;
      head = head->next;
    }
    for (int subLength = 1; subLength <= length; subLength <<= 1) {
      ListNode *curr = dummy->next, *prev = dummy;
      while (curr) {
        ListNode *head1 = curr;
        // 向后一定 subLength 长度，确定第二个子链表
        for (int i = 1; i < subLength && curr->next; ++i)
          curr = curr->next;
        // 断开第一个链表
        ListNode *head2 = curr->next;
        curr->next = nullptr;
        curr = head2;
        // 寻找第二个链表的结尾
        for (int i = 1; i < subLength && curr && curr->next; ++i)
          curr = curr->next;
        // 记录第三个子链表的开始位置（即下一趟准备合并的两个子链表的第一个链表的开始位置）
        ListNode *next = nullptr;
        if (curr) {
          // 断开第二个子链表
          next = curr->next;
          curr->next = nullptr;
        }
        ListNode *node = merge(head1, head2);
        prev->next = node;
        while (prev->next)
          prev = prev->next;
        curr = next;
      }
    }
    return dummy->next;
  }
};

/// @brief 快速排序（会超时，知道有这个写法就可以）
template <> class Solution<3> {
public:
  ListNode *quickSort(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return head;
    // 以 head 为 pivot
    ListNode *small = new ListNode(-1), *large = new ListNode(-1),
             *tmp = head->next;
    ListNode *pA = small, *pB = large;
    while (tmp) {
      if (tmp->val < head->val) {
        pA->next = tmp;
        pA = pA->next;
      } else {
        pB->next = tmp;
        pB = pB->next;
      }
      tmp = tmp->next;
    }
    pA->next = head;
    head->next = nullptr;
    pB->next = nullptr;
    ListNode *left = quickSort(small->next), *right = quickSort(large->next);
    head->next = right;
    return left;
  }
  ListNode *sortList(ListNode *head) { return quickSort(head); }
};

/// @brief 堆排序
template <> class Solution<4> {
public:
  ListNode *sortList(ListNode *head) {
    auto cmp = [](const ListNode *lhs, const ListNode *rhs) {
      return lhs->val > rhs->val;
    };
    priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> heap(cmp);
    while (head) {
      heap.push(head);
      head = head->next;
    }
    ListNode *dummy = new ListNode(-1), *prev = dummy;
    while (!heap.empty()) {
      prev->next = heap.top();
      heap.pop();
      prev = prev->next;
    }
    prev->next = nullptr; // 不要忘记执行，否则会出错
    return dummy->next;
  }
};

/// @brief 堆排序 手写堆
template <> class Solution<5> {
public:
  void minHeapify(vector<ListNode *> &heap, int idx, size_t heapSize) {
    int l = idx * 2, r = idx * 2 + 1, target = idx;
    if (l <= heapSize && heap[l]->val < heap[target]->val)
      target = l;
    if (r <= heapSize && heap[r]->val < heap[target]->val)
      target = r;
    if (target != idx) {
      swap(heap[target], heap[idx]);
      minHeapify(heap, target, heapSize);
    }
  }
  void buildHeap(vector<ListNode *> &heap, size_t heapSize) {
    for (int i = heapSize / 2; i >= 1; --i)
      minHeapify(heap, i, heapSize);
  }
  ListNode *sortList(ListNode *head) {
    vector<ListNode *> heap(1);
    size_t heapSize = 0;
    while (head) {
      heap.push_back(head);
      ++heapSize;
      head = head->next;
    }
    buildHeap(heap, heapSize);
    ListNode *dummy = new ListNode(-1), *prev = dummy;
    while (heapSize > 0) {
      prev->next = heap[1];
      prev = prev->next;
      swap(heap[1], heap[heapSize--]);
      minHeapify(heap, 1, heapSize);
    }
    prev->next = nullptr;
    return dummy->next;
  }
};