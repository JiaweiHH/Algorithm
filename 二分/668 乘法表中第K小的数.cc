#include <vector>
using namespace std;

class Solution {
public:
  int findKthNumber(int m, int n, int k) {
    // 找到恰好有 k 个数字小于等于「目标值」
    int l = 1, r = m * n;
    auto count = [&](int target) {
      int cnt = 0;
      for (int i = 1; i <= m; ++i)
        cnt += min(target / i, n);
      return cnt;
    };
    while (l <= r) {
      int mid = (l + r) / 2;
      if (count(mid) >= k)
        r = mid - 1;
      else
        l = mid + 1;
    }
    return l;
  }
};