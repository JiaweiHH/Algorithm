#include <vector>
using namespace std;

class Solution {
public:
  int singleNonDuplicate(vector<int> &nums) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (mid > 0 && nums[mid] == nums[mid - 1]) {
        if (mid % 2 == 0)
          r = mid - 2;
        else
          l = mid + 1;
      } else if (mid + 1 < nums.size() && nums[mid] == nums[mid + 1]) {
        if (mid % 2 == 1)
          r = mid - 1;
        else
          l = mid + 2;
      } else {
        return nums[mid];
      }
    }
    return -1;
  }
};