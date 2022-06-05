#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int maxSubArrayLen(vector<int> &nums, int k) {
    long long prefix = 0;
    unordered_map<int64_t, int> map;
    map[0] = -1;
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
      prefix += nums[i];
      if (map.count(prefix - k))
        res = max(res, i - map[prefix - k]);
      if (!map.count(prefix))
        map[prefix] = i;
    }
    return res;
  }
};