#include <vector>
using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int first_idx, last_idx;
    first_idx = first_search(nums, target);
    last_idx = last_search(nums, target);
    return {first_idx, last_idx};
  }
  int first_search(const vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (nums[mid] >= target)
        r = mid - 1;
      else
        l = mid + 1;
    }
    return l == nums.size() || nums[l] != target ? -1 : l;
  }
  int last_search(const vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (nums[mid] > target)
        r = mid - 1;
      else
        l = mid + 1;
    }
    return r < 0 || nums[r] != target ? -1 : r;
  }
};