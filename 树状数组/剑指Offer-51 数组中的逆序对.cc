#include <vector>
using namespace std;

template <int> class Solution;

/// 归并排序
template <> class Solution<2> {
public:
  vector<int> index, res;
  int merge_sort(vector<int> &nums, int l, int r) {
    if (l >= r)
      return 0;
    int mid = (l + r) / 2;
    int res = merge_sort(nums, l, mid) + merge_sort(nums, mid + 1, r);
    // 归并
    int pA = l, pB = mid + 1;
    vector<int> tmp;
    while (pA <= mid && pB <= r) {
      if (nums[pA] > nums[pB]) {
        tmp.push_back(nums[pB]);
        ++pB;
      } else {
        tmp.push_back(nums[pA]);
        ++pA;
        res += pB - (mid + 1);
      }
    }
    while (pA <= mid) {
      tmp.push_back(nums[pA]);
      ++pA;
      res += pB - (mid + 1);
    }
    while (pB <= r)
      tmp.push_back(nums[pB++]);
    copy(tmp.begin(), tmp.end(), nums.begin() + l);
    return res;
  }
  int reversePairs(vector<int> &nums) {
    return merge_sort(nums, 0, nums.size() - 1);
  }
};

/// 树状数组
template <> class Solution<2> {
public:
  int reversePairs(vector<int> &nums) {
    int n = nums.size(), res = 0;
    binaryIndexedTree tree(n);
    vector<int> index(n + 1, INT_MIN);
    // 离散化 nums 数组
    copy(nums.begin(), nums.end(), index.begin() + 1);
    sort(index.begin() + 1, index.end());
    index.erase(unique(index.begin() + 1, index.end()), index.end());
    // 查找前缀
    for (int i = nums.size() - 1; i >= 0; --i) {
      int l = 1, r = index.size() - 1;
      while (l <= r) {
        int mid = (l + r) / 2;
        if (index[mid] >= nums[i])
          r = mid - 1;
        else
          l = mid + 1;
      }
      res += tree.query(l - 1);
      tree.update(l, 1);
    }
    return res;
  }

private:
  struct binaryIndexedTree {
    vector<int> tree; // 保存前 i 项的前缀和
    int n;
    binaryIndexedTree(int n) : n(n) { tree.resize(n + 1); }
    int low_bit(int x) { return x & -x; }
    // 计算前 x 项的前缀和
    int query(int x) {
      int res = 0;
      while (x) {
        res += tree[x];
        x -= low_bit(x);
      }
      return res;
    }
    // 更新 x ~ n 的前缀和
    void update(int x, int val) {
      while (x <= n) {
        tree[x] += val;
        x += low_bit(x);
      }
    }
  };
};