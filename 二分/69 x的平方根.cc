#include <vector>
using namespace std;

class Solution {
public:
  int mySqrt(int x) {
    int left = 1, right = x;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      uint64_t p = (uint64_t)mid * mid;
      if (p == x)
        return mid;
      if (p < x)
        left = mid + 1;
      else
        right = mid - 1;
    }
    return left - 1;
  }
};