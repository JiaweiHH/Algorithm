#include <vector>
using namespace std;

/// @brief 给你一个仅由整数组成的有序数组，其中每个元素都会出现两次，唯有一个数只会出现一次
/// 请你找出并返回只出现一次的那个数，解决方案必须满足 O(log n) 时间复杂度和 O(1) 空间复杂度

/// 1. 如果 mid 为奇数并且 nums[mid] != nums[mid - 1]，则说明出现一次的数在 mid 的左侧，否则出现在右侧
/// 2. 如果 mid 为偶数并且 nums[mid] != nums[mid + 1]，则说明出现一次的数在 mid 的左侧，否则出现在右侧
class Solution {
public:
  int singleNonDuplicate(vector<int> &nums) {
    int left = 0, right = nums.size();
    while (left != right) {
      int mid = (left + right) / 2;
      if (mid % 2 == 1) {
        if (nums[mid] != nums[mid - 1])
          right = mid;
        else
          left = mid + 1;
      } else {
        if (mid != nums.size() - 1 && nums[mid] != nums[mid + 1])
          right = mid;
        else
          left = mid + 1;
      }
    }
    return left == nums.size() ? nums[nums.size() - 1] : nums[left];
  }
};