#include <string>
#include <vector>
using namespace std;

/// 给定一个非负整数 N，找出小于或等于 N 的最大的整数，同时这个整数需要满足其各个位数上的数字是单调递增
/// （当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。）

template <int> class Solution;

/// 时间复杂度 O(n)，空间复杂度 O(n)
/// 对 n 从后往前遍历每一位数字，如果发现 digits[i] > digits[i + 1]，那么 digits[i] - 1，然后第 i 位之后的数字都设置为 9
template <> class Solution<1> {
public:
  int monotoneIncreasingDigits(int n) {
    vector<int> digits;
    while (n) {
      int t = n % 10;
      n /= 10;
      digits.insert(digits.begin(), t);
    }
    for (int i = digits.size() - 2; i >= 0; --i) {
      if (digits[i] > digits[i + 1]) {
        digits[i + 1] = 9;
        digits[i]--;
      }
    }
    int res = 0, flag = false;
    for (int i = 0; i < digits.size(); ++i) {
      if (flag)
        res = res * 10 + 9;
      else {
        res = res * 10 + digits[i];
        if (digits[i] == 9)
          flag = true;
      }
    }
    return res;
  }
};

/// 相同的思路，官方代码更加优雅的实现
template <> class Solution<2> {
public:
  int monotoneIncreasingDigits(int n) {
    string strN = to_string(n);
    int i = 1;
    while (i < strN.length() && strN[i - 1] <= strN[i]) {
      i += 1;
    }
    if (i < strN.length()) {
      while (i > 0 && strN[i - 1] > strN[i]) {
        strN[i - 1] -= 1;
        i -= 1;
      }
      for (i += 1; i < strN.length(); ++i) {
        strN[i] = '9';
      }
    }
    return stoi(strN);
  }
};