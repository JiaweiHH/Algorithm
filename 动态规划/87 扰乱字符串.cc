#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  bool isScramble(string s1, string s2) {
    if (s1.size() != s2.size())
      return false;
    int n = s1.size();
    vector<vector<vector<bool>>> dp(
        n, vector<vector<bool>>(n, vector<bool>(n + 1)));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j)
        dp[i][j][1] = s1[i] == s2[j];
    }
    for (int len = 2; len <= n; ++len) {
      for (int i = 0; i <= n - len; ++i) {
        for (int j = 0; j <= n - len; ++j) {
          for (int k = 1; k <= len - 1; ++k) {
            if (dp[i][j][k] && dp[i + k][j + k][len - k]) {
              dp[i][j][len] = true;
              break;
            }
            if (dp[i][j + k][len - k] && dp[i + len - k][j][k]) {
              dp[i][j][len] = true;
              break;
            }
          }
        }
      }
    }
    return dp[0][0][n];
  }
};