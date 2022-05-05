#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
    vector<int> boundry;
    vector<vector<int>> res;
    auto cmp = [](pair<int, int> &lhs, pair<int, int> &rhs) {
      return lhs.second < rhs.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> heap(
        cmp);
    for (int i = 0; i < buildings.size(); ++i) {
      boundry.push_back(buildings[i][0]);
      boundry.push_back(buildings[i][1]);
    }
    sort(boundry.begin(), boundry.end());
    int idx = 0, prev_height = 0;
    for (int i = 0; i < boundry.size(); ++i) {
      while (idx < buildings.size() && buildings[idx][0] <= boundry[i]) {
        heap.push({buildings[idx][1], buildings[idx][2]});
        ++idx;
      }
      while (!heap.empty() && heap.top().first <= boundry[i])
        heap.pop();
      int max_height = heap.empty() ? 0 : heap.top().second;
      if (res.empty() || max_height != prev_height) {
        res.push_back({boundry[i], max_height});
        prev_height = max_height;
      }
    }
    return res;
  }
};