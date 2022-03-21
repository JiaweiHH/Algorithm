#include <vector>
using namespace std;

template <int> class Solution;

/// 双指针 O(n) 空间复杂度
template <> class Solution<1> {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    vector<int> vec;
    int p1 = 0, p2 = 0;
    while (p1 != m && p2 != n) {
      int tmp = nums1[p1] < nums2[p2] ? nums1[p1++] : nums2[p2++];
      vec.push_back(tmp);
    }
    if (p1 != m) {
      for (int i = p1; i < m; ++i)
        vec.push_back(nums1[i]);
    }
    if (p2 != n) {
      for (int i = p2; i < n; ++i)
        vec.push_back(nums2[i]);
    }
    for (int i = 0; i < m + n; ++i)
      nums1[i] = vec[i];
  }
};

/// 逆向双指针 O(1) 空间复杂度
template <> class Solution<2> {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int p1 = m - 1, p2 = n - 1, tail = m + n - 1;
    while (p1 >= 0 && p2 >= 0)
      nums1[tail--] = nums1[p1] > nums2[p2] ? nums1[p1--] : nums2[p2--];
    if (p1 >= 0)
      return;
    while (p2 >= 0)
      nums1[tail--] = nums2[p2--];
  }
};