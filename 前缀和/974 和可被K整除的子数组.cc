#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int subarraysDivByK(vector<int> &nums, int k) {
    int prefix = 0, res = 0;
    unordered_map<int, int> map;
    map[0] = 1;
    for (int i = 0; i < nums.size(); ++i) {
      prefix = (prefix + nums[i]) % k;
      if (prefix < 0)
        prefix = (prefix + k) % k;
      if (map.count(prefix))
        res += map[prefix];
      ++map[prefix];
    }
    return res;
  }
};