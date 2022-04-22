#include <vector>
using namespace std;

class Solution {
public:
  int numberOfSubarrays(vector<int> &nums, int k) {
    return number_k(nums, k) - number_k(nums, k - 1);
  }
  int number_k(const vector<int> &nums, int k) {
    int l = 0, r = 0;
    int valid = 0, res = 0;
    while (r != nums.size()) {
      if (nums[r] % 2 == 1)
        ++valid;
      while (valid > k) {
        if (nums[l] % 2 == 1)
          --valid;
        ++l;
      }
      res += r - l + 1;
      ++r;
    }
    return res;
  }
};