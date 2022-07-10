#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> summaryRanges(vector<int> &nums) {
    if (nums.size() == 0)
      return {};
    vector<string> res;
    int l = nums[0], r = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > r + 1) {
        string str = l == r ? to_string(l) : to_string(l) + "->" + to_string(r);
        res.push_back(str);
        l = nums[i];
      }
      r = nums[i];
    }
    res.push_back(l == r ? to_string(l) : to_string(l) + "->" + to_string(r));
    return res;
  }
};