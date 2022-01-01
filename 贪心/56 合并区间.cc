#include <vector>
using namespace std;

/// 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间

/// 将 intervals 按照左边界从小到大排序，然后遍历 intervals。用 start 和 end 表示合并区间的左右边界
/// 如果 intervals[i][0] > end 说明该区间没有和合并区间重叠，那么就讲合并区间保存到 res 中，将新的合并区间的左右边界设置为 interval[i][0] 和 interval[i][1]
/// 否则的话说明区间有重叠了，此时判断 intervals[i][1] > end，如果成立的话说明合并区间的右边界需要拉长，设置为 interval[i][1]
class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](const vector<int> &lhs, const vector<int> &rhs) {
           return lhs[0] < rhs[0];
         });
    int start = intervals[0][0], end = intervals[0][1];
    vector<vector<int>> res;
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i][0] > end) {
        res.push_back({start, end});
        start = intervals[i][0];
        end = intervals[i][1];
      } else if (intervals[i][1] > end) {
        end = intervals[i][1];
      }
    }
    res.push_back({start, end});
    return res;
  }
};