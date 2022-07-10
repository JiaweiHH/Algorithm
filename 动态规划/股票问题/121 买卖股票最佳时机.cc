#include <vector>
using namespace std;

template <int> class Solution;

/// @brief 贪心
template <> class Solution<1> {
public:
  int maxProfit(vector<int> &prices) {
    // mi 表示第 i 个元素之前的最小值
    int res = 0, mi = prices[0];
    for (int i = 1; i < prices.size(); ++i) {
      res = max(res, prices[i] - mi);
      mi = min(mi, prices[i]);
    }
    return res;
  }
};

/// @brief 动态规划
template <> class Solution<2> {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    // dp[i][0] 表示第 i 天持有股票的最大利润，dp[i][1] 表示不持有的最大利润
    vector<vector<int>> dp(n, vector<int>(2));
    dp[0][0] = -prices[0];
    for (int i = 1; i < prices.size(); ++i) {
      // 多次买入卖出的时候是 dp[i - 1][1] - prices[i]
      dp[i][0] = max(dp[i - 1][0], -prices[i]);
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }
    return dp[n - 1][1];
  }
};