#include <vector>

using namespace std;

// 可以进行任意次数的买卖，但是每一次卖出股票之后第二天不能买入新的股票

// 大体的动态规划思路相同，多了一个状态用来确定是不是冷冻期
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    // dp[i][0] 表示第 i 天持有股票的最大利润
    // dp[i][1] 表示第 i 天不持有股票且不在冷冻期的最大利润
    // dp[i][2] 表示第 i 天不持有股票且在冷冻期的最大利润
    vector<vector<int>> dp(n, vector<int>(3));
    dp[0][0] = -prices[0], dp[0][1] = dp[0][2] = 0;
    for (int i = 1; i < n; ++i) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][2]);
      dp[i][2] = dp[i - 1][0] + prices[i];
    }
    return max(dp[n - 1][1], dp[n - 1][2]);
  }
};