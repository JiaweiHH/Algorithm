#include <vector>

using namespace std;

// 给出 n 天的股票价格，最多可以进行两笔交易，求出能获得最大利润

// 动态规划，本题 j 最大等于 2
// dp[i][j][0] 表示第 i 天最多执行 j 笔交易，并且没有持有股票的最大利润
// dp[i][j][1] 表示第 i 天最多执行 j 笔交易，并且持有股票的最大利润
// 状态转移过程如下
// 对于第 i 天执行 k 笔交易来说，如果第 i 天不持有股票，
// 那么该状态可以在以下这两种状态中选择
// 1. 第 i - 1 天执行 k 笔交易不持有股票，此时第 i 天什么都不做
// 2. 第 i - 1 天执行 k 笔交易持有股票，此时第 i 天卖出股票
// 如果第 i 天要持有股票，那么该状态可以在以下两个状态选择
// 1. 第 i - 1 天执行了 k - 1 笔交易但是不持有股票，此时第 i 天就可以购入新的股票
// 2. 第 i - 1 天执行了 k 笔交易并且持有了股票，此时第 i 天什么都不做
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1,
                                   vector<vector<int>>(3, vector<int>(2)));
    dp[0][1][0] = dp[0][2][0] = 0;
    dp[0][1][1] = dp[0][2][1] = -prices[0];
    for (int i = 1; i < n; ++i) {
      for (int k = 1; k <= 2; ++k) {
        dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
        dp[i][k][1] = max(dp[i - 1][k - 1][0] - prices[i], dp[i - 1][k][1]);
      }
    }
    return dp[n - 1][2][0];
  }
};