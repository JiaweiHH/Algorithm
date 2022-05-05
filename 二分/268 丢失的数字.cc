#include <vector>
using namespace std;

template <int> class Solution;

// 排序 + 二分
template <> class Solution<1> {
public:
  int missingNumber(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (nums[mid] > mid)
        r = mid - 1;
      else
        l = mid + 1;
    }
    return l;
  }
};

// 位运算
template <> class Solution<2> {
public:
  int missingNumber(vector<int> &nums) {
    int val = nums[0];
    for (int i = 1; i < nums.size(); ++i)
      val ^= nums[i];
    for (int i = 0; i <= nums.size(); ++i)
      val ^= i;
    return val;
  }
};