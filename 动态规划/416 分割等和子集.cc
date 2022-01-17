#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2)
      return false;
    int v = accumulate(nums.begin(), nums.end(), 0) / 2;
    vector<int> dp(v + 1);
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = v; j >= nums[i]; --j) {
        dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
      }
    }
    return dp[v] == v;
  }
};