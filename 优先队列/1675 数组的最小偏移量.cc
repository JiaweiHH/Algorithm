#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumDeviation(vector<int> &nums) {
    priority_queue<int, vector<int>, less<int>> heap;
    int min_value = INT_MAX, res = INT_MAX;
    for (int i = 0; i < nums.size(); ++i) {
      int val = nums[i] % 2 == 0 ? nums[i] : nums[i] * 2;
      heap.push(val);
      min_value = min(min_value, val);
    }
    while (heap.top() % 2 == 0) {
      int val = heap.top();
      heap.pop();
      res = min(res, val - min_value);
      heap.push(val / 2);
      min_value = min(min_value, val / 2);
    }
    res = min(res, heap.top() - min_value);
    return res;
  }
};