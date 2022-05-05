#include <vector>
using namespace std;

class Solution {
public:
  int binary_search(vector<int> &vec, int l, int r, int target) {
    while (l <= r) {
      int mid = (l + r) / 2;
      if (vec[mid] >= target)
        r = mid - 1;
      else
        l = mid + 1;
    }
    return l;
  }
  int maxEnvelopes(vector<vector<int>> &envelopes) {
    int n = envelopes.size();
    sort(envelopes.begin(), envelopes.end(),
         [](vector<int> &lhs, vector<int> &rhs) {
           return lhs[0] < rhs[0] || (lhs[0] == rhs[0] && lhs[1] > rhs[1]);
         });
    vector<int> vec(n + 1);
    int len = 0;
    for (int i = 0; i < n; ++i) {
      if (envelopes[i][1] > vec[len])
        vec[++len] = envelopes[i][1];
      else {
        int idx = binary_search(vec, 1, len, envelopes[i][1]);
        vec[idx] = envelopes[i][1];
      }
    }
    return len;
  }
};