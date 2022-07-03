#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    unordered_map<char, int> map;
    for (auto ch : p)
      ++map[ch];
    vector<int> res;
    int len = static_cast<int>(s.size()) - static_cast<int>(p.size());
    for (int i = 0; i <= len; ++i) {
      if (!map.count(s[i]))
        continue;
      int l = i, r = i, valid = 0;
      unordered_map<char, int> cur;
      while (r != s.size()) {
        if (!map.count(s[r]))
          break;
        if (++cur[s[r]] == map[s[r]])
          ++valid;
        while (cur[s[r]] > map[s[r]]) {
          if (cur[s[l]]-- == map[s[l]])
            --valid;
          ++l;
        }
        if (valid == map.size())
          res.push_back(l);
        ++r;
      }
      i = r;
    }
    return res;
  }
};