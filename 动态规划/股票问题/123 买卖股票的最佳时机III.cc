#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2)));
    dp[0][1][0] = dp[0][2][0] = -prices[0];
    for (int i = 1; i < n; ++i) {
      for (int k = 1; k <= 2; ++k) {
        dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k - 1][1] - prices[i]);
        dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k][0] + prices[i]);
      }
    }
    return dp[n - 1][2][1];
  }
};