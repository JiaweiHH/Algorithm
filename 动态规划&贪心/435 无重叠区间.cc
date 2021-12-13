#include <algorithm>
#include <vector>

using namespace std;

template <int> class Solution;

/// @brief 给定 n 个区间，找到需要移除的最小区间数量，使得剩余的区间互不重叠

/// @brief 贪心
/// 将 n 个区间按照起始位置从小到大排序，然后每次从前一个区间的右端点出发寻找下一个左端点在其右侧的区间，记录所有找到的区间的数量
/// 最后返回 n - count 就是需要移除的区间数量
/// @note 时间复杂度：O(nlogn)，空间复杂度：O(logn)
template <> class Solution<0> {
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](const vector<int> &lhs, const vector<int> &rhs) {
           return lhs[1] < rhs[1];
         });
    int end = intervals[0][1], count = 1;
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i][0] >= end) {
        end = intervals[i][1];
        ++count;
      }
    }
    return intervals.size() - count;
  }
};