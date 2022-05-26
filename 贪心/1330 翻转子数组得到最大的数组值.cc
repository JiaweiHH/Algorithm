#include <vector>
using namespace std;

class Solution {
public:
  int maxValueAfterReverse(vector<int> &nums) {
    int sum = 0;
    for (int i = 0; i < nums.size() - 1; ++i)
      sum += abs(nums[i] - nums[i + 1]);
    int min_val = INT_MIN, max_val = INT_MAX;
    for (int i = 0; i < nums.size() - 1; ++i) {
      min_val = max(min_val, min(nums[i], nums[i + 1]));
      max_val = min(max_val, max(nums[i], nums[i + 1]));
    }
    int diff = 2 * min_val - 2 * max_val;
    for (int i = 1; i < nums.size(); ++i) {
      // 翻转 [0, i - 1]
      int val_1 = -abs(nums[i] - nums[i - 1]) + abs(nums[i] - nums[0]);
      // 翻转 [i, n - 1]
      int val_2 = -abs(nums[i - 1] - nums[i]) +
                  abs(nums[nums.size() - 1] - nums[i - 1]);
      diff = max({diff, val_1, val_2});
    }
    return sum + max(diff, 0);
  }
};