#include <vector>
using namespace std;

template <int> class Solution;

/// 线性时间复杂度
template <> class Solution<1> {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size();
    vector<int> left(n, 1), right(n, 1);
    vector<int> res(n);
    for (int i = 1; i < n; ++i)
      left[i] = left[i - 1] * nums[i - 1];
    for (int i = n - 2; i >= 0; --i)
      right[i] = right[i + 1] * nums[i + 1];
    for (int i = 0; i < n; ++i)
      res[i] = left[i] * right[i];
    return res;
  }
};

/// 常数空间
template <> class Solution<2> {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size();
    vector<int> res(n, 1);
    for (int i = 1; i < n; ++i)
      res[i] = res[i - 1] * nums[i - 1];
    int R = 1;
    for (int i = n - 1; i >= 0; --i) {
      res[i] = res[i] * R;
      R = R * nums[i];
    }
    return res;
  }
};