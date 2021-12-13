#include <vector>

using namespace std;

// 给定一个数组表示每一个房屋的金额，不能连着偷两个房屋，求能偷到的最大金额

// dp[i][0] 表示第 i 个房屋选择不偷的最大金额
// dp[i][1] 表示第 i 个房屋选择偷的最大金额
class Solution {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(2));
    dp[0][0] = 0, dp[0][1] = nums[0];
    for (int i = 1; i < n; ++i) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
      dp[i][1] = dp[i - 1][0] + nums[i];
    }
    return max(dp[n - 1][0], dp[n - 1][1]);
  }
};

// 优化，减少空间复杂度
// 直接考虑 dp[i] 表示前 i 间房屋能偷到的最大金额
// dp[i] 有两种选择
// 1. 偷窃第 i 间房屋，dp[i] = dp[i - 2] + nums[i]
// 2. 不偷窃第 i 间房屋，dp[i] = dp[i - 1]
//   （选择不偷第 i - 1 间的时候，dp[i - 1] 就是 dp[i - 2]，dp[i - 1] >= dp[i - 2] 的）
//    所以这里没什么问题
// 综上，dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])