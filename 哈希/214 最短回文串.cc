#include <string>
#include <unordered_map>
using namespace std;

template <int> class Solution;

/// 中心扩展枚举，会超时
template <> class Solution<1> {
public:
  string centralExpand(string &s, int l, int r) {
    string tmp;
    while (l >= 0 && r < s.size() && s[l] == s[r]) {
      --l;
      ++r;
    }
    if ((l >= 0 && r != s.size()) || l >= 0)
      return s;
    if (r != s.size()) {
      while (r != s.size()) {
        tmp.insert(tmp.end(), s[r]);
        ++r;
      }
      reverse(tmp.begin(), tmp.end());
      return tmp + s;
    }
    return "";
  }
  bool check(string &s) {
    if (s.empty())
      return true;
    int l = 0, r = s.size() - 1;
    while (l <= r) {
      if (s[l] != s[r])
        return false;
      ++l;
      --r;
    }
    return true;
  }
  string shortestPalindrome(string s) {
    if (check(s))
      return s;
    string res;
    int len = INT_MAX;
    for (int i = 0; i < s.size(); ++i) {
      string tmp = centralExpand(s, i, i);
      if (tmp != s && tmp.size() < len) {
        res = tmp;
        len = res.size();
      }
      tmp = centralExpand(s, i, i + 1);
      if (tmp != s && tmp.size() < len) {
        res = tmp;
        len = res.size();
      }
    }
    return res;
  }
};

/// 哈希
template <> class Solution<2> {
public:
  string shortestPalindrome(string s) {
    long l = 0, r = 0, mul = 1;
    int mod = 1000000007, base = 131, pos = -1;
    for (int i = 0; i < s.size(); ++i) {
      l = (l * base + s[i]) % mod;
      r = (mul * s[i] + r) % mod;
      if (l == r)
        pos = i;
      mul = (mul * base) % mod;
    }
    string str = pos == s.size() - 1 ? "" : s.substr(pos + 1);
    reverse(str.begin(), str.end());
    return str + s;
  }
};