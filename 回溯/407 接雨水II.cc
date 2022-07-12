#include <queue>
#include <vector>
using namespace std;

template <int> class Solution;

/// @brief 广搜
template <> class Solution<1> {
public:
  int trapRainWater(vector<vector<int>> &heightMap) {
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int m = heightMap.size(), n = heightMap[0].size(), heightMax = 0;
    for (int i = 0; i < m; ++i)
      heightMax = max(heightMax,
                      *max_element(heightMap[i].begin(), heightMap[i].end()));
    vector<vector<int>> water(m, vector<int>(n, heightMax));
    queue<pair<int, int>> que;
    // 放入边缘的方块，恢复它们的 water 为 heightMap
    for (int i = 0; i < m; ++i) {
      if (water[i][0] > heightMap[i][0]) {
        water[i][0] = heightMap[i][0];
        que.push({i, 0});
      }
      if (water[i][n - 1] > heightMap[i][n - 1]) {
        water[i][n - 1] = heightMap[i][n - 1];
        que.push({i, n - 1});
      }
    }
    for (int j = 0; j < n; ++j) {
      if (water[0][j] > heightMap[0][j]) {
        water[0][j] = heightMap[0][j];
        que.push({0, j});
      }
      if (water[m - 1][j] > heightMap[m - 1][j]) {
        water[m - 1][j] = heightMap[m - 1][j];
        que.push({m - 1, j});
      }
    }
    // 迭代更新所有方块的 water
    while (!que.empty()) {
      auto [x, y] = que.front();
      que.pop();
      for (int i = 0; i < 4; ++i) {
        int nx = x + dirs[i].first, ny = y + dirs[i].second;
        if (nx < 0 || nx == m || ny < 0 || ny == n)
          continue;
        // (nx, ny) 还有更新的可能
        if (water[x][y] < water[nx][ny] && water[nx][ny] > heightMap[nx][ny]) {
          water[nx][ny] = max(water[x][y], heightMap[nx][ny]);
          que.push({nx, ny});
        }
      }
    }
    // 计算可以接到的雨水
    int res = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        res += water[i][j] - heightMap[i][j];
      }
    }
    return res;
  }
};

/// @brief 小根堆
template <> class Solution<2> {
public:
  int trapRainWater(vector<vector<int>> &heightMap) {
    int m = heightMap.size(), n = heightMap[0].size();
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        que;
    vector<vector<bool>> visited(m, vector<bool>(n));
    // 从边缘的方块出发
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
          visited[i][j] = true;
          que.push({heightMap[i][j], i * n + j});
        }
      }
    }
    vector<int> dirs = {1, 0, -1, 0, 1};
    int res = 0;
    while (!que.empty()) {
      // 每次从堆中选择高度最小的格子，判断周围的格子能否被填充
      auto curr = que.top();
      que.pop();
      for (int i = 0; i < 4; ++i) {
        int nx = curr.second / n + dirs[i], ny = curr.second % n + dirs[i + 1];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
          if (curr.first > heightMap[nx][ny]) {
            res += curr.first - heightMap[nx][ny];
          }
          visited[nx][ny] = true;
          // 周围的格子有可能高度高于当前被选择的格子，这个时候放入堆中的应该是周围格子的高度
          que.push({max(curr.first, heightMap[nx][ny]), nx * n + ny});
        }
      }
    }
    return res;
  }
};