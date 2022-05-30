#include <vector>
using namespace std;

template <int> class Solution;

class UnionFind {
public:
  UnionFind(int n) : count(n) {
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

/// 并查集
template <> class Solution<1> {
public:
  int minSwapsCouples(vector<int> &row) {
    UnionFind uf(row.size() / 2);
    for (int i = 0; i < row.size(); i += 2)
      uf._union(row[i] / 2, row[i + 1] / 2);
    return row.size() / 2 - uf._count();
  }
};

/// 贪心
template <> class Solution<2> {
public:
  int minSwapsCouples(vector<int> &row) {
    int n = row.size(), res = 0;
    // 预处理，记录每个编号所在的下标
    vector<int> vec(n);
    for (int i = 0; i < n; ++i)
      vec[row[i]] = i;
    // 计算需要交换的次数
    for (int i = 0; i < n; i += 2) {
      int pair = row[i] ^ 1; // row[i] 的情侣编号
      if (vec[pair] != i + 1) {
        ++res;
        swap(row[i + 1], row[vec[pair]]);
        swap(vec[row[i + 1]], vec[row[vec[pair]]]);
      }
    }
    return res;
  }
};