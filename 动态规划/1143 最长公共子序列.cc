#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m, vector<int>(n));
    dp[0][0] = text1[0] == text2[0] ? 1 : 0;
    for (int i = 1; i < m; ++i)
      dp[i][0] = text1[i] == text2[0] ? 1 : max(dp[i - 1][0], 0);
    for (int j = 1; j < n; ++j)
      dp[0][j] = text1[0] == text2[j] ? 1 : max(dp[0][j - 1], 0);
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (text1[i] == text2[j])
          dp[i][j] = dp[i - 1][j - 1] + 1;
        else
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
    return dp[m - 1][n - 1];
  }
};