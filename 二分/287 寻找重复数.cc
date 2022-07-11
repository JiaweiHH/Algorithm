#include <vector>
using namespace std;

template <int> class Solution;

/// @brief 二分查找
/// 如果重复数字为 x，则所有 n >= x 的数字来说，小于等于 n 的数字数量必定大于 n
/// 利用这个单调性来找到重复的数字
template <> class Solution<1> {
public:
  int check(vector<int> &nums, int target) {
    int cnt = 0;
    for (auto n : nums)
      cnt += n <= target ? 1 : 0;
    return cnt;
  }
  int findDuplicate(vector<int> &nums) {
    int l = 1, r = nums.size() - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (check(nums, mid) > mid)
        r = mid - 1;
      else
        l = mid + 1;
    }
    return l;
  }
};

/// 位运算
template <> class Solution<2> {
public:
  int findDuplicate(vector<int> &nums) {
    int bit_max = 0, n = nums.size() - 1;
    int tmp = n;
    while (tmp) {
      ++bit_max;
      tmp /= 2;
    }
    int res = 0;
    for (int i = 0; i < bit_max; ++i) {
      int cnt_1 = 0, cnt_2 = 0;
      for (int k = 1; k <= n; ++k)
        cnt_1 += (k & (1 << i)) > 0 ? 1 : 0;
      for (int k = 0; k < nums.size(); ++k)
        cnt_2 += (nums[k] & (1 << i)) > 0 ? 1 : 0;
      if (cnt_1 < cnt_2)
        res = res | (1 << i);
    }
    return res;
  }
};

/// 双指针（快慢指针）
template <> class Solution<3> {
public:
  int findDuplicate(vector<int> &nums) {
    int l = 0, r = nums[0];
    while (l != r) {
      l = nums[l];
      r = nums[nums[r]];
    }
    l = 0, r = nums[r];
    while (l != r) {
      l = nums[l];
      r = nums[r];
    }
    return l;
  }
};