#include <vector>
using namespace std;

template <int> class Solution;

/// 滑动窗口
template <> class Solution<1> {
public:
  int longestOnes(vector<int> &nums, int k) {
    int l = 0, r = 0;
    int zero_num = 0, one_num = 0, res = 0;
    while (r != nums.size()) {
      if (nums[r] == 0)
        ++zero_num;
      else
        ++one_num;
      while (zero_num > k) {
        res = max(res, r - l);
        if (nums[l++] == 1)
          --one_num;
        else
          --zero_num;
      }
      ++r;
    }
    res = max(res, r - l);
    return res;
  }
};

/// 前缀和 + 二分查找
template <> class Solution<2> {
public:
  int longestOnes(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> vec(n + 1);
    for (int i = 1; i <= n; ++i)
      vec[i] = nums[i - 1] == 0 ? vec[i - 1] + 1 : vec[i - 1];
    int res = 0;
    for (int i = 1; i <= n; ++i) {
      if (vec[i] - k <= 0)
        res = max(res, i);
      else {
        auto it = lower_bound(vec.begin(), vec.begin() + i, vec[i] - k);
        int idx = it - vec.begin();
        res = max(res, i - idx);
      }
    }
    return res;
  }
};