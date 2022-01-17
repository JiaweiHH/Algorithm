#include <vector>
using namespace std;

class Solution {
public:
  int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size(), n = nums2.size();
    vector<vector<int>> dp(m, vector<int>(n));
    dp[0][0] = nums1[0] == nums2[0] ? 1 : 0;
    for (int i = 1; i < m; ++i)
      dp[i][0] = nums1[i] == nums2[0] ? 1 : max(dp[i - 1][0], 0);
    for (int j = 1; j < n; ++j)
      dp[0][j] = nums2[j] == nums1[0] ? 1 : max(dp[0][j - 1], 0);
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (nums1[i] == nums2[j])
          dp[i][j] = dp[i - 1][j - 1] + 1;
        else
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
    return dp[m - 1][n - 1];
  }
};