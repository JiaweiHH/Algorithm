#include <queue>
#include <vector>
using namespace std;

template <int> class Solution;

/// 优先队列
template <> class Solution<1> {
public:
  vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
                                     int k) {
    vector<vector<int>> res;
    auto cmp = [&](pair<int, int> &lhs, pair<int, int> &rhs) {
      return nums1[lhs.first] + nums2[lhs.second] >
             nums1[rhs.first] + nums2[rhs.second];
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> heap(
        cmp);
    int m = nums1.size(), n = nums2.size();
    for (int i = 0; i < m; ++i)
      heap.push({i, 0});
    while (k-- && !heap.empty()) {
      auto [x, y] = heap.top();
      heap.pop();
      if (y + 1 < n)
        heap.push({x, y + 1});
      res.push_back({nums1[x], nums2[y]});
    }
    return res;
  }
};

/// 二分
template <> class Solution<2> {
public:
  vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
                                     int k) {
    vector<vector<int>> res;
    int m = nums1.size(), n = nums2.size();
    auto count = [&](int target) {
      int pA = 0, pB = n - 1;
      int64_t cnt = 0;
      while (pA < m && pB >= 0) {
        if (nums1[pA] + nums2[pB] > target)
          --pB;
        else {
          cnt += pB + 1;
          ++pA;
        }
      }
      return cnt;
    };

    // 找到恰好有大于等于 k 对数对的和等于某个目标值
    int64_t l = nums1[0] + nums2[0], r = nums1[m - 1] + nums2[n - 1];
    while (l <= r) {
      int64_t mid = l + (r - l) / 2;
      ;
      int64_t tmp = count(mid);
      if (count(mid) >= k)
        r = mid - 1;
      else
        l = mid + 1;
    }
    int64_t target_sum = l;
    // 找出所有和小于 target_sum 的数对
    int pA = 0, pB = n - 1;
    while (pA < m && pB >= 0) {
      if (nums1[pA] + nums2[pB] >= target_sum)
        --pB;
      else {
        for (int j = 0; j <= pB; ++j) {
          res.push_back({nums1[pA], nums2[j]});
          --k;
        }
        ++pA;
      }
    }
    // 找出所有和等于 target_sum 的数对
    pA = 0, pB = n - 1;
    while (pA < m && pB >= 0 && k) {
      if (nums1[pA] + nums2[pB] > target_sum)
        --pB;
      else if (nums1[pA] + nums2[pB] < target_sum)
        ++pA;
      else {
        int tmp = pB;
        while (tmp >= 0 && nums2[tmp] == nums2[pB] && k > 0) {
          res.push_back({nums1[pA], nums2[tmp]});
          --tmp;
          --k;
        }
        ++pA;
      }
    }
    return res;
  }
};