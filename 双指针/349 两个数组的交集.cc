#include <unordered_set>
#include <vector>
using namespace std;

template <int> class Solution;

/// 排序 + 双指针
template <> class Solution<1> {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int l = 0, r = 0;
    vector<int> res;
    while (l != nums1.size() && r != nums2.size()) {
      if (nums1[l] < nums2[r])
        ++l;
      else if (nums1[l] > nums2[r])
        ++r;
      else {
        res.push_back(nums1[l]);
        ++l;
        while (l != nums1.size() && nums1[l] == nums1[l - 1])
          ++l;
        ++r;
        while (r != nums2.size() && nums2[r] == nums2[r - 1])
          ++r;
      }
    }
    return res;
  }
};

/// 哈希集合
template <> class Solution<2> {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    unordered_set<int> st;
    vector<int> res;
    for (auto &val : nums1)
      st.insert(val);
    for (auto &val : nums2) {
      if (st.count(val)) {
        res.push_back(val);
        st.erase(val);
      }
    }
    return res;
  }
};