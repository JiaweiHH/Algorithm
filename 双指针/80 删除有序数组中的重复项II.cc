#include <vector>
using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int l = 1, r = 1, cnt = 1;
    while (r != nums.size()) {
      if (nums[r] == nums[l - 1] && cnt < 2) {
        swap(nums[l++], nums[r]);
        ++cnt;
      } else if (nums[r] != nums[l - 1]) {
        swap(nums[l++], nums[r]);
        cnt = 1;
      }
      ++r;
    }
    return l;
  }
};