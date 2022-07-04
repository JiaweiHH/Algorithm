#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i = 0; i < nums.size(); ++i) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      int l = i + 1, r = nums.size() - 1, target = -nums[i];
      while (l < r) {
        if (nums[l] + nums[r] > target)
          --r;
        else if (nums[l] + nums[r] < target)
          ++l;
        else {
          res.push_back({nums[i], nums[l], nums[r]});
          ++l;
          --r;
          while (r < nums.size() - 1 && r > l && nums[r] == nums[r + 1])
            --r;
          while (l > 0 && l < r && nums[l] == nums[l - 1])
            ++l;
        }
      }
    }
    return res;
  }
};