#include <vector>
using namespace std;

/// @brief 旋转数组类题目汇总
/// https://leetcode.cn/problems/search-rotate-array-lcci/solution/xuan-zhuan-shu-zu-cong-yi-dao-nan-ge-ge-dcv7a/

template <int> class Solution;

///  @brief 开辟额外空间
/// 原数组中第 i 个位置的元素在新数组中的位置是 (i + k) % n
template <> class Solution<1> {
public:
  void rotate(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> vec(n);
    for (int i = 0; i < n; ++i)
      vec[(i + k) % n] = nums[i];
    nums.assign(vec.begin(), vec.end());
  }
};

/// @brief 原地置换
/// 1. 置换整个数组; 2. 置换 [0, k); 3. 置换 [k, nums.size())
template <> class Solution<2> {
public:
  void rotate(vector<int> &nums, int k) {
    k = k % nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
  }
};

/// @brief 手动实现置换算法
template <> class Solution<3> {
public:
  void reverse(vector<int> &nums, int l, int r) {
    while (l <= r)
      swap(nums[l++], nums[r--]);
  }
  void rotate(vector<int> &nums, int k) {
    k = k % nums.size();
    reverse(nums, 0, nums.size() - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, nums.size() - 1);
  }
};