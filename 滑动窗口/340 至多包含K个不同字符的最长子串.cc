#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    unordered_map<char, int> map;
    int l = 0, r = 0, len = 0;
    while (r != s.size()) {
      char ch = s[r];
      map[ch]++;
      while (map.size() > k) {
        len = max(len, r - l);
        if (--map[s[l]] == 0)
          map.erase(s[l]);
        ++l;
      }
      ++r;
    }
    len = max(len, r - l);
    return len;
  }
};