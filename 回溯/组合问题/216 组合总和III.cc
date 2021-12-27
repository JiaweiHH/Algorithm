#include <vector>
using namespace std;

/// 找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字

/// 回溯
class Solution {
public:
  vector<vector<int>> res;
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> vec;
    backtracing(1, k, n, vec, 0);
    return res;
  }
  void backtracing(int cur, int k, int n, vector<int> &vec, int count) {
    if (vec.size() == k) {
      if (count == n)
        res.push_back(vec);
      return;
    }
    for (int i = cur; i <= 9; ++i) {
      if (count + i <= n) {
        vec.push_back(i);
        backtracing(i + 1, k, n, vec, count + i);
        vec.pop_back();
      }
    }
  }
};