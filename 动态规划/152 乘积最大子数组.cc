#include <vector>
using namespace std;

template <int> class Solution;

/// @brief 动态规划
template <> class Solution<1> {
public:
  int maxProduct(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp_min(n), dp_max(n);
    dp_min[0] = dp_max[0] = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      int min_val = dp_min[i - 1], max_val = dp_max[i - 1];
      dp_min[i] = min({min_val * nums[i], max_val * nums[i], nums[i]});
      dp_max[i] = max({min_val * nums[i], max_val * nums[i], nums[i]});
    }
    return max(*max_element(dp_min.begin(), dp_min.end()),
               *max_element(dp_max.begin(), dp_max.end()));
  }
};

/// @brief 空间压缩
template <> class Solution<2> {
public:
  int maxProduct(vector<int> &nums) {
    int min_val = nums[0], max_val = nums[0], res = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      int tmp_1 = min_val, tmp_2 = max_val;
      min_val = min({tmp_1 * nums[i], tmp_2 * nums[i], nums[i]});
      max_val = max({tmp_1 * nums[i], tmp_2 * nums[i], nums[i]});
      res = max({res, min_val, max_val});
    }
    return res;
  }
};