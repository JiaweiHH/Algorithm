#include <vector>
using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int start, end;
    start = find_first(nums, target);
    end = find_last(nums, target);
    return {start, end};
  }
  int find_first(const vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = (left + right) >> 1;
      if (nums[mid] > target)
        right = mid - 1;
      else if (nums[mid] < target)
        left = mid + 1;
      else
        right = mid - 1;
    }
    if (left == nums.size() || nums[left] != target)
      return -1;
    return left;
  }
  int find_last(const vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = (left + right) >> 1;
      if (nums[mid] > target)
        right = mid - 1;
      else if (nums[mid] < target)
        left = mid + 1;
      else
        left = mid + 1;
    }
    if (right == -1 || nums[right] != target)
      return -1;
    return right;
  }
};