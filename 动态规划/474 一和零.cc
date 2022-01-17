#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int findMaxForm(vector<string> &strs, int m, int n) {
    vector<pair<int, int>> nums;
    for_each(strs.begin(), strs.end(), [&nums](const string &str) {
      int zero = 0, one = 0;
      for (auto &c : str) {
        if (c == '0')
          zero++;
        else
          one++;
      }
      nums.push_back(make_pair(zero, one));
    });
    // 二维容量的背包
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = m; j >= nums[i].first; --j) {
        for (int k = n; k >= nums[i].second; --k)
          dp[j][k] =
              max(dp[j][k], dp[j - nums[i].first][k - nums[i].second] + 1);
      }
    }
    return dp[m][n];
  }
};