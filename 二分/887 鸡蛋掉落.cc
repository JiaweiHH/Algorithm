#include <unordered_map>
using namespace std;

class Solution {
public:
  unordered_map<int, int> memo;
  int dp(int k, int n) {
    if (!memo.count(k + n * 100)) {
      int res;
      if (n <= 1) {
        res = n;
      } else if (k == 1) {
        res = n;
      } else {
        int l = 1, r = n;
        while (l <= r) {
          int mid = (l + r) / 2;
          int val_1 = dp(k, n - mid), val_2 = dp(k - 1, mid - 1);
          if (val_1 - val_2 > 0)
            l = mid + 1;
          else
            r = mid - 1;
        }
        // 二分查找结束的时候，l 和 r 分别表示最小值左右的两个离散点
        int tmp_1 = INT_MAX, tmp_2 = INT_MAX;
        if (l <= n)
          tmp_1 = max(dp(k, n - l), dp(k - 1, l - 1));
        if (r >= 1)
          tmp_2 = max(dp(k, n - r), dp(k - 1, r - 1));
        res = 1 + min(tmp_1, tmp_2);
      }
      memo[k + n * 100] = res;
    }
    return memo[k + n * 100];
  }
  int superEggDrop(int k, int n) { return dp(k, n); }
};