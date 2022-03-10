#include <vector>
using namespace std;

template <int> class Solution;

template <> class Solution<1> {
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

template <> class Solution<2> {
public:
  vector<vector<int>> res;
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<int> cur;
    dfs(candidates, cur, target, 0, 0);
    return res;
  }
  void dfs(const vector<int> &candidates, vector<int> &cur, int target,
           int index, int sum) {
    if (sum == target) {
      res.push_back(cur);
      return;
    }
    for (int i = index; i < candidates.size(); ++i) {
      if (sum + candidates[i] <= target) {
        cur.push_back(candidates[i]);
        dfs(candidates, cur, target, i, sum + candidates[i]);
        cur.pop_back();
      }
    }
  }
};