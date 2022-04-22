#include <vector>
using namespace std;

class Solution {
public:
  bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
    if (matrix.empty())
      return false;
    int m = matrix.size(), n = matrix[0].size();
    int x = 0, y = n - 1;
    while (x < m && y >= 0) {
      if (target == matrix[x][y])
        return true;
      if (target < matrix[x][y])
        --y;
      else
        ++x;
    }
    return false;
  }
};