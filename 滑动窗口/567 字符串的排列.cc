#include <string>
#include <unordered_map>
using namespace std;

template <int> class Solution;

/// 滑动窗口 1：找到第一个出现在 s1 的字符，然后开始窗口的滑动
template <> class Solution<1> {
public:
  bool checkInclusion(string s1, string s2) {
    unordered_map<char, int> map;
    for (auto &ch : s1)
      ++map[ch];
    for (int i = 0; i < s2.size(); ++i) {
      if (!map.count(s2[i]))
        continue;
      unordered_map<char, int> cur;
      int l = i, r = i, valid = 0;
      while (r != s2.size()) {
        char ch = s2[r];
        if (!map.count(ch))
          break;
        if (++cur[ch] == map[ch])
          ++valid;
        if (valid == map.size())
          return true;
        while (cur[ch] > map[ch]) {
          if (cur[s2[l]]-- == map[s2[l]])
            --valid;
          ++l;
        }
        ++r;
      }
      i = r;
    }
    return false;
  }
};

/// 滑动窗口 2：固定窗口的长度滑动，判断此时窗口内部的字符是不是和 s1 中的一样
template <> class Solution<2> {
public:
  bool checkInclusion(string s1, string s2) {
    unordered_map<char, int> map;
    for (auto &ch : s1)
      ++map[ch];
    int l = 0, r = 0, valid = 0;
    unordered_map<char, int> cur;
    while (r != s2.size()) {
      char ch = s2[r];
      if (map.count(ch) && ++cur[ch] == map[ch]) {
        if (++valid == map.size())
          return true;
      }
      while (r - l + 1 >= s1.size()) {
        if (map.count(s2[l]) && cur[s2[l]]-- == map[s2[l]])
          --valid;
        ++l;
      }
      ++r;
    }
    return false;
  }
};