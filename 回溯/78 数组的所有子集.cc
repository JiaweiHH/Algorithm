#include <vector>

using namespace std;

// 给定一个数组，输出这个数组的所有子集

// dfs 对于每个元素都有选或者不选两种选择
class Solution {
public:
  vector<vector<int>> res;
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<int> tmp;
    dfs(nums, 0, tmp);
    return res;
  }
  void dfs(const vector<int> &nums, int index, vector<int> &tmp) {
    if (index == nums.size()) {
      res.push_back(tmp);
      return;
    }
    for (int i = 0; i < 2; ++i) {
      if (i == 0) {
        tmp.push_back(nums[index]);
        dfs(nums, index + 1, tmp);
        tmp.pop_back();
      } else {
        dfs(nums, index + 1, tmp);
      }
    }
  }
};