#include <vector>
using namespace std;

/**
 * @brief 无序数组中查找中位数，也是一样的做法
 * 
 * @tparam nt 
 */

template <int> class Solution;

/// @brief 快排
template <> class Solution<1> {
public:
  int findKthLargest(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end(),
         [](const int &lhs, const int &rhs) { return lhs > rhs; });
    return nums[k - 1];
  }
};

/// @brief 堆排序
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

/// @brief quick select
template <> class Solution<2> {
public:
  int partition(vector<int> &nums, int l, int r, int pivot) {
    swap(nums[pivot], nums[r]);
    int ptr = l;
    for (int i = l; i <= r; ++i) {
      if (nums[i] > nums[r])
        swap(nums[i], nums[ptr++]);
    }
    swap(nums[ptr], nums[r]);
    return ptr;
  }
  int quick_select(vector<int> &nums, int l, int r, int k) {
    int pivot = rand() % (r - l + 1) + l;
    int x = partition(nums, l, r, pivot);
    if (x == k - 1)
      return nums[x];
    return x < k - 1 ? quick_select(nums, x + 1, r, k)
                     : quick_select(nums, l, x - 1, k);
  }
  int findKthLargest(vector<int> &nums, int k) {
    return quick_select(nums, 0, nums.size() - 1, k);
  }
};