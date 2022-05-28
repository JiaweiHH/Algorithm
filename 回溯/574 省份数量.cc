#include <vector>
using namespace std;

class Solution {
public:
  vector<int> visit;
  int n;
  void dfs(vector<vector<int>> &isConnected, int idx) {
    visit[idx] = true;
    for (int i = 0; i < n; ++i) {
      if (i == idx)
        continue;
      if (!visit[i] && isConnected[idx][i])
        dfs(isConnected, i);
    }
  }
  int findCircleNum(vector<vector<int>> &isConnected) {
    n = isConnected[0].size();
    visit.resize(n);
    int res = 0;
    for (int i = 0; i < n; ++i) {
      if (!visit[i]) {
        dfs(isConnected, i);
        ++res;
      }
    }
    return res;
  }
};