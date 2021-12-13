#include <vector>
#include <stack>
using namespace std;

/// @brief 给出一个由字符 '0' 和 '1' 构成的二维矩阵，求出该二维矩阵中只包含 '1' 的最大矩形的面积


/// @brief 方法一
/// 1. 对于 matrix 中的每一个元素，先找出该元素左边有多少个连续的 1 记在 left 数组中。例如 000111，则结果是 000123
/// 2. 然后开始遍历 matrix 的每一个元素，计算以该点为右下角的矩形的最大面积
/// 2.1 对于每个这样的矩形，初始情况下宽度 width = left[i][j]，初始面积 area = width
/// 2.2 然后遍历 i > k >=0，以 (k, j) 作为矩形的右上角顶点。
///     对于每一个右上角，根据它的横向宽度 left[k][j]，更新矩形的宽度 width = min(width, left[k][j])，
///     然后宽度知道了，高度是 i - k + 1，所以每一个这样的矩形都可以计算出面积
/// 3. 计算出上一步骤中所有矩形的最大面积
/// 
/// 时间复杂度：O(m^2 * n)，空间复杂度：O(mn)
class Solution_1 {
public:
  int maximalRectangle(vector<vector<char>> &matrix) {
    if (matrix.size() == 0)
      return 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> left(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
      left[i][0] = matrix[i][0] == '1' ? 1 : 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (matrix[i][j] == '1')
          left[i][j] = left[i][j - 1] + 1;
      }
    }
    int max_area = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] == '0')
          continue;
        int width = left[i][j];
        int area = width;
        for (int k = i - 1; k >= 0; --k) {
          width = min(width, left[k][j]);
          area = max(area, width * (i - k + 1));
        }
        max_area = max(max_area, area);
      }
    }
    return max_area;
  }
};

/// @brief 方法二
/// 在生成柱状图的基础上，遍历每一列上的柱状图，使用单调栈的方法求解
class Solution_2 {
public:
  int maximalRectangle(vector<vector<char>> &matrix) {
    if (matrix.size() == 0)
      return 0;
    int m = matrix.size(), n = matrix[0].size();
    // 构造出柱状图
    vector<vector<int>> left(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
      left[i][0] = matrix[i][0] == '1' ? 1 : 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (matrix[i][j] == '1')
          left[i][j] = left[i][j - 1] + 1;
      }
    }
    int res = 0;
    // 对于每一列使用基于柱状图的单调栈
    for (int i = 0; i < n; ++i) {
      stack<int> st;
      vector<int> down(m), up(m);
      int area = 0;
      // 遍历该列中的每一根柱子
      for (int k = 0; k < m; ++k) {
        while (!st.empty() && left[st.top()][i] >= left[k][i]) {
          up[st.top()] = k;
          st.pop();
        }
        down[k] = st.empty() ? -1 : st.top();
        st.push(k);
      }
      while (!st.empty()) {
        up[st.top()] = m;
        st.pop();
      }
      for (int k = 0; k < m; ++k)
        area = max(area, (up[k] - down[k] - 1) * left[k][i]);
      res = max(res, area);
    }
    return res;
  }
};