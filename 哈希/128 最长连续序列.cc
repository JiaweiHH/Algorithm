#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    int res = 0;
    unordered_set<int> st;
    for (auto &val : nums)
      st.insert(val);
    for (auto &val : nums) {
      if (!st.count(val - 1)) {
        int cur = val + 1;
        int len = 1;
        while (st.count(cur)) {
          cur++;
          len++;
        }
        res = max(res, len);
      }
    }
    return res;
  }
};