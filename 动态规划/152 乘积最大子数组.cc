#include <vector>
using namespace std;

class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int min_val = nums[0], max_val = nums[0], res = max(min_val, max_val);
    for (int i = 1; i < nums.size(); ++i) {
      int tmp1 = min_val, tmp2 = max_val;
      min_val = min({tmp1 * nums[i], tmp2 * nums[i], nums[i]});
      max_val = max({tmp1 * nums[i], tmp2 * nums[i], nums[i]});
      res = max({res, min_val, max_val});
    }
    return res;
  }
};