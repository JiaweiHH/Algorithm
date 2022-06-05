#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  bool checkSubarraySum(vector<int> &nums, int k) {
    int cur_prefix = 0, pre_prefix = 0;
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
      cur_prefix = (cur_prefix + nums[i]) % k;
      if (map.count(cur_prefix))
        return true;
      ++map[pre_prefix];
      pre_prefix = cur_prefix;
    }
    return false;
  }
};