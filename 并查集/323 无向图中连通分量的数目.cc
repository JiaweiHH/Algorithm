#include <vector>
using namespace std;

class UnionFind {
public:
  UnionFind(int n) : count(n) {
    for (int i = 0; i < n; ++i)
      parent.push_back(i);
  }
  int _find(int x) {
    while (x != parent[x]) {
      parent[x] = parent[parent[x]];
      x = parent[x];
    }
    return x;
  }
  void _union(int x, int y) {
    int root_x = _find(x), root_y = _find(y);
    if (root_x != root_y) {
      parent[root_x] = root_y;
      --count;
    }
  }
  int _count() const { return count; }

private:
  vector<int> parent;
  int count;
};

class Solution {
public:
  int countComponents(int n, vector<vector<int>> &edges) {
    UnionFind uf(n);
    for (int i = 0; i < edges.size(); ++i) {
      uf._union(edges[i][0], edges[i][1]);
    }
    return uf._count();
  }
};