#include <vector>
using namespace std;

class Solution {
public:
  int maxDistance(vector<int> &position, int m) {
    int n = position.size();
    sort(position.begin(), position.end());
    auto count = [&](int target) {
      int cnt = 1, point = 0;
      for (int i = 1; i < n; ++i) {
        if (position[i] - position[point] >= target) {
          ++cnt;
          point = i;
        }
      }
      return cnt;
    };
    int l = 1, r = position[n - 1] - position[0];
    while (l <= r) {
      int mid = (l + r) / 2;
      if (count(mid) >= m)
        l = mid + 1;
      else
        r = mid - 1;
    }
    return r;
  }
};