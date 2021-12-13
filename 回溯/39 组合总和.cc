#include <vector>

using namespace std;

// 给定一个数组，数组中的元素可以使用任意次，找出能够组合出总和等于 target 的所有组合

// DFS
class Solution {
public:
  vector<vector<int>> res;
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> tmp;
    dfs(candidates, 0, tmp, target);
    return res;
  }
  void dfs(const vector<int> &candidates, int sum, vector<int> &tmp,
           const int &target) {
    if (sum == target) {
      res.push_back(tmp);
      return;
    }
    for (const auto &n : candidates) {
      // 避免往前选，出现重复的排列
      if (!tmp.empty() && n < *(tmp.end() - 1))
        continue;
      if (sum + n <= target) {
        tmp.push_back(n);
        dfs(candidates, sum + n, tmp, target);
        tmp.pop_back();
      } else {
        break;
      }
    }
  }
};