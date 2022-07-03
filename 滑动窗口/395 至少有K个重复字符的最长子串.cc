#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

template <int> class Solution;

/// 分治
template <> class Solution<1> {
public:
  int dfs(const string &str, int l, int r, int k) {
    unordered_map<char, int> count;
    for (int i = l; i <= r; ++i)
      ++count[str[i]];
    // 找到出现次数小于 k 的字符，按照这个字符分割字符串
    // 然后递归计算
    char split = 0;
    for (auto it = count.begin(); it != count.end(); ++it)
      if (it->second < k) {
        split = it->first;
        break;
      }
    if (split == 0) // 没有出现次数小于 k 的字符
      return r - l + 1;
    int res = 0;
    while (l <= r) {
      while (l <= r && str[l] == split)
        ++l;
      if (l > r)
        break;
      int start = l;
      while (l <= r && str[l] != split)
        ++l;
      res = max(res, dfs(str, start, l - 1, k));
    }
    return res;
  }
  int longestSubstring(string s, int k) { return dfs(s, 0, s.size() - 1, k); }
};

/// 滑动窗口
template <> class Solution<2> {
public:
  int longestSubstring(string s, int k) {
    int res = 0;
    for (int i = 1; i <= 26; ++i) {
      int l = 0, r = 0, less = 0;
      unordered_map<char, int> cnt;
      while (r != s.size()) {
        if (++cnt[s[r]] == 1)
          ++less;
        if (cnt[s[r]] == k)
          --less;
        while (cnt.size() > i) {
          --cnt[s[l]];
          if (cnt[s[l]] == 0) {
            --less;
            cnt.erase(s[l]);
          } else if (cnt[s[l]] == k - 1) {
            ++less;
          }
          ++l;
        }
        if (less == 0)
          res = max(res, r - l + 1);
        ++r;
      }
    }
    return res;
  }
};