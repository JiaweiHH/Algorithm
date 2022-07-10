#include <vector>
using namespace std;

/// 一支弓箭可以沿着 x 轴从不同点完全垂直地射出。在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend，且满足  xstart ≤ x ≤ xend，
/// 则该气球会被引爆。可以射出的弓箭的数量没有限制。弓箭一旦被射出之后，可以无限地前进。我们想找到使得所有气球全部被引爆，所需的弓箭的最小数量

/// 贪心算法，时间复杂度 O(nlogn)，空间复杂度 O(logn) 为排序的空间复杂度，找出所有气球的公共交集区间个数，就是需要射出的弓箭的数量
/// 首先将 points 按照 start 从小到大，start 相同的按照 end 从小到大排序，然后遍历 points，使用 [begin, end] 记录上一支弓箭能够射出的区间范围
/// 如果发现 points[i].start > end，则更新计数值 res 表示需要射出一支新的弓箭，并更新新的弓箭的区间范围为 points[i].start, points[i].end
/// 如果 points[i].start <= begin && points[i].end < end，则更新弓箭的区间范围 [begin = points[i].start, end = points[i].end]
class Solution {
public:
  int findMinArrowShots(vector<vector<int>> &points) {
    sort(points.begin(), points.end(),
         [](vector<int> &lhs, vector<int> &rhs) { return lhs[0] < rhs[0]; });
    // r 表示下一发箭准备射的位置
    int res = 1, r = points[0][1];
    for (int i = 1; i < points.size(); ++i) {
      if (points[i][0] > r) {
        // r 这支箭已经不能继续引爆新的气球了，射出一支新的箭
        ++res;
        r = points[i][1];
      } else {
        // 当前区间在 r 内部，更新之前射出的位置，尽可能的小
        r = min(r, points[i][1]);
      }
    }
    return res;
  }
};