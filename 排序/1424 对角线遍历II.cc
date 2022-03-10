#include <map>
#include <queue>
#include <vector>
using namespace std;

template <int> class Solution;

/// map，本质上也是排序
template <> class Solution<1> {
public:
  vector<int> findDiagonalOrder(vector<vector<int>> &nums) {
    map<int, vector<int>> map;
    for (int i = nums.size() - 1; i >= 0; --i) {
      for (int j = 0; j < nums[i].size(); ++j) {
        map[i + j].push_back(nums[i][j]);
      }
    }
    vector<int> res;
    for (auto it = map.begin(); it != map.end(); ++it) {
      for (auto &val : it->second)
        res.push_back(val);
    }
    return res;
  }
};

/// 堆排序
template <> class Solution<2> {
public:
  vector<int> findDiagonalOrder(vector<vector<int>> &nums) {
    auto cmp = [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
      if (lhs.first + lhs.second == rhs.first + rhs.second)
        return lhs.first < rhs.first; // 和相同的时候，横坐标大的排在前面
      return (lhs.first + lhs.second) > (rhs.first + rhs.second); // 小顶堆
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(
        cmp);
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = 0; j < nums[i].size(); ++j)
        q.push({i, j});
    }
    vector<int> res;
    while (!q.empty()) {
      auto val = q.top();
      q.pop();
      res.push_back(nums[val.first][val.second]);
    }
    return res;
  }
};