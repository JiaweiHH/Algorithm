#include <vector>
using namespace std;

class Solution {
public:
  int findPeakElement(vector<int> &nums) {
    int l = 0, r = nums.size() - 1;
    nums.push_back(INT_MIN);
    while (l <= r) {
      int mid = (l + r) / 2;
      if (nums[mid] < nums[mid + 1])
        l = mid + 1;
      else
        r = mid - 1;
    }
    return l;
  }
};