#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> threeEqualParts(vector<int> &arr) {
    int one_cnt = accumulate(arr.begin(), arr.end(), 0);
    if (one_cnt % 3 != 0)
      return {-1, -1};
    if (one_cnt == 0 && arr.size() > 2)
      return {0, 2};
    int per_cnt = one_cnt / 3, count = 0;
    int pA = 0, pB, pC;

    for (int i = arr.size() - 1; i >= 0; --i) {
      count += arr[i];
      if (count == per_cnt) {
        pC = i;
        break;
      }
    }
    int res_1, res_2 = pC;

    while (arr[pA] == 0)
      ++pA;
    while (pC != arr.size()) {
      if (arr[pA] == arr[pC]) {
        ++pA;
        ++pC;
        continue;
      }
      return {-1, -1};
    }
    res_1 = pA - 1;

    pC = res_2;
    while (arr[pA] == 0)
      ++pA;
    while (pC != arr.size()) {
      if (arr[pA] == arr[pC]) {
        ++pA;
        ++pC;
        continue;
      }
      return {-1, -1};
    }
    int tmp = pA;
    for (int i = pA; i != res_2; ++i) {
      if (arr[pA] != 0)
        return {-1, -1};
    }
    return {res_1, tmp};
  }
};