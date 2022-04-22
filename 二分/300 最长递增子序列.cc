#include <vector>
using namespace std;

template <int> class Solution;

/// DP
template <> class Solution<1> {
public:
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[j] < nums[i])
          dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    return dp[n - 1];
  }
};

/// 二分
template <> class Solution<2> {
public:
  int binary_search(vector<int> &index, int l, int r, int target) {
    while (l <= r) {
      int mid = (l + r) / 2;
      if (index[mid] >= target)
        r = mid - 1;
      else
        l = mid + 1;
    }
    return l;
  }
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    // 记录每个长度为 i 的子序列的最后一个元素
    vector<int> index(n + 1, INT_MIN);
    int len = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > index[len])
        index[++len] = nums[i];
      else {
        int idx = binary_search(index, 1, len, nums[i]);
        index[idx] = nums[i];
      }
    }
    return len;
  }
};