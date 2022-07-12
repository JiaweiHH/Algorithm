#include <string>
#include <vector>
using namespace std;

template <int> class Solution;

/// @brief 暴力翻转
template <> class Solution<1> {
public:
  string reverseWords(string s) {
    string res;
    int prev = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == ' ') {
        string str = s.substr(prev, i - prev);
        reverse(str.begin(), str.end());
        res.append(str);
        res.push_back(' ');
        prev = i + 1;
      }
    }
    string str = s.substr(prev);
    reverse(str.begin(), str.end());
    res.append(str);
    return res;
  }
};

/// @brief 双指针原地交换
template <> class Solution<2> {
public:
  string reverseWords(string s) {
    vector<int> pos;
    for (int i = 0; i < s.size(); ++i)
      if (s[i] == ' ')
        pos.push_back(i);
    pos.push_back(s.size());
    int pA = 0;
    for (int i = 0; i < pos.size(); ++i) {
      int pB = pos[i] - 1;
      while (pA <= pB)
        swap(s[pA++], s[pB--]);
      pA = pos[i] + 1;
    }
    return s;
  }
};