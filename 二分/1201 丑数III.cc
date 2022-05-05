#include <vector>
using namespace std;

class Solution {
public:
  int gcd(int a, int b) {
    int min_val = a < b ? a : b, max_val = a + b - min_val;
    return max_val % min_val == 0 ? min_val : gcd(max_val % min_val, min_val);
  }
  int nthUglyNumber(int n, int a, int b, int c) {
    int l = 1, r = INT_MAX;
    // 计算 ab、bc、ac 的最小公倍数
    int gcd_ab = gcd(a, b), gcd_bc = gcd(b, c), gcd_ac = gcd(a, c);
    int64_t min_mul_ab = int64_t(a) * b / gcd_ab,
            min_mul_bc = int64_t(b) * c / gcd_bc,
            min_mul_ac = int64_t(a) * c / gcd_ac;
    // 计算 a, b, c 的最小公倍数
    int gcd_tmp = gcd(min_mul_ab, c);
    int64_t min_mul_abc = int64_t(min_mul_ab) * c / gcd_tmp;
    auto count = [&](int target) {
      return int64_t(target) / a + target / b + target / c -
             target / min_mul_ab - target / min_mul_bc - target / min_mul_ac +
             target / min_mul_abc;
    };
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (count(mid) >= n)
        r = mid - 1;
      else
        l = mid + 1;
    }
    return l;
  }
};