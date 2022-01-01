#include <vector>
using namespace std;

/// 如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为摆动序列
/// 给你一个整数数组 nums，返回 nums 中作为摆动序列的最长子序列的长度

template <int> class Solution;

/// 采用动态规划的思路，首先将 nums 数组中相邻两个元素的差值放入一个新的数组 values 中
/// 然后该问题就转变为了最长正负交叉子序列问题，可以采用最长子序列问题求解，使用 dp[i] 表示 values 中截止到第 i 个元素之前的最长正负交叉子序列，最后原来问题的返回值就是 dp[n - 1] + 1
/// 唯一需要注意的是，当相邻两个元素的值相等的时候，差值不放入 values 数组中，否则 [1, 1, 1] 的返回值就是 2 了，而正确答案是 1。对于 values 为空的情况直接返回 1 即可
/// @note 时间复杂度：O(n^2)，空间复杂度 O(n)
template <> class Solution<1> {
public:
  int wiggleMaxLength(vector<int> &nums) {
    vector<int> values;
    for (int i = 0; i < nums.size() - 1; ++i)
      if (nums[i + 1] - nums[i] != 0)
        values.push_back(nums[i + 1] - nums[i]);
    int n = values.size();
    if (n == 0)
      return 1;
    vector<int> dp(n, 1);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (values[i] * values[j] < 0)
          dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    return dp[n - 1] + 1;
  }
};

/// 另一种思路的动态规划，时间复杂度 O(n)，空间复杂度 O(n)，空间复杂度可以优化为 O(1)，因为每一个状态只和前一个状态有关，可以只使用一个变量来存储
/// 使用 down[i] 表示前 i 个元素的「最长下降摆动序列」的长度，「最长下降摆动序列」的定义为，最后一个元素是下降的摆动序列
/// 使用 up[i] 表示前 i 个元素的「最长上升摆动序列」的长度，「最长上升摆动序列」的定义为，最后一个元素是上升的摆动序列
/// 那么对于 nums 中的某一个元素 nums[i]，其 up[i] 的更新规则为：
/// 1. 如果 nums[i] > nums[i - 1]，up[i] = max(up[i - 1], down[i - 1] + 1)，因为可以从一个「最长下降摆动序列」的最后一个上升，从而获得一个「最长上升摆动序列」
/// 2. 如果 nums[i] <= nums[i - 1]，up[i] = up[i - 1]
/// 其 down[i] 的更新规则为：
/// 1. 如果 nums[i] >= nums[i - 1]，down[i] = down[i - 1]
/// 2. 如果 nums[i] < nums[i - 1]，down[i] = max(up[i - 1] + 1, down[i - 1])，因为可以从一个 「最长上升摆动序列」的最后一个元素下降，从而获得一个「最长下降摆动序列」
/// 最后最长摆动序列长度是 max(up[n - 1], down[n - 1])
template <> class Solution<2> {
public:
  int wiggleMaxLength(vector<int> &nums) {
    int n = nums.size();
    vector<int> up(n), down(n);
    up[0] = down[0] = 1;
    for (int i = 1; i < n; ++i) {
      if (nums[i] > nums[i - 1]) {
        down[i] = down[i - 1];
        up[i] = max(down[i - 1] + 1, up[i - 1]);
      } else if (nums[i] < nums[i - 1]) {
        down[i] = max(up[i - 1] + 1, down[i - 1]);
        up[i] = up[i - 1];
      } else {
        down[i] = down[i - 1];
        up[i] = up[i - 1];
      }
    }
    return max(up[n - 1], down[n - 1]);
  }
};

/// 采用贪心算法，贪心策略为统计原序列中峰和谷的数量，该数量就是最后的最长摆动序列
template <> class Solution<3> {
public:
  int wiggleMaxLength(vector<int> &nums) {
    if (nums.size() == 1)
      return 1;
    int prevdiff = nums[1] - nums[0];
    int res = prevdiff != 0 ? 2 : 1;
    for (int i = 2; i < nums.size(); ++i) {
      int diff = nums[i] - nums[i - 1];
      // 记录峰和谷的数量
      if ((diff > 0 && prevdiff <= 0) || (diff < 0 && prevdiff >= 0)) {
        prevdiff = diff;
        res++;
      }
    }
    return res;
  }
};