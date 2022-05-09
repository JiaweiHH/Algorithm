#include <vector>
using namespace std;

class Solution {
public:
  int countPrimes(int n) {
    vector<bool> is_prime(n, true);
    int res = 0;
    for (int i = 2; i < n; ++i) {
      if (is_prime[i]) {
        ++res;
        for (long j = (long)i * i; j < n; j += i) {
          is_prime[j] = false;
        }
      }
    }
    return res;
  }
};