#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
    dp[0][0] = true;
    // 判断 s[i - 1] 和 p[j - 1] 是否匹配
    auto match = [&](int i, int j) -> bool {
      if (i == 0)
        return false;
      return s[i - 1] == p[j - 1] || p[j - 1] == '.';
    };
    for (int i = 0; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (p[j - 1] == '*') {
          // 跳过 * 规则的匹配
          dp[i][j] = dp[i][j - 2];
          // 尝试 * 规则的匹配
          if (match(i, j - 1))
            dp[i][j] = dp[i][j] | dp[i - 1][j];
        } else {
          if (match(i, j))
            dp[i][j] = dp[i - 1][j - 1];
        }
      }
    }
    return dp[m][n];
  }
};