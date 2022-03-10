#include <vector>
using namespace std;

template <int> class Solution;

/// 哈希
template <> class Solution<1> {
public:
  int firstMissingPositive(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i)
      if (nums[i] <= 0)
        nums[i] = n + 1;
    for (int i = 0; i < n; ++i) {
      // 标记数组的下标作为类似于 “哈希” 的作用
      int tmp = abs(nums[i]);
      if (tmp <= n)
        nums[tmp - 1] = -abs(nums[tmp - 1]);
    }
    for (int i = 0; i < n; ++i) {
      if (nums[i] > 0)
        return i + 1;
    }
    return n + 1;
  }
};

/// 置换法
template <> class Solution<2> {
public:
  int firstMissingPositive(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      while (nums[i] > 0 && nums[i] < n && nums[nums[i] - 1] != nums[i])
        swap(nums[i], nums[nums[i] - 1]);
    }
    for (int i = 0; i < n; ++i) {
      if (nums[i] != i + 1)
        return i + 1;
    }
    return n + 1;
  }
};