#include <numeric>
#include <vector>
using namespace std;

template <int> class Solution;

/// 回溯
template <> class Solution<1> {
public:
  int res, sum;
  int findTargetSumWays(vector<int> &nums, int target) {
    sum = accumulate(nums.begin(), nums.end(), 0);
    dfs(0, nums, 0, target);
    return target == 0 ? res * 2 : res;
  }
  void dfs(int index, const vector<int> &nums, int curSum, int target) {
    if (index == nums.size()) {
      if (abs(sum - curSum * 2) == abs(target))
        res++;
      return;
    }
    for (int i = index; i < nums.size(); ++i) {
      dfs(i + 1, nums, curSum + nums[i], target);
    }
  }
};

/// 0-1 背包
template <> class Solution<2> {
public:
  int findTargetSumWays(vector<int> &nums, int target) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if ((sum + target) % 2)
      return 0;
    int v = (sum + target) / 2;
    if (v < 0)
      return 0;
    vector<int> dp(v + 1);
    dp[0] = 1;
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = v; j >= nums[i]; --j) {
        dp[j] += dp[j - nums[i]];
      }
    }
    return dp[v];
  }
};