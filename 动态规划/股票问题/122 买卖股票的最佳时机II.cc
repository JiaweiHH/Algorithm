#include <vector>

using namespace std;

// 给定 prices 数组，表示某一天的股票价格
// 可以完成多笔交易，但是必须要在上一笔股票卖出之后才可以购入新的
// 求出能获得的最大利润

// 只需要找出数组中所有的“上坡”，累加即可
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int last = -1, res = 0;
    for (const auto &p : prices) {
      if (last == -1 || p < last)
        last = p;
      else {
        res += p - last;
        last = p;
      }
    }
    return res;
  }
};