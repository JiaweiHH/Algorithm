#include <vector>

using namespace std;

// 与 198 题的区别在于，现在房屋是围成一个环的

// 总体上分为两种情况
// 1. 偷了第一间房屋
// 2. 没有偷第一间房屋
class Solution {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    if (n == 1)
      return nums[0];
    vector<int> dp1(n), dp2(n);
    // 1. 选择第一个，那么最后一个不考虑
    dp1[0] = nums[0];
    for (int i = 1; i < n - 1; ++i) {
      if (i == 1)
        dp1[i] = max(dp1[0], nums[i]);
      else
        dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
    }
    // 2. 不选择第一个，那么可以把最后一个纳入考虑范围
    dp2[1] = nums[1];
    for (int i = 2; i < n; ++i) {
      dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i]);
    }
    return max(dp1[n - 2], dp2[n - 1]);
  }
};

// 其实，如果第一种情况 dp[1] = nums[1]，dp[2] = dp[1] 的话
// 那么此时第一种情况的最后的答案已经被第二种情况包含进去了
// 第一种情况只是多了一种第一个房屋可以被偷的考虑，这种情况的可能性而已
// 所以也可以写成下面这样
class Solution {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    if (n == 1)
      return nums[0];
    vector<int> dp1(n), dp2(n);
    // 1. 选择第一个，那么最后一个不考虑
    dp1[0] = nums[0];
    int flag1 = false, flag2 = false;
    for (int i = 1; i < n - 1; ++i) {
      if (i == 1) {
        dp1[i] = max(dp1[0], nums[i]);
        if (dp1[i] == nums[1])
          flag1 = true;
      } else {
        dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
        if (dp1[2] == dp1[1]) {
          flag2 = true;
          break;
        }
      }
    }
    // 2. 不选择第一个，那么可以把最后一个纳入考虑范围
    dp2[1] = nums[1];
    for (int i = 2; i < n; ++i) {
      dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i]);
    }
    return max(dp1[n - 2], dp2[n - 1]);
  }
};