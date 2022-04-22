#include <vector>
using namespace std;

class Solution {
public:
  int binary_search(vector<int> &arr, int l, int r, int target) {
    while (l <= r) {
      int mid = (l + r) / 2;
      if (arr[mid] >= target)
        r = mid - 1;
      else
        l = mid + 1;
    }
    return l;
  }
  int findLengthOfShortestSubarray(vector<int> &arr) {
    int n = arr.size();
    int l = 0, r = n - 1;
    while (l + 1 < n && arr[l + 1] >= arr[l])
      ++l;
    while (r - 1 >= 0 && arr[r - 1] <= arr[r])
      --r;
    int res = r;
    for (int i = 0; i <= l; ++i) {
      int idx = binary_search(arr, r, n - 1, arr[i]);
      res = min(res, idx - i - 1);
    }
    return max(res, 0);
  }
};