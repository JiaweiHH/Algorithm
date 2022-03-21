#include <vector>
using namespace std;

template <int> class Solution;

template <> class Solution<1> {
public:
  int findMin(vector<int> &nums) {
    int l = 0, r = nums.size() - 1;
    int left_min = nums[l], right_max = nums[r];
    while (l <= r) {
      int mid = (l + r) / 2;
      if (mid > 0 && nums[mid] < nums[mid - 1])
        return nums[mid];
      if (nums[mid] > right_max)
        l = mid + 1;
      else
        r = mid - 1;
    }
    return left_min;
  }
};

/// 官方的二分查找
template <> class Solution<2> {
public:
  int findMin(vector<int> &nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int mid = (l + r) / 2;
      if (nums[mid] > nums[r])
        l = mid + 1;
      else
        r = mid;
    }
    return nums[r];
  }
};

/// 方法二一样的思路，但是修改遍历条件
template <> class Solution<3> {
public:
  int findMin(vector<int> &nums) {
    int l = 0, r = nums.size() - 1;
    int right_max = nums[r];
    while (l <= r) {
      int mid = (l + r) / 2;
      if (nums[mid] > right_max)
        l = mid + 1;
      else
        r = mid - 1;
    }
    return nums[l];
  }
};