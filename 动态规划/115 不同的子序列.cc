#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int numDistinct(string s, string t) {
    int m = s.size(), n = t.size();
    vector<vector<uint64_t>> dp(m, vector<uint64_t>(n));
    dp[0][0] = s[0] == t[0] ? 1 : 0;
    for (int i = 1; i < m; ++i)
      dp[i][0] = s[i] == t[0] ? 1 + dp[i - 1][0] : dp[i - 1][0];
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (s[i] == t[j])
          dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        else
          dp[i][j] = dp[i - 1][j];
      }
    }
    return dp[m - 1][n - 1];
  }
};