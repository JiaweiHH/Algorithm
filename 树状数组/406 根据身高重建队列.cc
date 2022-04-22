#include <vector>
using namespace std;

template <int> class Solution;

/// 贪心
template <> class Solution<1> {
public:
  vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
    vector<vector<int>> res(people.size(), vector<int>(2, -1));
    sort(people.begin(), people.end(),
         [](const vector<int> &lhs, const vector<int> &rhs) {
           return lhs[0] < rhs[0] || (lhs[0] == rhs[0] && lhs[1] < rhs[1]);
         });
    for (int i = 0; i < people.size(); ++i) {
      int hight = people[i][0], space = people[i][1];
      for (int j = 0; j < people.size(); ++j) {
        if (res[j][0] == -1 && space == 0) {
          res[j] = people[i];
          break;
        }
        if (res[j][0] >= hight || res[j][0] == -1) {
          --space;
        }
      }
    }
    return res;
  }
};

/// 树状数组
template <> class Solution<2> {
public:
  struct binaryIndexedTree {
    vector<int> tree;
    int n;
    binaryIndexedTree(int n) : n(n) { tree.resize(n + 1); }
    int low_bit(int x) { return x & -x; }
    int query(int x) {
      int res = 0;
      while (x) {
        res += tree[x];
        x -= low_bit(x);
      }
      return res;
    }
    void update(int x, int val) {
      while (x <= n) {
        tree[x] += val;
        x += low_bit(x);
      }
    }
  };

public:
  int binary_search(binaryIndexedTree &tree, int target, int n) {
    int l = 1, r = n;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (tree.query(mid) >= target)
        r = mid - 1;
      else
        l = mid + 1;
    }
    return l;
  }
  vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
    int n = people.size();
    vector<vector<int>> res(n, vector<int>(2));
    binaryIndexedTree tree(n);
    // 初始化每个位置前面还有多少个空位置（包含自身）
    for (int i = 1; i <= n; ++i)
      tree.update(i, 1);
    sort(people.begin(), people.end(), [](vector<int> &lhs, vector<int> &rhs) {
      return lhs[0] < rhs[0] || (lhs[0] == rhs[0] && lhs[1] > rhs[1]);
    });
    for (int i = 0; i < n; ++i) {
      int target = people[i][1] + 1;
      // 找到前面恰好包含 target 个空位置的位置
      int idx = binary_search(tree, target, n);
      res[idx - 1] = people[i];
      // 占据该位置，然后更新后面所有位置的前缀
      tree.update(idx, -1);
    }
    return res;
  }
};