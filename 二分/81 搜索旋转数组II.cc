#include <vector>
using namespace std;

class Solution {
public:
  bool search(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l < r && nums[l] == nums[l + 1])
      ++l;
    while (l < r && nums[l] == nums[r])
      --r;
    int left_min = nums[l], right_max = nums[r];
    while (l <= r) {
      int mid = (l + r) / 2;
      if (nums[mid] == target)
        return true;
      if (target > right_max) {
        if (nums[mid] > target)
          r = mid - 1;
        else if (nums[mid] < target && nums[mid] > right_max)
          l = mid + 1;
        else
          r = mid - 1;
      } else {
        if (nums[mid] < target)
          l = mid + 1;
        else if (nums[mid] > target && nums[mid] > right_max)
          l = mid + 1;
        else
          r = mid - 1;
      }
    }
    return false;
  }
};