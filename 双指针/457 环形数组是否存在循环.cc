#include <vector>
using namespace std;

template <int> class Solution;

/// dfs
template <> class Solution<1> {
public:
  vector<bool> visited;
  bool res;
  int n;
  bool circularArrayLoop(vector<int> &nums) {
    n = nums.size();
    visited.resize(n);
    for (int i = 0; i < nums.size(); ++i) {
      if (visited[i])
        continue;
      bool tag = nums[i] > 0 ? true : false;
      dfs(nums, i, -1, tag);
      if (res)
        return true;
    }
    return false;
  }
  void dfs(const vector<int> &nums, int idx, int prev, bool tag) {
    if (visited[idx]) {
      if (prev != idx)
        res = true;
      return;
    }
    if (nums[idx] > 0 && !tag || nums[idx] < 0 && tag)
      return;
    visited[idx] = true;
    int new_idx = (idx + nums[idx] + n * 10) % n;
    dfs(nums, new_idx, idx, tag);
    visited[idx] = false;
  }
};

/// 双指针
template <> class Solution<2> {
public:
  bool circularArrayLoop(vector<int> &nums) {
    int n = nums.size();
    auto next = [&](int x) { return ((x + nums[x]) % n + n) % n; };
    for (int i = 0; i < nums.size(); ++i) {
      if (!nums[i])
        continue;
      int l = i, r = next(l);
      while (nums[l] * nums[r] > 0 && nums[l] * nums[next(r)] > 0) {
        if (l == r) {
          if (l != next(l))
            return true;
          break;
        }
        l = next(l);
        r = next(next(r));
      }
      l = i;
      while (nums[l] * nums[next(l)] > 0) {
        int nxt = next(l);
        nums[l] = 0;
        l = nxt;
      }
    }
    return false;
  }
};
