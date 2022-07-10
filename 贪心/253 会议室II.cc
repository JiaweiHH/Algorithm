#include <queue>
#include <vector>
using namespace std;

template <int> class Solution;

/// @brief 堆
template <> class Solution<1> {
public:
  int minMeetingRooms(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](vector<int> &lhs, vector<int> &rhs) { return lhs[0] < rhs[0]; });
    // que 记录当前正在执行的会议的结束之间
    priority_queue<int, vector<int>, greater<int>> que;
    que.push(intervals[0][1]); // 第一个会议先开始
    size_t res = 1;
    for (int i = 1; i < intervals.size(); ++i) {
      // 弹出所有已经结束的会议
      while (!que.empty() && que.top() <= intervals[i][0]) {
        que.pop();
      }
      que.push(intervals[i][1]);
      res = max(res, que.size());
    }
    return res;
  }
};

template <> class Solution<2> {
public:
  int minMeetingRooms(vector<vector<int>> &intervals) {
    int n = intervals.size();
    vector<int> s_ptr, e_ptr;
    for (int i = 0; i < n; ++i) {
      s_ptr.push_back(intervals[i][0]);
      e_ptr.push_back(intervals[i][1]);
    }
    sort(s_ptr.begin(), s_ptr.end());
    sort(e_ptr.begin(), e_ptr.end());
    int res = 0;
    int i = 0, j = 0;
    while (i != n) {
      if (s_ptr[i] < e_ptr[j])
        res++;
      else
        j++;
      i++;
    }
    return res;
  }
};

/// @brief 扫描线
template <> class Solution<3> {
public:
  int minMeetingRooms(vector<vector<int>> &intervals) {
    vector<pair<int, int>> vec;
    for (int i = 0; i < intervals.size(); ++i) {
      vec.push_back({intervals[i][0], 1});
      vec.push_back({intervals[i][1], -1});
    }
    sort(vec.begin(), vec.end());
    int res = 1, cnt = 0;
    for (int i = 0; i < vec.size(); ++i) {
      cnt += vec[i].second;
      res = max(res, cnt);
    }
    return res;
  }
};