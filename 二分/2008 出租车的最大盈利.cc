#include <vector>
using namespace std;

class Solution {
public:
  long long maxTaxiEarnings(int n, vector<vector<int>> &rides) {
    sort(rides.begin(), rides.end(),
         [](vector<int> &lhs, vector<int> &rhs) { return lhs[1] < rhs[1]; });
    vector<int64_t> dp(rides.size());
    dp[0] = rides[0][1] - rides[0][0] + rides[0][2];
    for (int i = 1; i < rides.size(); ++i) {
      int l = 0, r = i - 1;
      while (l <= r) {
        int mid = (l + r) / 2;
        if (rides[mid][1] <= rides[i][0])
          l = mid + 1;
        else
          r = mid - 1;
      }
      int profit = rides[i][1] - rides[i][0] + rides[i][2];
      int64_t val_1 = dp[i - 1], val_2 = r >= 0 ? dp[r] + profit : profit;
      dp[i] = max({dp[i], val_1, val_2});
    }
    return dp[rides.size() - 1];
  }
};