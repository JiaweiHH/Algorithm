#include <vector>
using namespace std;

class Solution {
public:
  int peakIndexInMountainArray(vector<int> &arr) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (mid > 0 && arr[mid] > arr[mid - 1])
        l = mid + 1;
      else if (mid > 0 && arr[mid] < arr[mid - 1])
        r = mid - 1;
      else if (mid == 0)
        l = mid + 1;
    }
    return r;
  }
};