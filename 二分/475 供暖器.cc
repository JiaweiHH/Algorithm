#include <vector>

using namespace std;

/// @brief 现在，给出位于一条水平线上的房屋 houses 和供暖器 heaters 的位置，请你找出并返回可以覆盖所有房屋的最小加热半径，所有的供暖器遵循同一个半径

template <int>
class Solution;

/// @brief 二分查找
/// 对于每一个房子 house 采用二分查找找到第一个位置大于它的供暖器的索引 index
/// 那么 heaters[index - 1] 到 house 的距离，heaters[index] 到 house 的距离，它们之间的最小值就是房子 house 需要的最小半径
/// 所有房子的最小半径中的最大值就是最终的供暖器半径
/// 
/// @note 时间复杂度：O(mlogn + nlogn)，时间复杂度：O(logn)
template <> class Solution<1> {
public:
  int findRadius(vector<int> &houses, vector<int> &heaters) {
    sort(heaters.begin(), heaters.end());
    int res = 0;
    for (auto &h : houses) {
      int index =
          upper_bound(heaters.begin(), heaters.end(), h) - heaters.begin();
      // 计算每一个房子所需的最小半径
      int right = index == heaters.size() ? INT_MAX : heaters[index] - h;
      int left = index == 0 ? INT_MAX : h - heaters[index - 1];
      res = max(res, min(left, right));
    }
    return res;
  }
};

/// @brief 双指针方法
/// 首先对 houses 和 heaters 都进行排序，然后顺序遍历每一个 houses i0，找到距离它最近的那个供暖器 j0
/// 那么对于 i > i0 的 house 来说，距离它最近的供暖器的 j 必定满足 j >= j0
template <> class Solution<2> {
public:
  int findRadius(vector<int> &houses, vector<int> &heaters) {
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());
    int res = 0;
    for (int i = 0, j = 0; i < houses.size(); ++i) {
      // 对于每个 houses[i] 找到最近的那个供暖器 j
      while (j < heaters.size() - 1 &&
             abs(heaters[j] - houses[i]) >= abs(heaters[j + 1] - houses[i])) {
        j++;
      }
      res = max(res, abs(heaters[j] - houses[i]));
    }
    return res;
  }
};