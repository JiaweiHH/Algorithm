#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int minOperations(vector<int> &nums, int x) {
    int sum = accumulate(nums.begin(), nums.end(), 0), target = sum - x;
    if (target < 0)
      return -1;
    int l = 0, r = 0, res = INT_MAX, count = 0;
    int sz = nums.size();
    while (r != sz) {
      count += nums[r];
      while (count > target) {
        count -= nums[l];
        ++l;
      }
      if (count == target)
        res = min(res, l + sz - 1 - r);
      ++r;
    }
    return res == INT_MAX ? -1 : res;
  }
};