#include <vector>
using namespace std;

/// @brief 153, 154 是一组，对比 33, 81 这两题的代码更加简单
/// 重复元素不管是 81 还是 154 都需要对 nums[mid] == nums[r] 做特殊判断
/// 判断之后的操作都是 --r
/// 153, 154 的 while 条件是 l < r
class Solution {
public:
  int findMin(vector<int> &nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int mid = (l + r) / 2;
      if (nums[mid] > nums[r])
        l = mid + 1;
      else if (nums[mid] < nums[r])
        r = mid;
      else // 无法确定丢弃左半部分还是有半部分
        --r;
    }
    return nums[l];
  }
};

/// @brief 进阶：输出旋转的位置
/// 注意上面的算法只能确定旋转的元素值，但是没法直接确定旋转元素的位置
/// 一种方法是直接从 nums.size() - 1 开始倒着找 nums[l] 出现的位置
/// 或者使用下面给出的方法
int func(vector<int> &arr) {
  int n = arr.size();
  // 找到旋转位置下标
  int l = 0, r = n - 1, start_idx = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (arr[mid] > arr[r])
      l = mid + 1;
    else if (arr[mid] < arr[r]) {
      start_idx = max(start_idx, r + 1);
      r = mid;
    } else {
      --r;
    }
  }
  start_idx = start_idx == n || arr[start_idx] != arr[l] ? l : start_idx;
}