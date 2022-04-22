#include <queue>
#include <vector>
using namespace std;

template <int> class Solution;

/// 优先队列
template <> class Solution<1> {
public:
  int kthSmallest(vector<vector<int>> &matrix, int k) {
    auto cmp = [&](pair<int, int> &lhs, pair<int, int> &rhs) {
      return matrix[lhs.first][lhs.second] > matrix[rhs.first][rhs.second];
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> heap(
        cmp);
    for (int i = 0; i < matrix.size(); ++i) {
      heap.push({i, 0});
    }
    while (--k) {
      auto top = heap.top();
      heap.pop();
      if (top.second + 1 < matrix[0].size())
        heap.push({top.first, top.second + 1});
    }
    return matrix[heap.top().first][heap.top().second];
  }
};

/// 二分查找
template <> class Solution<2> {
public:
  bool check(vector<vector<int>> &matrix, int target, int k) {
    int res = 0, x = matrix.size() - 1, y = 0;
    while (x >= 0 && y < matrix.size()) {
      if (matrix[x][y] <= target) {
        res += x + 1;
        ++y;
      } else {
        --x;
      }
    }
    // cout << target << ", " << res << '\n';
    return res >= k;
  }
  int kthSmallest(vector<vector<int>> &matrix, int k) {
    int n = matrix.size();
    int l = matrix[0][0], r = matrix[n - 1][n - 1];
    while (l <= r) {
      int mid = (l + r) / 2;
      if (check(matrix, mid, k))
        r = mid - 1;
      else
        l = mid + 1;
    }
    return l;
  }
};