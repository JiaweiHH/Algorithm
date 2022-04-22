#include <vector>
using namespace std;

template <int> class Solution;

/// 树状数组
template <> class Solution<1> {
public:
  int binary_search(vector<int> &index, int target) {
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
  int reversePairs(vector<int> &nums) {
    int n = nums.size(), res = 0;
    vector<int> index(n + 1);
    binaryIndexedTree tree(n);
    // 离散化 nums
    copy(nums.begin(), nums.end(), index.begin() + 1);
    sort(index.begin() + 1, index.end());
    index.erase(unique(index.begin() + 1, index.end()), index.end());
    // 计算结果
    for (int i = n - 1; i >= 0; --i) {
      int target =
          nums[i] < 0 || nums[i] % 2 == 0 ? nums[i] / 2 - 1 : nums[i] / 2;
      int idx = binary_search(index, target);
      res += idx == index.size() || index[idx] != target ? tree.query(idx - 1)
                                                         : tree.query(idx);
      idx = binary_search(index, nums[i]);
      tree.update(idx, 1);
    }
    return res;
  }

private:
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
};

/// 归并排序
template <> class Solution<2> {
public:
  int merge_sort(vector<int> &nums, vector<int> &tmp, int l, int r) {
    if (l >= r)
      return 0;
    int mid = (l + r) / 2;
    int res = merge_sort(nums, tmp, l, mid) + merge_sort(nums, tmp, mid + 1, r);
    // 统计 [l, mid] 中每个数，在 [mid + 1, r] 中满足 nums[i] > 2 * nums[j]
    // 的元素个数
    int p_window = mid + 1;
    for (int i = l; i <= mid; ++i) {
      while (p_window <= r && (int64_t)nums[p_window] * 2 < nums[i])
        ++p_window;
      res += p_window - (mid + 1);
    }
    // 归并排序
    int pA = l, pB = mid + 1, pos = l;
    while (pA <= mid && pB <= r) {
      if (nums[pA] > nums[pB])
        tmp[pos] = nums[pB++];
      else
        tmp[pos] = nums[pA++];
      ++pos;
    }
    while (pA <= mid)
      tmp[pos++] = nums[pA++];
    while (pB <= r)
      tmp[pos++] = nums[pB++];
    copy(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
    return res;
  }
  int reversePairs(vector<int> &nums) {
    vector<int> tmp(nums.size());
    return merge_sort(nums, tmp, 0, nums.size() - 1);
  }
};