#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  int shipWithinDays(vector<int> &weights, int days) {
    int l = *max_element(weights.begin(), weights.end()),
        r = accumulate(weights.begin(), weights.end(), 0);
    auto check = [&](int target) {
      int sum = 0, cnt = 0;
      for (int i = 0; i < weights.size(); ++i) {
        if (sum + weights[i] > target) {
          sum = weights[i];
          ++cnt;
        } else {
          sum += weights[i];
        }
      }
      return ++cnt <= days;
    };
    while (l <= r) {
      int mid = (l + r) / 2;
      if (check(mid))
        r = mid - 1;
      else
        l = mid + 1;
    }
    return l;
  }
};