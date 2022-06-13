#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size())
      return false;
    unordered_map<char, int> map;
    for (int i = 0; i < s.size(); ++i) {
      ++map[s[i]];
      --map[t[i]];
    }
    for (auto it = map.begin(); it != map.end(); ++it)
      if (it->second != 0)
        return false;
    return true;
  }
};