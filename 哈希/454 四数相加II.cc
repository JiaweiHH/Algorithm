#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3,
                   vector<int> &nums4) {
    unordered_map<int, int> count_1_2;
    for (auto v1 : nums1) {
      for (auto v2 : nums2) {
        ++count_1_2[v1 + v2];
      }
    }
    int res = 0;
    for (auto v3 : nums3) {
      for (auto v4 : nums4) {
        if (count_1_2.count(-v3 - v4))
          res += count_1_2[-v3 - v4];
      }
    }
    return res;
  }
};