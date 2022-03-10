#include <vector>
using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();
    for (int i = 0; i < n / 2; ++i) {
      for (int k = 0; k < n - 1 - 2 * i; ++k)
        subRotate(matrix, i, n - 1 - i);
    }
  }
  void subRotate(vector<vector<int>> &matrix, int left, int right) {
    int tmp = matrix[left][right];
    // 旋转正方形上面这条边
    for (int i = right; i > left; --i) {
      matrix[left][i] = matrix[left][i - 1];
    }
    // 旋转正方形左边这条边
    for (int i = left; i < right; ++i)
      matrix[i][left] = matrix[i + 1][left];
    // 旋转正方形下面这条边
    for (int i = left; i < right; ++i)
      matrix[right][i] = matrix[right][i + 1];
    // 旋转正方形右边这条边
    for (int i = right; i > left; --i)
      matrix[i][right] = matrix[i - 1][right];
    matrix[left + 1][right] = tmp;
  }
};