#include <cstdint>
using namespace std;

class Solution {
public:
  bool isPerfectSquare(int num) {
    int64_t l = 1, r = num;
    while (l <= r) {
      int64_t mid = (l + r) / 2;
      if (mid * mid >= num)
        r = mid - 1;
      else
        l = mid + 1;
    }
    return l * l == num;
  }
};