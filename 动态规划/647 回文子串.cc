#include <string>
#include <vector>
using namespace std;

template <int> class Solution;

template <> class Solution<1> {
public:
  int countSubstrings(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(n + 1));
    for (int i = 0; i < n; ++i) {
      dp[i][i] = true;
      for (int j = 0; j < i; ++j)
        dp[i][j] = true;
    }
    for (int i = n - 1; i >= 0; --i) {
      for (int j = i + 1; j < n; ++j) {
        if (s[i] == s[j])
          dp[i][j] = dp[i + 1][j - 1];
      }
    }
    int res = 0;
    for (int i = 0; i < n; ++i)
      for (int j = i; j < n; ++j)
        res += dp[i][j] == true ? 1 : 0;
    return res;
  }
};

template <> class Solution<2> {
public:
  int countSubstrings(string s) {
    int result = 0;
    for (int i = 0; i < s.size(); i++) {
      result += extend(s, i, i, s.size());     // 以i为中心
      result += extend(s, i, i + 1, s.size()); // 以i和i+1为中心
    }
    return result;
  }
  int extend(const string &s, int i, int j, int n) {
    int res = 0;
    while (i >= 0 && j < n && s[i] == s[j]) {
      i--;
      j++;
      res++;
    }
    return res;
  }
};