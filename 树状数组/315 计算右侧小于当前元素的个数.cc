#include <vector>
using namespace std;

template <int> class Solution;

/// 归并排序
template <> class Solution<1> {
public:
  vector<int> res;
  void merge_sort(vector<pair<int, int>> &vec, int l, int r) {
    if (l >= r)
      return;
    int mid = (l + r) / 2;
    merge_sort(vec, l, mid);
    merge_sort(vec, mid + 1, r);
    // 归并
    vector<pair<int, int>> tmp;
    int pA = l, pB = mid + 1;
    while (pA <= mid && pB <= r) {
      if (vec[pA].first > vec[pB].first) {
        tmp.push_back(vec[pB]);
        ++pB;
      } else {
        tmp.push_back(vec[pA]);
        res[vec[pA].second] += pB - (mid + 1);
        ++pA;
      }
    }
    while (pA <= mid) {
      tmp.push_back(vec[pA]);
      res[vec[pA].second] += pB - (mid + 1);
      ++pA;
    }
    while (pB <= r)
      tmp.push_back(vec[pB++]);
    copy(tmp.begin(), tmp.end(), vec.begin() + l);
  }
  vector<int> countSmaller(vector<int> &nums) {
    res.resize(nums.size());
    // vec 记录每个元素和自身的下标
    vector<pair<int, int>> vec(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
      vec[i].first = nums[i];
      vec[i].second = i;
    }
    merge_sort(vec, 0, nums.size() - 1);
    return res;
  }
};

/// 树状数组
template <> class Solution<2> {
public:
  vector<int> countSmaller(vector<int> &nums) {
    int n = nums.size();
    vector<int> res(n), index(n + 1);
    binaryIndexedTree tree(n);
    // 将 nums 按顺序离散到 index
    copy(nums.begin(), nums.end(), index.begin() + 1);
    sort(index.begin() + 1, index.end());
    index.erase(unique(index.begin() + 1, index.end()), index.end());
    // 计算前缀和
    for (int i = n - 1; i >= 0; --i) {
      int l = 1, r = n;
      while (l <= r) {
        int mid = (l + r) / 2;
        if (index[mid] >= nums[i])
          r = mid - 1;
        else
          l = mid + 1;
      }
      res[i] = tree.query(l - 1);
      tree.update(l, 1);
    }
    return res;
  }

private:
  struct binaryIndexedTree {
    vector<int> tree;
    int n;
    binaryIndexedTree(int n) : n(n) { tree.resize(n + 1); }
    int low_bit(int x) { return x & -x; }
    // 计算前缀和
    int query(int x) {
      int res = 0;
      while (x) {
        res += tree[x];
        x -= low_bit(x);
      }
      return res;
    }
    // 更新前缀和
    void update(int x, int val) {
      while (x <= n) {
        tree[x] += val;
        x += low_bit(x);
      }
    }
  };
};