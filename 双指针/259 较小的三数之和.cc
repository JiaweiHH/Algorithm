#include <vector>
using namespace std;

class Solution {
public:
  int threeSumSmaller(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int val = target - nums[i];
      int left = i + 1, right = nums.size() - 1;
      while (left < right) {
        int tmp = nums[left] + nums[right];
        if (tmp < val) {
          res += right - left;
          ++left;
        } else {
          --right;
        }
      }
    }
    return res;
  }
};