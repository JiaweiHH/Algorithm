#include <queue>
#include <vector>
using namespace std;

// Definition for an Interval.
class Interval {
public:
  int start;
  int end;

  Interval() {}

  Interval(int _start, int _end) {
    start = _start;
    end = _end;
  }
};

template <int> class Solution;

/// 堆 + 贪心
template <> class Solution<1> {
public:
  vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
    auto cmp = [&](pair<int, int> &lhs, pair<int, int> &rhs) {
      return schedule[lhs.second][lhs.first].start >
             schedule[rhs.second][rhs.first].start;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> heap(
        cmp);
    for (int i = 0; i < schedule.size(); ++i)
      heap.push({0, i});
    vector<Interval> res;
    int ptr = schedule[heap.top().second][heap.top().first].start;
    while (!heap.empty()) {
      auto worker = heap.top();
      heap.pop();
      if (ptr < schedule[worker.second][worker.first].start)
        res.emplace_back(ptr, schedule[worker.second][worker.first].start);
      ptr = max(ptr, schedule[worker.second][worker.first].end);
      if (++worker.first < schedule[worker.second].size())
        heap.push(worker);
    }
    return res;
  }
};

/// 扫描线(贪心)
template <> class Solution<2> {
public:
  vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
    vector<pair<int, int>> vec;
    for (int i = 0; i < schedule.size(); ++i) {
      for (int j = 0; j < schedule[i].size(); ++j) {
        vec.push_back({schedule[i][j].start, 1});
        vec.push_back({schedule[i][j].end, -1});
      }
    }
    sort(vec.begin(), vec.end());
    int cnt = 0, prev_time = -1;
    vector<Interval> res;
    for (int i = 0; i < vec.size(); ++i) {
      if (cnt == 0 && prev_time >= 0 && vec[i].first != prev_time)
        res.emplace_back(prev_time, vec[i].first);
      cnt += vec[i].second;
      prev_time = vec[i].first;
    }
    return res;
  }
};