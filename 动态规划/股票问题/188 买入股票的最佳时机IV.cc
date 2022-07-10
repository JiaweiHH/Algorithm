#include <vector>

using namespace std;

/// @brief 动态规划
/// dp[i][k][0] 表示第 i 天最多执行 k 笔交易，并且持有股票的最大收益
/// dp[i][k][1] 表示第 i 天最多执行 k 笔交易，并且不持有股票的最大收益
/// 交易的笔数在买入股票的时候增加
class Solution {
public:
  int maxProfit(int k, vector<int> &prices) {
    int n = prices.size();
    if (n == 0)
      return 0;
    vector<vector<vector<int>>> dp(n,
                                   vector<vector<int>>(k + 1, vector<int>(2)));
    for (int i = 1; i <= k; ++i)
      dp[0][i][0] = -prices[0];
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j <= k; ++j) {
        dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j - 1][1] - prices[i]);
        dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j][0] + prices[i]);
      }
    }
    return dp[n - 1][k][1];
  }
};