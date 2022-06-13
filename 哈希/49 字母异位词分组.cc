#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> res;
    unordered_map<string, vector<string>> map;
    for (auto &str : strs) {
      string tmp = str;
      sort(tmp.begin(), tmp.end());
      map[tmp].push_back(str);
    }
    for (auto it = map.begin(); it != map.end(); ++it)
      res.push_back(it->second);
    return res;
  }
};