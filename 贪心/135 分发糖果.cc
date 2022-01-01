#include <vector>
using namespace std;

/// n 个孩子站成一排，给你一个整数数组 ratings 表示每个孩子的评分
/// 你需要按照以下要求，给这些孩子分发糖果：
/// 1. 每个孩子至少分配到 1 个糖果
/// 2. 相邻两个孩子评分更高的孩子会获得更多的糖果（注意只有 ratings[i] > ratings[i + 1] 才能获得更多的糖果）
/// 请你给每个孩子分发糖果，计算并返回需要准备的最少糖果数目

template <int> class Solution;


/// 动态规划 + 贪心，时间复杂度 O(n)，空间复杂度 O(n)
/// 
/// 有一个很明显的贪心策略是，对于每一个孩子，寻找他左侧分数最低的孩子的位置 left，以及他右侧分数最低的孩子的位置 right，即寻找左侧峰谷和右侧的峰谷
/// 由于所有峰谷的糖果数量必定都是 1，那么对于 i 来说，他的糖果数量就是 max(i - left, right - i) + 1
/// 例如对于 ratings = [1, 2, 3, 1]，那么分到的糖果就是 [1, 2, 3, 1]，其中 index = 2 所分到的糖果刚好是 1 + (2 - 0)
/// 
/// 所以问题就转化为如果计算每个孩子左侧和右侧的峰谷，这里可以使用动态规划求解。使用 pos[i].first 表示左侧的峰谷，pos[i].second 表示右侧的峰谷
/// pos[i].first 的更新策略：
/// 1. 如果 raitngs[i] > ratings[i - 1]，那么 pos[i].first = pos[i - 1].first
/// 2. 如果 ratings[i] == ratings[i - 1]，也就是出现平的时候，此时对于糖果计算来说需要相当于他左侧没有峰谷，pos[i].first = i
///    因为对于 ratings =  [1, 2, 3, 3, 3, 1] 来说，最后的糖果是 [1, 2, 3, 1, 2, 1]，题目并没有要求相等的 raings 糖果必须相等，所以分配给 index = 3 的糖果还是 1
/// 3. 如果 ratings[i] < ratings[i - 1]，那么左侧必定没有峰谷，pos[i].first = i
/// pos[i].second 的更新策略：
/// 1. 如果 raitngs[i] > ratings[i + 1]，那么 pos[i].second = pos[i + 1].second
/// 2. 如果 ratings[i] <= ratings[i + 1]，相当于右侧没有峰谷，pos[i].second = pos[i + 1].second
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

/// 与上一个方法相似的贪心思路，只不过这里先从左到右使用 left 计算每个孩子应该分得的糖果
/// 然后从右到左计算每个孩子应该分得的糖果，然后取 left 和 right 的最大值左侧实际的糖果
template <> class Solution<2> {
public:
  int candy(vector<int> &ratings) {
    int n = ratings.size();
    vector<int> left(n);
    for (int i = 0; i < n; i++) {
      if (i > 0 && ratings[i] > ratings[i - 1]) {
        left[i] = left[i - 1] + 1;
      } else {
        left[i] = 1;
      }
    }
    int right = 0, ret = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (i < n - 1 && ratings[i] > ratings[i + 1]) {
        right++;
      } else {
        right = 1;
      }
      ret += max(left[i], right);
    }
    return ret;
  }
};

/// 另一种不同的思路，空间复杂度优化到 O(1)，并且只需要从左到右一遍遍历 ratings 数组
/// 首先举一个例子 ratings = [1, 2, 3, 2, 1, 0]，那么从左到右我们可以尝试分配 [1, 2, 3, ...] 后续的 ratings = [2, 1, 0]，我们可以转换一下，对于一个递减序列将最后一个元素的糖果当成第一个元素的糖果，这样糖果的总量还是保持不变
/// 所以后续可以得到糖果 [1, 2, 3, 1, 2, 3]，当遍历到最后一个的时候可以发现递减序列的长度已经超过递增序列了，所以对于递减和递增的中间节点多一个糖果给他，最后可以得到 [1, 2, 4, 1, 2, 3]
template <> class Solution<3> {
public:
  int candy(vector<int> &ratings) {
    int n = ratings.size();
    int ret = 1;
    // inc 记录递增序列的长度，dec 记录后续递减序列的长度，pre 记录前一个元素的糖果数量
    int inc = 1, dec = 0, pre = 1;
    for (int i = 1; i < n; i++) {
      if (ratings[i] >= ratings[i - 1]) {
        dec = 0;
        pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1;
        ret += pre;
        inc = pre;
      } else {
        dec++;
        if (dec == inc) {
          dec++;
        }
        ret += dec;
        pre = 1;
      }
    }
    return ret;
  }
};