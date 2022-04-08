#include <vector>
using namespace std;

template <int> class Solution;

template <> class Solution<1> {
public:
  int res = 1, m, n;
  vector<vector<bool>> visited;
  vector<vector<int>> direc = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  vector<vector<int>> memo;
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    m = matrix.size(), n = matrix[0].size();
    visited.resize(m, vector<bool>(n, false));
    memo.resize(m, vector<int>(n, false));
    int res = 1;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i - 1 >= 0 && matrix[i][j] > matrix[i - 1][j])
          continue;
        if (i + 1 < m && matrix[i][j] > matrix[i + 1][j])
          continue;
        if (j - 1 >= 0 && matrix[i][j] > matrix[i][j - 1])
          continue;
        if (j + 1 < n && matrix[i][j] > matrix[i][j + 1])
          continue;
        visited[i][j] = true;
        int tmp = dfs(matrix, i, j);
        res = max(res, tmp);
        visited[i][j] = false;
      }
    }
    return res;
  }
  int dfs(const vector<vector<int>> &matrix, int x, int y) {
    if (memo[x][y])
      return memo[x][y];
    int len = 1;
    for (int i = 0; i < 4; ++i) {
      int new_x = x + direc[i][0], new_y = y + direc[i][1];
      if (!judge(matrix, x, y, new_x, new_y))
        continue;
      int tmp = dfs(matrix, new_x, new_y);
      len = max(len, tmp + 1);
    }
    memo[x][y] = len;
    return len;
  }
  bool judge(const vector<vector<int>> &matrix, int x, int y, int new_x,
             int new_y) {
    if (new_x < 0 || new_y < 0 || new_x >= m || new_y >= n)
      return false;
    if (visited[new_x][new_y])
      return false;
    if (matrix[x][y] >= matrix[new_x][new_y])
      return false;
    return true;
  }
};