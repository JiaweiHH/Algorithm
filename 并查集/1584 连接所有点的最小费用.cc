#include <vector>
using namespace std;

class UnionFind {
public:
  UnionFind(int n) {
    parent.resize(n);
    for (int i = 0; i < n; ++i)
      parent[i] = i;
  }
  int _find(int x) {
    while (x != parent[x]) {
      parent[x] = parent[parent[x]];
      x = parent[x];
    }
    return x;
  }
  void _union(int x, int y) {
    int rootX = _find(x), rootY = _find(y);
    if (rootX != rootY)
      parent[rootX] = rootY;
  }

private:
  vector<int> parent;
};

class Edge {
public:
  Edge(int _len, int _x, int _y) : len(_len), x(_x), y(_y) {}
  bool operator<(const Edge &rhs) { return len < rhs.len; }

  int len, x, y;
};

class Solution {
public:
  int minCostConnectPoints(vector<vector<int>> &points) {
    vector<Edge> vec;
    for (int i = 0; i < points.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        int len =
            abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
        vec.emplace_back(len, i, j);
      }
    }
    sort(vec.begin(), vec.end());
    UnionFind uf(points.size());
    int res = 0;
    for (int i = 0; i < vec.size(); ++i) {
      int len = vec[i].len, x = vec[i].x, y = vec[i].y;
      if (uf._find(x) == uf._find(y))
        continue;
      uf._union(x, y);
      res += len;
    }
    return res;
  }
};