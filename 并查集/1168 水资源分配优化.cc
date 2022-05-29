#include <vector>
using namespace std;

class UnionFind {
public:
  UnionFind(int n) : cost(0) {
    parent.resize(n + 1);
    for (int i = 1; i <= n; ++i)
      parent[i] = i;
  }
  int _find(int x) {
    while (x != parent[x]) {
      parent[x] = parent[parent[x]];
      x = parent[x];
    }
    return x;
  }
  void _union(int x, int y, int _cost) {
    int root_x = _find(x), root_y = _find(y);
    if (root_x != root_y) {
      parent[root_x] = root_y;
      cost += _cost;
    }
  }

  vector<int> parent;
  int cost;
};

class Solution {
public:
  int minCostToSupplyWater(int n, vector<int> &wells,
                           vector<vector<int>> &pipes) {
    UnionFind uf(n);
    for (int i = 0; i < wells.size(); ++i)
      pipes.push_back({0, i + 1, wells[i]});
    sort(pipes.begin(), pipes.end(),
         [](vector<int> &lhs, vector<int> &rhs) { return lhs[2] < rhs[2]; });
    for (int i = 0; i < pipes.size(); ++i)
      uf._union(pipes[i][0], pipes[i][1], pipes[i][2]);
    return uf.cost;
  }
};