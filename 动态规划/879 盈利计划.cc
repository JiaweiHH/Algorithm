#include <vector>
using namespace std;

class Solution {
public:
  int profitableSchemes(int n, int minProfit, vector<int> &group,
                        vector<int> &profit) {
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1));
    for (int i = 0; i <= n; ++i)
      dp[i][0] = 1;
    for (int i = 0; i < group.size(); ++i) {
      for (int j = n; j >= group[i]; --j) {
        // 因为可以 profit 超标，因此 k 没有必要将下限设置为 profit[i]
        for (int k = minProfit; k >= 0; --k) {
          dp[j][k] = (dp[j][k] + dp[j - group[i]][max(0, k - profit[i])]) % MOD;
        }
      }
    }
    return dp[n][minProfit];
  }
};