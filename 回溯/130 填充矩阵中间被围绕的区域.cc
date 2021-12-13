#include <vector>

using namespace std;

// 深度优先搜索
// 转换思路，从初始矩阵的边界出发找到所有的 'O' 将其改为 '#'
// 然后将所有剩余的 'O' 改为 'X'，再将所有的 '#' 改为 'O'
class Solution {
public:
  vector<vector<int>> dv = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  int m, n;
  void solve(vector<vector<char>> &board) {
    m = board.size(), n = board[0].size();
    // 将和边缘连接的所有 'O' 都标记为 '#'
    for (int i = 0; i < n; ++i) {
      dfs(board, 0, i);
      dfs(board, m - 1, i);
    }
    for (int i = 0; i < m; ++i) {
      dfs(board, i, 0);
      dfs(board, i, n - 1);
    }
    // 将所有的 'O' 都改为 'X', 所有的 '#' 都改为 'O'
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == 'O')
          board[i][j] = 'X';
        if (board[i][j] == '#')
          board[i][j] = 'O';
      }
    }
  }
  void dfs(vector<vector<char>> &board, int x, int y) {
    if (board[x][y] != 'O')
      return;
    // 将和边缘连接的所有 'O' 都标记为 '#'
    board[x][y] = '#';
    for (const auto &d : dv) {
      int nextX = x + d[0], nextY = y + d[1];
      if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n)
        continue;
      dfs(board, nextX, nextY);
    }
  }
};