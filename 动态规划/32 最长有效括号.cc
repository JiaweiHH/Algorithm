#include <vector>
#include <string>
#include <stack>
using namespace std;

template <int>
class Solution {};

/// @brief 给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号字串的长度

/// @brief 暴力方法，最后会超时
/// 每次对于 i 到 j 的字符串，判断是不是符合条件的
template <> class Solution<1> {
public:
  int longestValidParentheses(string s) {
    int m = s.size();
    int res = 0;
    for (int i = 0; i < m; ++i) {
      if (s[i] != '(')
        continue;
      for (int j = i + 1; j < m; j += 2) {
        if (isValid(s.substr(i, j - i + 1))) {
          res = max(res, j - i + 1);
        }
      }
    }
    return res;
  }
  bool isValid(string s) {
    stack<char> stk;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(')
        stk.push(s[i]);
      else {
        if (stk.empty())
          return false;
        stk.pop();
      }
    }
    if (stk.empty())
      return true;
    return false;
  }
};

/// @brief 动态规划
/// dp[i] 表示以 i 结尾的字符串的最长有效括号字串的长度，则如果 s[i] == '('，dp[i] 都等于 0
/// 1. 如果 s[i] == ')' 并且 s[i - 1] == '('，那么 dp[i] = dp[i - 2] + 2.
/// 2. 如果 s[i] == ')' 并且 s[i - 1] == ')'，那么说明字串的形式是 ...))，考虑 s[i - dp[i - 1] - 1] 这个字符结尾的字串，
/// 2.1 如果 s[i - dp[i - 1] - 1] == '('，那么 dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2，
///     即跳过 i - 1 匹配好的所有字符，然后 s[i - dp[i - 1] - 1] 又和 s[i] 匹配了，那么继续尝试连接 s[i - dp[i - 1] - 2]
/// 2.2 否则 dp[i] = dp[i - 1] + 2。即现在只能连接到 s[i - dp[i - 1]]，有效的长度就是 dp[i - 1] 的长度
template <> class Solution<2> {
public:
  int longestValidParentheses(string s) {
    int m = s.size();
    vector<int> dp(m, 0);
    for (int i = 0; i < m; ++i) {
      if (s[i] == '(')
        continue;
      if (i - 1 >= 0 && s[i - 1] == '(') {
        dp[i] = ((i - 2 >= 0) ? dp[i - 2] : 0) + 2;
      } else if (i - 1 >= 0 && s[i - 1] == ')') {
        if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
          dp[i] = dp[i - 1] +
                  ((i - dp[i - 1] - 2 >= 0) ? dp[i - dp[i - 1] - 2] : 0) + 2;
        }
      }
    }
    return !dp.empty() ? *max_element(dp.begin(), dp.end()) : 0;
  }
};

/// @brief 使用栈
/// 遍历字符串，对于每个索引 i ，如果 s[i] = '(' 则将其放入栈中，如果 s[i] = ')' 则弹出栈顶元素。
/// 那么对于下标 i 来说，以它结尾的字符串的最长有效括号的长度就等于 i - top，top 是当前栈顶元素的下标。
/// 
/// 最后当遇到 s[i] = ')' 并且栈为空的时候就将 i 自己入栈，用来告诉后面的字符，这是第一个不满足匹配要求的下标。并且此时以 i 结尾的答案是 0
/// 即栈底始终存放第一个不匹配的下标
template <> class Solution<3> {
public:
  int longestValidParentheses(string s) {
    stack<int> stk;
    // 避免第一个不匹配的 ')' 没有东西弹出
    stk.push(-1);
    int res = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(')
        stk.push(i);
      else {
        stk.pop();
        if (!stk.empty()) {
          int index = stk.top();
          res = max(res, i - index);
        } else {
          stk.push(i);
        }
      }
    }
    return res;
  }
};

/// @brief 使用双指针
/// 初始 left 和 right 都等于 0，首先从左到右遍历字符串，遇到一个 '(' left++，遇到一个 ')' right++，
/// 如果 left = right，那么计算此时以当前遍历到的下标为结尾的最长有效括号长度，
/// 如果 right > left，那么丢弃之前所有的字符串，令 left 和 right 重新恢复到 0
/// 
/// 上述这么做不能找出左括号多余右括号时候的答案，例如 (((())。解决方法是从右到左再遍历一次，此时 left 和 right 的职责刚好反了一下
template <> class Solution<4> {
public:
  int longestValidParentheses(string s) {
    int left = 0, right = 0, res = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(')
        left++;
      else if (s[i] == ')')
        right++;

      if (left == right)
        res = max(res, left + right);
      else if (right > left) {
        left = right = 0;
      }
    }
    left = right = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
      if (s[i] == ')')
        right++;
      else if (s[i] == '(')
        left++;

      if (left == right)
        res = max(res, left + right);
      else if (left > right) {
        left = right = 0;
      }
    }
    return res;
  }
};