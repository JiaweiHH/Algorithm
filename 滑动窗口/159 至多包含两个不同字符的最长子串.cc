#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstringTwoDistinct(string s) {
    int l = 0, r = 0, res = 0;
    unordered_map<char, int> map;
    while (r != s.size()) {
      char ch = s[r];
      ++map[ch];
      while (map.size() > 2) {
        res = max(res, r - l);
        if (--map[s[l]] == 0)
          map.erase(s[l]);
        ++l;
      }
      ++r;
    }
    res = max(res, r - l);
    return res;
  }
};