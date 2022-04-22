#include <vector>
using namespace std;

template <int> class Solution;

/// 双指针，枚举山脚
template <> class Solution<1> {
public:
  int longestMountain(vector<int> &arr) {
    int res = 0;
    for (int i = 0; i < arr.size(); ++i) {
      if (i > 0 && arr[i] > arr[i - 1]) {
        int r = i - 1;
        bool upper = true;
        while (r != arr.size()) {
          int val = arr[r];
          if (r > i - 1 && arr[r] == arr[r - 1] && upper)
            break;
          else if (r > i - 1 && arr[r] >= arr[r - 1] && !upper) {
            res = max(res, r - i + 1);
            break;
          } else if (r > i - 1 && arr[r] < arr[r - 1])
            upper = false;
          ++r;
        }
        if (r == arr.size() && !upper)
          res = max(res, r - i + 1);
        i = r - 1;
      }
    }
    return res >= 3 ? res : 0;
  }
};

/// 双指针，枚举山顶
template <> class Solution<2> {
public:
  int longestMountain(vector<int> &arr) {
    int n = arr.size();
    vector<int> left(n), right(n);
    for (int i = 1; i < n; ++i) {
      if (arr[i] > arr[i - 1])
        left[i] = left[i - 1] + 1;
    }
    for (int i = n - 2; i >= 0; --i) {
      if (arr[i] > arr[i + 1])
        right[i] = right[i + 1] + 1;
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
      if (left[i] == 0 || right[i] == 0)
        continue;
      res = max(res, left[i] + right[i] + 1);
    }
    return res >= 3 ? res : 0;
  }
};