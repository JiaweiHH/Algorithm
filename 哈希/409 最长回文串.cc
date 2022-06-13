#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int longestPalindrome(string s) {
    unordered_map<char, int> map;
    for (int i = 0; i < s.size(); ++i)
      ++map[s[i]];
    int res = 0, cnt = 0;
    for (auto it = map.begin(); it != map.end(); ++it) {
      if (it->second % 2 == 0 || it->second < cnt)
        res += it->second % 2 == 0 ? it->second : it->second - 1;
      else {
        res += cnt == 0 ? it->second : it->second - 1;
        cnt = it->second;
      }
    }
    return res;
  }
};