#include <unordered_map>
#include <vector>
using namespace std;

template <int> class Solution;

/// 哈希
template <> class Solution<1> {
public:
  int majorityElement(vector<int> &nums) {
    unordered_map<int, int> map;
    for (auto &n : nums) {
      if (++map[n] > nums.size() / 2)
        return n;
    }
    return -1;
  }
};

/// 排序
template <> class Solution<2> {
public:
  int majorityElement(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
  }
};

/// 分治
template <> class Solution<3> {
public:
  int majorityElement(vector<int> &nums) {
    return find_majority_ele(nums, 0, nums.size() - 1);
  }
  int find_majority_ele(const vector<int> &nums, int start, int end) {
    if (start == end)
      return nums[start];
    int mid = (start + end) >> 1;
    int left = find_majority_ele(nums, start, mid);
    int right = find_majority_ele(nums, mid + 1, end);
    if (count(nums, left, start, end) > (end - start + 1) / 2)
      return left;
    if (count(nums, right, start, end) > (end - start + 1) / 2)
      return right;
    return -1;
  }
  int count(const vector<int> &nums, int target, int start, int end) {
    int res = 0;
    for (int i = start; i <= end; ++i)
      if (nums[i] == target)
        ++res;
    return res;
  }
};

/// 投票
template <> class Solution<4> {
public:
  int majorityElement(vector<int> &nums) {
    int res = 0, count = 0;
    for (auto &val : nums) {
      if (count == 0)
        res = val;
      count += res == val ? 1 : -1;
    }
    return res;
  }
};