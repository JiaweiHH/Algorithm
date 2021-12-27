#include <vector>
using namespace std;

/// @brief 给出一个矩形 grid，返回其中被 1 包围的最大正方形的面积

/// dp[i][j][0] 表示 grid[i][j] 左侧 1 的个数，dp[i][j][1] 表示 grid[i][j] 上方 1 的个数
/// 当计算得到 dp[i][j][0] 和 dp[i][j][1] 之后，尝试使用 grid[i][j] 为右下角构建一个被 1 包围的正方形
/// 该正方形的最大可能边长 len = min(dp[i][j][0], dp[i][j][1])
/// 检查该正方形右上角点的左侧是否至少有 len 个 1，以及该正方形左下角点的上方是否有至少 len 个 1，
/// 如果满足条件，那么 len 就是以 i 和 j 为右下角能够构造出的最大正方形，否则的话 len--，继续判断
class Solution {
public:
  int largest1BorderedSquare(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    // dp[i][j][0] 表示第 i 行、第 j 列左边连续 1 的个数，dp[i][j][1] 表示第 i
    // 行、第 j 列上方连续 1 的个数
    vector<vector<vector<int>>> dp(m,
                                   vector<vector<int>>(n, vector<int>(2, 0)));
    int res = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          dp[i][j][0] = (j == 0 ? 0 : dp[i][j - 1][0]) + 1;
          dp[i][j][1] = (i == 0 ? 0 : dp[i - 1][j][1]) + 1;
          // 以 grid[i][j] 为右下角的正方形的最大可能长度
          int len = min(dp[i][j][0], dp[i][j][1]);
          while (len) { // 计算以 grid[i][j] 为右下角的正方形最大长度
            // 如果该正方形的右上角左侧有至少 len 个 1，并且左下角的上方有至少
            // len 个 1 那么以 grid[i][j] 为右下角可以获得边长为 len 的正方形
            if (dp[i - len + 1][j][0] >= len && dp[i][j - len + 1][1] >= len)
              break;
            --len;
          }
          res = max(res, len);
        }
      }
    }
    return res * res;
  }
};