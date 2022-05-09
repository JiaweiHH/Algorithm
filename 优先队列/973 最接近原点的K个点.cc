#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    auto cmp = [](pair<int, int> &lhs, pair<int, int> &rhs) {
      return lhs.first * lhs.first + lhs.second * lhs.second <
             rhs.first * rhs.first + rhs.second * rhs.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> heap(
        cmp);
    vector<vector<int>> res;
    for (auto &point : points) {
      heap.push({point[0], point[1]});
      if (heap.size() > k)
        heap.pop();
    }
    while (!heap.empty()) {
      res.push_back({heap.top().first, heap.top().second});
      heap.pop();
    }
    return res;
  }
};