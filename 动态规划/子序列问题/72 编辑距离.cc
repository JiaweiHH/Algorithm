#include <string>
#include <vector>

using namespace std;

// 给出两个字符串 word1 和 word2，求出 word1 转换到 word2 的最小操作数
// 每次可以对 word1 进行插入、删除、替换中的一个操作

// 比较简单，唯一需要注意的是，这里的 dp[i][j] 表示前 i 个字符到前 j 个字符的距离
class Solution {
public:
  int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= n; ++i)
      dp[0][i] = i;
    for (int i = 0; i <= m; ++i)
      dp[i][0] = i;
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (word1[i - 1] == word2[j - 1])
          dp[i][j] = dp[i - 1][j - 1];
        else {
          dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
        }
      }
    }
    return dp[m][n];
  }
};