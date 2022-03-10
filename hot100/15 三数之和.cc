#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      int target = -nums[i];
      int left = i + 1, right = nums.size() - 1;
      while (left < right) {
        if (nums[left] + nums[right] > target)
          right--;
        else if (nums[left] + nums[right] < target)
          left++;
        else {
          res.push_back({nums[i], nums[left], nums[right]});
          left++;
          right--;
          while (left > 0 && left < right && nums[left] == nums[left - 1])
            left++;
          while (right < nums.size() - 1 && right > left &&
                 nums[right] == nums[right + 1])
            right--;
        }
      }
    }
    return res;
  }
};