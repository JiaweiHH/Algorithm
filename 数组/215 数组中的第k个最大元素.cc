#include <vector>
using namespace std;

template <int> class Solution;

template <> class Solution<1> {
public:
  int findKthLargest(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end(),
         [](const int &lhs, const int &rhs) { return lhs > rhs; });
    return nums[k - 1];
  }
};

/// 堆排序
template <> class Solution<2> {
public:
  int findKthLargest(vector<int> &nums, int k) {
    int heapSize = nums.size();
    buildMaxHeap(nums, heapSize);
    for (int i = nums.size() - 1; i >= nums.size() - k + 1; --i) {
      swap(nums[0], nums[heapSize - 1]);
      heapSize--;
      maxHeapify(nums, 0, heapSize);
    }
    return nums[0];
  }
  void buildMaxHeap(vector<int> &heap, int heapSize) {
    for (int i = heapSize / 2; i >= 0; --i)
      maxHeapify(heap, i, heapSize); // 从下到上调整堆
  }
  void maxHeapify(vector<int> &heap, int index, int heapSize) {
    int left = 2 * index + 1, right = 2 * index + 2;
    int target = index;
    if (left < heapSize && heap[left] > heap[target])
      target = left;
    if (right < heapSize && heap[right] > heap[target])
      target = right;
    if (target != index) {
      swap(heap[index], heap[target]);
      maxHeapify(heap, target, heapSize);
    }
  }
};

/// 快速选择
template <> class Solution<2> {
public:
  int findKthLargest(vector<int> &nums, int k) {
    return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
  }
  int quickSelect(vector<int> &nums, int l, int r, int k) {
    int q = randomPartition(nums, l, r);
    if (q == k)
      return nums[q];
    return q < k ? quickSelect(nums, q + 1, r, k)
                 : quickSelect(nums, l, q - 1, k);
  }
  int randomPartition(vector<int> &nums, int l, int r) {
    int idx = rand() % (r - l + 1) + l;
    swap(nums[idx], nums[r]);
    return partition(nums, l, r);
  }
  int partition(vector<int> &nums, int l, int r) {
    int x = nums[r], k = l;
    for (int i = l; i < r; ++i) {
      if (nums[i] < x)
        swap(nums[k++], nums[i]);
    }
    swap(nums[k], nums[r]);
    return k;
  }
};