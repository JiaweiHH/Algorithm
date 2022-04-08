#include <vector>
using namespace std;

class Solution {
public:
  vector<int> sortedSquares(vector<int> &nums) {
    int l = -1, r = -1, idx = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (abs(nums[i] < abs(nums[idx])))
        idx = i;
    }
    l = idx - 1;
    r = idx;
    vector<int> res;
    while (l >= 0 && r < nums.size()) {
      if (abs(nums[l]) > abs(nums[r])) {
        res.push_back(nums[r] * nums[r]);
        ++r;
      } else {
        res.push_back(nums[l] * nums[l]);
        --l;
      }
    }
    while (l >= 0) {
      res.push_back(nums[l] * nums[l]);
      --l;
    }
    while (r < nums.size()) {
      res.push_back(nums[r] * nums[r]);
      ++r;
    }
    return res;
  }
};