#include <vector>
using namespace std;

template <int> class Solution;

/// 枚举工作时间DP（超时）
template <> class Solution<1> {
public:
  pair<int, int> binary_search(vector<pair<int, int>> &end_time, int target) {
    int l = 0, r = end_time.size() - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (end_time[mid].first >= target)
        r = mid - 1;
      else
        l = mid + 1;
    }
    return end_time[l];
  }
  int jobScheduling(vector<int> &startTime, vector<int> &endTime,
                    vector<int> &profit) {
    vector<pair<int, int>> end_time;
    for (int i = 0; i < endTime.size(); ++i)
      end_time.push_back({endTime[i], i});
    sort(end_time.begin(), end_time.end(),
         [&](pair<int, int> &lhs, pair<int, int> &rhs) {
           return lhs.first < rhs.first ||
                  (lhs.first == rhs.first &&
                   startTime[lhs.second] < startTime[rhs.second]);
         });
    int max_time = end_time[end_time.size() - 1].first, ptr = 0;
    vector<int> dp(max_time + 1);
    for (int i = 1; i <= max_time; ++i) {
      auto [time, idx] = end_time[ptr];
      if (time == i) {
        while (time == i) {
          dp[i] = max({dp[i], dp[startTime[idx]] + profit[idx], dp[i - 1]});
          if (++ptr == end_time.size())
            break;
          time = end_time[ptr].first;
          idx = end_time[ptr].second;
        }
      } else {
        dp[i] = dp[i - 1];
      }
    }
    return dp[max_time];
  }
};

/// 枚举任务编号DP
template <> class Solution<2> {
public:
  int jobScheduling(vector<int> &startTime, vector<int> &endTime,
                    vector<int> &profit) {
    vector<vector<int>> vec;
    for (int i = 0; i < startTime.size(); ++i)
      vec.push_back({startTime[i], endTime[i], profit[i]});
    sort(vec.begin(), vec.end(),
         [](vector<int> &lhs, vector<int> &rhs) { return lhs[1] < rhs[1]; });
    vector<int> dp(vec.size() + 1);
    dp[0] = vec[0][2];
    for (int i = 1; i < vec.size(); ++i) {
      int s_time = vec[i][0];
      int l = 0, r = i - 1;
      while (l <= r) {
        int mid = (l + r) / 2;
        if (vec[mid][1] <= s_time)
          l = mid + 1;
        else
          r = mid - 1;
      }
      int val_1 = dp[i - 1], val_2 = r >= 0 ? dp[r] + vec[i][2] : vec[i][2];
      dp[i] = max({dp[i], val_1, val_2});
    }
    return *max_element(dp.begin(), dp.end());
  }
};