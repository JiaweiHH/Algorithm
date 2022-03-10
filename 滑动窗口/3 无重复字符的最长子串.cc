#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<int, int> map;
    int left = 0, right = 0;
    int res = 0;
    while (right != s.size()) {
      map[s[right]]++;
      while (map[s[right]] > 1) {
        res = max(res, right - left);
        map[s[left]]--;
        if (s[left] == s[right]) {
          left++;
          break;
        }
        left++;
      }
      right++;
    }
    return max(res, right - left);
  }
};