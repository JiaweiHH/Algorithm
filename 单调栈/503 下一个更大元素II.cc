#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> nextGreaterElements(vector<int> &nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> stk;
    for (int i = 0; i < n; ++i) {
      while (!stk.empty() && nums[i] > nums[stk.top()]) {
        int idx = stk.top();
        stk.pop();
        res[idx] = nums[i];
      }
      stk.push(i);
    }
    for (int i = 0; i < n; ++i) {
      while (!stk.empty() && nums[i] > nums[stk.top()]) {
        int idx = stk.top();
        stk.pop();
        res[idx] = nums[i];
      }
    }
    return res;
  }
};