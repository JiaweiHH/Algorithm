#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  // unordered_set<string> res;
  vector<string> res;
  void dfs(unordered_map<char, int> &map, string &str, int idx) {
    if (idx < 0) {
      res.push_back(str);
      return;
    }
    for (auto &[ch, cnt] : map) {
      if (cnt == 0)
        continue;
      cnt -= 2;
      str[idx] = str[str.size() - idx - 1] = ch;
      dfs(map, str, idx - 1);
      cnt += 2;
    }
  }
  vector<string> generatePalindromes(string s) {
    // 统计字符出现次数
    unordered_map<char, int> map;
    for (auto ch : s)
      ++map[ch];
    // 获取奇数次数的字符
    int odd_cnt = 0;
    char odd_ch = ' ';
    for (auto [ch, cnt] : map) {
      if (cnt % 2) {
        odd_ch = ch;
        if (++odd_cnt > 1)
          return {};
      }
    }
    if (odd_cnt <= 1) {
      string str(s.size(), odd_ch);
      if (map.count(odd_ch)) {
        if (--map[odd_ch] == 0)
          map.erase(odd_ch);
      }
      dfs(map, str, s.size() / 2 - 1);
    }
    return res;
  }
};