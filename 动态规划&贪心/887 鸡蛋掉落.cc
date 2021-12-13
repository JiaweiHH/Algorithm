#include <vector>

using namespace std;

// 有 k 个鸡蛋，n 层楼，鸡蛋在某一层 f 刚好不会碎，求找出这个 f
// 需要扔鸡蛋的最小次数

// drop(k, n) 表示现在有 k 个鸡蛋，n 层楼，返回所需扔鸡蛋的最小次数
// 对于每一个 drop(k, n) 选择鸡蛋在 1 <= i <= n 层楼扔一次
// 如果鸡蛋碎了，则继续求 drop(k - 1, i - 1) 的最小值
// 如果没有碎，则继续求 drop(k, n - i) 的最小值
// 最后对于在第 i 层楼扔的这一次情况，需要取 drop(k - 1, i - 1) 和 drop(k, n - i) 的最大值
// 然后尝试每一个 i，找到所有的 i 中的最小值
// note: 这种方法最后会超时
class Solution_0 {
public:
  vector<vector<int>> dp;
  int superEggDrop(int k, int n) {
    dp.resize(k + 1, vector<int>(n + 1));
    return drop(k, n);
  }
  int drop(int k, int n) {
    if (k == 1)
      return n;
    if (n <= 1)
      return n;
    if (dp[k][n])
      return dp[k][n];
    int res = INT_MAX;
    for (int i = 1; i <= n; ++i) {
      // 选择在第 i 层楼扔，会有碎和不碎两种情况
      // 如果碎了，那么剩余的次数就是 drop(k - 1, i - 1);
      // 否则，剩余的次数就是 drop(k, n - i);
      res = min(res, max(drop(k - 1, i - 1), drop(k, n - i)));
    }
    // 这里需要加上在第 i 层扔的那一次
    dp[k][n] = res + 1;
    return res + 1;
  }
};

/// 二分查找优化
/// 由于直接暴力搜索 1 <= i <= n 会超时，所以这里采用二分搜索
/// 考虑到 drop(k - 1, i - 1) 是一个单调递增的函数，drop(k, n - i) 是一个单调递减的函数
/// 所以这里的 min(max(...)) 相当于找两个函数的交点，即山谷值
/// 因此可以用二分搜索确定这个值
class Solution_1 {
public:
  vector<vector<int>> dp;
  int superEggDrop(int k, int n) {
    dp.resize(k + 1, vector<int>(n + 1));
    return drop(k, n);
  }
  int drop(int k, int n) {
    if (k == 1)
      return n;
    if (n <= 1)
      return n;
    if (dp[k][n])
      return dp[k][n];
    int res = INT_MAX;
    int low = 1, high = n;
    while (low <= high) {
      int mid = (low + high) / 2;
      int tmp1 = drop(k - 1, mid - 1);
      int tmp2 = drop(k, n - mid);
      if (tmp1 < tmp2) {
        low = mid + 1;
        res = min(res, tmp2);
      } else {
        high = mid - 1;
        res = min(res, tmp1);
      }
    }
    // 这里需要加上在第 i 层扔的那一次
    dp[k][n] = res + 1;
    return res + 1;
  }
};

// 更改 dp 的含义
// 现在 dp[k][m] 表示有 k 个鸡蛋可以扔 m 次的情况，能够确定的最大楼层数
// 所以现在的目标是求最大的 m，使得可以确定 n 层楼层
// 对于每一个 dp[k][m] 还是假设在某一层扔下，然后 dp[k][m] = dp[k - 1][m - 1] + dp[k][m - 1] + 1
// 其中 dp[k - 1][m - 1] 表示在该层扔了之后鸡蛋碎了，可以确定下面有多少层
// dp[k][m - 1] 表示在该层扔了之后鸡蛋没碎，可以确定上面有多少层
// 最后加上当前层就是 dp[k][m] 可以确定的最大楼层数
class Solution_2 {
public:
  int superEggDrop(int k, int n) {
    // dp[k][m] 表示当前有 k 个鸡蛋最多允许扔 m 次，能够确定多少楼层
    vector<vector<int>> dp(k + 1, vector<int>(n + 1));
    int m = 0;
    while (dp[k][m] < n) {
      ++m;
      for (int i = 1; i <= k; ++i)
        // dp[i - 1][m - 1] 相当于在某一层扔了之后，下面有多少层
        // dp[i][m - 1] 相当于在某一层扔了之后，上面有多少层
        // 最后加上当前层，即为在 i 个鸡蛋可以扔 m 次的情况下可以确定的楼层数
        dp[i][m] = dp[i - 1][m - 1] + dp[i][m - 1] + 1;
    }
    return m;
  }
};