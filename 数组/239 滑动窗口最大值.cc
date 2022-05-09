#include <deque>
#include <queue>
#include <vector>
using namespace std;

template <int> class Solution;

/// 堆（优先队列）
template <> class Solution<1> {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    auto cmp = [](pair<int, int> &lhs, pair<int, int> &rhs) {
      return lhs.first < rhs.first;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> heap(
        cmp);
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {
      heap.push({nums[i], i});
      while (heap.top().second <= i - k) {
        heap.pop();
      }
      if (i >= k - 1)
        res.push_back(heap.top().first);
    }
    return res;
  }
};

/// 堆（手写）
template <> class Solution<2> {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    vector<pair<int, int>> heap;
    for (int i = 0; i < k; ++i)
      heap.push_back({nums[i], i});
    buildHeap(heap, k); // 构建大顶堆
    vector<int> res;
    int heap_size = k;
    for (int i = k; i < nums.size(); ++i) {
      res.push_back(heap[0].first);
      while (heap_size > 0 && heap[0].second <= i - k) {
        swap(heap[0], heap[heap_size - 1]);
        heap_size--;
        heap.pop_back();
        maxHeapify(heap, 0, heap_size);
      }
      heap.push_back({nums[i], i});
      heap_size++;
      insertHeapify(heap, heap_size);
    }
    res.push_back(heap[0].first);
    return res;
  }
  void insertHeapify(vector<pair<int, int>> &heap, int heap_size) {
    int idx = heap_size - 1;
    while (idx) {
      if (idx % 2 == 0) {
        idx = (idx - 2) / 2;
        maxHeapify(heap, idx, heap_size);
      } else {
        idx = (idx - 1) / 2;
        maxHeapify(heap, idx, heap_size);
      }
    }
  }
  void buildHeap(vector<pair<int, int>> &heap, int heap_size) {
    // 向下调整堆
    for (int i = heap_size / 2; i >= 0; --i)
      maxHeapify(heap, i, heap_size);
  }
  void maxHeapify(vector<pair<int, int>> &heap, int index, int heap_size) {
    int l = index * 2 + 1, r = index * 2 + 2, target = index;
    if (l < heap_size && heap[l].first > heap[target].first)
      target = l;
    if (r < heap_size && heap[r].first > heap[target].first)
      target = r;
    if (target != index) {
      // 递归向下调整堆
      swap(heap[index], heap[target]);
      maxHeapify(heap, target, heap_size);
    }
  }
};

/// 单调队列（使用双端队列实现）
template <> class Solution<3> {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    deque<int> que;
    for (int i = 0; i < k; ++i) {
      while (!que.empty() && nums[i] >= nums[que.back()])
        que.pop_back();
      que.push_back(i);
    }
    vector<int> res;
    for (int i = k; i < nums.size(); ++i) {
      res.push_back(nums[que.front()]);
      while (!que.empty() && nums[i] >= nums[que.back()])
        que.pop_back();
      while (!que.empty() && que.front() <= i - k)
        que.pop_front();
      que.push_back(i);
    }
    res.push_back(nums[que.front()]);
    return res;
  }
};