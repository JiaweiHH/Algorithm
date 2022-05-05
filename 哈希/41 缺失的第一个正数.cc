#include <vector>
using namespace std;

template <int> class Solution;

/// 哈希1
template <> class Solution<1> {
public:
  int firstMissingPositive(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i)
      if (nums[i] <= 0)
        nums[i] = n + 1;
    for (int i = 0; i < n; ++i) {
      // 标记数组的下标作为类似于 “哈希” 的作用
      int tmp = abs(nums[i]);
      if (tmp <= n)
        nums[tmp - 1] = -abs(nums[tmp - 1]);
    }
    for (int i = 0; i < n; ++i) {
      if (nums[i] > 0)
        return i + 1;
    }
    return n + 1;
  }
};

/// 哈希2
template <> class Solution<2> {
public:
  int firstMissingPositive(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < nums.size(); ++i) {
      int tmp = nums[i];
      while (tmp > 0 && tmp <= n && nums[tmp - 1] != tmp) {
        int tmp_1 = nums[tmp - 1];
        nums[tmp - 1] = tmp;
        tmp = tmp_1;
      }
    }
    for (int i = 0; i < n; ++i) {
      if (nums[i] != i + 1)
        return i + 1;
    }
    return n + 1;
  }
};