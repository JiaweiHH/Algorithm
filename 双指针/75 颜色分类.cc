#include <vector>
using namespace std;

template <int> class Solution;

/// @brief 遍历两次，第一次将所有 0 放到数组开头，第二次将所有 1 放到数组开头
template <> class Solution<1> {
public:
  void sortColors(vector<int> &nums) {
    int p = 0;
    for (int i = 0; i < nums.size(); ++i)
      if (nums[i] == 0)
        swap(nums[i], nums[p++]);
    for (int i = p; i < nums.size(); ++i)
      if (nums[i] == 1)
        swap(nums[i], nums[p++]);
  }
};

/// @brief 一次遍历，循环的将 2 放到后面，然后将 0 放到前面
template <> class Solution<2> {
public:
  void sortColors(vector<int> &nums) {
    int pA = 0, pB = nums.size() - 1;
    for (int i = 0; i <= pB; ++i) {
      // 不断循环判断，直到 `nums[i] != 2`
      while (nums[i] == 2 && pB >= i)
        swap(nums[i], nums[pB--]);
      // 对于 0 只需要判断一次，因为 i 前面不可能出现 2
      if (nums[i] == 0)
        swap(nums[i], nums[pA++]);
    }
  }
};