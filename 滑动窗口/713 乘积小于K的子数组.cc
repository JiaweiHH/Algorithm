#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    if (k == 0)
      return 0;
    int l = 0, r = 0, res = 0;
    int mul = 1;
    while (r != nums.size()) {
      mul *= nums[r];
      while (mul >= k) {
        mul /= nums[l];
        ++l;
      }
      res += r - l + 1;
      ++r;
    }
    return res <= 0 ? 0 : res;
  }
};