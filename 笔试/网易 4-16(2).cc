#include <iostream>
#include <vector>
using namespace std;

/// @brief 题目描述
/// 给出三个数字 n, k, x，要求凑出一个长度为 n
/// 的数组，其中数组中的每个元素互不相同， 元素的最大值不超过
/// k，并且所有元素之和是 x

int64_t sum(int mid, int n) { return (mid - n + 1 + mid) * n / 2; }

int main() {
  int n, k, x;
  cin >> n >> k >> x;
  int l = n, r = k;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (sum(mid, n) <= x)
      l = mid + 1;
    else
      r = mid - 1;
  }
  cout << "l = " << l << "\n";
  if (l > k || sum(l, n) < x)
    cout << "-1\n";
  else {
    int val = sum(l, n) - x;
    vector<int> res;
    for (int i = 0; i < n; ++i)
      res.push_back(l--);
    for (int i = n - 1; i >= 0; --i) {
      if (res[i] - val > 0) {
        res[i] -= val;
        break;
      }
    }
    for (int i = n - 1; i > 0; --i)
      cout << res[i] << " ";
    cout << res[0] << "\n";
  }
}