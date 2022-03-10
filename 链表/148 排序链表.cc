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

/// 递归归并排序
template <> class Solution<1> {
public:
  ListNode *sortList(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return head;
    ListNode *slow = head, *fast = head->next;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    // 对左右两半链表进行排序
    ListNode *left = sortList(slow->next);
    slow->next = nullptr;
    ListNode *right = sortList(head);

    // 合并排序的链表
    ListNode *dummy = new ListNode(0);
    ListNode *tmp = dummy;
    while (left && right) {
      if (left->val < right->val) {
        tmp->next = left;
        left = left->next;
      } else {
        tmp->next = right;
        right = right->next;
      }
      tmp = tmp->next;
    }
    while (left) {
      tmp->next = left;
      left = left->next;
      tmp = tmp->next;
    }
    while (right) {
      tmp->next = right;
      right = right->next;
      tmp = tmp->next;
    }
    return dummy->next;
  }
};

/// 迭代归并排序
template <> class Solution<2> {
public:
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
};

/// 快排
template <> class Solution<3> {
public:
  ListNode *sortList(ListNode *head) { return quickSort(head); }
  ListNode *quickSort(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return head;
    ListNode *small = new ListNode(0), *large = new ListNode(0);
    ListNode *pA = small, *pB = large, *tmp = head->next;
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

    ListNode *left = quickSort(small->next);
    ListNode *right = quickSort(large->next);
    head->next = right;

    return left;
  }
};

/// 堆排序
template <> class Solution<4> {
public:
  ListNode *sortList(ListNode *head) {
    auto cmp = [](const ListNode *lhs, const ListNode *rhs) {
      return lhs->val > rhs->val;
    };
    priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> queue(cmp);
    while (head) {
      queue.push(head);
      head = head->next;
    }
    ListNode *dummy = new ListNode(0), *tmp = dummy;
    while (!queue.empty()) {
      ListNode *node = queue.top();
      queue.pop();
      tmp->next = node;
      tmp = node;
    }
    tmp->next = nullptr;
    return dummy->next;
  }
};

/// 手写堆排序
template <> class Solution<5> {
public:
  ListNode *sortList(ListNode *head) {
    ListNode *tmp = head;
    vector<ListNode *> heap(1, nullptr);
    while (tmp) {
      heap.push_back(tmp);
      tmp = tmp->next;
    }
    int heapSize = heap.size() - 1;
    buildMinHeap(heap, heapSize);

    ListNode *dummy = new ListNode(0);
    tmp = dummy;
    while (heapSize > 0) {
      ListNode *node = heap[1];
      tmp->next = node;
      tmp = tmp->next;
      swap(heap[1], heap[heapSize]);
      heapSize--;
      minHeapify(heap, 1, heapSize);
    }
    tmp->next = nullptr;
    return dummy->next;
  }
  void buildMinHeap(vector<ListNode *> &heap, int heapSize) {
    for (int i = heapSize / 2; i > 0; --i)
      minHeapify(heap, i, heapSize);
  }
  void minHeapify(vector<ListNode *> &heap, int index, int heapSize) {
    int l = index * 2, r = index * 2 + 1, target = index;
    if (l <= heapSize && heap[l]->val < heap[target]->val)
      target = l;
    if (r <= heapSize && heap[r]->val < heap[target]->val)
      target = r;
    if (target != index) {
      swap(heap[index], heap[target]);
      minHeapify(heap, target, heapSize);
    }
  }
};