#include <vector>
using namespace std;

class Solution {
public:
  int findMin(vector<int> &nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int mid = (l + r) / 2;
      if (nums[mid] > nums[r])
        l = mid + 1;
      else // nums[mid] <= nums[r], mid 有可能是最小值
        r = mid;
    }
    return nums[l];
  }
};