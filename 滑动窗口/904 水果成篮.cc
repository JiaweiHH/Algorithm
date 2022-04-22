#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int totalFruit(vector<int> &fruits) {
    int l = 0, r = 0, res = 0;
    unordered_map<int, int> map;
    while (r != fruits.size()) {
      int val = fruits[r];
      ++map[val];
      while (map.size() > 2) {
        if (--map[fruits[l]] == 0)
          map.erase(fruits[l]);
        ++l;
      }
      res = max(res, r - l + 1);
      ++r;
    }
    return res;
  }
};