#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    int n = temperatures.size();
    stack<int> stk;
    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
      while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
        int index = stk.top();
        stk.pop();
        res[index] = i - index;
      }
      stk.push(i);
    }
    return res;
  }
};