#include <vector>
using namespace std;

template <int>
class Solution {};

/// @brief 给定一个整数 n，找到若干个完全平方数，使得它们的和等于 n，你需要让组成和的完全平方数的个数最少

/// @brief 动态规划，类似于硬币问题
/// dp[i] 表示组合出和等于 i 所需要的最少的完全平方数的数量，dp[i] = min(dp[i - j * j] + 1)，j >= 1 && j * j <= i
/// 即计算 dp[i] 我们可以先让它减去一个完全平方数，然后通过 dp[i - j * j] + 1 就是 dp[i] 的值，在所有的可能中求最小值
/// @note 时间复杂度：O(n * sqrt(n))，空间复杂度：O(n)
template <> class Solution<1> {
public:
  int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j * j <= i; ++j) {
        dp[i] = min(dp[i], dp[i - j * j] + 1);
      }
    }
    return dp[n];
  }
};

/// 完全背包问题
template <> class Solution<3> {
public:
  int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX - 1);
    dp[0] = 0;
    for (int i = 1; i * i <= n; ++i) {
      for (int j = i * i; j <= n; ++j)
        dp[j] = min(dp[j], dp[j - i * i] + 1);
    }
    return dp[n];
  }
};

/// @brief 数学定理：四平方和定力
/// 1. 当 n = 4^k * (8m + 7) 时，n 只能被表示为四个正整数的平方和
/// 2. 当 n != 4^k * (8m + 7) 时，至多只能被表示为 3 个正整数的平方和
/// 3. 如果答案是 1，判断 n 是不是完全平方数
/// 4. 如果答案是 2，枚举所有的 i(1 <= i <= sqrt(n))，判断 n - i * i 是不是完全平方数
/// 5. 如果答案是 3，很难在一个优秀的时间复杂度内解决，但是只需要检查完 1 或 2 的情况即可
template <> class Solution<2> {
public:
  int numSquares(int n) {
    if (check(n))
      return 4;
    if (isPerfectSquares(n))
      return 1;
    for (int i = 1; i * i <= n; ++i) {
      if (isPerfectSquares(n - i * i))
        return 2;
    }
    return 3;
  }
  bool isPerfectSquares(int n) {
    int x = sqrt(n);
    return x * x == n;
  }
  bool check(int n) {
    while (n % 4 == 0) {
      n /= 4;
    }
    return n % 8 == 7;
  }
};