#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findRightInterval(vector<vector<int>> &intervals) {
    int n = intervals.size();
    vector<pair<int, int>> vec;
    vector<int> res(n);
    for (int i = 0; i < n; ++i)
      vec.push_back({intervals[i][0], i});
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; ++i) {
      int l = 0, r = n - 1;
      while (l <= r) {
        int mid = (l + r) / 2;
        if (vec[mid].first < intervals[i][1])
          l = mid + 1;
        else
          r = mid - 1;
      }
      res[i] = l == n ? -1 : vec[l].second;
    }
    return res;
  }
};