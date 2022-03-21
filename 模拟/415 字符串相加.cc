#include <string>
using namespace std;

class Solution {
public:
  string addStrings(string num1, string num2) {
    int tag = 0, i = num1.size() - 1, j = num2.size() - 1;
    string res;
    while (i >= 0 && j >= 0) {
      int tmp = num1[i] - '0' + num2[j] - '0' + tag;
      tag = tmp / 10;
      --i;
      --j;
      res.push_back(tmp % 10 + '0');
    }
    while (i >= 0) {
      int tmp = num1[i] - '0' + tag;
      tag = tmp / 10;
      --i;
      res.push_back(tmp % 10 + '0');
    }
    while (j >= 0) {
      int tmp = num2[j] - '0' + tag;
      tag = tmp / 10;
      --j;
      res.push_back(tmp % 10 + '0');
    }
    if (tag)
      res.push_back(tag + '0');
    reverse(res.begin(), res.end());
    return res;
  }
};