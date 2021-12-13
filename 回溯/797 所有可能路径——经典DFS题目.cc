#include <vector>

using namespace std;

// 给定一个有向无环图，找出从节点 0 到节点 n - 1 的所有可能路径，不要求输出顺序

// DFS 搜索
// 时间复杂度 O(n * 2^n)，总共有 2^n 种状态，每种状态需要 O(n) 的时间来构造
// 空间复杂度 O(n)
class Solution {
public:
  vector<vector<int>> res;
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    vector<int> tmp;
    dfs(graph, 0, tmp);
    return res;
  }
  void dfs(const vector<vector<int>> &graph, int index, vector<int> &tmp) {
    // push_back 既可以放在这里
    tmp.push_back(index);
    if (index == graph.size() - 1) {
      res.push_back(tmp);
      tmp.pop_back();
      return;
    }
    for (const auto &i : graph[index]) {
      // push_back 也可以放在这里
      dfs(graph, i, tmp);
      // pop_back 也可以放在这里
    }
    // pop_back 既可以放在这里
    tmp.pop_back();
  }
};

// 二进制表示
// 数组的每个元素都可以选或者不选，刚好对应了二进制的一个 bit
// 对于 n 个元素的数组来说，总共有 2^n 个状态，因此可以使用 n 位的二进制数 i 表示
// 当 i 的第 j 位为 1，则 nums[j] 被选择
// 时间复杂度 O(n * 2^n)，空间复杂度 O(n)
class Solution_1 {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>> res;
    for (int i = 0; i < (1 << n); ++i) {
      vector<int> tmp;
      for (int j = 0; j < n; ++j) {
        if (i & (1 << j)) {
          tmp.push_back(nums[j]);
        }
      }
      res.push_back(tmp);
    }
    return res;
  }
};