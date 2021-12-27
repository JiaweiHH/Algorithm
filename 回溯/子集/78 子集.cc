#include <vector>

using namespace std;

/// 给定一个数组，输出这个数组的所有子集

template <int> class Solution;

/// 回溯 1
template <> class Solution<1> {
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

/// 回溯 2
template <> class Solution<2> {
public:
  vector<vector<int>> res;
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<int> cur;
    backtracing(0, nums, cur);
    return res;
  }
  void backtracing(int index, const vector<int> &nums, vector<int> &cur) {
    res.push_back(cur);
    for (int i = index; i < nums.size(); ++i) {
      cur.push_back(nums[i]);
      backtracing(i + 1, nums, cur);
      cur.pop_back();
    }
  }
};