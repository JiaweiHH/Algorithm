#include <unordered_map>
#include <vector>
using namespace std;

template <int> class Solution;

/// 二分 + 滑动窗口
template <> class Solution<1> {
public:
  int count(vector<int> &nums, int target) {
    int l = 0, r = 1;
    int res = 0;
    while (r != nums.size()) {
      while (nums[r] - nums[l] > target)
        ++l;
      res += r - l;
      ++r;
    }
    return res;
  }
  int smallestDistancePair(vector<int> &nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int l = 0, r = nums[n - 1] - nums[0];
    while (l <= r) {
      int mid = (l + r) / 2;
      if (count(nums, mid) >= k)
        r = mid - 1;
      else
        l = mid + 1;
    }
    return l;
  }
};

/// 二分 + 前缀和
template <> class Solution<2> {
public:
  int count(vector<int> &nums, int target, unordered_map<int, int> &repeat,
            vector<int> &prefix) {
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int tmp =
          prefix[nums[i] + target] - prefix[nums[i]] + repeat[nums[i]] - i;
      res += tmp;
    }
    return res;
  }
  int smallestDistancePair(vector<int> &nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    // 记录每个元素值出现的开始位置和结束为止
    unordered_map<int, int> repeat;
    int start = 0;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] != nums[i - 1])
        repeat[nums[i - 1]] = i - 1;
    }
    repeat[nums[n - 1]] = n - 1;
    // 记录对于给定的值 v，nums 中小于等于 v 的元素有多少个
    int max_value = nums[n - 1];
    vector<int> prefix(2 * max_value + 1);
    int idx = 0;
    for (int i = nums[0]; i <= 2 * max_value; ++i) {
      while (idx < n && nums[idx] == i)
        ++idx;
      prefix[i] = idx;
    }

    int l = 0, r = nums[n - 1] - nums[0];
    while (l <= r) {
      int mid = (l + r) / 2;
      if (count(nums, mid, repeat, prefix) >= k)
        r = mid - 1;
      else
        l = mid + 1;
    }
    return l;
  }
};