#include <vector>
using namespace std;

template <int> class Solution;

/// 动态规划
template <> class Solution<1> {
public:
  int splitArray(vector<int> &nums, int m) {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
    // 初始化前 i 个元素分割成 1 段的值
    dp[0][1] = 0;
    for (int i = 1; i <= n; ++i)
      dp[i][1] = dp[i - 1][1] + nums[i - 1];
    // 初始化前缀和，节省时间
    vector<int> prefix(n + 1);
    for (int i = 1; i <= n; ++i)
      prefix[i] = prefix[i - 1] + nums[i - 1];
    for (int i = 1; i <= n; ++i) {
      for (int j = 2; j <= min(i, m); ++j) {
        for (int k = j - 1; k < i; ++k) {
          int tmp = max(dp[k][j - 1], prefix[i] - prefix[k]);
          dp[i][j] = min(dp[i][j], tmp);
        }
      }
    }
    return dp[n][m];
  }
};

/// 二分 + 贪心
template <> class Solution<2> {
public:
  int splitArray(vector<int> &nums, int m) {
    int l = 0, r = 0;
    for (auto &val : nums) {
      l = max(l, val);
      r += val;
    }
    auto count = [&](int target) {
      int cnt = 0, sum = 0;
      for (int i = 0; i < nums.size(); ++i) {
        if (sum + nums[i] > target) {
          ++cnt;
          sum = nums[i];
        } else {
          sum += nums[i];
        }
      }
      return cnt + 1;
    };
    while (l <= r) {
      int mid = (l + r) / 2;
      if (count(mid) <= m)
        r = mid - 1;
      else
        l = mid + 1;
    }
    return l;
  }
};