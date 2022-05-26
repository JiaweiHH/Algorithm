#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

template <int> class Solution;

/// 哈希
template <> class Solution<1> {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> st;
    for (int i = 0; i < nums.size(); ++i)
      st.insert(nums[i]);
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (!st.count(nums[i] - 1)) {
        int cnt = 1, tmp = nums[i];
        while (st.count(tmp + 1)) {
          ++cnt;
          ++tmp;
        }
        res = max(res, cnt);
      }
    }
    return res;
  }
};

/// 并查集
template <> class UnionFind {
public:
  UnionFind(vector<int> &nums) : max_cnt(1) {
    for (auto num : nums) {
      map[num] = num;
      cnt[num] = 1;
    }
  }
  int _find(int x) {
    while (x != map[x]) {
      map[x] = map[map[x]];
      x = map[x];
    }
    return x;
  }
  void _union(int x, int y) {
    int rootX = _find(x), rootY = _find(y);
    if (rootX != rootY) {
      map[rootX] = rootY;
      cnt[rootY] += cnt[rootX];
      max_cnt = max(max_cnt, cnt[rootY]);
    }
  }
  bool _count(int x) { return map.count(x); }
  int _cnt() { return max_cnt; }

private:
  unordered_map<int, int> map;
  unordered_map<int, int> cnt;
  int max_cnt;
};

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    if (nums.empty())
      return 0;
    UnionFind uf(nums);
    for (auto num : nums) {
      if (uf._count(num - 1))
        uf._union(num, num - 1);
      if (uf._count(num + 1))
        uf._union(num, num + 1);
    }
    return uf._cnt();
  }
};