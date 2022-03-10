#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  int maximalRectangle(vector<vector<char>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
      dp[i][0] = matrix[i][0] == '1' ? 1 : 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        dp[i][j] = matrix[i][j] == '1' ? dp[i][j - 1] + 1 : 0;
      }
    }
    int res = 0;
    for (int j = 0; j < n; ++j) {
      stack<int> stk;
      vector<int> left(m), right(m);
      for (int i = 0; i < m; ++i) {
        while (!stk.empty() && dp[i][j] <= dp[stk.top()][j])
          stk.pop();
        left[i] = stk.empty() ? -1 : stk.top();
        stk.push(i);
      }
      while (!stk.empty())
        stk.pop();
      for (int i = m - 1; i >= 0; --i) {
        while (!stk.empty() && dp[i][j] <= dp[stk.top()][j])
          stk.pop();
        right[i] = stk.empty() ? m : stk.top();
        stk.push(i);
      }
      for (int i = 0; i < m; ++i)
        res = max(res, (right[i] - left[i] - 1) * dp[i][j]);
    }
    return res;
  }
};