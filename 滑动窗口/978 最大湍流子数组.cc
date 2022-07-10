#include <vector>
using namespace std;

template <int> class Solution;

/// @brief 滑动窗口
template <> class Solution<1> {
public:
  int maxTurbulenceSize(vector<int> &arr) {
    int l = 0, r = 0, res = 1;
    while (r != arr.size() - 1) {
      if (l == r) {
        // 跳过相同的元素
        if (arr[l] == arr[l + 1])
          ++l;
        ++r;
      } else {
        // 如果 arr[r - 1], arr[r], arr[r + 1] 构成湍流数组，则窗口右移
        // 否则的话，l 需要移动到 r 的位置
        if (arr[r] > arr[r - 1] && arr[r] > arr[r + 1])
          ++r;
        else if (arr[r] < arr[r - 1] && arr[r] < arr[r + 1])
          ++r;
        else
          l = r;
      }
      res = max(res, r - l + 1);
    }
    return res;
  }
};

/// @brief 动态规划
/// dp1[i] 表示以 nums[i] 和 "<" 结尾的数组长度
/// dp2[i] 表示以 nums[i] 和 ">" 结尾的数组长度
template <> class Solution<2> {
public:
  int maxTurbulenceSize(vector<int> &arr) {
    int n = arr.size();
    vector<int> dp1(n), dp2(n);
    // dp1 表示以 < 结尾的数组，dp2 表示以 > 结尾的数组
    dp1[0] = dp2[0] = 1;
    for (int i = 1; i < arr.size(); ++i) {
      if (arr[i] > arr[i - 1]) {
        dp2[i] = dp1[i - 1] + 1;
        dp1[i] = 1;
      } else if (arr[i] < arr[i - 1]) {
        dp1[i] = dp2[i - 1] + 1;
        dp2[i] = 1;
      } else {
        dp1[i] = dp2[i] = 1;
      }
    }
    return max(*max_element(dp1.begin(), dp1.end()),
               *max_element(dp2.begin(), dp2.end()));
  }
};