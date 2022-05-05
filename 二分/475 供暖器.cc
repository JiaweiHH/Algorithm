#include <vector>
using namespace std;

template <int> class Solution;

/// 二分
template <> class Solution<1> {
public:
  int binary_search(vector<int> &heaters, int target) {
    int l = 0, r = heaters.size() - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (heaters[mid] <= target)
        l = mid + 1;
      else
        r = mid - 1;
    }
    return max(r, 0);
  }
  int findRadius(vector<int> &houses, vector<int> &heaters) {
    sort(heaters.begin(), heaters.end());
    int res = INT_MIN;
    for (int i = 0; i < houses.size(); ++i) {
      int idx = binary_search(heaters, houses[i]);
      int val_1 = abs(heaters[idx] - houses[i]),
          val_2 = idx == heaters.size() - 1 ? INT_MAX
                                            : abs(heaters[idx + 1] - houses[i]);
      res = max(res, min(val_1, val_2));
    }
    return res;
  }
};

/// 双指针
template <> class Solution<2> {
public:
  int findRadius(vector<int> &houses, vector<int> &heaters) {
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());
    int res = 0, ptr = 0;
    for (int i = 0; i < houses.size(); ++i) {
      while (ptr < heaters.size() - 1 &&
             abs(heaters[ptr] - houses[i]) >= abs(heaters[ptr + 1] - houses[i]))
        ++ptr;
      res = max(res, abs(heaters[ptr] - houses[i]));
    }
    return res;
  }
};