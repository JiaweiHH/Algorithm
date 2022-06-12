#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n));
    int ptr_r1 = 0, ptr_r2 = n - 1, ptr_c1 = 0, ptr_c2 = n - 1, cnt = 1;
    while (ptr_r1 <= ptr_r2 && ptr_c1 <= ptr_c2) {
      for (int i = ptr_c1; i <= ptr_c2; ++i)
        res[ptr_r1][i] = cnt++;
      for (int i = ptr_r1 + 1; i <= ptr_r2; ++i)
        res[i][ptr_c2] = cnt++;
      if (ptr_r1 != ptr_r2) {
        for (int i = ptr_c2 - 1; i >= ptr_c1; --i)
          res[ptr_r2][i] = cnt++;
      }
      if (ptr_c1 != ptr_c2) {
        for (int i = ptr_r2 - 1; i >= ptr_r1 + 1; --i)
          res[i][ptr_c1] = cnt++;
      }
      ++ptr_r1;
      ++ptr_c1;
      --ptr_r2;
      --ptr_c2;
    }
    return res;
  }
};