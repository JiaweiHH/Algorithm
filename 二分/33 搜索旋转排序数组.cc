#include <vector>
using namespace std;

template <int> class Solution;

template <> class Solution<1> {
public:
  int search(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = (left + right) >> 1;
      if (nums[left] > target) {     // target 在第二段有序区间
        if (nums[mid] >= nums[left]) // mid 在第一段有序区间
          left = mid + 1;
        else { // mid 在第二段有序区间
          if (nums[mid] > target)
            right = mid - 1;
          else if (nums[mid] < target)
            left = mid + 1;
          else
            return mid;
        }
      } else if (nums[left] < target) { // target 在第一段有序区间
        if (nums[mid] >= nums[left]) {  // mid 在第一段有序区间
          if (nums[mid] > target)
            right = mid - 1;
          else if (nums[mid] < target)
            left = mid + 1;
          else
            return mid;
        } else { // mid 在第二段有序区间
          right = mid - 1;
        }
      } else {
        return left;
      }
    }
    return -1;
  }
};

template <> class Solution<2> {
public:
  int search(vector<int> &nums, int target) {
    int n = nums.size();
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = (left + right) >> 1;
      if (nums[mid] == target)
        return mid;
      if (nums[0] <= nums[mid]) { // mid 位于第一段区间
        if (nums[0] <= target && target < nums[mid]) // target 在 [0, mid] 之间
          right = mid - 1;
        else
          left = mid + 1;
      } else { // mid 位于第二段区间
        if (nums[n - 1] >= target && target > nums[mid])
          left = mid + 1;
        else
          right = mid - 1;
      }
    }
    return -1;
  }
};