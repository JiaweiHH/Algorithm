#include <vector>
using namespace std;

/// @brief
/// 编写一个程序，通过填充空格来解决数独问题，数独部分空格内已填入了数字，空白格用 '.' 表示

/// @brief 常规的回溯操作
class Solution {
public:
  void solveSudoku(vector<vector<char>> &board) { dfs(0, 0, board); }
  bool dfs(int r, int c, vector<vector<char>> &board) {
    if (r == board.size()) // board 已经填充完了
      return true;
    if (c == board.size()) // 第 r 行已经填充完了
      return dfs(r + 1, 0, board);
    if (board[r][c] != '.') // board[r][c] 不需要填充
      return dfs(r, c + 1, board);
    // 尝试数字 1~9
    for (char i = '1'; i <= '9'; ++i) {
      // 判断填充 i 是不是有效的
      if (isValid(board, r, c, i)) {
        board[r][c] = i;
        if (dfs(r, c + 1, board))
          return true;
        board[r][c] = '.';
      }
    }
    return false;
  }
  bool isValid(const vector<vector<char>> &board, int r, int c, char num) {
    // 判断行是否重复
    for (int i = 0; i < board.size(); ++i)
      if (board[r][i] == num)
        return false;
    // 判断列是否重复
    for (int i = 0; i < board.size(); ++i)
      if (board[i][c] == num)
        return false;
    // 判断分块内部是否重复
    int startRow = (r / 3) * 3, startCol = (c / 3) * 3;
    for (int i = startRow; i < startRow + 3; ++i) {
      for (int j = startCol; j < startCol + 3; ++j) {
        if (board[i][j] == num)
          return false;
      }
    }
    return true;
  }
};