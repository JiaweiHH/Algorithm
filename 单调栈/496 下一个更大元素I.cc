#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    vector<int> res(nums1.size());
    unordered_map<int, int> map;
    stack<int> stk;
    for (int i = 0; i < nums2.size(); ++i) {
      while (!stk.empty() && nums2[i] > nums2[stk.top()]) {
        int idx = stk.top();
        stk.pop();
        map[nums2[idx]] = nums2[i];
      }
      stk.push(i);
    }
    for (int i = 0; i < nums1.size(); ++i) {
      res[i] = map[nums1[i]] == 0 ? -1 : map[nums1[i]];
    }
    return res;
  }
};