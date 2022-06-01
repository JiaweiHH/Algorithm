#include <string>
using namespace std;

class Solution {
public:
  string countAndSay(int n) {
    if (n == 1)
      return "1";
    string prev = countAndSay(n - 1);
    string res;
    int cnt = 1;
    for (int i = 1; i < prev.size(); ++i) {
      if (prev[i] == prev[i - 1])
        ++cnt;
      else {
        string str = to_string(cnt);
        str.push_back(prev[i - 1]);
        res.append(str);
        cnt = 1;
      }
    }
    string str = to_string(cnt);
    str.push_back(prev[prev.size() - 1]);
    res.append(str);
    return res;
  }
};