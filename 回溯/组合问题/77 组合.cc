#include <vector>
using namespace std;

/// 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合

template <int>
class Solution;

/// 回溯方式 1
template <> class Solution<1> {
public:
  vector<vector<int>> res;
  vector<vector<int>> combine(int n, int k) {
    vector<int> tmp;
    backtracing(1, n, k, tmp);
    return res;
  }
  void backtracing(int cur, int n, int k, vector<int> &tmp) {
    if (tmp.size() == k) {
      res.push_back(tmp);
      return;
    }
    // 剪枝优化
    // if (cur > n || cur + (k - tmp.size()) - 1 > n)
    if (cur > n)
      return;
    // 选择 cur
    tmp.push_back(cur);
    backtracing(cur + 1, n, k, tmp);
    tmp.pop_back();
    // 不选择 cur
    backtracing(cur + 1, n, k, tmp);
  }
};

/// 回溯方式 2
template <> class Solution<2> {
public:
  vector<vector<int>> res;
  vector<vector<int>> combine(int n, int k) {
    vector<int> tmp;
    backtracing(1, n, k, tmp);
    return res;
  }
  void backtracing(int cur, int n, int k, vector<int> &tmp) {
    if (tmp.size() == k) {
      res.push_back(tmp);
      return;
    }
    // 剪枝优化
    // for (int i = cur; i <= n - (k - tmp.size()) + 1; ++i)
    for (int i = cur; i <= n; ++i) {
      tmp.push_back(i);
      backtracing(i + 1, n, k, tmp);
      tmp.pop_back();
    }
  }
};