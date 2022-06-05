#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  int pivotIndex(vector<int> &nums) {
    int total_cnt = accumulate(nums.begin(), nums.end(), 0);
    int prefix = 0;
    for (int i = 0; i < nums.size(); ++i) {
      prefix += nums[i];
      if (prefix - nums[i] == total_cnt - prefix)
        return i;
    }
    return -1;
  }
};