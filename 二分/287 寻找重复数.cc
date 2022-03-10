#include <vector>
using namespace std;

template <int> class Solution;

/// 二分
template <> class Solution<1> {
public:
  int findDuplicate(vector<int> &nums) {
    int n = nums.size() - 1;
    int left = 1, right = n;
    int res = -1;
    while (left <= right) {
      int mid = (left + right) >> 1;
      int cnt = 0;
      for (int i = 0; i < nums.size(); ++i)
        cnt += nums[i] <= mid;
      if (cnt <= mid)
        left = mid + 1;
      else {
        right = mid - 1;
        res = mid;
      }
    }
    return res;
  }
};

/// 位运算
template <> class Solution<2> {
public:
  int findDuplicate(vector<int> &nums) {
    int n = nums.size() - 1;
    int res = 0, bitmax = 0;
    int tmp = n;
    while (tmp) {
      tmp = tmp >> 1;
      bitmax++;
    }
    for (int bit = 0; bit <= bitmax; ++bit) {
      int x = 0, y = 0;
      for (int i = 1; i <= n; ++i)
        if (i & (1 << bit))
          x++;
      for (int i = 0; i < nums.size(); ++i)
        if (nums[i] & (1 << bit))
          y++;
      if (x < y)
        res |= (1 << bit);
    }
    return res;
  }
};

/// 双指针（快慢指针）
template <> class Solution<3> {
public:
  int findDuplicate(vector<int> &nums) {
    int slow = 0, fast = 0;
    while (fast != nums.size()) {
      slow = nums[slow];
      if (nums[fast] != nums.size())
        fast = nums[nums[fast]];
      if (slow == fast)
        break;
    }
    slow = 0;
    while (nums[slow] != nums[fast]) {
      slow = nums[slow];
      fast = nums[fast];
    }
    return nums[slow];
  }
};