#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool canPermutePalindrome(string s) {
    unordered_map<char, int> map;
    for (auto ch : s)
      ++map[ch];
    int count = 0;
    for (auto [ch, cnt] : map) {
      if (cnt % 2) {
        if (++count > 1)
          return false;
      }
    }
    return true;
  }
};