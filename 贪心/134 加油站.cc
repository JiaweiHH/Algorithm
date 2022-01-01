#include <vector>
using namespace std;

/// 在一条环路上有 N 个加油站，其中第 i 个加油站有汽油 gas[i] 升
/// 你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升
/// 你从其中的一个加油站出发，开始时油箱为空. 如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1

template <int>
class Solution;

/// 贪心算法，时间复杂度 O(n)，空间复杂度 O(1)
/// 初始的时候从 0 号加油站出发，计算每次经过加油站之后油箱的剩余容量 gas[i]-cost[i]
/// 如果到达某一个加油站 i 之后发现 curSum 是负数，则说明从 [lastStart, i] 之间的任何加油站出发都会发生油不足的情况
/// 因为 [lastStart, i - 1] 之间剩余油箱容量总是一个正数，这就说明如果想要从 [lastStart, i] 之间的某一个加油站出发
/// 即便一开始邮箱里面有剩余的油都不足以通过第 i 站，所以就可以得出 [lastStart, i] 之间的任何加油站出发都不能通过站点 i
/// 然后让开始站点 start = i + 1，重新计算油箱当前余量从 curSum = 0 开始
/// 最后如果发现 totalSum < 0 就说明不能从任何加油站出发环绕一周，否则的话 start 就是起始站点
template <> class Solution<1> {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int curSum = 0, totalSum = 0, start = 0;
    for (int i = 0; i < gas.size(); ++i) {
      totalSum += gas[i] - cost[i];
      curSum += gas[i] - cost[i];
      if (curSum < 0) {
        // 如果 curSum < 0 说明 [lastStart, i] 区间之内都不适合成为起点
        // 更新新的起点为 i + 1
        start = i + 1;
        curSum = 0;
      }
    }
    if (totalSum < 0)
      return -1;
    return start;
  }
};