#include <vector>
using namespace std;

template <int> class Solution;

/// 动态规划 + 贪心，时间复杂度 O(n)，空间复杂度 O(n)
///
/// 有一个很明显的贪心策略是，对于每一个孩子，寻找他左侧分数最低的孩子的位置
/// left，以及他右侧分数最低的孩子的位置 right，即寻找左侧峰谷和右侧的峰谷
/// 由于所有峰谷的糖果数量必定都是 1，那么对于 i 来说，他的糖果数量就是 max(i -
/// left, right - i) + 1 例如对于 ratings = [1, 2, 3, 1]，那么分到的糖果就是 [1,
/// 2, 3, 1]，其中 index = 2 所分到的糖果刚好是 1 + (2 - 0)
///
/// 所以问题就转化为如果计算每个孩子左侧和右侧的峰谷，这里可以使用动态规划求解。使用
/// pos[i].first 表示左侧的峰谷，pos[i].second 表示右侧的峰谷 pos[i].first
/// 的更新策略：
/// 1. 如果 raitngs[i] > ratings[i - 1]，那么 pos[i].first = pos[i - 1].first
/// 2. 如果 ratings[i] == ratings[i -
/// 1]，也就是出现平的时候，此时对于糖果计算来说需要相当于他左侧没有峰谷，pos[i].first
/// = i
///    因为对于 ratings =  [1, 2, 3, 3, 3, 1] 来说，最后的糖果是 [1, 2, 3, 1, 2,
///    1]，题目并没有要求相等的 raings 糖果必须相等，所以分配给 index = 3
///    的糖果还是 1
/// 3. 如果 ratings[i] < ratings[i - 1]，那么左侧必定没有峰谷，pos[i].first = i
/// pos[i].second 的更新策略：
/// 1. 如果 raitngs[i] > ratings[i + 1]，那么 pos[i].second = pos[i + 1].second
/// 2. 如果 ratings[i] <= ratings[i + 1]，相当于右侧没有峰谷，pos[i].second =
/// pos[i + 1].second
template <> class Solution<1> {
public:
  int candy(vector<int> &ratings) {
    int n = ratings.size();
    // pos[i].first 表示距离 i 左侧最近的一个谷的位置
    // pos[i].second 表示距离 i 右侧最近的一个谷的位置
    vector<pair<int, int>> pos(n);
    pos[0].first = 0;
    pos[n - 1].second = n - 1;
    // 计算左侧谷的位置
    for (int i = 1; i < n; ++i) {
      if (ratings[i] > ratings[i - 1])
        pos[i].first = pos[i - 1].first;
      else if (ratings[i] <= ratings[i - 1])
        pos[i].first = i;
    }
    // 计算右侧谷的位置
    for (int i = n - 2; i >= 0; --i) {
      if (ratings[i] > ratings[i + 1])
        pos[i].second = pos[i + 1].second;
      else if (ratings[i] <= ratings[i + 1])
        pos[i].second = i;
    }
    // 计算最少需要的糖果
    int res = n;
    for (int i = 0; i < n; ++i) {
      res += max(i - pos[i].first, pos[i].second - i);
    }
    return res;
  }
};

/// 贪心
template <> class Solution<2> {
public:
  int candy(vector<int> &ratings) {
    int n = ratings.size();
    vector<int> vec(n, 1);
    for (int i = 1; i < n; ++i) {
      if (ratings[i] > ratings[i - 1])
        vec[i] = vec[i - 1] + 1;
    }
    for (int i = n - 2; i >= 0; --i) {
      if (ratings[i] > ratings[i + 1] && vec[i] <= vec[i + 1])
        vec[i] = vec[i + 1] + 1;
    }
    int res = 0;
    for (int i = 0; i < n; ++i)
      res += vec[i];
    return res;
  }
};

/// O(1) 空间复杂度
template <> class Solution<3> {
public:
  int candy(vector<int> &ratings) {
    // pre 记录前一个孩子分得的糖果，dec 记录当前递减序列的长度
    // inc 记录当前递增序列的长度，res 记录当前最少需要分多少糖果
    int pre = 1, dec = 1, inc = 1, res = 1;
    for (int i = 1; i < ratings.size(); ++i) {
      if (ratings[i] > ratings[i - 1]) {
        pre++;      // 当前这个孩子需要分得 pre + 1 的糖果
        inc = pre;  // 递增序列长度就是现在 pre 的长度
        res += pre; // res 加上当前孩子的糖果
        dec = 0;
      } else if (ratings[i] == ratings[i - 1]) {
        // 相等就重置递增序列，并设置当前孩子的糖果数量为 1
        pre = 1;
        inc = 1;
        res++;
        dec = 0;
      } else {
        dec++; // 递减序列长度加一
        // 如果和上一个递增序列想等了，将上一个递增序列的最后一个元素加入递减序列
        if (dec == inc)
          dec++;
        res += dec;
        pre = 1;
      }
    }
    return res;
  }
};