#include <vector>
using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int ptr_r1 = 0, ptr_r2 = matrix.size() - 1, ptr_c1 = 0,
        ptr_c2 = matrix[0].size() - 1;
    vector<int> res;
    while (ptr_r1 <= ptr_r2 && ptr_c1 <= ptr_c2) {
      for (int i = ptr_c1; i <= ptr_c2; ++i)
        res.push_back(matrix[ptr_r1][i]);
      for (int i = ptr_r1 + 1; i <= ptr_r2; ++i)
        res.push_back(matrix[i][ptr_c2]);
      if (ptr_r1 != ptr_r2) {
        for (int i = ptr_c2 - 1; i >= ptr_c1; --i)
          res.push_back(matrix[ptr_r2][i]);
      }
      if (ptr_c1 != ptr_c2) {
        for (int i = ptr_r2 - 1; i >= ptr_r1 + 1; --i)
          res.push_back(matrix[i][ptr_c1]);
      }
      ptr_r1++;
      ptr_r2--;
      ptr_c1++;
      ptr_c2--;
    }
    return res;
  }
};