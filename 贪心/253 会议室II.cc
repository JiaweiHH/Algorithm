#include <queue>
#include <vector>
using namespace std;

template <int> class Solution;

/// 优先队列
template <> class Solution<1> {
public:
  int minMeetingRooms(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](vector<int> &lhs, vector<int> &rhs) {
           if (lhs[0] == rhs[0])
             return lhs[1] < rhs[1];
           return lhs[0] < rhs[0];
         });
    priority_queue<int, vector<int>, greater<int>> q;
    int res = 0;
    for (int i = 0; i < intervals.size(); ++i) {
      if (q.empty() || intervals[i][0] < q.top())
        res++;
      else
        q.pop();
      q.push(intervals[i][1]);
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

template <> class Solution<3> {
public:
  int minMeetingRooms(vector<vector<int>> &intervals) {
    vector<pair<int, int>> meeting;
    for (int i = 0; i < intervals.size(); ++i) {
      meeting.push_back({intervals[i][0], 1});
      meeting.push_back({intervals[i][1], -1});
    }
    sort(meeting.begin(), meeting.end(),
         [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
           if (lhs.first == rhs.first)
             return lhs.second < rhs.second;
           return lhs.first < rhs.first;
         });
    int res = 0, count;
    for (int i = 0; i < meeting.size(); ++i) {
      count += meeting[i].second;
      res = max(res, count);
    }
    return res;
  }
};