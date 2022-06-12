#include <vector>

using namespace std;

class Solution {
public:
  int maxCoins(vector<int> &nums) {
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = n - 1; i >= 0; --i) {
      for (int j = i + 2; j < n; ++j) {
        for (int k = i + 1; k < j; ++k) {
          dp[i][j] =
              max(dp[i][j], dp[i][k] + dp[k][j] + nums[k] * nums[i] * nums[j]);
        }
      }
    }
    return dp[0][n - 1];
  }
};