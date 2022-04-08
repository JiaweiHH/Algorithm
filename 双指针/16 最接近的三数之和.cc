#include <vector>
using namespace std;

class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    int res = 1000;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      int val = target - nums[i];
      int left = i + 1, right = nums.size() - 1;
      while (left < right) {
        int tmp = nums[left] + nums[right];
        res = abs(val - tmp) < abs(res - target) ? tmp + nums[i] : res;
        if (tmp > val) {
          --right;
          while (right > left && nums[right] == nums[right + 1])
            --right;
        } else {
          ++left;
          while (left < right && nums[left] == nums[left - 1])
            ++left;
        }
      }
    }
    return res;
  }
};