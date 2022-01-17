#include <vector>
#include <stack>
using namespace std;

template <int>
class Solution {};

/// @brief 给出 n 个柱子的高度，每个柱子彼此相邻并且宽度为 1，求出在该柱状图中能够勾勒出的矩形的最大面积

/// @brief 方法 1，这也是 85 最大矩形的一种解题方法（85 题通过构造出柱状图，然后用该方法）
/// 对每一根柱子初始情况下记录其高度 height 为 heights[i]，面积 area = height
/// 遍历其后的所有柱子，对于每一根柱子更新 height = min(height, height[j])，
/// 然后计算新的面积 area = max(height * (j - i + 1))。
/// 最后取所有 area 的最大值
template <>
class Solution<1> {
public:
  int largestRectangleArea(vector<int> &heights) {
    int res = 0;
    for (int i = 0; i < heights.size(); ++i) {
      int height = heights[i];
      int area = height;
      for (int j = i + 1; j < heights.size(); ++j) {
        height = min(height, heights[j]);
        area = max(area, height * (j - i + 1));
      }
      res = max(res, area);
    }
    return res;
  }
};

/// @brief 方法 2
/// 只需要遍历一次，每次对于柱子 i，分别向左和向右延伸直到遇到高度小于 heights[i] 的柱子，记录其索引为 k 和 j
/// 则最后根据柱子 i 计算出的面积 area = (j - k + 1) * heights[i]
/// 取所有的 area 的最大值
template <>
class Solution<2> {
public:
  int largestRectangleArea(vector<int> &heights) {
    int n = heights.size();
    int ans = 0;
    for (int mid = 0; mid < n; ++mid) {
      // 枚举高
      int height = heights[mid];
      int left = mid, right = mid;
      // 确定左右边界
      while (left - 1 >= 0 && heights[left - 1] >= height) {
        --left;
      }
      while (right + 1 < n && heights[right + 1] >= height) {
        ++right;
      }
      // 计算面积
      ans = max(ans, (right - left + 1) * height);
    }
    return ans;
  }
};

/// 上述两种方法的时间复杂度均为 O(n^2)，最后提交的时候会超时

/// @brief 方法三，在方法二的基础上使用单调栈改进，栈中的所有柱子按照高度低到高保存，并且索引也严格有序
///        使用单调栈找到每一根柱子左侧最靠近它但是比它低的柱子，同样的方法找到右侧的柱子
/// @note 时间复杂度：O(n)，因为每根柱子只会入栈和出栈一次
/// @note 空间复杂度：O(n)
template <> class Solution<3> {
public:
  int largestRectangleArea(vector<int> &heights) {
    int n = heights.size();
    vector<int> left(n, -1), right(n, n);
    stack<int> stk;
    // 找到左侧第一个比它低的柱子
    for (int i = 0; i < n; ++i) {
      while (!stk.empty() && heights[i] <= heights[stk.top()])
        stk.pop();
      if (!stk.empty())
        left[i] = stk.top();
      stk.push(i);
    }
    while (!stk.empty())
      stk.pop();
    // 找到右侧第一个比它低的柱子
    for (int i = n - 1; i >= 0; --i) {
      while (!stk.empty() && heights[i] <= heights[stk.top()])
        stk.pop();
      if (!stk.empty())
        right[i] = stk.top();
      stk.push(i);
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
      res = max(res, heights[i] * (right[i] - left[i] - 1));
    }
    return res;
  }
};

/// @brief 方法三 + 常数优化，只进行一次遍历就求出 left 和 right
template <> class Solution<4> {
public:
  int largestRectangleArea(vector<int> &heights) {
    stack<int> st;
    vector<int> left(heights.size()), right(heights.size());
    for (int i = 0; i < heights.size(); ++i) {
      while (!st.empty() && heights[st.top()] >= heights[i]) {
        right[st.top()] = i;
        st.pop();
      }
      left[i] = st.empty() ? -1 : st.top();
      st.push(i);
    }
    // 对于栈中剩下的柱子，它们的右边界都是
    // heights.size()，因为没有人可以弹出它们
    while (!st.empty()) {
      right[st.top()] = heights.size();
      st.pop();
    }
    int res = 0;
    for (int i = 0; i < heights.size(); ++i) {
      res = max(res, (right[i] - left[i] - 1) * heights[i]);
    }
    return res;
  }
};