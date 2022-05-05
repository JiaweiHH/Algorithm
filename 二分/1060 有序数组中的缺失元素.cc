#include <vector>
using namespace std;

class Solution {
public:
  int missingElement(vector<int> &nums, int k) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (nums[mid] - nums[0] - mid >= k)
        r = mid - 1;
      else
        l = mid + 1;
    }
    int cnt = nums[l - 1] - nums[0] - (l - 1);
    return nums[l - 1] + k - cnt;
  }
};