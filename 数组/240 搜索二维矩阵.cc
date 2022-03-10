#include <vector>
using namespace std;

template <int> class Solution;

/// 二分
template <> class Solution<1> {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    for (int i = 0; i < m; ++i) {
      if (matrix[i][0] <= target && target <= matrix[i][n - 1]) {
        bool tmp = find(matrix[i], target);
        if (tmp)
          return true;
      }
    }
    return false;
  }
  bool find(vector<int> &vec, int target) {
    int left = 0, right = vec.size() - 1;
    while (left <= right) {
      int mid = (left + right) >> 1;
      if (vec[mid] == target)
        return true;
      if (vec[mid] > target)
        right = mid - 1;
      else
        left = mid + 1;
    }
    return false;
  }
};

/// Z 字型查找
template <> class Solution<2> {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int x = 0, y = n - 1;
    while (x != m && y != -1) {
      if (matrix[x][y] == target)
        return true;
      if (matrix[x][y] > target)
        --y;
      else
        ++x;
    }
    return false;
  }
};