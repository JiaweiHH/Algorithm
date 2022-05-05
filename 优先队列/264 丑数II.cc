#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

template <int> class Solution;

/// 堆
template <> class Solution<1> {
public:
  int nthUglyNumber(int n) {
    vector<int> res(n);
    res[0] = 1;
    unordered_set<long> st{1};
    auto cmp = [](vector<long> &lhs, vector<long> &rhs) {
      return lhs[0] > rhs[0];
    };
    priority_queue<vector<long>, vector<vector<long>>, decltype(cmp)> heap(cmp);
    heap.push({2, 2, 0});
    st.insert(2);
    heap.push({3, 3, 0});
    st.insert(3);
    heap.push({5, 5, 0});
    st.insert(5);

    int cur = 0;
    while (--n) {
      auto top_element = heap.top();
      heap.pop();
      long value = top_element[0], prime = top_element[1], idx = top_element[2];
      res[++cur] = value;
      st.erase(value);
      while (st.count(prime * res[idx + 1]))
        ++idx;
      heap.push({prime * res[idx + 1], prime, idx + 1});
      st.insert(prime * res[idx + 1]);
    }
    return res.back();
  }
};

/// 动态规划
template <> class Solution<2> {
public:
  int nthUglyNumber(int n) {
    vector<int> dp(n);
    vector<int> pointer(3), nums(3, 1), primes{2, 3, 5};
    for (int i = 0; i < n; ++i) {
      dp[i] = *min_element(nums.begin(), nums.end());
      for (int j = 0; j < nums.size(); ++j) {
        if (nums[j] == dp[i]) {
          nums[j] = dp[pointer[j]] * primes[j];
          ++pointer[j];
        }
      }
    }
    return dp[n - 1];
  }
};