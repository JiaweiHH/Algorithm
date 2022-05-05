#include <vector>
using namespace std;

template <int> class Solution;

/// 二分
template <> class Solution<1> {
public:
  int count(vector<int> &nums, int target) {
    int cnt = 0;
    for (auto &v : nums)
      cnt += v <= target ? 1 : 0;
    return cnt;
  }
  int findDuplicate(vector<int> &nums) {
    int n = nums.size() - 1;
    int l = 1, r = n;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (count(nums, mid) > mid)
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