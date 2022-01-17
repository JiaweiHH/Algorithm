#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    // dp[i][0] 表示持有股票，dp[i][1] 表示不持有股票且在冷冻期，dp[i][2] 表示不持有股票且不在冷冻期
    vector<vector<int>> dp(n, vector<int>(3));
    dp[0][0] = -prices[0];
    for (int i = 1; i < n; ++i) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
      dp[i][1] = dp[i - 1][2];
      dp[i][2] =
          max(dp[i - 1][2],
              dp[i - 1][0] + prices[i]); // 在这一天卖出，这一天还不算冷冻期
    }
    return max(dp[n - 1][1], dp[n - 1][2]);
  }
};