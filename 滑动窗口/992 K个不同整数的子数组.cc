#include <unordered_map>
#include <vector>
using namespace std;

/// @brief 滑动窗口
/// 恰好有 k 个可以转化为：最多有 k 个 - 最多有 k-1 个
class Solution {
public:
  // func 函数统计 nums 中最多包含 k 个不同数字的数组的数量
  int func(vector<int> &nums, int k) {
    unordered_map<int, int> map;
    int l = 0, r = 0, cnt = 0;
    while (r != nums.size()) {
      ++map[nums[r]];
      while (map.size() > k) {
        if (--map[nums[l]] == 0)
          map.erase(nums[l]);
        ++l;
      }
      // 考虑以 nums[r] 为右端点的子数组的数量
      cnt += r - l + 1;
      ++r;
    }
    return cnt;
  }
  int subarraysWithKDistinct(vector<int> &nums, int k) {
    return func(nums, k) - func(nums, k - 1);
  }
};