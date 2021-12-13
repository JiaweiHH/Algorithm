#include <string>
#include <vector>
using namespace std;

/// @brief 给出一个由字符串表示的整数 num 和一个整数 k，移除这个数中的 k
/// 位数字，使得剩下的数字最小。返回这个最小数字的字符串形式

template <int> class Solution;

/// @brief 贪心
/// 只要靠前位数的数字尽可能的小，那么最后的数字也会尽可能的小
/// 对于数字 num 来说，如果 num[i - 1] > num[i] 就移除 i - 1 位上的字符，
/// 如果没有出现这样的情况就说明整个数字每位上的树是单调递增的，那么移除最后一位数字
template <> class Solution<1> {
public:
  string removeKdigits(string num, int k) {
    while (k--) {
      int len = num.size();
      if (len == 1)
        num = "";
      for (int i = 1; i < len; ++i) {
        if (num[i - 1] > num[i]) {
          num.erase(i - 1, 1);
          break;
        }
      }
      if (len == num.size())
        num.erase(num.size() - 1, 1);
    }
    while (!num.empty() && num[0] == '0')
      num.erase(0, 1);
    return num == "" ? "0" : num;
  }
};

/// @brief 贪心 + 单调栈
/// 每次弹出栈中所有比自己大的数字并执行 k--，然后将自己压入栈
template <> class Solution<2> {
public:
  string removeKdigits(string num, int k) {
    vector<char> stk;
    for (const auto &digit : num) {
      while (k && stk.size() > 0 && stk.back() > digit) {
        k--;
        stk.pop_back();
      }
      stk.push_back(digit);
    }
    while (k > 0) {
      stk.pop_back();
      k--;
    }
    string res;
    bool isLeadingDigit = true;
    for (int i = 0; i < stk.size(); ++i) {
      if (isLeadingDigit && stk[i] == '0')
        continue;
      isLeadingDigit = false;
      res.push_back(stk[i]);
    }
    return res == "" ? "0" : res;
  }
};