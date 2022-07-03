#include <queue>
#include <vector>
using namespace std;

template <int> class Solution;

/// @brief 大根堆 + 小根堆
/// 该方法本质上类似快排，然后双指针往中间走
template <> class Solution<1> {
public:
  void add_num(int num, priority_queue<int, vector<int>, less<int>> &max_heap,
               priority_queue<int, vector<int>, greater<int>> &min_heap) {
    if (min_heap.empty() && max_heap.empty()) {
      max_heap.push(num);
      return;
    }
    int val = num;
    // num 小于 max_heap 的堆顶元素，则放到 max_heap 并获取堆顶元素
    // num 大于 min_heap 的堆顶元素，则放到 min_heap 并获取堆顶元素
    if (num < max_heap.top()) {
      max_heap.push(num);
      val = max_heap.top();
      max_heap.pop();
    } else if (!min_heap.empty() && num > min_heap.top()) {
      min_heap.push(num);
      val = min_heap.top();
      min_heap.pop();
    }
    // 如果两个堆的元素数量不平衡，则放到 min_heap
    // 否则放到 max_heap
    if (min_heap.size() < max_heap.size())
      min_heap.push(val);
    else
      max_heap.push(val);
  }
  void wiggleSort(vector<int> &nums) {
    // 存放较小的一半数字
    priority_queue<int, vector<int>, less<int>> max_heap;
    // 存放较大的一半数字
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for (int i = 0; i < nums.size(); ++i) {
      add_num(nums[i], max_heap, min_heap);
    }
    int ptr = nums.size() - 1;
    if (max_heap.size() != min_heap.size()) {
      nums[ptr--] = max_heap.top();
      max_heap.pop();
    }
    while (ptr >= 0) {
      nums[ptr--] = min_heap.top();
      min_heap.pop();
      nums[ptr--] = max_heap.top();
      max_heap.pop();
    }
  }
};

/// @brief 排序，然后交换相邻的元素
template <> class Solution<2> {
public:
  void wiggleSort(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size() - 1; i += 2)
      swap(nums[i], nums[i + 1]);
  }
};

/// @brief 一边遍历
/// i 是奇数，且 nums[i] < nums[i + 1]，则交换 nums[i] 和 nums[i + 1]
/// i 是偶数，且 nums[i] > nums[i + 1]，则交换 nums[i] 和 nums[i + 1]
template <> class Solution<2> {
public:
  void wiggleSort(vector<int> &nums) {
    for (int i = 0; i < nums.size() - 1; ++i) {
      if (i % 2 == 0 && nums[i] > nums[i + 1])
        swap(nums[i], nums[i + 1]);
      else if (i % 2 && nums[i] < nums[i + 1])
        swap(nums[i], nums[i + 1]);
    }
  }
};