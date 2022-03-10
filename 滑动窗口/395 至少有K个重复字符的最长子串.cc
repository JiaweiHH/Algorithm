#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

template <int> class Solution;

/// 分治
template <> class Solution<1> {
public:
  int longestSubstring(string s, int k) { return dfs(s, 0, s.size() - 1, k); }
  int dfs(const string &s, int l, int r, int k) {
    unordered_map<char, int> map;
    for (int i = l; i <= r; ++i)
      map[s[i]]++;
    char split = 0;
    for (auto it = map.begin(); it != map.end(); ++it) {
      if (it->second < k) {
        split = it->first;
        break;
      }
    }
    if (split == 0)
      return r - l + 1;
    int res = 0;
    while (l <= r) {
      while (l <= r && s[l] == split)
        l++;
      if (l > r)
        break;
      int start = l;
      while (l <= r && s[l] != split)
        l++;
      res = max(res, dfs(s, start, l - 1, k));
    }
    return res;
  }
};

/// 滑动窗口
template <> class Solution<2> {
public:
  int longestSubstring(string s, int k) {
    unordered_set<char> st;
    for (int i = 0; i < s.size(); ++i) {
      if (!st.count(s[i]))
        st.insert(s[i]);
    }
    int n = st.size();
    int len = 0;
    // 枚举滑动窗口内出现字符种类的数量
    for (int i = 1; i <= n; ++i) {
      // num 记录当前窗口内出现次数小于 k 的字符种数
      int left = 0, right = 0, num = 0;
      unordered_map<char, int> map;
      while (right != s.size()) {
        char ch = s[right];
        if (!map.count(ch))
          num++;
        if (++map[ch] == k)
          num--;
        // 窗口中字符的种类大于 i，开始收缩窗口
        while (map.size() > i) {
          map[s[left]]--;
          if (map[s[left]] == 0) {
            num--;
            map.erase(s[left]);
          } else if (map[s[left]] == k - 1)
            num++;
          left++;
        }
        // 窗口中的字符，出现的次数都大于等于 k
        if (num == 0)
          len = max(len, right - left + 1);
        right++;
      }
    }
    return len;
  }
};