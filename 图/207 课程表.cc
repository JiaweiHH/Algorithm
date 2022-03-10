#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> edges;
  vector<int> visited;
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    visited.resize(numCourses);
    edges.resize(numCourses);
    for (auto &e : prerequisites)
      edges[e[0]].push_back(e[1]);
    for (int i = 0; i < numCourses; ++i) {
      if (!visited[i]) {
        visited[i] = 1;
        bool tmp = dfs(i);
        if (!tmp)
          return false;
      }
    }
    return true;
  }
  bool dfs(int index) {
    for (auto &i : edges[index]) {
      if (visited[i] == 1)
        return false;
      if (visited[i] == 2)
        continue;
      visited[i] = 1;
      bool tmp = dfs(i);
      if (!tmp)
        return false;
    }
    visited[index] = 2;
    return true;
  }
};