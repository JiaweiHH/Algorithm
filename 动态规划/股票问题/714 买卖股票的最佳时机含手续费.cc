#include <vector>

using namespace std;

// 同样是可以进行任意次数的交易，但是每一笔交易需要支付手续费

// 只需要在状态转移方程中售出股票的时候计算一下手续费就好了
class Solution {
public:
  int maxProfit(vector<int> &prices, int fee) {
    int n = prices.size();
    // dp[i][0] 表示第 i 天不持有股票的最大利润
    // dp[i][1] 表示第 i 天持有股票的最大利润
    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[0][1] = -prices[0];
    for (int i = 1; i < n; ++i) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
      dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][1]);
    }
    return dp[n - 1][0];
  }
};