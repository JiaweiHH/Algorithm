#include <set>
#include <vector>

using namespace std;

// 与 78
// 题的区别在于，现在数组中包含重复的元素，但是最后给出的子集中不能包含重复的解

template <int> class Solution;

// 回溯 1
// 1. 采用 set 去除重复的解
//    不能使用 unordered_set，原因在于 unordered_set 采用哈希实现，vector<>
//    没有默认的哈希函数
// 2. 但是需要首先对 nums 排序，不然还是会出现重复解，考虑 [1,1,1,2,1]，会出现
// [1,1,1,2] 和 [1,1,2,1]
template <> class Solution<1> {
public:
  set<vector<int>> res;
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<int> tmp;
    sort(nums.begin(), nums.end());
    dfs(nums, 0, tmp);
    return vector<vector<int>>(res.begin(), res.end());
  }
  void dfs(const vector<int> &nums, int index, vector<int> &tmp) {
    if (index == nums.size()) {
      res.insert(tmp);
      return;
    }
    // 选 nums[index]
    tmp.push_back(nums[index]);
    dfs(nums, index + 1, tmp);
    tmp.pop_back();
    // 不选 nums[index]
    dfs(nums, index + 1, tmp);
  }
};

/// 回溯 2
template <> class Solution<2> {
public:
  vector<vector<int>> res;
  set<vector<int>> st;
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<int> cur;
    backtracing(0, nums, cur);
    return res;
  }
  void backtracing(int index, const vector<int> &nums, vector<int> &cur) {
    if (!st.count(cur)) {
      st.insert(cur);
      res.push_back(cur);
    }
    for (int i = index; i < nums.size(); ++i) {
      cur.push_back(nums[i]);
      backtracing(i + 1, nums, cur);
      cur.pop_back();
    }
  }
};

/// @brief 保证在同一层树上只会选择一次重复的数字
template <> class Solution<3> {
public:
  vector<vector<int>> res;
  void dfs(vector<int> &nums, int idx, vector<int> &tmp) {
    res.push_back(tmp);
    for (int i = idx; i < nums.size(); ++i) {
      // 同一层只能选择一次重复的数字
      if (i > idx && nums[i] == nums[i - 1])
        continue;
      // 每次选择都构成一个新的子集
      tmp.push_back(nums[i]);
      dfs(nums, i + 1, tmp);
      tmp.pop_back();
    }
  }
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<int> tmp;
    dfs(nums, 0, tmp);
    return res;
  }
};

// 不使用 set 去重复解集，并使用迭代的二进制方法
template <> class Solution<4> {
public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < (1 << n); ++i) {
      bool flag = true;
      vector<int> tmp;
      for (int j = 0; j < n; ++j) {
        if (i & (1 << j)) { // 如果第 j 位是 1，表示选择 nums[j]
          if (j > 0 && (i >> (j - 1) & 1) == 0 &&
              nums[j] == nums[j - 1]) { // 判断是不是没有选上一个数
            flag = false;
            // 一旦出现重复的数，则当前组合肯定已经在选择前面那个数的情况下考虑过了
            // 可以直接跳出循环
            break;
          }
          tmp.push_back(nums[j]);
        }
      }
      if (flag)
        res.push_back(tmp);
    }
    return res;
  }
};