#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    vector<vector<int>> res;
    bool placed = false; // 记录 newInterval 是否被插入过
    for (int i = 0; i < intervals.size(); ++i) {
      // 没有交集的时候直接插入到 res 中
      if (intervals[i][1] < newInterval[0]) {
        res.push_back(intervals[i]);
        continue;
      }
      if (intervals[i][0] > newInterval[1]) {
        if (!placed) {
          res.push_back(newInterval);
          placed = true;
        }
        res.push_back(intervals[i]);
        continue;
      }
      // 相当于将 newInterval 在这个点插入到 intervals 中，后续按照合并区间处理
      int l = min(intervals[i][0], newInterval[0]),
          r = max(intervals[i][1], newInterval[1]);
      int j = i + 1;
      for (j = i + 1; j < intervals.size(); ++j) {
        if (intervals[j][0] > r) {
          res.push_back({l, r});
          l = intervals[j][0];
        }
        r = max(r, intervals[j][1]);
      }
      placed = true;
      res.push_back({l, r});
      i = j - 1;
    }
    if (!placed)
      res.push_back(newInterval);
    return res;
  }
};