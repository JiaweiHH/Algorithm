#include <vector>

using namespace std;

// 对比 123 题区别在于，现在最多可以进行的交易笔数不是 2 而是 k

// 动态规划，总体思路和 123 题差不多
class Solution {
public:
  int maxProfit(int k, vector<int> &prices) {
    int n = prices.size();
    if (n == 0)
      return 0;
    vector<vector<vector<int>>> dp(n + 1,
                                   vector<vector<int>>(k + 1, vector<int>(2)));
    for (int i = 1; i <= k; ++i) {
      dp[0][i][0] = 0;
      dp[0][i][1] = -prices[0];
    }
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j <= k; ++j) {
        dp[i][j][0] = max(dp[i - 1][j][1] + prices[i], dp[i - 1][j][0]);
        dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
      }
    }
    return dp[n - 1][k][0];
  }
};