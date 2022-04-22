#include <vector>
using namespace std;

template <int> class Solution;

/// 归并排序
template <> class Solution<1> {
public:
  int merge_sort(vector<int64_t> &prefix, vector<int64_t> &tmp, int l, int r,
                 int min_diff, int max_diff) {
    if (l >= r)
      return 0;
    int mid = (l + r) / 2;
    int res = merge_sort(prefix, tmp, l, mid, min_diff, max_diff) +
              merge_sort(prefix, tmp, mid + 1, r, min_diff, max_diff);
    // 统计 prefix[i]（l <= i <= mid） 在 [mid + 1, r] 中满足差值在 [min_diff, max_diff] 区间的数量
    int window_l = mid + 1, window_r = mid + 1;
    for (int i = l; i <= mid; ++i) {
      while (window_l <= r && prefix[i] + min_diff > prefix[window_l])
        ++window_l;
      while (window_r <= r && prefix[i] + max_diff >= prefix[window_r])
        ++window_r;
      res += window_r - window_l;
    }
    // 归并
    int pA = l, pB = mid + 1, pos = l;
    while (pA <= mid && pB <= r) {
      if (prefix[pA] > prefix[pB])
        tmp[pos] = prefix[pB++];
      else
        tmp[pos] = prefix[pA++];
      ++pos;
    }
    while (pA <= mid)
      tmp[pos++] = prefix[pA++];
    while (pB <= r)
      tmp[pos++] = prefix[pB++];
    copy(tmp.begin() + l, tmp.begin() + r + 1, prefix.begin() + l);
    return res;
  }
  int countRangeSum(vector<int> &nums, int lower, int upper) {
    int n = nums.size(), res = 0;
    vector<int64_t> prefix(n);
    for (int i = 0; i < n; ++i) {
      prefix[i] = i > 0 ? prefix[i - 1] + nums[i] : nums[i];
      res += (prefix[i] >= lower && prefix[i] <= upper) ? 1 : 0;
    }
    vector<int64_t> tmp(n);
    return res + merge_sort(prefix, tmp, 0, n - 1, lower, upper);
  }
};

/// 树状数组
template <> class Solution<2> {
public:
  int binary_search(vector<int64_t> &index, int64_t target) {
    int l = 1, r = index.size() - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (index[mid] >= target)
        r = mid - 1;
      else
        l = mid + 1;
    }
    return l;
  }
  int countRangeSum(vector<int> &nums, int lower, int upper) {
    int n = nums.size(), res = 0;
    vector<int64_t> prefix(n), index(n + 1, LONG_MIN);
    binaryIndexedTree tree(n);
    for (int i = 0; i < n; ++i)
      prefix[i] = i > 0 ? prefix[i - 1] + nums[i] : nums[i];
    // 离散化 prefix
    copy(prefix.begin(), prefix.end(), index.begin() + 1);
    sort(index.begin() + 1, index.end());
    index.erase(unique(index.begin() + 1, index.end()), index.end());
    // 计算前缀
    for (int i = 0; i < n; ++i) {
      int x = binary_search(index, prefix[i] - upper),
          y = binary_search(index, prefix[i] - lower);
      if (x != index.size())
        res += y == index.size() || index[y] != prefix[i] - lower
                   ? tree.query(x, y - 1)
                   : tree.query(x, y);
      int z = binary_search(index, prefix[i]);
      tree.update(z, 1);
      if (prefix[i] >= lower && prefix[i] <= upper)
        ++res;
    }
    return res;
  }

private:
  struct binaryIndexedTree {
    vector<int64_t> tree;
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
    int query(int x, int y) { return query(y) - query(x - 1); }
    void update(int x, int64_t val) {
      while (x <= n) {
        tree[x] += val;
        x += low_bit(x);
      }
    }
  };
};