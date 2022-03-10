#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> res;
    unordered_map<string, vector<string>> mp;
    for (auto &str : strs) {
      string key = str;
      sort(key.begin(), key.end());
      mp[key].push_back(str);
    }
    for (auto it = mp.begin(); it != mp.end(); ++it)
      res.push_back(it->second);
    return res;
  }
};