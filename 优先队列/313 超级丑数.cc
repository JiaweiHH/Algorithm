#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int nthSuperUglyNumber(int n, vector<int> &primes) {
    vector<int> res{1};
    unordered_set<int64_t> st;
    auto cmp = [](vector<int64_t> &lhs, vector<int64_t> &rhs) {
      return lhs[0] > rhs[0];
    };
    priority_queue<vector<int64_t>, vector<vector<int64_t>>, decltype(cmp)>
        heap(cmp);
    for (int i = 0; i < primes.size(); ++i) {
      heap.push({primes[i], primes[i], 0});
      st.insert(primes[i]);
    }
    --n;
    while (n) {
      int value = heap.top()[0], prime = heap.top()[1], idx = heap.top()[2];
      heap.pop();
      st.erase(value);
      if (res.back() != value) {
        res.push_back(value);
        --n;
      }
      while (st.count((int64_t)prime * res[idx + 1]))
        ++idx;
      heap.push({(int64_t)prime * res[idx + 1], prime, idx + 1});
      st.insert((int64_t)prime * res[idx + 1]);
    }
    return res.back();
  }
};