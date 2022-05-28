#include <vector>
using namespace std;

class UnionFind {
public:
  UnionFind(int m, int n) : count(0), m(m), n(n) {
    parent.resize(m * n);
    vec.resize(m, vector<int>(n));
  }
  bool _check(int x, int y) { return !(x < 0 || x == m || y < 0 || y == n); }
  void _add(int x, int y) {
    if (vec[x][y] == 1)
      return;
    ++count;
    vec[x][y] = 1;
    parent[x * n + y] = x * n + y;
    for (int i = 0; i < 4; ++i) {
      int new_x = x + direc[i][0], new_y = y + direc[i][1];
      if (_check(new_x, new_y) && vec[new_x][new_y] == 1) {
        _union(new_x * n + new_y, x * n + y);
      }
    }
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
    if (rootX != rootY) {
      parent[rootX] = rootY;
      --count;
    }
  }
  int _count() const { return count; }

private:
  vector<int> parent;
  vector<vector<int>> direc = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}, vec;
  int count, m, n;
};

class Solution {
public:
  vector<int> numIslands2(int m, int n, vector<vector<int>> &positions) {
    UnionFind uf(m, n);
    vector<int> res;
    for (auto pos : positions) {
      uf._add(pos[0], pos[1]);
      res.push_back(uf._count());
    }
    return res;
  }
};