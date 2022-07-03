#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<string>> groupStrings(vector<string> &strings) {
    auto hash_func = [fn = hash<int>{}](const vector<int> &vec) -> size_t {
      return accumulate(vec.begin(), vec.end(), 0u, [&](size_t acc, int num) {
        return (acc << 1) ^ fn(num);
      });
    };
    unordered_map<vector<int>, vector<string>, decltype(hash_func)> map(
        0, hash_func);
    for (auto &str : strings) {
      vector<int> vec;
      for (int i = 1; i < str.size(); ++i)
        vec.push_back((str[i] - str[i - 1] + 26) % 26);
      map[vec].push_back(str);
    }
    vector<vector<string>> res;
    for (auto it = map.begin(); it != map.end(); ++it)
      res.push_back(it->second);
    return res;
  }
};