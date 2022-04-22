#include <vector>
using namespace std;

template <int> class Solution;

/// 动态规划
template <> class Solution<1> {
public:
  int findLength(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size(), m = nums2.size();
    vector<vector<int>> dp(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
      dp[i][0] = nums1[i] == nums2[0] ? 1 : 0;
    for (int j = 0; j < m; ++j)
      dp[0][j] = nums2[j] == nums1[0] ? 1 : 0;
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < m; ++j) {
        if (nums1[i] == nums2[j])
          dp[i][j] = dp[i - 1][j - 1] + 1;
        else
          dp[i][j] = 0;
      }
    }
    int res = 0;
    for (auto &vec : dp)
      for (auto &v : vec)
        res = max(res, v);
    return res;
  }
};

/// 滑动窗口
template <> class Solution<2> {
public:
  int findLength(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size(), n = nums2.size();
    int res = 0;
    for (int i = 0; i < m; ++i) {
      int len = min(n, m - i);
      int tmp = findMaxLength(nums1, nums2, i, 0, len);
      res = max(res, tmp);
    }
    for (int i = 0; i < n; ++i) {
      int len = min(m, n - i);
      int tmp = findMaxLength(nums1, nums2, 0, i, len);
      res = max(res, tmp);
    }
    return res;
  }
  int findMaxLength(const vector<int> &nums1, const vector<int> &nums2, int pA,
                    int pB, int len) {
    int res = 0, cnt = 0;
    for (int i = 0; i < len; ++i) {
      if (nums1[pA + i] == nums2[pB + i])
        ++cnt;
      else
        cnt = 0;
      res = max(res, cnt);
    }
    return res;
  }
};