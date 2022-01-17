#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m, vector<int>(n));
    dp[0][0] = word1[0] == word2[0] ? 1 : 0;
    for (int i = 1; i < m; ++i)
      dp[i][0] = word1[i] == word2[0] ? 1 : max(dp[i - 1][0], 0);
    for (int j = 1; j < n; ++j)
      dp[0][j] = word1[0] == word2[j] ? 1 : max(dp[0][j - 1], 0);
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (word1[i] == word2[j])
          dp[i][j] = dp[i - 1][j - 1] + 1;
        else
          dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
      }
    }
    return (m - dp[m - 1][n - 1]) + (n - dp[m - 1][n - 1]);
  }
};