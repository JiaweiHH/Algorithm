#include <vector>
using namespace std;

template <int> class Solution;

// 1. 确定旋转位置 2. 确定 target 在哪个旋转区间 3. 搜索
template <> class Solution<1> {
public:
  int search(vector<int> &arr, int target) {
    int n = arr.size();
    // 找到旋转位置下标
    int l = 0, r = n - 1, start_idx = 0;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (arr[mid] > arr[r])
        l = mid + 1;
      else if (arr[mid] < arr[r]) {
        start_idx = max(start_idx, r + 1);
        r = mid;
      } else {
        --r;
      }
    }
    start_idx = start_idx == n || arr[start_idx] != arr[l] ? l : start_idx;
    // 确定 target 的搜索区间
    if (start_idx == 0)
      l = 0, r = n - 1;
    else {
      if (target < arr[0])
        l = start_idx, r = n - 1;
      else
        l = 0, r = start_idx - 1;
    }
    int bound = r + 1;
    // 二分搜索 target
    while (l <= r) {
      int mid = (l + r) / 2;
      if (arr[mid] >= target)
        r = mid - 1;
      else
        l = mid + 1;
    }
    return l == bound || arr[l] != target ? -1 : l;
  }
};

// 一遍搜索
template <> class Solution<2> {
public:
  int search(vector<int> &arr, int target) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
      if (arr[l] == target)
        return l;
      int mid = (l + r) / 2;
      if (arr[mid] == target)
        r = mid;
      else if (arr[mid] > arr[r]) {
        if (arr[l] < target && target < arr[mid])
          r = mid - 1;
        else
          l = mid + 1;
      } else if (arr[mid] < arr[r]) {
        if (arr[mid] < target && target <= arr[r])
          l = mid + 1;
        else
          r = mid - 1;
      } else {
        --r;
      }
    }
    return -1;
  }
};