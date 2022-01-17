#include <vector>
using namespace std;

template <int> class Solution;

/// 贪心
template <> class Solution<1> {
public:
  int findLengthOfLCIS(vector<int> &nums) {
    int res = 1, cur = 1;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) {
        cur++;
        res = max(res, cur);
      } else {
        cur = 1;
      }
    }
    return res;
  }
};