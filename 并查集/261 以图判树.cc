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
  bool _union(int x, int y) {
    int root_x = _find(x), root_y = _find(y);
    if (root_x == root_y)
      return false;
    parent[root_x] = root_y;
    --count;
    return true;
  }
  int _count() const { return count; }

private:
  vector<int> parent;
  int count;
};

class Solution {
public:
  bool validTree(int n, vector<vector<int>> &edges) {
    UnionFind uf(n);
    for (vector<int> &e : edges) {
      if (!uf._union(e[0], e[1]))
        return false;
    }
    return uf._count() == 1;
  }
};