#include <vector>
using namespace std;

template <int> class Solution;

template <> class Solution<1> {
public:
  bool canJump(vector<int> &nums) {
    int n = nums.size();
    vector<bool> dp(n);
    dp[n - 1] = true;
    for (int i = n - 2; i >= 0; --i) {
      for (int j = i + 1; j <= i + nums[i]; ++j) {
        if (dp[j]) {
          dp[i] = true;
          break;
        }
      }
    }
    return dp[0];
  }
};

template <> class Solution<2> {
public:
  bool canJump(vector<int> &nums) {
    int rightmost = 0;
    for (int i = 0; i <= rightmost; ++i) {
      rightmost = max(rightmost, i + nums[i]);
      if (rightmost >= nums.size() - 1)
        return true;
    }
    return false;
  }
};