#include <vector>
using namespace std;

class Solution {
public:
  int translateNum(int num) {
    if (num == 0)
      return 1;
    vector<int> vec;
    while (num) {
      int val = num % 10;
      num = num / 10;
      vec.push_back(val);
    }
    reverse(vec.begin(), vec.end());

    int prev_tail = 1, prev_cnt = 1, prev = vec[0];
    for (int i = 1; i < vec.size(); ++i) {
      int tmp = prev_cnt;
      prev_cnt = prev * 10 + vec[i] < 26 && prev != 0 ? prev_cnt + prev_tail
                                                      : prev_cnt;
      prev_tail = tmp;
      prev = vec[i];
    }
    return prev_cnt;
  }
};