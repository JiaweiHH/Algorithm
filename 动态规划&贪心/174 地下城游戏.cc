#include <vector>

using namespace std;

// 给出一个矩阵，矩阵中的每一个方格表示经过该点可以获取或者减少的生命值
// 求出骑士从 [0, 0] 出发，到达 [m - 1, n - 1] 所需要的最少生命值


// dp[i][j] 表示到达坐标 [i, j] 所需要的最少生命值
// dp[i][j] 需要从 dp[i + 1][j]、dp[i][j + 1] 推导出来
// dp[i][j] = min{dp[i][j + 1], dp[i + 1][j]} - dungeon[i][j]
class Solution {
public:
  int calculateMinimumHP(vector<vector<int>> &dungeon) {
    int m = dungeon.size(), n = dungeon[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
    dp[m - 1][n] = dp[m][n - 1] = 0;
    for (int i = m - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        int tmp = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
        dp[i][j] = tmp < 0 ? 0 : tmp;
      }
    }
    return dp[0][0] + 1;
  }
};