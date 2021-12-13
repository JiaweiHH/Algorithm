#include <vector>
#include <string>
using namespace std;

template <int>
class Solution {};

/// @brief 给你一个回文串，将 s 分割成一些字串，使得每个字串都是回文串。返回 s 所有可能的分割方案

/// @brief 动态规划计算出 i 到 j 的字符串是不是回文串，然后回溯找出所有的回文串
/// @note 时间复杂度：O(n * 2^n)，空间复杂度：O(n^2)
template <> class Solution<1> {
public:
  vector<vector<string>> res;
  int len;
  vector<vector<string>> partition(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, true));
    for (int i = 0; i < n; ++i)
      dp[i][i] = true;
    for (int i = n - 1; i >= 0; --i) {
      for (int j = i + 1; j < n; ++j) {
        dp[i][j] = s[i] == s[j] ? dp[i + 1][j - 1] : false;
      }
    }
    vector<string> cur;
    getPalindromes(0, dp, cur, s, n);
    return res;
  }
  void getPalindromes(int start, const vector<vector<bool>> &judge,
                      vector<string> &cur, const string &s, const int &n) {
    if (start == n) {
      res.push_back(cur);
      return;
    }
    for (int i = start; i < n; ++i) {
      if (judge[start][i]) {
        cur.push_back(s.substr(start, i - start + 1));
        getPalindromes(i + 1, judge, cur, s, n);
        cur.pop_back();
      }
    }
  }
};