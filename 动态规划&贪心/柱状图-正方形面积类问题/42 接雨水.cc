#include <vector>
#include <stack>
using namespace std;

template <int>
class Solution {};

/// @brief 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子下雨之后能接多少雨水

/// @brief 大体思路类似 84 题，但是也有些许区别
/// 84 题对于柱子 i 是向左右两侧延伸找出第一根小于 height[i] 的柱子就停止，
/// 但是这里是分别找出左右两侧高度最高的柱子
/// 
/// 原因是这里是接雨水，只要左右两侧有更高的柱子挡住那么对于柱子 i 上面的空间的雨水是一定能被接到的
/// 所以对于柱子 i 能够接到的雨水 count = min(left[i], right[i]) - height[i]
/// 
/// 这里另外用了动态规划来求左右两侧最高的柱子，以左侧为例，left[i] 表示柱子 i 左侧的最高柱子（包括 i），
/// 那么对于柱子 i + 1 来说，left[i + 1] = max(left[i], height[i + 1])，
/// 即从柱子 i 左侧最高的柱子和柱子 i + 1 的高度比较得到柱子 i + 1 左侧的最高柱子
/// 
/// @note 时间复杂度：O(n), 空间复杂度：O(n)
template <>
class Solution<1> {
public:
  int trap(vector<int> &height) {
    int n = height.size();
    vector<int> left(n, height[0]), right(n, height[n - 1]);
    // 动态规划求出每根柱子左侧和右侧最高的那根柱子
    for (int i = 1; i < n; ++i)
      left[i] = max(left[i - 1], height[i]);
    for (int i = n - 2; i >= 0; --i)
      right[i] = max(right[i + 1], height[i]);

    int res = 0;
    for (int i = 0; i < n; ++i)
      res += min(left[i], right[i]) - height[i];
    return res;
  }
};

/// @brief 84 题用了单调栈的做法，这里同样可以使用
/// 维护一个单调栈，单调栈存储的是下标，满足从栈底到栈顶的下标对应的数组 height 中的元素递减
/// 
/// 从左到右遍历数组，当遍历到下标 i 时，如果栈内至少有两个元素，记栈顶的元素为 top，top 下面的元素为 left
/// 则一定有 height[left] >= height[top]，
/// 则可以得到一个接雨水的区域，width = i - left - 1，height = min(height[left], height[i]) - height[top]
/// 相当于用 left 这个柱子和 i 这个柱子把 top 这个柱子围住
/// 
/// 每次计算完之后相当于 top 空的空间都被填充了，所以将 top 出栈，
/// 重复操作直到栈变为空或者 height[stack.top()] >= height[i]
/// 
/// 在对下标 i 计算完成之后，将 i 入栈，继续遍历后续的下标
/// 
/// @note 时间复杂度：O(n)，空间复杂度：O(n)
template <>
class Solution<2> {
public:
  int trap(vector<int> &height) {
    stack<int> stack;
    int res = 0;
    for (int i = 0; i < height.size(); ++i) {
      while (!stack.empty() && height[i] > height[stack.top()]) {
        int mid = stack.top();
        stack.pop();
        if (stack.empty())
          break;
        int left = stack.top();
        res += (i - left - 1) * (min(height[i], height[left]) - height[mid]);
      }
      stack.push(i);
    }
    return res;
  }
};

/// @brief 使用双指针优化动态规划算法，空间复杂度降低为 O(1)
template <>
class Solution<3> {
public:
  int trap(vector<int> &height) {
    int ans = 0;
    int left = 0, right = height.size() - 1;
    int leftMax = 0, rightMax = 0;
    while (left < right) {
      leftMax = max(leftMax, height[left]);
      rightMax = max(rightMax, height[right]);
      if (height[left] < height[right]) {
        ans += leftMax - height[left];
        ++left;
      } else {
        ans += rightMax - height[right];
        --right;
      }
    }
    return ans;
  }
};