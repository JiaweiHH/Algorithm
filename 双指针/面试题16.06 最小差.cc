#include <vector>
using namespace std;

class Solution {
public:
  int smallestDifference(vector<int> &a, vector<int> &b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int l = 0, r = 0;
    int64_t res = INT_MAX;
    while (l != a.size() && r != b.size()) {
      int64_t tmp_1 = a[l], tmp_2 = b[r];
      int64_t tmp = tmp_1 < tmp_2 ? tmp_2 - tmp_1 : tmp_1 - tmp_2;
      res = min(res, tmp);
      if (a[l] < b[r])
        ++l;
      else
        ++r;
    }
    return res;
  }
};