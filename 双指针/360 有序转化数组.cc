#include <vector>
using namespace std;

class Solution {
public:
  vector<int> sortTransformedArray(vector<int> &nums, int a, int b, int c) {
    if (a < 0) {
      return negtive_sort(nums, a, b, c);
    } else if (a > 0) {
      return postive_sort(nums, a, b, c);
    } else {
      auto fx = [&](const int &x) -> int { return a * x * x + b * x + c; };
      vector<int> res;
      if (b < 0) {
        for (int i = nums.size() - 1; i >= 0; --i)
          res.push_back(fx(nums[i]));
      } else if (b > 0) {
        for (int i = 0; i < nums.size(); ++i)
          res.push_back(fx(nums[i]));
      } else {
        res.resize(nums.size(), c);
      }
      return res;
    }
  }
  vector<int> postive_sort(const vector<int> &nums, int a, int b, int c) {
    int target_val = -b / (2 * a);
    int l = 0, r = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] >= target_val) {
        l = i - 1;
        r = i;
        break;
      }
    }
    auto fx = [&](const int &x) -> int { return a * x * x + b * x + c; };
    vector<int> res;
    while (l >= 0 && r < nums.size()) {
      int val_l = fx(nums[l]), val_r = fx(nums[r]);
      if (val_l < val_r) {
        res.push_back(val_l);
        --l;
      } else {
        res.push_back(val_r);
        ++r;
      }
    }
    while (l >= 0) {
      res.push_back(fx(nums[l]));
      --l;
    }
    while (r < nums.size()) {
      res.push_back(fx(nums[r]));
      ++r;
    }
    return res;
  }
  vector<int> negtive_sort(const vector<int> &nums, int a, int b, int c) {
    int target_val = -b / (2 * a);
    int idx = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] >= target_val) {
        idx = i;
        break;
      }
    }
    auto fx = [&](const int &x) -> int { return a * x * x + b * x + c; };
    int l = 0, r = nums.size() - 1;
    vector<int> res;
    while (l < idx && r >= idx) {
      int val_l = fx(nums[l]), val_r = fx(nums[r]);
      if (val_l < val_r) {
        res.push_back(val_l);
        ++l;
      } else {
        res.push_back(val_r);
        --r;
      }
    }
    while (l < idx) {
      res.push_back(fx(nums[l]));
      ++l;
    }
    while (r >= idx) {
      res.push_back(fx(nums[r]));
      --r;
    }
    return res;
  }
};