#include <vector>
#include <string>
using namespace std;

template <int>
class Solution {};

/// @brief 给定三个字符串 s1, s2, s3，判断 s3 能不能由 s1 和 s2 交错组成

/// @brief 动态规划
/// s3 如果可以由 s1 和 s3 交错组成，那么必定有 s1.size() + s2.size() == s3.size()
/// 使用 dp[i][j] 表示 s1 的前 i 个字符和 s2 的前 j 个字符能不能组合出 s3 的前 i + j 个字符
/// 判断 s1[i - 1] 或者 s2[j - 1] 是否和当前循环中 s3 的最后一个字符相等
/// 1. 如果 s1[i - 1] == s3[i + j - 1]，那么只需要判断 s1 的前 i - 1 个字符加上 s2 的前 j 个字符能不能组合出 s3 的前 i + j - 1 个字符即可
/// 2. 如果 s2[j - 1] == s3[i + j - 1]，那么只需要判断 s2 的前 j - 1 个字符加上 s1 的前 i 个字符能不能组合出 s3 的前 i + j - 1 个字符即可
/// 最后返回 dp[m][n] 即可
template <> class Solution<1> {
public:
  bool isInterleave(string s1, string s2, string s3) {
    int m = s1.size(), n = s2.size();
    if (m + n != s3.size())
      return false;
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;

    for (int i = 0; i <= m; ++i) {
      for (int j = 0; j <= n; ++j) {
        // 判断 s1 前 i - 1 个元素加上 s2 前 j 个元素能不能组合出 s3 的前 i + j - 1 个元素
        if (i > 0 && s1[i - 1] == s3[i + j - 1])
          dp[i][j] = dp[i][j] | dp[i - 1][j];
        if (j > 0 && s2[j - 1] == s3[i + j - 1])
          dp[i][j] = dp[i][j] | dp[i][j - 1];
      }
    }
    return dp[m][n];
  }
};

/// @brief 思路和前一种一样，但是使用滚动数组优化
/// f[j] 表示
template <> class Solution<2> {
public:
  bool isInterleave(string s1, string s2, string s3) {
    auto f = vector<int>(s2.size() + 1, false);
    int n = s1.size(), m = s2.size(), t = s3.size();
    if (n + m != t) {
      return false;
    }
    f[0] = true;
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= m; ++j) {
        int p = i + j - 1;
        if (i > 0) {
          // 由于这里没有 dp[i - 1][j] 的信息了，所以要用 &，把所有的信息累积在一起
          f[j] &= (s1[i - 1] == s3[p]);
        }
        if (j > 0) {
          // dp[i][j - 1] 的信息一直都在，所以只需要用 |
          f[j] |= (f[j - 1] && s2[j - 1] == s3[p]);
        }
      }
    }

    return f[m];
  }
};