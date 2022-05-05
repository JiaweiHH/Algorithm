#include <climits>
#include <cstdint>

using namespace std;

class Solution {
public:
  int arrangeCoins(int n) {
    int l = 1, r = INT_MAX;
    while (l <= r) {
      int64_t mid = l + (r - l) / 2;
      int64_t number = (mid + 1) * mid / 2;
      if (number <= n)
        l = mid + 1;
      else
        r = mid - 1;
    }
    return r;
  }
};