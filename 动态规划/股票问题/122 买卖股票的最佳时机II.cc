#include <vector>
using namespace std;

template <int> class Solution;

/// 贪心
template <> class Solution<1> {
public:
  int maxProfit(vector<int> &prices) {
    int res = 0;
    for (int i = 1; i < prices.size(); ++i) {
      if (prices[i] > prices[i - 1])
        res += prices[i] - prices[i - 1];
    }
    return res;
  }
};

/// 动态规划
template <> class Solution<2> {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2));
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    for (int i = 1; i < n; ++i) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }
    return dp[n - 1][1];
  }
};