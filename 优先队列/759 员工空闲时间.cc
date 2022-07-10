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

/// @brief 堆
template <> class Solution<1> {
public:
  vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
    auto cmp = [&](pair<int, int> &lhs, pair<int, int> &rhs) {
      return schedule[lhs.first][lhs.second].start >
             schedule[rhs.first][rhs.second].start;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> heap(
        cmp);
    for (int i = 0; i < schedule.size(); ++i)
      heap.push({i, 0});
    // cur_time 表示在此之前的时间都扫描过，是空闲时间或工作时间都已经判断好了
    int cur_time = schedule[heap.top().first][heap.top().second].end;
    vector<Interval> res;
    while (!heap.empty()) {
      auto [idx1, idx2] = heap.top();
      heap.pop();
      // end_time = shcedule[idx1][idx2].start
      // [cur_time, end_time] 必定是所有工人的空闲时间
      // 因为后续工人的开始时间比定大于 end_time，不可能和这段区间有交集
      if (schedule[idx1][idx2].start > cur_time)
        res.emplace_back(cur_time, schedule[idx1][idx2].start);
      // 这里需要 max，考虑两个区间 [1, 9], [2, 8]
      // [1, 9] 先于弹出来，但是后续 [2, 8] 的结束时间小于 9
      cur_time = max(cur_time, schedule[idx1][idx2].end);
      if (++idx2 != schedule[idx1].size())
        heap.push({idx1, idx2});
    }
    return res;
  }
};

/// @brief 扫描线
/// 将所有的时间离散，开始时间打上标签 1， 结束时间打上标签 -1
/// 顺序遍历所有时间，某个时刻 cnt = 0 表示 [prev_time, cur_time] 是空闲时间
template <> class Solution<2> {
public:
  vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
    vector<pair<int, int>> times;
    for (int i = 0; i < schedule.size(); ++i) {
      for (int j = 0; j < schedule[i].size(); ++j) {
        times.push_back({schedule[i][j].start, 1});
        times.push_back({schedule[i][j].end, -1});
      }
    }
    // 排序
    sort(times.begin(), times.end());
    vector<Interval> res;
    int prev_time = times[0].first, cnt = 0;
    for (int i = 0; i < times.size(); ++i) {
      // 相等的区间不作为空闲时间
      if (cnt == 0 && prev_time != times[i].first)
        res.emplace_back(prev_time, times[i].first);
      cnt += times[i].second;
      prev_time = times[i].first;
    }
    return res;
  }
};