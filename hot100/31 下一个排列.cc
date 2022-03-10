#include <vector>
using namespace std;

class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    int left = -1, right;
    for (int i = nums.size() - 1; i > 0; --i) {
      if (nums[i] > nums[i - 1]) {
        left = i - 1;
        break;
      }
    }
    if (left >= 0) {
      for (int j = nums.size() - 1; j >= left + 1; --j) {
        if (nums[j] > nums[left]) {
          right = j;
          break;
        }
      }
      swap(nums[left], nums[right]);
      reverse(nums.begin() + left + 1, nums.end());
    } else {
      reverse(nums.begin(), nums.end());
    }
  }
};