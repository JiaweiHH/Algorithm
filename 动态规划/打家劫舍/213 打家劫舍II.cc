#include <vector>
using namespace std;

class Solution {
public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    if (n == 2) return max(nums[0], nums[1]);
    vector<int> dp_odd(n + 1), dp_even(n + 1);
    // 1. 考虑偷第 0 间房屋
    dp_odd[0] = nums[0];
    dp_odd[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n - 1; ++i)
      dp_odd[i] = max(dp_odd[i - 1], dp_odd[i - 2] + nums[i]);
    // 2. 考虑不偷第 0 间房屋
    dp_even[1] = nums[1];
    dp_even[2] = max(nums[1], nums[2]);
    for (int i = 3; i < n; ++i)
      dp_even[i] = max(dp_even[i - 1], dp_even[i - 2] + nums[i]);
    return max(dp_odd[n - 2], dp_even[n - 1]);
  }
};