#include <vector>
#include <map>

using namespace std;

/// @brief  有 n 件在售的物品。每件物品都有对应的价格。然而，也有一些大礼包，每个大礼包以优惠的价格捆绑销售一组物品
/// 给你一个整数数组 price 表示物品价格，其中 price[i] 是第 i 件物品的价格。另有一个整数数组 needs 表示购物清单，其中 needs[i] 是需要购买第 i 件物品的数量
/// 还有一个数组 special 表示大礼包，special[i] 的长度为 n + 1 ，其中 special[i][j] 表示第 i 个大礼包中内含第 j 件物品的数量，且 special[i][n] （也就是数组中的最后一个整数）为第 i 个大礼包的价格
/// 返回 确切 满足购物清单所需花费的最低价格，你可以充分利用大礼包的优惠活动。你不能购买超出购物清单指定数量的物品，即使那样会降低整体价格。任意大礼包可无限次购买。

/// @brief 动态规划
/// 1. 除去无效的大礼包，无效的大礼包定义为总价格并不会得到优惠的大礼包
/// 2. 一个背包问题。对于当前的需求 cur_needs 分别尝试购买 special 中的某一个大礼包，然后计算剩余的需求 next_needs 所需的最低价格
///    最后将购买 next_needs 的价格加上 special[i] 的价格和按照原价购买 cur_needs 中的商品的价格比较，价格低的就是购买 cur_needs 的最低价格
class Solution {
public:
  map<vector<int>, int> memo;
  int shoppingOffers(vector<int> &price, vector<vector<int>> &special,
                     vector<int> &needs) {
    vector<vector<int>> filter;
    int n = price.size();
    // 去除无效的大礼包
    for (auto &sp : special) {
      int total_count = 0, total_price = 0;
      for (int i = 0; i < n; ++i) {
        total_count += sp[i];
        total_price += sp[i] * price[i];
      }
      if (total_count > 0 && total_price > sp[n]) {
        filter.push_back(sp);
      }
    }
    return dfs(price, filter, needs);
  }
  int dfs(const vector<int> &price, const vector<vector<int>> &special,
          const vector<int> &cur_needs) {
    if (!memo.count(cur_needs)) {
      int min_price = 0;
      for (int i = 0; i < cur_needs.size(); ++i) {
        min_price += cur_needs[i] * price[i];
      }
      for (auto &cur_special : special) { // 尝试购买某一个大礼包
        vector<int> next_needs;
        for (int i = 0; i < cur_special.size() - 1; ++i) {
          if (cur_needs[i] - cur_special[i] < 0)
            break;
          next_needs.push_back(cur_needs[i] - cur_special[i]);
        }
        if (next_needs.size() == cur_needs.size()) {
          int cur_price = dfs(price, special, next_needs) +
                          cur_special[cur_special.size() - 1];
          if (cur_price < min_price)
            min_price = cur_price;
        }
      }
      memo[cur_needs] = min_price;
    }
    return memo[cur_needs];
  }
};