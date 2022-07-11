#include <vector>
using namespace std;

template <int> class Solution;

// 1. 确定旋转位置 2. 确定 target 在哪个旋转区间 3. 搜索
template <> class Solution<1> {
public:
  int search(vector<int> &arr, int target) {
    // 1. 找到数组的旋转位置
    int l = 0, r = arr.size() - 1, idx = 0;
    while (l < r) {
      int mid = (l + r) / 2;
      if (arr[mid] > arr[r])
        l = mid + 1;
      else if (arr[mid] < arr[r]) {
        idx = max(idx, r + 1); // idx 记录可能的下标位置
        r = mid;
      } else
        --r;
    }
    // 注意只有当 idx == n 或者 arr[idx] != arr[r] 的时候才使用 r. 
    // 否则就使用 idx
    idx = idx == arr.size() || arr[idx] != arr[r] ? r : idx;
    // 2. 找到 target
    if (target >= arr[0])
      l = 0, r = idx - 1;
    else
      l = idx, r = arr.size() - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (arr[mid] >= target)
        r = mid - 1;
      else
        l = mid + 1;
    }
    return l == arr.size() || arr[l] != target ? -1 : l;
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