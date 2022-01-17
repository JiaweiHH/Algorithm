#include <vector>
#include <string>
using namespace std;

/// @brief 给出两个字符串 s1, s2，找到使两个字符串相等所需删除字符的 ASCII 值的最小和

template <int> class Solution {};

/// @brief 动态规划
/// dp[i][j] 表示 s1 前 i 个字符 -> s2 前 j 个字符所需删除的字符的 ASCII 值的最小和
/// 如果 s1[i - 1] == s2[j - 1]，则 dp[i][j] = dp[i - 1][j - 1]
/// 如果 s1[i - 1] != s2[j - 1]，则 dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1])
/// 后一种情况即，从 i - 1 -> j 然后删除 s1[i - 1]，和从 i -> j - 1 然后删除 s2[j - 1] 中取最小值
/// 
/// @note 时间复杂度：O(mn)，空间复杂度：O(mn)
template <> class Solution<1> {
public:
  int minimumDeleteSum(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
      dp[i][0] = dp[i - 1][0] + s1[i - 1];
    }
    for (int j = 1; j <= n; ++j) {
      dp[0][j] = dp[0][j - 1] + s2[j - 1];
    }
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (s1[i - 1] == s2[j - 1])
          dp[i][j] = dp[i - 1][j - 1];
        else
          dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
      }
    }
    return dp[m][n];
  }
};