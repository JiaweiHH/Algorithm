#include <string>
using namespace std;

class Solution {
public:
  string removeKdigits(string num, int k) {
    string res;
    int count = 0;
    for (int i = 0; i < num.size(); ++i) {
      while (count != k && !res.empty() && num[i] < res.back()) {
        res.pop_back();
        count++;
      }
      res.push_back(num[i]);
    }
    while (count++ < k)
      res.pop_back();
    for (int i = 0; i < res.size(); ++i) {
      if (res[i] != '0')
        return res.substr(i);
    }
    return "0";
  }
};