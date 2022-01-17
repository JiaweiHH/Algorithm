#include <vector>
using namespace std;

template <int> class Solution;

/// DP，O(n^2)
template <> class Solution<1> {
public:
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[j] < nums[i])
          dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    return dp[n - 1];
  }
};

template <> class Solution<2> {
public:
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size(), len = 1;
    vector<int> dp(n);
    dp[0] = nums[0];
    for (int i = 1; i < n; ++i) {
      if (nums[i] > dp[len - 1]) {
        dp[len++] = nums[i];
        continue;
      }
      int left = 0, right = len - 1;
      while (left < right) {
        int mid = (left + right) / 2;
        if (dp[mid] >= nums[i])
          right = mid;
        else
          left = mid + 1;
      }
      dp[left] = nums[i];
    }
    return len;
  }
};