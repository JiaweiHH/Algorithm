#include <vector>
using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size(), n = nums2.size();
    if ((m + n) % 2 == 1) {
      int k = (m + n + 1) >> 1;
      return getKthEle(nums1, nums2, k);
    } else {
      int k = (m + n) >> 1;
      double ele1 = getKthEle(nums1, nums2, k),
             ele2 = getKthEle(nums1, nums2, k + 1);
      return (ele1 + ele2) / 2;
    }
  }
  double getKthEle(vector<int> &nums1, vector<int> &nums2, int k) {
    // 对于 nums1 和 nums2，判断 nums1[k / 2 - 1] 和 nums2[k / 2 - 1] 的大小
    // if nums1[k / 2 - 1] < nums2[k / 2 - 1]，那么说明 nums1[k / 2 - 1] 至多是合并之后数组的第 k / 2 - 1 + k / 2 - 1 + 1 = k - 1 个元素，所以可以跳过 nums1[0...k/2 - 1]
    // if nums1[k / 2 - 1] > nums2[k / 2 - 1]，那么跳过 nums2[0...k / 2 - 1]
    // if nums1[k / 2 - 1] == nums2[k / 2 - 1]，按照第一种情况处理
    int m = nums1.size(), n = nums2.size();
    int idx1 = 0, idx2 = 0;
    while (true) {
      if (idx1 == m)
        return nums2[idx2 + k - 1];
      if (idx2 == n)
        return nums1[idx1 + k - 1];
      if (k == 1)
        return min(nums1[idx1], nums2[idx2]);
      int new_idx1 = min(idx1 + k / 2 - 1, m - 1),
          new_idx2 = min(idx2 + k / 2 - 1, n - 1);
      if (nums1[new_idx1] <= nums2[new_idx2]) {
        k -= new_idx1 - idx1 + 1;
        idx1 = new_idx1 + 1;
      } else if (nums1[new_idx1] > nums2[new_idx2]) {
        k -= new_idx2 - idx2 + 1;
        idx2 = new_idx2 + 1;
      }
    }
  }
};