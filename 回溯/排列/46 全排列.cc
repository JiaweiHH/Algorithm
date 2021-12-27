#include <vector>
using namespace std;

/// 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以按任意顺序 返回答案

class Solution {
public:
  vector<bool> visit;
  vector<vector<int>> res;
  vector<int> cur;
  vector<vector<int>> permute(vector<int> &nums) {
    visit.resize(nums.size(), false);
    backtracing(nums);
    return res;
  }
  void backtracing(const vector<int> &nums) {
    if (cur.size() == nums.size()) {
      res.push_back(cur);
      return;
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (!visit[i]) {
        visit[i] = true;
        cur.push_back(nums[i]);
        backtracing(nums);
        cur.pop_back();
        visit[i] = false;
      }
    }
  }
};