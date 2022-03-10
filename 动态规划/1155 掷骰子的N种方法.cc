#include <vector>
using namespace std;

template <int> class Solution;

/// 动态规划
template <> class Solution<1> {
public:
  int numRollsToTarget(int n, int k, int target) {
    int MOD = 1e9 + 7;
    vector<vector<int>> dp(n + 1, vector<int>(target + 1));
    for (int i = 1; i <= min(k, target); ++i)
      dp[1][i] = 1;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= target; ++j) {
        for (int t = 1; t <= k && j - t > 0; ++t) {
          dp[i][j] += dp[i - 1][j - t];
          dp[i][j] %= MOD;
        }
      }
    }
    return dp[n][target];
  }
};

/// 回溯，会超时
template <> class Solution<2> {
public:
  int res = 0;
  int MOD = 1e9 + 7;
  int numRollsToTarget(int n, int k, int target) {
    int cur = 0;
    dfs(n, k, target, 0, cur);
    return res;
  }
  void dfs(int n, int k, int target, int index, int &cur) {
    if (index == n) {
      if (cur == target) {
        res++;
        res %= MOD;
      }
      return;
    }
    for (int i = 1; i <= k; ++i) {
      if (cur + i > target)
        break;
      cur += i;
      dfs(n, k, target, index + 1, cur);
      cur -= i;
    }
  }
};