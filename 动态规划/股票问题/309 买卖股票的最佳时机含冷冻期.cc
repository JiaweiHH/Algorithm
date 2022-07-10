#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    // dp[i][0] 表示第 i 天持有股票
    // dp[i][1] 表示第 i 天不持有股票且不在冷冻期
    // dp[i][2] 表示第 i 天不持有股票且处于冷冻期
    vector<vector<int>> dp(n, vector<int>(3));
    dp[0][0] = -prices[0];
    for (int i = 1; i < n; ++i) {
      // i - 1 天处于冷冻期，则第 i 天就不处于冷冻期，可以购买股票
      dp[i][0] = max({dp[i - 1][0], dp[i - 1][2] - prices[i]});
      // 这里可以优化，因为 dp[i - 1][2] <= dp[i - 1][1]
      dp[i][1] = max({dp[i - 1][1], dp[i - 1][2], dp[i - 1][0] + prices[i]});
      // 第 i 天要处于冷冻期，则只能从 i-1 天不持有股票转移而来
      dp[i][2] = dp[i - 1][1];
    }
    return dp[n - 1][1];
  }
};