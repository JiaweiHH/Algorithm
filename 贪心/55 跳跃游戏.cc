#include <vector>
using namespace std;

class Solution {
public:
  bool canJump(vector<int> &nums) {
    int right_most = 0;
    for (int i = 0; i <= right_most && i < nums.size(); ++i)
      right_most = max(right_most, i + nums[i]);
    return right_most >= nums.size() - 1;
  }
};