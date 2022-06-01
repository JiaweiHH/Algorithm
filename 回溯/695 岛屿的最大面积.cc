#include <vector>
using namespace std;

class Solution {
public:
  int res = 0, m, n;
  vector<vector<bool>> visit;
  vector<vector<int>> direc = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  bool check(vector<vector<int>> &grid, int x, int y) {
    if (x < 0 || x == m || y < 0 || y == n)
      return false;
    return !visit[x][y] && grid[x][y] == 1;
  }
  void dfs(vector<vector<int>> &grid, int x, int y, int &cur_area) {
    visit[x][y] = true;
    for (int i = 0; i < direc.size(); ++i) {
      int new_x = x + direc[i][0], new_y = y + direc[i][1];
      if (check(grid, new_x, new_y)) {
        dfs(grid, new_x, new_y, ++cur_area);
      }
    }
    res = max(res, cur_area);
  }
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    m = grid.size(), n = grid[0].size();
    visit.resize(m, vector<bool>(n));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (check(grid, i, j)) {
          int tmp = 1;
          dfs(grid, i, j, tmp);
        }
      }
    }
    return res;
  }
};