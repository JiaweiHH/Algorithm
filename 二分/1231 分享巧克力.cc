#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  int maximizeSweetness(vector<int> &sweetness, int k) {
    int l = *min_element(sweetness.begin(), sweetness.end()),
        r = accumulate(sweetness.begin(), sweetness.end(), 0);
    auto check = [&](int target) {
      int cnt = 0, sum = 0;
      for (int i = 0; i < sweetness.size(); ++i) {
        if (sum + sweetness[i] >= target) {
          ++cnt;
          sum = 0;
        } else {
          sum += sweetness[i];
        }
      }
      return cnt >= k + 1;
    };
    while (l <= r) {
      int mid = (l + r) / 2;
      if (check(mid)) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return r;
  }
};