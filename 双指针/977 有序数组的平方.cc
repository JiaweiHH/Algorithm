#include <list>
#include <vector>
using namespace std;

/// @brief 双指针，从第一个元素和最后一个元素出发
class Solution {
public:
  vector<int> sortedSquares(vector<int> &nums) {
    int n = nums.size();
    vector<int> res(n, 0);
    int pA = 0, pB = n - 1, ptr = n - 1;
    while (pA <= pB) {
      if (abs(nums[pA]) > abs(nums[pB]))
        res[ptr--] = nums[pA] * nums[pA++];
      else
        res[ptr--] = nums[pB] * nums[pB--];
    }
    return res;
  }
};

/// @brief 进阶：取出重复元素
class Solution_RemoveRepeat {
public:
  vector<int> sortedSquares(vector<int> &nums) {
    int n = nums.size();
    list<int> res;
    int pA = 0, pB = n - 1;
    while (pA <= pB) {
      if (abs(nums[pA]) > abs(nums[pB])) {
        res.push_front(nums[pA] * nums[pA++]);
        // 去除重复元素
        while (pA <= pB && abs(nums[pA]) == abs(nums[pA - 1]))
          ++pA;
        while (pA <= pB && abs(nums[pB]) == abs(nums[pA - 1]))
          --pB;
      } else {
        res.push_front(nums[pB] * nums[pB--]);
        // 去除重复元素
        while (pA <= pB && abs(nums[pB]) == abs(nums[pB + 1]))
          --pB;
        while (pA <= pB && abs(nums[pA]) == abs(nums[pB + 1]))
          ++pA;
      }
    }
    return {res.begin(), res.end()};
  }
};