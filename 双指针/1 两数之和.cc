#include <unordered_map>
#include <vector>
using namespace std;

template <int> class Solution;

template <> class Solution<1> {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> res;
    vector<pair<int, int>> arr;
    for (int i = 0; i < nums.size(); ++i) {
      arr.push_back({i, nums[i]});
    }
    sort(arr.begin(), arr.end(), [](pair<int, int> lhs, pair<int, int> rhs) {
      return lhs.second < rhs.second;
    });
    int i = 0, j = arr.size() - 1;
    while (i < j) {
      int remain = target - arr[i].second;
      if (arr[j].second == remain) {
        res.push_back(arr[i].first);
        res.push_back(arr[j].first);
        break;
      }
      if (remain < arr[j].second)
        --j;
      else
        ++i;
    }
    return res;
  }
};

template <> class Solution<2> {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
      auto it = map.find(target - nums[i]);
      if (it != map.end()) {
        return {i, it->second};
      }
      map[nums[i]] = i;
    }
    return {};
  }
};