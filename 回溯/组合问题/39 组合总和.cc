#include <vector>
using namespace std;

/// @brief 取出重复有多种方法
/// 1. 排序之后，!tmp.empty() && candidates[i] == tmp.back()
/// 2. 可以不需要排序，利用子集的方式保证后续回溯只能从前一个回溯的元素开始查找

class Solution {
public:
  vector<vector<int>> res;
  void dfs(vector<int> &candidates, vector<int> &tmp, int target, int cnt,
           int idx) {
    if (cnt == target) {
      res.push_back(tmp);
      return;
    }
    for (int i = idx; i < candidates.size(); ++i) {
      if (cnt + candidates[i] > target)
        break;
      tmp.push_back(candidates[i]);
      dfs(candidates, tmp, target, cnt + candidates[i], i);
      tmp.pop_back();
    }
  }
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<int> tmp;
    sort(candidates.begin(), candidates.end());
    dfs(candidates, tmp, target, 0, 0);
    return res;
  }
};