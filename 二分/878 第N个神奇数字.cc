#include <climits>
#include <cstdint>

class Solution {
public:
  const int MOD = 1e9 + 7;
  int64_t gcd(int a, int b) {
    int min_val = a < b ? a : b, max_val = a + b - min_val;
    return max_val % min_val == 0 ? min_val : gcd(max_val % min_val, min_val);
  }
  int nthMagicalNumber(int n, int a, int b) {
    int64_t gcd_ab = gcd(a, b), lcm_ab = a * b / gcd_ab;
    auto count = [&](int64_t target) {
      return int64_t(target) / a + target / b - target / lcm_ab;
    };
    int64_t l = 1, r = LONG_MAX;
    while (l <= r) {
      int64_t mid = l + (r - l) / 2;
      if (count(mid) >= n)
        r = mid - 1;
      else
        l = mid + 1;
    }
    return l % MOD;
  }
};