#include <vector>
using namespace std;

template <int> class Solution;

template <> class Solution<1> {
public:
  void sortColors(vector<int> &nums) {
    int ptr = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == 0) {
        swap(nums[i], nums[ptr]);
        ptr++;
      }
    }
    for (int i = ptr; i < nums.size(); ++i) {
      if (nums[i] == 1) {
        swap(nums[i], nums[ptr]);
        ptr++;
      }
    }
  }
};

template <> class Solution<2> {
public:
  void sortColors(vector<int> &nums) {
    int p0 = 0, p1 = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == 1) {
        swap(nums[i], nums[p1]);
        p1++;
      } else if (nums[i] == 0) {
        if (p0 < p1) {
          swap(nums[i], nums[p0]);
          swap(nums[i], nums[p1]);
        } else {
          swap(nums[i], nums[p0]);
        }
        p0++;
        p1++;
      }
    }
  }
};

template <> class Solution<3> {
public:
  void sortColors(vector<int> &nums) {
    int p0 = 0, p2 = nums.size() - 1;
    for (int i = 0; i <= p2; ++i) {
      while (i <= p2 && nums[i] == 2) {
        swap(nums[i], nums[p2]);
        p2--;
      }
      if (nums[i] == 0) {
        swap(nums[i], nums[p0]);
        p0++;
      }
    }
  }
};