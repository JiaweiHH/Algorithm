#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
    int l = lower - 1;
    vector<string> res;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > l + 1) {
        string str = nums[i] - 1 == l + 1
                         ? to_string(l + 1)
                         : to_string(l + 1) + "->" + to_string(nums[i] - 1);
        res.push_back(str);
      }
      l = nums[i];
    }
    if (l < upper)
      res.push_back(l + 1 == upper
                        ? to_string(l + 1)
                        : to_string(l + 1) + "->" + to_string(upper));
    return res;
  }
};