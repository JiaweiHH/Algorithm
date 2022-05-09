#include <queue>
#include <vector>
using namespace std;

template <int> class Solution;

/// 排序 + 优先队列
template <> class Solution<1> {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    auto cmp = [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
      return lhs.first < rhs.first;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> heap(
        cmp);
    int count = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (i > 0 && nums[i] != nums[i - 1]) {
        heap.push({count, nums[i - 1]});
        count = 0;
      }
      ++count;
    }
    heap.push({count, nums[nums.size() - 1]});
    vector<int> res;
    for (int i = 0; i < k; ++i) {
      auto val = heap.top();
      heap.pop();
      res.push_back(val.second);
    }
    return res;
  }
};

