#include <vector>
#include <string>

using namespace std;

// 给定一个二维字符数组，给定一个单词字符串，要求判断能不能在数组中组合出这个单词
// 每次只能从一个方格走向相邻的方格，走过的元素不能重复走

// 直接 DFS 搜索
class Solution {
public:
  vector<vector<bool>> visited;
  vector<vector<int>> dire = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  int m, n;
  bool exist(vector<vector<char>> &board, string word) {
    m = board.size(), n = board[0].size();
    visited.resize(m, vector<bool>(n, false));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == word[0]) {
          for_each(visited.begin(), visited.end(),
                   [](vector<bool> &vb) { fill(vb.begin(), vb.end(), false); });
          bool res = dfs(board, i, j, 0, word);
          if (res)
            return true;
        }
      }
    }
    return false;
  }
  bool dfs(const vector<vector<char>> &board, int r, int c, int index,
           const string &word) {
    if (r < 0 || r >= m || c < 0 || c >= n)
      return false;
    if (word[index] != board[r][c] || visited[r][c])
      return false;
    if (index == word.size() - 1)
      return true;
    visited[r][c] = true;
    for (const auto &d : dire) {
      int tmp_r = r + d[0], tmp_c = c + d[1];
      bool res = dfs(board, tmp_r, tmp_c, index + 1, word);
      if (res)
        return true;
    }
    visited[r][c] = false;
    return false;
  }
};