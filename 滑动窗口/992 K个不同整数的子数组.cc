#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int subarraysWithKDistinct(vector<int> &nums, int k) {
    return slide_window(nums, k) - slide_window(nums, k - 1);
  }
  int slide_window(const vector<int> &nums, int k) {
    if (k == 0)
      return 0;
    int l = 0, r = 0, res = 0;
    unordered_map<int, int> map;
    while (r != nums.size()) {
      int val = nums[r];
      ++map[val];
      while (map.size() > k) {
        if (--map[nums[l]] == 0)
          map.erase(nums[l]);
        ++l;
      }
      res += r - l + 1;
      ++r;
    }
    return res;
  }
};