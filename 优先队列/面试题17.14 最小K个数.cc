#include <queue>
#include <vector>
using namespace std;

template <int> class Solution;

/// 快速选择
template <> class Solution<1> {
public:
  int partition(vector<int> &arr, int l, int r) {
    int x = arr[r], p = l;
    for (int i = l; i < r; ++i) {
      if (arr[i] < x)
        swap(arr[p++], arr[i]);
    }
    swap(arr[p], arr[r]);
    return p;
  }
  vector<int> quick_select(vector<int> &arr, int l, int r, int k) {
    if (l > r)
      return {};
    int pivot = rand() % (r - l + 1) + l;
    swap(arr[pivot], arr[r]);
    int idx = partition(arr, l, r);
    if (idx == k)
      return vector<int>(arr.begin(), arr.begin() + k);
    return idx > k ? quick_select(arr, l, idx - 1, k)
                   : quick_select(arr, idx + 1, r, k);
  }
  vector<int> smallestK(vector<int> &arr, int k) {
    return quick_select(arr, 0, arr.size() - 1, k);
  }
};

/// 堆
template <> class Solution<2> {
public:
  vector<int> smallestK(vector<int> &arr, int k) {
    priority_queue<int, vector<int>, less<int>> heap;
    for (int i = 0; i < arr.size(); ++i) {
      heap.push(arr[i]);
      if (heap.size() == k + 1)
        heap.pop();
    }
    vector<int> res;
    while (!heap.empty()) {
      res.push_back(heap.top());
      heap.pop();
    }
    return res;
  }
};