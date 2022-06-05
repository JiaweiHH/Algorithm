#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    int prefix = 0, res = 0;
    unordered_map<int, int> map;
    map[0] = 1;
    for (int i = 0; i < nums.size(); ++i) {
      prefix += nums[i];
      if (map.count(prefix - k))
        res += map[prefix - k];
      ++map[prefix];
    }
    return res;
  }
};