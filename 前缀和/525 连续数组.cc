#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int findMaxLength(vector<int> &nums) {
    for_each(nums.begin(), nums.end(), [](int &val) {
      if (val == 0)
        val = -1;
    });
    int prefix = 0, res = 0;
    unordered_map<int, int> map;
    map[0] = -1;
    for (int i = 0; i < nums.size(); ++i) {
      prefix += nums[i];
      if (map.count(prefix))
        res = max(res, i - map[prefix]);
      else
        map[prefix] = i;
    }
    return res == 1 ? 0 : res;
  }
};