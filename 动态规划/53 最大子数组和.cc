#include <vector>
using namespace std;

/// 给你一个整数数组 nums，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和

template <int> class Solution;

/// @brief 贪心
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

/// @brief 动态规划
template <> class Solution<2> {
public:
  int maxSubArray(vector<int> &nums) {
    int m = nums.size();
    // dp[i] 表示以 nums[i] 结尾的子数组的最大和
    vector<int> dp(m, INT_MIN);
    dp[0] = nums[0];
    for (int i = 1; i < m; ++i) {
      dp[i] = max({dp[i], dp[i - 1] + nums[i], nums[i]});
    }
    return *max_element(dp.begin(), dp.end());
  }
};

struct Status {
  Status(int l, int r, int m, int i) : lSum(l), rSum(r), mSum(m), iSum(i) {}
  Status() = default;
  // lSum 表示以 l 为左端点的区间最大子段和
  // rSum 表示以 r 为右端点的区间最大子段和
  // mSum 表示 [l, r] 内的最大子段和
  // iSum 表示 [l, r] 的区间和
  int lSum, rSum, mSum, iSum;
};
/// @brief 分治
/// status.iSum = left.iSum + right.iSum
/// status.lSum = max(left.lSum, left.iSum + right.lSum)
/// status.rSum = max(right.rSum, right.iSum + left.rSum)
/// status.mSum = max({left.mSum, right.mSum, left.rSum + right.lSum})
template <> class Solution<3> {
public:
  Status merge(Status &left, Status &right) {
    Status res;
    res.iSum = left.iSum + right.iSum;
    res.lSum = max(left.lSum, left.iSum + right.lSum);
    res.rSum = max(left.rSum + right.iSum, right.rSum);
    res.mSum = max({left.mSum, right.mSum, left.rSum + right.lSum});
    return res;
  }
  Status getResult(vector<int> &nums, int l, int r) {
    if (l == r)
      return Status(nums[l], nums[l], nums[l], nums[l]);
    int mid = (l + r) / 2;
    Status left = getResult(nums, l, mid), right = getResult(nums, mid + 1, r);
    return merge(left, right);
  }
  int maxSubArray(vector<int> &nums) {
    return getResult(nums, 0, nums.size() - 1).mSum;
  }
};