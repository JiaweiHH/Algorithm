#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> res;
  void dfs(int idx, int n, int k, int cnt, vector<int> &tmp) {
    if (tmp.size() == k) {
      if (cnt == n)
        res.push_back(tmp);
      return;
    }
    for (int i = idx; i <= 9; ++i) {
      if (cnt + i > n)
        break;
      tmp.push_back(i);
      dfs(i + 1, n, k, cnt + i, tmp);
      tmp.pop_back();
    }
  }
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> tmp;
    dfs(1, n, k, 0, tmp);
    return res;
  }
};