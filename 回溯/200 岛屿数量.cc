#include <vector>
using namespace std;

class Solution {
public:
  int res = 0;
  int m, n;
  vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
  vector<vector<bool>> visit;
  int numIslands(vector<vector<char>> &grid) {
    m = grid.size();
    n = grid[0].size();
    visit.resize(m, vector<bool>(n));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '1' && !visit[i][j]) {
          visit[i][j] = true;
          dfs(grid, i, j);
          res++;
        }
      }
    }
    return res;
  }
  void dfs(const vector<vector<char>> &grid, int x, int y) {
    for (int i = 0; i < dir.size(); ++i) {
      int newX = x + dir[i][0];
      int newY = y + dir[i][1];
      if (newX < 0 || newX == m || newY < 0 || newY == n || visit[newX][newY] ||
          grid[newX][newY] == '0')
        continue;
      visit[newX][newY] = true;
      dfs(grid, newX, newY);
    }
  }
};