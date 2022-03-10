#include <queue>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

template <int> class Solution;

/// 归并排序
template <> class Solution<1> {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.size() == 0)
      return nullptr;
    return merge(lists, 0, lists.size() - 1);
  }
  ListNode *merge(vector<ListNode *> &lists, int l, int r) {
    if (l == r)
      return lists[l];
    int mid = (l + r) / 2;
    ListNode *left = merge(lists, l, mid);
    ListNode *right = merge(lists, mid + 1, r);
    return mergeTwoLists(left, right);
  }
  ListNode *mergeTwoLists(ListNode *left, ListNode *right) {
    ListNode *dummy = new ListNode(-1), *tmp = dummy;
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
    if (left)
      tmp->next = left;
    else if (right)
      tmp->next = right;
    return dummy->next;
  }
};

/// 堆排序
template <> class Solution<2> {
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

/// 手写堆排序
template <> class Solution<3> {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    int heapSize = 0;
    vector<ListNode *> heap(1);
    for (int i = 0; i < lists.size(); ++i) {
      if (lists[i]) {
        heap.push_back(lists[i]);
        heapSize++;
      }
    }
    buildMinHeap(heap, heapSize);
    ListNode *dummy = new ListNode(-1), *head = dummy;
    while (heapSize > 0) {
      ListNode *node = heap[1];
      head->next = node;
      head = head->next;
      if (node->next)
        heap[1] = node->next;
      else {
        swap(heap[1], heap[heapSize]);
        heapSize--;
      }
      minHeapify(heap, 1, heapSize);
    }
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