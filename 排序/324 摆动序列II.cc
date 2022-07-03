#include <vector>
#include <random>
using namespace std;

template <int> class Solution;

/// @brief 排序，然后双指针
/// 由于要求按照严格顺序摆动排列，因此不能简单的使用头尾元素匹配
/// 转换成从中间元素开始和尾元素匹配，左指针从中间往 0 走，右指针从数组尾部往中间走
template <> class Solution<1> {
public:
  // O(nlogn), O(n)
  void wiggleSort(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    // 如果是奇数 l = nums.size() / 2，否则 l = nums.size() / 2 - 1
    // 或者 l = (n + 1) / 2 - 1，同样的意思
    int l = n % 2 == 1 ? nums.size() / 2 : nums.size() / 2 - 1,
        r = nums.size() - 1;
    vector<int> tmp(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
      if (i % 2 == 0)
        tmp[i] = nums[l--];
      else
        tmp[i] = nums[r--];
    }
    nums = tmp;
  }
};

/// @brief quick select + 荷兰国旗 ---------- 三项切分
/// 思路差不多，通过 quick select 找出数组中第 x = (n + 1) / 2 - 1 个元素
/// 然后按照 nums[x] 将数组分为三段 {< nums[x], = nums[x], > nums[x]}
/// 最后 l 指针从 x -> 0，r 指针从 n - 1 -> x + 1，组装新的数组
template <> class Solution<2> {
public:
  int partition(vector<int> &nums, int l, int r, int pivot) {
    swap(nums[pivot], nums[r]);
    int p = l;
    for (int i = l; i <= r; ++i) {
      if (nums[i] < nums[r])
        swap(nums[i], nums[p++]);
    }
    swap(nums[p], nums[r]);
    return p;
  }
  int quick_select(vector<int> &nums, int l, int r, int k) {
    int pivot = rand() % (r - l + 1) + l;
    int x = partition(nums, l, r, pivot);
    if (x == k)
      return x;
    return x < k ? quick_select(nums, x + 1, r, k)
                 : quick_select(nums, l, x - 1, k);
  }
  // O(n), O(n)
  void wiggleSort(vector<int> &nums) {
    int n = nums.size();
    int x = quick_select(nums, 0, n - 1, (n + 1) / 2 - 1);
    // 将数组分割为 {< nums[x], = nums[x], > nums[x]}
    int pA = 0, pB = n - 1;
    for (int i = 0; i <= pB; ++i) {
      while (pB >= i && nums[i] > nums[x])
        swap(nums[i], nums[pB--]);
      if (nums[i] < nums[x])
        swap(nums[i], nums[pA++]);
    }
    vector<int> tmp(n);
    pA = x, pB = n - 1;
    for (int i = 0; i < n; i += 2) {
      tmp[i] = nums[pA--];
      if (i + 1 < n)
        tmp[i + 1] = nums[pB--];
    }
    nums = tmp;
  }
};

/// @brief 基于 quick select 优化，直接在 nums 上原地交换元素
template <> class Solution<3> {
public:
  int partition(vector<int> &nums, int l, int r, int pivot) {
    swap(nums[pivot], nums[r]);
    int p = l;
    for (int i = l; i <= r; ++i) {
      if (nums[i] < nums[r])
        swap(nums[i], nums[p++]);
    }
    swap(nums[p], nums[r]);
    return p;
  }
  int quick_select(vector<int> &nums, int l, int r, int k) {
    int pivot = rand() % (r - l + 1) + l;
    int x = partition(nums, l, r, pivot);
    if (x == k)
      return nums[x];
    return x < k ? quick_select(nums, x + 1, r, k)
                 : quick_select(nums, l, x - 1, k);
  }
  // quick select 之后元素 i 在最终元素的位置，满足关系 (2 * n - 2 * i - 1) % (n | 1)
  int transAddr(int i, int n) { return (2 * n - 2 * i - 1) % (n | 1); }
  // O(n), O(logn)
  void wiggleSort(vector<int> &nums) {
    int n = nums.size();
    // int x = (n + 1) / 2 - 1; // 这里也可以使用 C++ 提供的算法
    // nth_element(nums.begin(), nums.begin() + x, nums.end());
    int target = quick_select(nums, 0, n - 1, (n + 1) / 2 - 1);
    // 直接对转换后的数组进行 partition
    int pA = 0, pB = n - 1;
    for (int i = 0; i <= pB; ++i) {
      while (pB > i && nums[transAddr(i, n)] > target)
        swap(nums[transAddr(i, n)], nums[transAddr(pB--, n)]);
      if (nums[transAddr(i, n)] < target)
        swap(nums[transAddr(i, n)], nums[transAddr(pA++, n)]);
    }
  }
};

/// @brief 进一步优化空间复杂度，使用非递归的 quick select
/// 空间复杂度 O(logn) -> O(1)
template <> class Solution<4> {
public:
  int partition(vector<int> &nums, int l, int r, int pivot) {
    swap(nums[pivot], nums[r]);
    int p = l;
    for (int i = l; i <= r; ++i) {
      if (nums[i] < nums[r])
        swap(nums[i], nums[p++]);
    }
    swap(nums[p], nums[r]);
    return p;
  }
  // 非递归的快速选择
  int quick_select(vector<int> &nums, int k) {
    int l = 0, r = nums.size() - 1;
    default_random_engine gen((random_device())());
    while (l <= r) {
      uniform_int_distribution<int> dis(l, r);
      int pivot = dis(gen);
      int x = partition(nums, l, r, pivot);
      if (x == k)
        return nums[x];
      else if (x > k)
        r = x - 1;
      else
        l = x + 1;
    }
    return -1;
  }
  int transAddr(int i, int n) { return (2 * n - 2 * i - 1) % (n | 1); }
  void wiggleSort(vector<int> &nums) {
    int n = nums.size();
    int target = quick_select(nums, (n + 1) / 2 - 1);
    // 直接对转换后的数组进行 partition
    int pA = 0, pB = n - 1;
    for (int i = 0; i <= pB; ++i) {
      while (pB > i && nums[transAddr(i, n)] > target)
        swap(nums[transAddr(i, n)], nums[transAddr(pB--, n)]);
      if (nums[transAddr(i, n)] < target)
        swap(nums[transAddr(i, n)], nums[transAddr(pA++, n)]);
    }
  }
};