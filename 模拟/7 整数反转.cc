#include <vector>
using namespace std;

template <int> class Solution;

template <> class Solution<1> {
public:
  int reverse(int x) {
    int reverse(int x) {
      long long res = 0;
      while (x != 0) {
        res = res * 10 + x % 10;
        x /= 10;
      }
      return (res > INT_MAX || res < INT_MIN) ? 0 : res;
    }
  }
};

template <> class Solution<2> {
public:
  int reverse(int x) {
    int res = 0;
    while (x != 0) {
      res = res * 10 + x % 10;
      x /= 10;
      if (x != 0 && (res > INT_MAX / 10 || res < INT_MIN / 10))
        return 0;
    }
    return res;
  }
};