#include <string>
using namespace std;

class Solution {
public:
  int myAtoi(string s) {
    bool start = false, positive = true;
    long res = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == ' ') {
        if (start)
          break;
        else
          continue;
      }
      if (s[i] == '-') {
        if (start)
          break;
        else {
          positive = false;
          start = true;
          continue;
        }
      }
      if (s[i] == '+') {
        if (start)
          break;
        else {
          start = true;
          continue;
        }
      }
      if (s[i] >= '0' && s[i] <= '9') {
        start = true;
        int val = s[i] - '0';
        res = res * 10 + val;
        if (res >= INT_MAX && positive)
          return INT_MAX;
        if (-res <= INT_MIN && !positive)
          return INT_MIN;
      } else {
        break;
      }
    }
    return positive ? res : -res;
  }
};