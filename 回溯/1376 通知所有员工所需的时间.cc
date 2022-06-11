#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int res = 0;
  void dfs(int index, unordered_map<int, vector<int>> &map,
           vector<int> &informTime, int &cur) {
    if (!map.count(index)) {
      res = max(res, cur);
      return;
    }
    cur += informTime[index];
    for (auto idx : map[index]) {
      dfs(idx, map, informTime, cur);
    }
    cur -= informTime[index];
  }
  int numOfMinutes(int n, int headID, vector<int> &manager,
                   vector<int> &informTime) {
    unordered_map<int, vector<int>> map;
    for (int i = 0; i < manager.size(); ++i)
      map[manager[i]].push_back(i);
    int cur = 0;
    dfs(headID, map, informTime, cur);
    return res;
  }
};