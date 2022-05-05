#include <vector>
using namespace std;

class Solution {
public:
  double minmaxGasDist(vector<int> &stations, int k) {
    int max_val = INT_MIN;
    for (int i = 1; i < stations.size(); ++i)
      max_val = max(max_val, stations[i] - stations[i - 1]);
    auto count = [&](double target) {
      int cnt = 0;
      for (int i = 1; i < stations.size(); ++i) {
        int diff = stations[i] - stations[i - 1];
        cnt += (diff - 1e-6) / target;
      }
      return cnt;
    };
    double l = 0, r = max_val;
    while (l <= r) {
      double mid = (l + r) * 1.0 / 2;
      if (count(mid) <= k)
        r = mid;
      else
        l = mid;
      if (r - l < (1e-6))
        break;
    }
    return l;
  }
};