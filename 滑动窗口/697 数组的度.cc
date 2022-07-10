#include <unordered_map>
#include <vector>
using namespace std;

/// @brief 数组的度定义为数组中出现次数最多的元素的次数
/// 找到一个最短子数组，子数组的度和原数组的度相同

template <int> class Solution;

/// @brief 滑动窗口
template <> class Solution<1> {
public:
  int findShortestSubArray(vector<int> &nums) {
    // 计算数组的度
    unordered_map<int, int> map;
    for (auto n : nums)
      ++map[n];
    int target = 1;
    for (auto [_, v] : map)
      target = max(target, v);
    // 滑动窗口，当窗口中某个元素的出现次数等于 target 的时候就收缩窗口
    unordered_map<int, int> cnt;
    int l = 0, r = 0, res = INT_MAX;
    while (r != nums.size()) {
      ++cnt[nums[r]];
      while (cnt[nums[r]] == target) {
        --cnt[nums[l]];
        res = min(res, r - l + 1);
        ++l;
      }
      ++r;
    }
    return res;
  }
};

/// @brief 哈希表
template <> class Solution<2> {
public:
  int findShortestSubArray(vector<int> &nums) {
    unordered_map<int, tuple<int, int, int>> map;
    int cnt = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (!map.count(nums[i]))
        get<0>(map[nums[i]]) = i;
      get<1>(map[nums[i]]) = i;
      ++get<2>(map[nums[i]]);
      cnt = max(cnt, get<2>(map[nums[i]]));
    }
    int res = INT_MAX;
    for (auto [_, p] : map) {
      if (get<2>(p) == cnt)
        res = min(res, get<1>(p) - get<0>(p) + 1);
    }
    return res;
  }
};