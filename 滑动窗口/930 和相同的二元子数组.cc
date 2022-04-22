#include <unordered_map>
#include <vector>
using namespace std;

template <int> class Solution;

/// 滑动窗口 1：前缀和的思想
template <> class Solution<1> {
public:
  int numSubarraysWithSum(vector<int> &nums, int goal) {
    return nums_goal(nums, goal) - nums_goal(nums, goal - 1);
  }
  int nums_goal(const vector<int> &nums, int goal) {
    int l = 0, r = 0, res = 0;
    int count = 0;
    while (l <= r && r != nums.size()) {
      count += nums[r];
      while (count > goal) {
        count -= nums[l];
        ++l;
      }
      res += r - l + 1;
      ++r;
    }
    return res;
  }
};

/// 滑动窗口 2：同样也是前缀和的思想
template <> class Solution<2> {
public:
  int numSubarraysWithSum(vector<int> &nums, int goal) {
    int l1 = 0, l2 = 0, r = 0;
    int count1 = 0, count2 = 0;
    int res = 0;
    while (r != nums.size()) {
      count1 += nums[r];
      while (l1 <= r && count1 > goal) {
        count1 -= nums[l1];
        ++l1;
      } // 循环结束的时候 [l1, r] 的子数组和恰好等于 goal
      count2 += nums[r];
      while (l2 <= r && count2 >= goal) {
        count2 -= nums[l2];
        ++l2;
      } // 循环结束的时候 [l2, r] 的子数组和恰好小于 goal
      res += l2 - l1; // l1, l2 中任何一个作为 r 的左边界都可以
      ++r;
    }
    return res;
  }
};

/// 哈希
template <> class Solution<3> {
public:
  int numSubarraysWithSum(vector<int> &nums, int goal) {
    unordered_map<int, int> map;
    int cnt = 0, res = 0;
    for (int i = 0; i < nums.size(); ++i) {
      map[cnt]++;
      cnt += nums[i];
      res += map[cnt - goal];
    }
    return res;
  }
};