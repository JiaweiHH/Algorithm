#include <queue>
#include <vector>
using namespace std;

template <int> class Solution;

/// 深搜
template <> class Solution<0> {
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

/// 广搜
template <> class Solution<2> {
public:
  int numIslands(vector<vector<char>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> direc = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<bool>> visit(m, vector<bool>(n));
    int res = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (!visit[i][j] && grid[i][j] == '1') {
          queue<pair<int, int>> q;
          q.push({i, j});
          visit[i][j] = true;
          while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
              int x = p.first + direc[i][0], y = p.second + direc[i][1];
              if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1' &&
                  !visit[x][y]) {
                visit[x][y] = true;
                q.push({x, y});
              }
            }
          }
          res++;
        }
      }
    }
    return res;
  }
};

/// 并查集
template <> class Solution<3> {
public:
  int numIslands(vector<vector<char>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> direc = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    UnionFind uf(m * n);
    int sum = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '0') {
          sum++;
          continue;
        }
        for (int k = 0; k < 4; ++k) {
          int x = i + direc[k][0], y = j + direc[k][1];
          if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1')
            uf.unite(i * n + j, x * n + y);
        }
      }
    }
    return uf.count - sum;
  }

private:
  struct UnionFind {
    vector<int> parent;
    int count;
    UnionFind(int n) : count(n) {
      for (int i = 0; i < n; ++i)
        parent.push_back(i);
    }
    int find(int x) {
      while (x != parent[x]) {
        parent[x] = parent[parent[x]];
        x = parent[x];
      }
      return x;
    }
    void unite(int p, int q) {
      int rootP = find(p), rootQ = find(q);
      if (rootP == rootQ)
        return;
      parent[rootP] = rootQ;
      count--;
    }
    bool connected(int p, int q) {
      int rootP = find(p), rootQ = find(q);
      return rootP == rootQ;
    }
  };
};