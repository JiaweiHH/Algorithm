#include <vector>
using namespace std;

template <int> class Solution;

/// 使用数组
template <> class Solution<1> {
public:
  bool isPalindrome(int x) {
    if (x < 0)
      return false;
    vector<int> num;
    while (x) {
      int tmp = x % 10;
      x = x / 10;
      num.push_back(tmp);
    }
    int l = 0, r = num.size() - 1;
    while (l <= r) {
      if (num[l] != num[r])
        return false;
      l++;
      r--;
    }
    return true;
  }
};

/// 构造一个反转的数
template <> class Solution<2> {
public:
  bool isPalindrome(int x) {
    if (x < 0)
      return false;
    long long y = 0, z = x;
    while (x) {
      int tmp = x % 10;
      x = x / 10;
      y = y * 10 + tmp;
    }
    return z == y;
  }
};