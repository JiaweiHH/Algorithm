#include <vector>
using namespace std;

template <int> class Solution;

/// 二分
template <> class Solution<1> {
public:
  int findDuplicate(vector<int> &nums) {
    int l = 1, r = nums.size() - 1;
    while (l < r) {
      int mid = (l + r) / 2;
      int cnt = 0;
      for (int i = 0; i < nums.size(); ++i)
        cnt += nums[i] <= mid;
      if (cnt <= mid)
        l = mid + 1;
      else
        r = mid;
    }
    return l;
  }
};

/// 位运算
template <> class Solution<2> {
public:
  int findDuplicate(vector<int> &nums) {
    int n = nums.size() - 1;
    // 找到 n 中二进制位的最高位
    int bit_max = 0, tmp = n;
    while (tmp) {
      ++bit_max;
      tmp /= 2;
    }
    int res = 0;
    for (int i = 1; i <= bit_max; ++i) {
      int cnt_1 = 0, cnt_2 = 0;
      for (int k = 1; k <= n; ++k)
        cnt_1 += (k >> (i - 1)) & 1 != 0 ? 1 : 0;
      for (auto val : nums)
        cnt_2 += (val >> (i - 1)) & 1 != 0 ? 1 : 0;
      if (cnt_2 > cnt_1)
        res = res | (1 << i - 1);
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