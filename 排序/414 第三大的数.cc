#include <random>
#include <unordered_set>
#include <vector>
using namespace std;

template <int> class Solution;

/// @brief quick select
template <> class Solution<1> {
public:
  int partition(vector<int> &nums, int l, int r, int pivot) {
    swap(nums[pivot], nums[r]);
    int x = l;
    for (int i = l; i <= r; ++i) {
      if (nums[i] > nums[r])
        swap(nums[i], nums[x++]);
    }
    swap(nums[x], nums[r]);
    return x;
  }
  int quick_select(vector<int> &nums, int k) {
    default_random_engine gen(random_device{}());
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      uniform_int_distribution<int> dis(l, r);
      int pivot = dis(gen);
      int x = partition(nums, l, r, pivot);
      if (x == k)
        return nums[x];
      else if (x > k)
        r = x - 1;
      else
        l = x + 1;
    }
    return -1;
  }
  int thirdMax(vector<int> &nums) {
    unordered_set<int> st(nums.begin(), nums.end());
    vector<int> vec(st.begin(), st.end());
    int k = vec.size() < 3 ? 1 : 3;
    return quick_select(vec, k - 1);
  }
};

/// @brief 一次遍历，依赖元素的范围
template <> class Solution<2> {
public:
  int thirdMax(vector<int> &nums) {
    long x = LONG_MIN, y = LONG_MIN, z = LONG_MIN;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > x) {
        z = y;
        y = x;
        x = nums[i];
      } else if (x > nums[i] && nums[i] > y) {
        z = y;
        y = nums[i];
      } else if (y > nums[i] && nums[i] > z) {
        z = nums[i];
      }
    }
    return z == LONG_MIN ? x : z;
  }
};

/// @brief 不依赖元素范围
template <> class Solution<3> {
public:
  int thirdMax(vector<int> &nums) {
    int *x = nullptr, *y = nullptr, *z = nullptr;
    for (int i = 0; i < nums.size(); ++i) {
      if (x == nullptr || nums[i] > *x) {
        z = y;
        y = x;
        x = &nums[i];
      } else if (*x > nums[i] && (y == nullptr || nums[i] > *y)) {
        z = y;
        y = &nums[i];
      } else if ((y == nullptr || *y > nums[i]) &&
                 (z == nullptr || nums[i] > *z)) {
        z = &nums[i];
      }
    }
    return z == nullptr ? *x : *z;
  }
};