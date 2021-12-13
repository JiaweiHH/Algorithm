#include <algorithm>
#include <vector>

using namespace std;

// 给定一个数组 nums，输出它的全排列，排列中可能有重复的顺序，此时去掉重复的顺序

// 类似于 90 题——数组的所有子集
// 这里也是判断当前打算选择的元素和上一个元素是不是相等，由于这里代码写的总是会先选择一次前面的元素
// 因此考虑如下的情况：没有选择前面一个重复的元素，但是选择后面这个相等的元素
// 那么此时的排列一定是被选择前面这个相等的元素的排列输出过了，所以需要跳过选择当前元素
// note: 感觉这种方法去掉回溯里面的重复解挺实用的
class Solution {
public:
  vector<vector<int>> res;
  vector<int> visited;
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<int> tmp;
    visited.resize(nums.size(), false);
    sort(nums.begin(), nums.end());
    dfs(nums, 0, tmp);
    return res;
  }
  void dfs(const vector<int> &nums, int index, vector<int> &tmp) {
    if (index == nums.size()) {
      res.push_back(tmp);
      return;
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])
        continue;
      if (!visited[i]) {
        visited[i] = true;
        tmp.push_back(nums[i]);
        dfs(nums, index + 1, tmp);
        visited[i] = false;
        tmp.pop_back();
      }
    }
  }
};