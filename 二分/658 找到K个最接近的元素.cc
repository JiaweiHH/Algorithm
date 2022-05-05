#include <list>
#include <vector>
using namespace std;

template <int> class Solution;

/// 双指针从中间开始向两边扩张，需要使用 list 保留结果
template <> class Solution<1> {
public:
  vector<int> findClosestElements(vector<int> &arr, int k, int x) {
    vector<int> res;
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (arr[mid] >= x)
        r = mid - 1;
      else
        l = mid + 1;
    }
    int pA = l - 1, pB = l;
    list<int> lst;
    while (pA >= 0 && pB <= arr.size() - 1) {
      if (abs(arr[pA] - x) > abs(arr[pB] - x))
        lst.push_back(arr[pB++]);
      else
        lst.push_front(arr[pA--]);
      if (--k == 0)
        break;
    }
    while (pA >= 0 && k > 0) {
      lst.push_front(arr[pA--]);
      --k;
    }
    while (pB <= arr.size() - 1 && k > 0) {
      lst.push_back(arr[pB++]);
      --k;
    }
    copy(lst.begin(), lst.end(), back_inserter(res));
    return res;
  }
};

/// 双指针从两边开始往中间收缩
template <> class Solution<2> {
public:
  vector<int> findClosestElements(vector<int> &arr, int k, int x) {
    vector<int> res;
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (arr[mid] >= x)
        r = mid - 1;
      else
        l = mid + 1;
    }
    int pA = l - k, pB = l + k - 1;
    while (pB - pA > k - 1) {
      if (pA < 0) {
        ++pA;
        continue;
      }
      if (pB >= arr.size()) {
        --pB;
        continue;
      }
      if (abs(arr[pA] - x) > abs(arr[pB] - x))
        ++pA;
      else
        --pB;
    }
    return vector<int>(arr.begin() + pA, arr.begin() + pB + 1);
  }
};