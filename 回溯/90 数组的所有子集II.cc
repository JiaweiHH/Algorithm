#include <set>
#include <vector>

using namespace std;

// 与 78 题的区别在于，现在数组中包含重复的元素，但是最后给出的子集中不能包含重复的解

// DFS
// 1. 采用 set 去除重复的解
//    不能使用 unordered_set，原因在于 unordered_set 采用哈希实现，vector<> 没有默认的哈希函数
// 2. 但是需要首先对 nums 排序，不然还是会出现重复解，考虑 [1,1,1,2,1]，会出现 [1,1,1,2] 和 [1,1,2,1]
class Solution {
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

// 不使用 set 去重
// 搜索的时候 在保证数组有序的情况下，如果发现没有选择上一个数，并且当前数和上一个数相同，则跳过当前数
// 这样可以保证不出现重复的解集
class Solution_1 {
public:
  vector<vector<int>> res;
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<int> tmp;
    sort(nums.begin(), nums.end());
    dfs(true, nums, 0, tmp);
    return res;
  }
  void dfs(bool checkLast, const vector<int> &nums, int index,
           vector<int> &tmp) {
    if (index == nums.size()) {
      res.push_back(tmp);
      return;
    }
    // 当前数和上一个数相等，并且不选上一个数，那么也不选当前数
    if (!checkLast && index != 0 && nums[index] == nums[index - 1]) {
      dfs(false, nums, index + 1, tmp);
      return;
    } else {
      tmp.push_back(nums[index]);
      dfs(true, nums, index + 1, tmp);
      tmp.pop_back();
      dfs(false, nums, index + 1, tmp);
    }
  }
};

// 不使用 set 去重复解集，并使用迭代的二进制方法
class Solution_2 {
public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < (1 << n); ++i) {
      bool flag = true;
      vector<int> tmp;
      for (int j = 0; j < n; ++j) {
        if (i & (1 << j)) {
          // 判断是不是没有选上一个数
          if (j > 0 && (i >> (j - 1) & 1) == 0 && nums[j] == nums[j - 1]) {
            flag = false;
            // 一旦出现重复的数，则当前组合肯定已经被，选择前面那个数的情况下考虑过了
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