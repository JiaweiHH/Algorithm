#include <vector>
using namespace std;

class Solution {
public:
  int findLength(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size(), m = nums2.size();
    vector<vector<int>> dp(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
      dp[i][0] = nums1[i] == nums2[0] ? 1 : 0;
    for (int j = 0; j < m; ++j)
      dp[0][j] = nums2[j] == nums1[0] ? 1 : 0;
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < m; ++j) {
        if (nums1[i] == nums2[j])
          dp[i][j] = dp[i - 1][j - 1] + 1;
        else
          dp[i][j] = 0;
      }
    }
    int res = 0;
    for (auto &vec : dp)
      for (auto &v : vec)
        res = max(res, v);
    return res;
  }
};