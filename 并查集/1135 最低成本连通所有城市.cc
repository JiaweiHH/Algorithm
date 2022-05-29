#include <vector>
using namespace std;

class UnionFind {
public:
  UnionFind(int n) : count(n), costs(0) {
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
  bool _union(int x, int y, int cost) {
    int root_x = _find(x), root_y = _find(y);
    if (root_x == root_y)
      return false;
    parent[root_x] = root_y;
    costs += cost;
    --count;
    return true;
  }
  int _count() const { return count; }
  int _costs() const { return costs; }

private:
  vector<int> parent;
  int count, costs;
};

class Edge {
public:
  Edge(int _len, int _x, int _y) : len(_len), x(_x), y(_y) {}
  bool operator<(const Edge &rhs) { return len < rhs.len; }
  int len, x, y;
};

class Solution {
public:
  int minimumCost(int n, vector<vector<int>> &connections) {
    UnionFind uf(n);
    vector<Edge> edges;
    for (int i = 0; i < connections.size(); ++i)
      edges.emplace_back(connections[i][2], connections[i][0],
                         connections[i][1]);
    sort(edges.begin(), edges.end());
    for (auto &e : edges)
      uf._union(e.x, e.y, e.len);
    return uf._count() == 1 ? uf._costs() : -1;
  }
};