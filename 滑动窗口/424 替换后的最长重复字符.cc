#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int characterReplacement(string s, int k) {
    int l = 0, r = 0, count = 0, res = 0;
    unordered_map<char, int> map;
    while (r != s.size()) {
      ++map[s[r]];
      count = max(count, map[s[r]]);
      while (r - l + 1 - count > k) {
        if (--map[s[l]] == 0)
          map.erase(s[l]);
        ++l;
      }
      res = max(res, r - l + 1);
      ++r;
    }
    return res;
  }
};