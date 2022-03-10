#include <vector>
using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int left = 0, right = height.size() - 1;
    int res = (right - left) * min(height[left], height[right]);
    while (left < right) {
      if (height[left] < height[right]) {
        int tmp = height[left];
        while (height[left] <= tmp && left != right)
          left++;
      } else {
        int tmp = height[right];
        while (height[right] <= tmp && right != left)
          right--;
      }
      res = max(res, min(height[left], height[right]) * (right - left));
    }
    return res;
  }
};