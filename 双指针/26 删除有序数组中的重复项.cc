#include <vector>
using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int ptr = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (i == 0) {
        ++ptr;
        continue;
      }
      if (i > 0 && nums[i] == nums[ptr - 1])
        continue;
      swap(nums[ptr++], nums[i]);
    }
    return ptr;
  }
};