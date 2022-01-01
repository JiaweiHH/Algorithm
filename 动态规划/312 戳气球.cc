#include <vector>

using namespace std;

// 有 n 个气球，编号为0 到 n - 1，每个气球上都标有一个数字，这些数字存在数组 nums 中
// 现在要求你戳破所有的气球。戳破第 i 个气球，你可以获得 nums[i - 1] * nums[i] * nums[i + 1] 枚硬币
// 这里的 i - 1 和 i + 1 代表和 i 相邻的两个气球的序号
// 如果 i - 1或 i + 1 超出了数组的边界，那么就当它是一个数字为 1 的气球。

// 这里首先给 nums[] 收尾都添加了一个元素 1，这样就不需要特殊考虑戳破最后一个和第一个气球的情况了
// dp[i][j] 表示戳破开区间 i 到 j 之间的所有气球能获取的最大分数，最后的答案就是 dp[0][n + 1]
// 在戳破这里面的所有气球的时候，考虑最后剩下来的是原来数组中索引为 k 的气球，那么此时
// dp[i][j] = dp[i][k] + dp[k][j] + nums[i]*nums[k]*nums[j]
// 对所有可能的 k 取 dp[i][j] 的最大值
// note：在计算 dp[i][j] 的时候需要先计算 dp[i][k] 和 dp[k][j]，所以对于 i 的遍历需要从大到小，对于 j 的遍历需要从小到大
class Solution {
public:
  int maxCoins(vector<int> &nums) {
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.insert(nums.end(), 1);
    // dp[i][j] 表示戳破 i 到 j 的所有气球不包括 i 和 j 能获得的最大分数
    vector<vector<int>> dp(n + 2, vector<int>(n + 2));
    // dp[i][j] = max{dp[i][k] + dp[k][j] + nums[i] * nums[k] * nums[j]}
    // k 是最后一个戳破的气球编号
    for (int i = n + 1; i >= 0; --i) {
      for (int j = i + 1; j <= n + 1; ++j) {
        for (int k = i + 1; k < j; ++k) {
          dp[i][j] =
              max(dp[i][j], dp[i][k] + dp[k][j] + nums[i] * nums[k] * nums[j]);
        }
      }
    }
    return dp[0][n + 1];
  }
};