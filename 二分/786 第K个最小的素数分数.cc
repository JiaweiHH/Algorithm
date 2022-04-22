#include <queue>
#include <vector>
using namespace std;

template <int> class Solution;

/// 二分
template <> class Solution<1> {
public:
  vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k) {
    int n = arr.size();
    double l = 0, r = 1;
    while (l < r) {
      double mid = (l + r) / 2;
      int x = 0, y = 0, cnt = 0;
      int res_x = -1, res_y = -1;
      while (x < n - 1 && y < n - 1) {
        if (double(arr[y]) / arr[x + 1] > mid)
          ++x;
        else {
          if (res_x == -1 && res_y == -1) {
            res_x = arr[y];
            res_y = arr[x + 1];
          } else {
            if (double(arr[y]) / arr[x + 1] > double(res_x) / res_y) {
              res_x = arr[y];
              res_y = arr[x + 1];
            }
          }
          cnt += n - 1 - x;
          if (++y > x)
            ++x;
        }
      }
      if (cnt == k)
        return {res_x, res_y};
      else if (cnt > k)
        r = mid;
      else
        l = mid;
    }
    return {};
  }
};

/// 堆
template <> class Solution<2> {
public:
  vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k) {
    auto cmp = [&](pair<int, int> &lhs, pair<int, int> &rhs) {
      return double(arr[lhs.first]) / arr[lhs.second] >
             double(arr[rhs.first]) / arr[rhs.second];
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> heap(
        cmp);
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
      heap.push({i, n - 1});
    while (--k) {
      auto [x, y] = heap.top();
      heap.pop();
      if (x < y - 1)
        heap.push({x, y - 1});
    }
    auto [res_x, res_y] = heap.top();
    return {arr[res_x], arr[res_y]};
  }
};