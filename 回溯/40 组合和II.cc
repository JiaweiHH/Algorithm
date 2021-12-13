#include <vector>

using namespace std;

// 给定一个数组 candidates，数组中的每个元素只能使用一次
// 给出一个数字 target，找出所有组合它们的和是 target

// 这道题和 39 的区别在于这题的元素只能使用一次
// 因此需要多考虑相邻元素相同导致的重复问题
// 1. 对输入数组 candidates 排序
// 2. 搜索的时候考虑吧相邻元素导致的重复问题，这种考虑方法已经用过很多次了，见 90 题
// 3. 搜索的时候考虑在选择了大的元素之后又回去选择小的元素导致的重复问题，这个就是在 39 题考虑的问题
// 4. 正常往下搜索就可以
class Solution {
public:
  vector<vector<int>> res;
  vector<bool> visited;
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<int> tmp;
    visited.resize(candidates.size(), false);
    sort(candidates.begin(), candidates.end());
    dfs(candidates, 0, tmp, target);
    return res;
  }
  void dfs(const vector<int> &candidates, int sum, vector<int> &tmp,
           const int &target) {
    if (sum == target) {
      res.push_back(tmp);
      return;
    }
    for (int i = 0; i < candidates.size(); ++i) {
      if (candidates[i] + sum > target)
        break;
      // 避免出现重复元素时候的重复解
      if (i > 0 && candidates[i] == candidates[i - 1] &&
          visited[i - 1] == false)
        continue;
      // 避免在选择大的元素的时候又往前选择小的元素出现重复解
      if (!tmp.empty() && candidates[i] < *(tmp.end() - 1))
        continue;
      if (!visited[i]) {
        visited[i] = true;
        tmp.push_back(candidates[i]);
        dfs(candidates, sum + candidates[i], tmp, target);
        tmp.pop_back();
        visited[i] = false;
      }
    }
  }
};