#include <numeric>
#include <vector>
using namespace std;

/// 给你一个整数数组 nums 和一个整数 k，选择数组中的某一个元素取反
/// 重复 k 次，每次可以选择同一个元素，返回修改后的数组的最大和

/// 将原数组按照绝对值从大到小排序，然后遍历数组选择负数取反，并对 k 减一
/// 如果遍历一遍数组之后发现 k 仍旧大于 0，那么就重复取反数组的最后一个元素
class Solution {
public:
  int largestSumAfterKNegations(vector<int> &nums, int k) {
    auto cmp = [](const int &lhs, const int &rhs) {
      return abs(lhs) > abs(rhs);
    };
    sort(nums.begin(), nums.end(), cmp);
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] < 0 && k) {
        nums[i] = -nums[i];
        k--;
      }
    }
    while (k--) {
      nums[nums.size() - 1] = -nums[nums.size() - 1];
    }
    return accumulate(nums.begin(), nums.end(), 0);
  }
};