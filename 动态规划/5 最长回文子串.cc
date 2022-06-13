#include <string>
#include <vector>
using namespace std;

template <int> class Solution;

/// 动态规划
template <> class Solution<1> {
public:
  string longestPalindrome(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(n + 1));
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= i; ++j)
        dp[i][j] = true;
    }
    int len = 1, left = 0;
    for (int i = n; i >= 1; --i) {
      for (int j = i + 1; j <= n; ++j) {
        if (s[i - 1] == s[j - 1]) {
          dp[i][j] = dp[i + 1][j - 1];
          if (dp[i][j] && (j - i + 1) > len) {
            len = j - i + 1;
            left = i - 1;
          }
        }
      }
    }
    return s.substr(left, len);
  }
};

/// 中心扩展
template <> class Solution<2> {
public:
  pair<int, int> centralExpand(int l, int r, string &s) {
    while (l >= 0 && r < s.size() && s[l] == s[r]) {
      --l;
      ++r;
    }
    return {l + 1, r - 1};
  }
  string longestPalindrome(string s) {
    int l = 0, len = 1;
    for (int i = 0; i < s.size(); ++i) {
      auto [l1, r1] = centralExpand(i, i, s);
      auto [l2, r2] = centralExpand(i, i + 1, s);
      if (r1 - l1 + 1 > len) {
        l = l1;
        len = r1 - l1 + 1;
      }
      if (r2 - l2 + 1 > len) {
        l = l2;
        len = r2 - l2 + 1;
      }
    }
    return s.substr(l, len);
  }
};