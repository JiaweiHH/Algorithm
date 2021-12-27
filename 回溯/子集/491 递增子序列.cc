#include <set>
#include <unordered_set>
#include <vector>
using namespace std;

/// 给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中
/// 至少有两个元素 。你可以按 任意顺序 返回答案

template <int> class Solution;

/// 回溯 1，for 循环的形式 + 最后结果去重
template <> class Solution<1> {
public:
  vector<vector<int>> res;
  set<vector<int>> st;
  vector<vector<int>> findSubsequences(vector<int> &nums) {
    vector<int> cur;
    backtracing(0, nums, cur, INT_MIN);
    return res;
  }
  void backtracing(int index, const vector<int> &nums, vector<int> &cur,
                   int value) {
    for (int i = index; i < nums.size(); ++i) {
      if (value <= nums[i]) {
        cur.push_back(nums[i]);
        backtracing(i + 1, nums, cur, nums[i]);
        cur.pop_back();
      }
    }
    if (cur.size() > 1 && !st.count(cur)) {
      st.insert(cur);
      res.push_back(cur);
    }
  }
};

/// 回溯 2，for 循环 + 当前层去重
template <> class Solution<2> {
public:
  vector<vector<int>> res;
  vector<vector<int>> findSubsequences(vector<int> &nums) {
    vector<int> cur;
    backtracing(0, nums, cur, INT_MIN);
    return res;
  }
  void backtracing(int index, const vector<int> &nums, vector<int> &cur,
                   int value) {
    if (cur.size() > 1)
      res.push_back(cur);
    unordered_set<int> st; // st 负责树上本层的去重工作
    for (int i = index; i < nums.size(); ++i) {
      if (value <= nums[i] && !st.count(nums[i])) {
        st.insert(nums[i]);
        cur.push_back(nums[i]);
        backtracing(i + 1, nums, cur, nums[i]);
        cur.pop_back();
      }
    }
  }
};

/// 回溯 3，不实用 for 循环遍历
template <> class Solution<3> {
public:
  vector<int> temp;
  vector<vector<int>> ans;

  void dfs(int cur, int last, vector<int> &nums) {
    if (cur == nums.size()) {
      if (temp.size() >= 2) {
        ans.push_back(temp);
      }
      return;
    }
    // 这里只要是大于前一个元素就直接选择，此时不存在选择或者不选择两种情况
    // 因为这个时候选择了，下面再次碰到重复的元素就必定不会再次选择了
    // 达到了去重的效果
    if (nums[cur] >= last) {
      temp.push_back(nums[cur]);
      dfs(cur + 1, nums[cur], nums);
      temp.pop_back();
    }
    if (nums[cur] != last) {
      dfs(cur + 1, last, nums);
    }
  }

  vector<vector<int>> findSubsequences(vector<int> &nums) {
    dfs(0, INT_MIN, nums);
    return ans;
  }
};