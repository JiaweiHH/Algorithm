#include <unordered_map>
#include <vector>
using namespace std;

template <int> class Solution;

/// 排序 + 双指针
template <> class Solution<1> {
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> res;
    int pA = 0, pB = 0;
    while (pA < nums1.size() && pB < nums2.size()) {
      if (nums1[pA] == nums2[pB]) {
        res.push_back(nums1[pA]);
        ++pA;
        ++pB;
      } else if (nums1[pA] < nums2[pB])
        ++pA;
      else
        ++pB;
    }
    return res;
  }
};

/// 哈希
template <> class Solution<2> {
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> map;
    for (auto val : nums1)
      ++map[val];
    vector<int> res;
    for (auto val : nums2) {
      if (map.count(val)) {
        res.push_back(val);
        if (--map[val] == 0)
          map.erase(val);
      }
    }
    return res;
  }
};