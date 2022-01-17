#include <string>
#include <vector>
using namespace std;

template <int> class Solution;

template <> class Solution<1> {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    int n = s.size();
    vector<bool> dp(n + 1);
    dp[0] = true;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (check(s, i, j, wordDict))
          dp[i] = dp[i] | dp[j];
      }
    }
    return dp[n];
  }
  bool check(string &s, int i, int j, vector<string> &wordDict) {
    string str = s.substr(j, i - j);
    for (auto &word : wordDict)
      if (word == str)
        return true;
    return false;
  }
};