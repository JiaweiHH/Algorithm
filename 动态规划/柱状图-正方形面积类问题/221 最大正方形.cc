#include <vector>
using namespace std;

/// @brief 给出一个二维矩阵，其中只包含字符 ‘0’ 和字符 ‘1’，找出其中只包含 1 的最大正方形面积

/// @brief dp[i][j] 表示以 i,j 为左上角顶点的最大正方形边长，
/// 则有 dp[i][j] = min(dp[i + 1][j], dp[i][j + 1], dp[i + 1][j + 1]) + 1
/// 类似木桶的短板理论一样，某一个点的边长取决于其右边、下边、右下方三个正方形的边长
/// https://leetcode-cn.com/problems/maximal-square/solution/li-jie-san-zhe-qu-zui-xiao-1-by-lzhlyle/
class Solution {
public:
  int maximalSquare(vector<vector<char>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = m - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        if (matrix[i][j] == '1')
          dp[i][j] = min({dp[i + 1][j], dp[i][j + 1], dp[i + 1][j + 1]}) + 1;
        else
          dp[i][j] = 0;
      }
    }
    int max_ele = INT_MIN;
    for_each(dp.begin(), dp.end(), [&max_ele](const vector<int> &vi) {
      for_each(vi.begin(), vi.end(), [&max_ele](const int ele) {
        if (ele > max_ele)
          max_ele = ele;
      });
    });
    return max_ele * max_ele;
  }
};