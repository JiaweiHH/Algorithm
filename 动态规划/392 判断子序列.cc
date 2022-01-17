#include <string>
#include <vector>
using namespace std;

template <int> class Solution;

/// 双指针
template <> class Solution<0> {
public:
  bool isSubsequence(string s, string t) {
    int n = s.length(), m = t.length();
    int i = 0, j = 0;
    while (i < n && j < m) {
      if (s[i] == t[j]) {
        i++;
      }
      j++;
    }
    return i == n;
  }
};

/// DP1
template <> class Solution<1> {
public:
  bool isSubsequence(string s, string t) {
    if (s == "")
      return true;
    if (t == "")
      return false;
    int m = s.size(), n = t.size();
    vector<vector<bool>> dp(m, vector<bool>(n));
    dp[0][0] = s[0] == t[0];
    for (int j = 1; j < n; ++j)
      dp[0][j] = dp[0][j - 1] | (s[0] == t[j]);
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (s[i] == t[j])
          dp[i][j] = dp[i - 1][j - 1];
        else
          dp[i][j] = dp[i][j - 1];
      }
    }
    return dp[m - 1][n - 1];
  }
};

/// DP2
template <> class Solution<2> {
public:
  bool isSubsequence(string s, string t) {
    if (s == "")
      return true;
    if (t == "")
      return false;
    int m = s.size(), n = t.size();
    vector<vector<int>> dp(m, vector<int>(n));
    dp[0][0] = s[0] == t[0] ? 1 : 0;
    for (int i = 1; i < m; ++i)
      dp[i][0] = s[i] == t[0] ? 1 : max(dp[i - 1][0], 0);
    for (int j = 1; j < n; ++j)
      dp[0][j] = s[0] == t[j] ? 1 : max(dp[0][j - 1], 0);
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (s[i] == t[j])
          dp[i][j] = dp[i - 1][j - 1] + 1;
        else
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
    return dp[m - 1][n - 1] == s.size();
  }
};