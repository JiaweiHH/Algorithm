#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  string minWindow(string s, string t) {
    unordered_map<char, int> map;
    for (auto &ch : t)
      map[ch]++;
    int left = 0, right = 0, valid = 0;
    int start, len = INT_MAX;
    unordered_map<char, int> window;
    while (right != s.size()) {
      int tmp = s[right];
      if (map.count(tmp)) {
        window[tmp]++;
        if (window[tmp] == map[tmp])
          valid++;
      }
      right++;
      while (left < right && valid == map.size()) {
        if (right - left < len) {
          len = right - left;
          start = left;
        }
        char ch = s[left];
        if (window.count(ch)) {
          if (--window[ch] < map[ch])
            valid--;
        }
        left++;
      }
    }
    return len == INT_MAX ? "" : s.substr(start, len);
  }
};