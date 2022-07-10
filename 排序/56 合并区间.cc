#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](vector<int> &lhs, vector<int> &rhs) {
           return lhs[0] < rhs[0] || (lhs[0] == rhs[0] && lhs[1] < rhs[1]);
         });
    vector<vector<int>> res;
    int l = intervals[0][0], r = intervals[0][1];
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i][0] > r) {
        res.push_back({l, r});
        l = intervals[i][0];
      }
      r = max(r, intervals[i][1]);
    }
    res.push_back({l, r});
    return res;
  }
};