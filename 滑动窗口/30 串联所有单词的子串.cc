#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findSubstring(string s, vector<string> &words) {
    unordered_map<string, int> map;
    for (int i = 0; i < words.size(); ++i)
      ++map[words[i]];
    int len = words[0].size(), count = words.size(), i = 0;
    vector<int> res;
    for (i = 0; i < s.size() - words.size() * len + 1; ++i) {
      int valid = 0;
      unordered_map<string, int> cur_map;
      for (int j = 0; j < count; ++j) {
        string str = s.substr(i + j * len, len);
        if (map.count(str)) {
          if (++cur_map[str] == map[str])
            valid++;
        } else {
          break;
        }
      }
      if (valid == map.size())
        res.push_back(i);
    }
    return res;
  }
};