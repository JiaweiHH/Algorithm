#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  using __vec = vector<pair<int, int>>;
  vector<int> smallestRange(vector<vector<int>> &nums) {
    __vec vec = merge(nums, 0, nums.size() - 1);
    int l = 0, r = 0, valid = 0;
    vector<int> res{0, INT_MAX};
    // 记录窗口中每个列表元素的出现次数
    unordered_map<int, int> map;
    while (r != vec.size()) {
      auto p = vec[r];
      ++map[p.second];
      while (map.size() == nums.size()) {
        if (vec[r].first - vec[l].first < res[1] - res[0]) {
          res[0] = vec[l].first;
          res[1] = vec[r].first;
        }
        if (--map[vec[l].second] == 0)
          map.erase(vec[l].second);
        ++l;
      }
      ++r;
    }
    return res;
  }
  __vec merge(const vector<vector<int>> &nums, int l, int r) {
    __vec res;
    if (l == r) {
      for (int i = 0; i < nums[l].size(); ++i)
        res.push_back({nums[l][i], l});
      return res;
    }
    int mid = (l + r) / 2, idx_1 = 0, idx_2 = 0;
    __vec left = merge(nums, l, mid), right = merge(nums, mid + 1, r);
    while (idx_1 != left.size() && idx_2 != right.size()) {
      if (left[idx_1].first < right[idx_2].first) {
        res.push_back(left[idx_1]);
        ++idx_1;
      } else {
        res.push_back(right[idx_2]);
        ++idx_2;
      }
    }
    while (idx_1 != left.size()) {
      res.push_back(left[idx_1]);
      ++idx_1;
    }
    while (idx_2 != right.size()) {
      res.push_back(right[idx_2]);
      ++idx_2;
    }
    return res;
  }
};