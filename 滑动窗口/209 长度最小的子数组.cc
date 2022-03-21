#include <vector>
using namespace std;

template <int> class Solution;

/// 滑动窗口
template <> class Solution<1> {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int l = 0, r = 0;
    int s = 0, len = INT_MAX, sum = 0;
    while (r != nums.size()) {
      sum += nums[r];
      while (sum >= target) {
        len = min(len, r - l + 1);
        sum -= nums[l];
        ++l;
      }
      ++r;
    }
    return len == INT_MAX ? 0 : len;
  }
};

/// 前缀和 + 二分查找
template <> class Solution<2> {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int n = nums.size();
    vector<int> vec(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += nums[i];
      vec[i] = sum;
    }
    int len = INT_MAX;
    for (int i = 0; i < n; ++i) {
      int val = vec[i] - nums[i] + target;
      int idx = binarySearch(vec, val);
      if (idx != n)
        len = min(len, idx - i + 1);
    }
    return len == INT_MAX ? 0 : len;
  }
  int binarySearch(const vector<int> &vec, int val) {
    int l = 0, r = vec.size() - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (vec[mid] >= val)
        r = mid - 1;
      else
        l = mid + 1;
    }
    return l;
  }
};