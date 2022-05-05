#include <queue>
#include <vector>
using namespace std;

template <int> class Solution;

/// 贪心 + 优先队列
template <> class Solution<1> {
public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations) {
    priority_queue<int, vector<int>, less<int>> heap;
    int max_value = startFuel, res = 0, i = 0;
    while (i != stations.size()) {
      if (stations[i][0] <= max_value) {
        heap.push(stations[i++][1]);
        continue;
      }
      if (heap.empty() || max_value >= target)
        break;
      max_value += heap.top();
      heap.pop();
      ++res;
    }
    while (!heap.empty()) {
      if (max_value >= target)
        break;
      max_value += heap.top();
      heap.pop();
      ++res;
    }
    return max_value >= target ? res : -1;
  }
};

/// 动态规划
template <> class Solution<2> {
public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations) {
    int n = stations.size();
    vector<long> dp(n + 1);
    dp[0] = startFuel;
    for (int i = 0; i < n; ++i) {
      for (int j = i; j >= 0; --j) {
        if (dp[j] >= stations[i][0])
          dp[j + 1] = max(dp[j + 1], dp[j] + stations[i][1]);
      }
    }
    for (int i = 0; i <= n; ++i)
      if (dp[i] >= target)
        return i;
    return -1;
  }
};