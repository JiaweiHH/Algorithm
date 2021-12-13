#include <vector>

using namespace std;

// 给定每一天的股票价格，你只能在某一天卖入，只能在另一天卖出。求出能获得的最大利润

// 只需要在数组中找出差距最大的两个数就好了
// 在遍历 prices[i] 的时候，用一个变量 mi 记住前 i - 1 个元素的最小值
// 这样就能保证 prices[i] - mi 永远是对于 prices[i] 来说最大的
// 遍历完 prices[i] 就更新一下 mi
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    // mi 表示第 i 个元素之前的最小值
    int res = 0, mi = prices[0];
    for (int i = 1; i < prices.size(); ++i) {
      res = max(res, prices[i] - mi);
      mi = min(mi, prices[i]);
    }
    return res;
  }
};