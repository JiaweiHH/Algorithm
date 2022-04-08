#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
    if (n == 1)
      return {0};
    unordered_map<int, vector<int>> graph;
    vector<int> degree(n, 0);
    for (auto &e : edges) {
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
      ++degree[e[0]];
      ++degree[e[1]];
    }
    queue<int> que;
    int remain_nodes = n;
    for (int i = 0; i < n; ++i)
      if (degree[i] == 1)
        que.push(i);
    while (remain_nodes > 2) {
      int sz = que.size();
      for (int i = 0; i < sz; ++i) {
        int v = que.front();
        que.pop();
        --remain_nodes;
        for (auto &node : graph[v])
          if (--degree[node] == 1)
            que.push(node);
      }
    }
    vector<int> res;
    while (!que.empty()) {
      int v = que.front();
      que.pop();
      res.push_back(v);
    }
    return res;
  }
};