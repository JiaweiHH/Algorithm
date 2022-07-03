#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

template <int> class Solution;

/**
 * @brief 1. 哈希表 {key -> min heap} 2. 贪心
 *
 * 哈希 + 最小堆 (O(nlogn), O(n))：
 * 对于 nums[i] 判断 nums[i] - 1 是否存在哈希表中，如果存在则将 nums[i] 并入
 * nums[i] - 1 为结尾的数组。否则的话新增一个以 nums[i] 结尾的数组
 *
 * 贪心 (O(n), O(n))：两个哈希表分别记录
 * 1. 所有数字出现的次数
 * 2. 以 nums[i] 为结尾的数组的数量
 * 对于 nums[i] 首先判断是否存在 nums[i - 1] 为结尾的数组，如果有则并入;
 * 否则的话，判断 nums[i], nums[i - 1], nums[i - 2]
 * 能否组成一个新的数组，如果可以则创建一个新的数组，否则说明不可能组成长度为 3
 * 的连续子数组（返回 false）
 */

/// @brief 哈希表 + 最小堆 模拟
/// 哈希表 key: 以 key 结尾的数组，value: 所有以 key 结尾的数组长度集合
template <> class Solution<1> {
public:
  // O(nlogn), O(n)
  bool isPossible(vector<int> &nums) {
    using MIN_HEAP = priority_queue<int, vector<int>, greater<int>>;
    // key: 以 key 结尾的子数组，value: 所有以 key 结尾的数组的长度
    unordered_map<int, MIN_HEAP> map;
    for (int i = 0; i < nums.size(); ++i) {
      if (!map.count(nums[i] - 1)) {
        map[nums[i]].push(1);
        continue;
      }
      auto &heap = map[nums[i] - 1];
      map[nums[i]].push(heap.top() + 1);
      heap.pop();
      if (heap.size() == 0)
        map.erase(nums[i] - 1);
    }
    for (auto it = map.begin(); it != map.end(); ++it)
      if (it->second.top() < 3)
        return false;
    return true;
  }
};

/// @brief 贪心
/// 能合并就合并，不能合并就新建一个长度为 3 的数组
template <> class Solution<2> {
public:
  bool isPossible(vector<int> &nums) {
    unordered_map<int, int> remain, cnt;
    for (auto n : nums)
      ++remain[n];
    for (auto n : nums) {
      if (remain[n] == 0)
        continue;
      if (cnt.count(n - 1)) {
        // n 并入以 n - 1 为结尾的子数组
        if (--cnt[n - 1] == 0)
          cnt.erase(n - 1);
        ++cnt[n];
        --remain[n];
      } else {
        // n 并入以 n + 2 为结尾的子数组
        if (remain[n + 1] > 0 && remain[n + 2] > 0) {
          --remain[n];
          --remain[n + 1];
          --remain[n + 2];
          ++cnt[n + 2];
        } else {
          return false;
        }
      }
    }
    return true;
  }
};