#include <vector>
using namespace std;

class Solution {
public:
  int minEatingSpeed(vector<int> &piles, int h) {
    int l = 1, r = *max_element(piles.begin(), piles.end());
    auto count = [&](int speed) {
      int cnt = 0;
      for (auto &p : piles)
        cnt += p % speed == 0 ? p / speed : p / speed + 1;
      return cnt;
    };
    while (l <= r) {
      int mid = (l + r) / 2;
      if (count(mid) <= h)
        r = mid - 1;
      else
        l = mid + 1;
    }
    return l;
  }
};