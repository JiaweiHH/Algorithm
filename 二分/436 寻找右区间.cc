#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findRightInterval(vector<vector<int>> &intervals) {
    vector<pair<int, int>> vec;
    for (int i = 0; i < intervals.size(); ++i)
      vec.push_back({intervals[i][0], i});
    sort(vec.begin(), vec.end(), [](pair<int, int> &lhs, pair<int, int> &rhs) {
      return lhs.first < rhs.first;
    });
    vector<int> res(intervals.size());
    ;
    for (int i = 0; i < intervals.size(); ++i) {
      int l = 0, r = vec.size() - 1;
      while (l <= r) {
        int mid = (l + r) / 2;
        if (vec[mid].first >= intervals[i][1])
          r = mid - 1;
        else
          l = mid + 1;
      }
      res[i] = l == vec.size() ? -1 : vec[l].second;
    }
    return res;
  }
};