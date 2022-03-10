#include <stack>
#include <string>
using namespace std;

class Solution {
public:
  string decodeString(string s) {
    stack<int> stk_i;
    stack<string> stk_str;
    string str;
    int num = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] >= '0' && s[i] <= '9') {
        num = num * 10 + (s[i] - '0');
      } else if (s[i] == '[') {
        stk_i.push(num);
        stk_str.push(str);
        str.clear();
        num = 0;
      } else if (s[i] == ']') {
        int repeat = stk_i.top();
        stk_i.pop();
        string tmp = stk_str.top();
        stk_str.pop();
        for (int j = 0; j < repeat; ++j) {
          tmp.append(str);
        }
        str = tmp;
      } else {
        str.push_back(s[i]);
      }
    }
    return str;
  }
};