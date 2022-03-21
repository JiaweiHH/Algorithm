#include <vector>
using namespace std;

template <int> class Solution;

template <> class Solution<1> {
public:
  int findMin(vector<int> &nums) {
    int l = 0, r = nums.size() - 1;
    while (l < nums.size() - 1 && nums[l] == nums[l + 1])
      ++l;
    while (l <= r && r > 0 && nums[l] == nums[r])
      --r;
    int left_min = nums[l], right_max = nums[r];
    int tmp_l = l;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (mid > tmp_l && nums[mid] < nums[mid - 1])
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
      else if (nums[mid] < nums[r])
        r = mid;
      else
        --r;
    }
    return nums[l];
  }
};