#include <stack>
#include <string>
using namespace std;

template <int> class Solution;

/// @brief 栈
template <> class Solution<1> {
public:
  bool isValid(string s) {
    stack<int> st;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == ')') {
        if (st.empty() || st.top() != '(')
          return false;
        st.pop();
      } else if (s[i] == ']') {
        if (st.empty() || st.top() != '[')
          return false;
        st.pop();
      } else if (s[i] == '}') {
        if (st.empty() || st.top() != '{')
          return false;
        st.pop();
      } else {
        st.push(s[i]);
      }
    }
    return st.empty();
  }
};

/// @brief "左括号必须以正确的顺序闭合" 这个条件去掉
template <> class Solution<2> {
public:
  bool isValid(string s) {
    int n1 = 0, n2 = 0, n3 = 0;
    for (auto ch : s) {
      switch (ch) {
      case ')':
        if (--n1 < 0)
          return false;
        break;
      case ']':
        if (--n2 < 0)
          return false;
        break;
      case '}':
        if (--n3 < 0)
          return false;
      case '(':
        ++n1;
        break;
      case '[':
        ++n2;
        break;
      default:
        ++n3;
        break;
      }
    }
    return true;
  }
};