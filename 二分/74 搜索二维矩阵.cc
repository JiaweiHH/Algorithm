#include <vector>
using namespace std;

template <int> class Solution;

/// Z 字型查找
template <> class Solution<1> {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int x = 0, y = n - 1;
    while (x < m && y >= 0) {
      if (matrix[x][y] > target)
        --y;
      else if (matrix[x][y] < target)
        ++x;
      else
        return true;
    }
    return false;
  }
};

/// 二分查找
template <> class Solution<2> {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int l = 0, r = m - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (matrix[mid][0] <= target)
        l = mid + 1;
      else
        r = mid - 1;
    }
    if (r < 0)
      return false;
    int idx = r;
    l = 0, r = n - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (matrix[idx][mid] < target)
        l = mid + 1;
      else if (matrix[idx][mid] > target)
        r = mid - 1;
      else
        return true;
    }
    return false;
  }
};