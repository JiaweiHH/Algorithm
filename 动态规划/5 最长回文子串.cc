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
  string longestPalindrome(string s) {
    int start = 0, end = 0;
    for (int i = 0; i < s.size(); ++i) {
      auto [left1, right1] = centralExtend(s, i, i);
      auto [left2, right2] = centralExtend(s, i, i + 1);
      if (right1 - left1 > end - start) {
        start = left1;
        end = right1;
      }
      if (right2 - left2 > end - start) {
        start = left2;
        end = right2;
      }
    }
    return s.substr(start, end - start + 1);
  }
  pair<int, int> centralExtend(const string &s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
      left--;
      right++;
    }
    return {left + 1, right - 1};
  }
};