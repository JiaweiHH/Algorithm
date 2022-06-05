#include <vector>
using namespace std;

template <int> class Solution;

/// 贪心
template <> class Solution<1> {
public:
  int jump(vector<int> &nums) {
    int right_max = 0, res = 0, end = 0;
    for (int i = 0; i <= right_max && i != nums.size() - 1; ++i) {
      end = max(i + nums[i], end);
      if (i == right_max) {
        ++res;
        right_max = end;
      }
    }
    return res;
  }
};

/// 暴力
template <> class Solution<2> {
public:
  int jump(vector<int> &nums) {
    int position = nums.size() - 1, res = 0;
    while (position > 0) {
      for (int i = 0; i < position; ++i) {
        if (i + nums[i] >= position) {
          position = i;
          ++res;
          break;
        }
      }
    }
    return res;
  }
};