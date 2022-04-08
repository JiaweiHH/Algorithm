#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i = 0; i < nums.size(); ++i) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      int val = target - nums[i];
      threeSum(nums, i + 1, nums.size() - 1, val, res, nums[i]);
    }
    return res;
  }
  void threeSum(vector<int> &nums, int l, int r, int target,
                vector<vector<int>> &res, int val0) {
    for (int i = l; i <= r; ++i) {
      if (i > l && nums[i] == nums[i - 1])
        continue;
      int val = target - nums[i];
      int left = i + 1, right = r;
      while (left < right) {
        if (nums[left] + nums[right] == val) {
          res.push_back({val0, nums[i], nums[left], nums[right]});
          ++left;
          while (left < right && nums[left] == nums[left - 1])
            ++left;
        } else if (nums[left] + nums[right] < val) {
          ++left;
        } else {
          --right;
        }
      }
    }
  }
};