#include <cstdint>
using namespace std;

class Solution {
public:
  double myPow(double x, int n) {
    int64_t N = n;
    if (n < 0)
      return 1.0 / cal(x, -N);
    return cal(x, N);
  }
  double cal(double x, int64_t n) {
    if (n == 0)
      return 1;
    if (n == 1)
      return x;
    double tmp = cal(x, n / 2);
    return n % 2 == 0 ? tmp * tmp : tmp * tmp * x;
  }
};