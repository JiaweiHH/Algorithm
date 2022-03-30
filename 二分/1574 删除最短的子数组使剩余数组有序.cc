#include <vector>
using namespace std;

class Solution {
public:
  int findLengthOfShortestSubarray(vector<int> &arr) {
    int l = 0, r = arr.size() - 1;
    while (l < arr.size() - 1 && arr[l] <= arr[l + 1])
      ++l;
    while (r > 0 && arr[r] >= arr[r - 1])
      --r;
    if (l >= r)
      return 0;
    int res = r;
    for (int i = 0; i <= l; ++i) {
      int target = arr[i];
      int idx = lower_bound(arr.begin() + r, arr.end(), target) - arr.begin();
      res = min(res, idx - i - 1);
    }
    return res;
  }
};