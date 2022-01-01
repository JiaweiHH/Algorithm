#include <vector>
using namespace std;

/// @brief 给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些正整数的乘积最大化

template <int> class Solution {};

/// @brief 动态规划
/// dp[n] 表示拆分正整数 n 可以获得的最大乘积，考虑将 n 拆分为 j + (n - j)，则有
/// 1. 如果 n - j 不继续拆分，那么 dp[n] = j * (n - j)
/// 2. 如果 n - j 继续拆分，那么 dp[n] = j * dp[n - j]
/// 遍历所有的 1 <= j < n，dp[n] = max(j * (n - j), j * dp[n - j])

template <> class Solution<1> {
public:
  int integerBreak(int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j < i; ++j) {
        dp[i] = max({dp[i], j * (i - j), j * dp[i - j]});
      }
    }
    return dp[n];
  }
};