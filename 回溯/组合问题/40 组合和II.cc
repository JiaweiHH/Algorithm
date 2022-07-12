#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> res;
  void dfs(vector<int> &candidates, vector<int> &tmp, int target, int cnt,
           int idx) {
    if (target == cnt) {
      res.push_back(tmp);
      return;
    }
    for (int i = idx; i < candidates.size(); ++i) {
      if (cnt + candidates[i] > target)
        break;
      // 同一层回溯去重，注意只有当 i > idx 的时候
      if (i > idx && candidates[i] == candidates[i - 1])
        continue;
      tmp.push_back(candidates[i]);
      dfs(candidates, tmp, target, cnt + candidates[i], i + 1);
      tmp.pop_back();
    }
  }
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> tmp;
    dfs(candidates, tmp, target, 0, 0);
    return res;
  }
};