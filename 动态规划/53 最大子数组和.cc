#include <vector>
using namespace std;

/// 给你一个整数数组 nums，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和

template <int> class Solution;

/// 贪心
template <> class Solution<1> {
public:
  int maxSubArray(vector<int> &nums) {
    int res = INT_MIN, cur = 0;
    for (int i = 0; i < nums.size(); ++i) {
      cur = cur + nums[i];
      res = max(res, cur);
      if (cur < 0)
        cur = 0;
    }
    return res;
  }
};

/// 动态规划
template <> class Solution<2> {
public:
  int maxSubArray(vector<int> &nums) {
    int m = nums.size();
    vector<int> dp(m, INT_MIN);
    dp[0] = nums[0];
    for (int i = 1; i < m; ++i) {
      dp[i] = max({dp[i], dp[i - 1] + nums[i], nums[i]});
    }
    return *max_element(dp.begin(), dp.end());
  }
};

/// 分治法
/// 对于每一个区间 [l, r] 维护四个状态：lSum 表示以 l 为左端点的最大子段和，rSum 表示以 r 为右端点的最大子段和，mSum 区间 [l, r] 的最大子段和，iSum 表示区间 [l, r] 的区间和
/// 那么原问题的答案就是区间 [0, nums.size() - 1] 区间的 mSum，其中 l = 0, r = nums.size() - 1，对于该问题可以分别求解 [l, m] 和 [m, r] 的状态，分别记为 left 和 right
/// 这样区间 [l, r] 的状态 status 可以从 left 和 right 推导得到，具体为：
/// 1. status.iSum = left.iSum + right.iSum
/// 2. status.lSum = max(left.lSum, left.iSum + right.lSum)
/// 3. status.rSum = max(right.rSum, right.iSum + left.rSum)
/// 4. status.mSum = max({left.mSum, right.mSum, left.rSum + right.lSum})
/// 递归的出口为 l == r 的时候，此时四个状态都是 nums[l]
/// 该方法的时间复杂度还是 O(n)，空间复杂度为 O(logn)
template <> class Solution<3> {
public:
  // 维护一个 [l, r] 区间的状态
  struct Status {
    // lSum 表示以 l 为左端点的区间最大子段和
    // rSum 表示以 r 为右端点的区间最大子段和
    // mSum 表示 [l, r] 内的最大子段和
    // iSum 表示 [l, r] 的区间和
    int lSum, rSum, mSum, iSum;
  };
  int maxSubArray(vector<int> &nums) {
    return get(nums, 0, nums.size() - 1).mSum;
  }
  // 查询序列 a，[l, r] 内的 Status
  Status get(const vector<int> &a, int l, int r) {
    if (l == r)
      return Status{a[l], a[l], a[l], a[l]};
    int m = (l + r) >> 1;
    Status left = get(a, l, m);
    Status right = get(a, m + 1, r);
    return merge(left, right);
  }
  Status merge(const Status &left, const Status &right) {
    Status s;
    s.iSum = left.iSum + right.iSum;
    // 合并区间的 lSum 取 left.lSum 和 left.iSum + right.lSum 中的最大值
    s.lSum = max(left.lSum, left.iSum + right.lSum);
    // 合并区间的 rSum 取 right.rSum 和 right.iSum + left.rSum 中的最大值
    s.rSum = max(right.rSum, right.iSum + left.rSum);
    // 合并区间的 mSum 要么来自 left.mSum，要么来自 right.mSum，要么来自 left.rSum + right.lSum
    s.mSum = max({left.mSum, right.mSum, left.rSum + right.lSum});
    return s;
  }
};