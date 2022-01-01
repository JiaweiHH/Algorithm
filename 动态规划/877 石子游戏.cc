#include <vector>

using namespace std;

/// 给出 n 堆石子，piles[i] 表示第 i 堆石子的数量。每次只能从第一堆或者最后一堆拿走一堆石子
/// 判断先手的人获取的石子是否大于后手的人

/// @param dp[i][j].first 表示在面对第 i 到 j 堆石子（包括 i 和 j）的时候先手能获取的最大数量
/// @param dp[i][j].second 表示在面对第 i 到 j 堆石子的时候后手能获取的最大数量
/// @brief 在计算 dp[i][j].first 的时候，先考虑从最前面那堆石头拿还是从最后面那堆石头拿
/// if left > right，此时先手的人要面对的是 i + 1 到 j 堆石子，并且是后手
/// if right >= left，此时先手的人要面对的是 i 到 j - 1 堆石子，并且是后手
/// 所以 dp[i][j].first = max(left + dp[i + 1][j].second, right + dp[i][j - 1].second)
/// dp[i][j].second = dp[i + 1][j].first or dp[i][j - 1].first
/// @return dp[0][n - 1].first > dp[0][n - 1].second 表示先手的人可以获胜
class Solution {
public:
  bool stoneGame(vector<int> &piles) {
    int n = piles.size();
    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n));
    for (int i = 0; i < n; ++i) {
      dp[i][i].first = piles[i];
      dp[i][i].second = 0;
    }
    for (int i = n - 1; i >= 0; --i) {
      for (int j = i + 1; j < n; ++j) {
        int left = piles[i] + dp[i + 1][j].second;
        int right = piles[j] + dp[i][j - 1].second;
        if (left > right) {
          dp[i][j].first = left;
          dp[i][j].second = dp[i + 1][j].first;
        } else {
          dp[i][j].first = right;
          dp[i][j].second = dp[i][j - 1].first;
        }
      }
    }
    return dp[0][n - 1].first > dp[0][n - 1].second ? true : false;
  }
};