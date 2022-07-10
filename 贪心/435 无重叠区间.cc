#include <algorithm>
#include <vector>

using namespace std;

template <int> class Solution;

/// @brief 给定 n 个区间，找到需要移除的最小区间数量，使得剩余的区间互不重叠

/// @brief 转化为 452.用最少的箭引爆气球
/// 求出需要射出的箭的数量，返回 intervals.size() - cnt
template <> class Solution<1> {
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](vector<int> &lhs, vector<int> &rhs) { return lhs[0] < rhs[0]; });
    int cnt = 1, r = intervals[0][1];
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i][0] >= r) {
        ++cnt;
        r = intervals[i][1];
      } else {
        r = min(r, intervals[i][1]);
      }
    }
    return intervals.size() - cnt;
  }
};