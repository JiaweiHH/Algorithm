#include <queue>
#include <utility>
#include <vector>

using namespace std;

// 广度优先搜索，如果在当前搜索层数能够到达终点，那么当前层数 n 就是最小值
// 为了确定下一层有多少个元素，需要在上一层入队的时候记录下一层元素的个数
class Solution {
public:
  int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
    int n = grid[0].size();
    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
      return -1;
    queue<pair<int, int>> queue;
    queue.push(make_pair(0, 0));
    // 方向数组
    vector<vector<int>> dv = {{0, 1},   {0, -1}, {1, 0},  {-1, 0},
                              {-1, -1}, {1, 1},  {1, -1}, {-1, 1}};
    // 标记这个坐标是不是已经走过
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    visited[0][0] = true;
    // res 记录最小步数，len 记录每一层队列中的元素个数
    int res = 1, len = 1;
    while (!queue.empty()) {
      int count = 0;
      for (int i = 0; i < len; ++i) {
        auto cur = queue.front();
        queue.pop();
        // 不能放在这里
        // visited[cur.first][cur.second] = true;
        if (cur.first == n - 1 && cur.second == n - 1)
          return res;
        for (const auto &d : dv) {
          int r = cur.first + d[0], c = cur.second + d[1];
          if (r < 0 || r >= n || c < 0 || c >= n || grid[r][c] == 1 ||
              visited[r][c])
            continue;
          // 需要放在这里
          visited[r][c] = true;
          queue.push(make_pair(r, c));
          ++count;
        }
      }
      len = count;
      // 每经过一层步数加一
      ++res;
    }
    return -1;
  }
};