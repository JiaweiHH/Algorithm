#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> map;
    int l = 0, r = 0;
    int res = 0;
    while (r != s.size()) {
      char ch = s[r];
      ++map[ch];
      while (map[ch] > 1) {
        res = max(res, r - l);
        --map[s[l]];
        ++l;
      }
      ++r;
    }
    res = max(res, r - l);
    return res;
  }
};