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
/// @note 对于每一根柱子 i，在栈中弹出所有比它高的柱子，然后再将 i 入栈，供 i + 1 比较。
///       虽然这样 i + 1 柱子无法比较到 i 左侧被弹出的柱子，但是这并没有什么问题，
///       因为被 i 弹出的柱子的高度都高于 i，但是 i + 1 在比较的时候是为了寻找到最靠近它的第一个比它低的柱子，
///       所以 i + 1 是不可能考虑到被 i 弹出的柱子的，因为这些柱子都被 i 给挡住了
/// 即 j0 < j1, height[j0] >= height[j1]，那么对于任意在它们之后出现的柱子 i(j1 < i)，
/// j0 一定不会是 i 左侧且最接近的小于其高度的柱子
/// @note 时间复杂度：O(n)，因为每根柱子只会入栈和出栈一次
/// @note 空间复杂度：O(n)
/// 
/// https://leetcode-cn.com/problems/largest-rectangle-in-histogram/solution/zhu-zhuang-tu-zhong-zui-da-de-ju-xing-by-leetcode-/
template <>
class Solution<3> {
public:
  int largestRectangleArea(vector<int> &heights) {
    stack<int> st;
    vector<int> left(heights.size()), right(heights.size());
    // 给所有柱子找到左侧第一个比它低的柱子
    for (int i = 0; i < heights.size(); ++i) {
      // 所有比 heights[i] 高的或者相等的都出栈
      while (!st.empty() && heights[st.top()] >= heights[i])
        st.pop();
      if (!st.empty()) {
        // 最后剩下的就是第一个比 heights[i] 低的
        left[i] = st.top();
      } else {
        left[i] = -1;
      }
      /// @note 将 heights[i] 入栈，给 heights[i + 1] 使用
      /// heights[i + 1] 不需要和比 heights[i] 高的比较，这些 都已经被 heights[i] 弹出了
      /// 这是没有问题的，因为 heights[i] < heights[j] (j < i)，
      /// heights[j] 不可能成为第一个比 heights[i + 1] 低的柱子，前面有 heights[i] 挡着了
      st.push(i);
    }

    // 清空栈
    while (!st.empty())
      st.pop();

    // 给所有柱子找到右侧第一个比它低的柱子
    for (int i = heights.size() - 1; i >= 0; --i) {
      while (!st.empty() && heights[st.top()] >= heights[i])
        st.pop();
      if (!st.empty()) {
        right[i] = st.top();
      } else {
        right[i] = heights.size();
      }
      st.push(i);
    }

    // 现在已经知道了每根柱子左右两个第一个比它小的柱子的位置，可以计算面积了
    int res = 0, area;
    for (int i = 0; i < heights.size(); ++i) {
      area = heights[i] * (right[i] - left[i] - 1);
      res = max(res, area);
    }
    return res;
  }
};

/// @brief 方法三 + 常数优化，只进行一次遍历就求出 left 和 right

/// 当我们在遍历 i0 的时候弹出了 i 时，此时有 heights[i] >= heights[i0]，
/// 并且可以得出在 i 和 i0 之间没有柱子高度比 i 要低，因为如果存在的话在遍历那个位置的时候 i 已经被弹出去了
/// 最后在遍历完所有的柱子的时候，栈中还会剩下一些柱子，这些柱子的右边界都是 heights.size()
/// 
/// 所以可以认为 i0 就是 i 的右边界，当然这是不完全准确的右边界，因为这是 <= 而不是 <
/// 但是对最后的结果没有影响，因为如果有若干个柱子的高度都等于矩形的高度，
/// 那么最右侧的那根柱子是可以正确求出右边界的（因为没有人弹出它了），
/// 但是由于我们没有对寻找左侧边界的算法做任何改动，所以还是可以得出最终正确的解
template <>
class Solution<4> {
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
    // 对于栈中剩下的柱子，它们的右边界都是 heights.size()，因为没有人可以弹出它们
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