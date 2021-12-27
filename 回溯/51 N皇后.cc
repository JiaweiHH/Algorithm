#include <string>
#include <vector>
using namespace std;

/// @brief n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击
/// 给你一个整数 n ，返回所有不同的 n 皇后问题的解决方案，方案中 'Q' 和 '.' 分别代表了皇后和空位

/// @brief 回溯（搜索）
/// 也可以使用集合或者位运算的方式来记录列方向和两个斜线方向上（坐标差值以及坐标之和）是否已经有皇后了
class Solution {
public:
  vector<vector<pair<int, int>>> p_vec; // 记录所有解法中的皇后坐标
  vector<pair<int, int>> cur;           // 记录所有皇后的坐标
  vector<vector<string>> solveNQueens(int n) {
    dfs(0, n);
    vector<vector<string>> res;
    // 将解法中的坐标转换为字符串
    for (auto &points : p_vec) {
      vector<string> tmp;
      for (auto &p : points) {
        string str(n, '.');
        str[p.second] = 'Q';
        tmp.push_back(str);
      }
      res.push_back(tmp);
    }
    return res;
  }
  void dfs(int row, int n) {
    if (row == n) {
      p_vec.push_back(cur);
      return;
    }
    // 对第 row 行选择一列，检查是否可以放置皇后
    for (int col = 0; col < n; ++col) {
      bool flag = false;
      // 判断该坐标 (row, col) 是否是可以放置的
      for (auto &point : cur) {
        if (abs(point.first - row) == abs(point.second - col) ||
            col == point.second) {
          flag = true;
          break;
        }
      }
      // 如果可以放置那么记录该位置，转到下一行
      if (!flag) {
        cur.push_back(make_pair(row, col));
        dfs(row + 1, n);
        cur.pop_back();
      }
    }
  }
};