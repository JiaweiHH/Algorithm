#include <vector>
using namespace std;

/// @brief 33, 81 是一组
/// 81 相对于 33 多了 nums[mid] == nums[r] && l != r 的判断

class Solution {
public:
  bool search(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      // nums[mid] == nums[r] 的时候，此时由于不知道 nums[mid]
      // 是在左侧区间还是在右侧区间，因此简单的对 r--.
      // 如果左侧还有一个 nums[mid] 存在的话不会影响最终的结果，
      // 如果不存在的话也不会影响，因为这里对 l != r 做了判断
      if (nums[mid] == nums[r] && l != r) {
        --r;
        continue;
      }
      if (nums[mid] > nums[r]) {
        if (nums[l] <= target && target < nums[mid])
          r = mid - 1;
        else
          l = mid + 1;
      } else {
        if (nums[mid] <= target && target <= nums[r])
          l = mid + 1;
        else
          r = mid - 1;
      }
    }
    return r < 0 || nums[r] != target ? false : true;
  }
};