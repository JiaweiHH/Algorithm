#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string modifyString(string s) {
    int n = s.size();
    for (int i = 1; i < n - 1; ++i) {
      if (s[i] == '?') {
        if (s[i - 1] != '?') {
          if (s[i - 1] - 1 != s[i + 1] && s[i - 1] - 1 >= 'a') {
            s[i] = s[i - 1] - 1;
            continue;
          } else if (s[i - 1] + 1 != s[i + 1] && s[i - 1] + 1 <= 'z') {
            s[i] = s[i - 1] + 1;
            continue;
          }
        }
        if (s[i + 1] != '?') {
          if (s[i + 1] - 1 != s[i - 1] && s[i + 1] - 1 >= 'a') {
            s[i] = s[i + 1] - 1;
            continue;
          } else if (s[i + 1] + 1 != s[i - 1] && s[i + 1] + 1 <= 'z') {
            s[i] = s[i + 1] + 1;
            continue;
          }
        }
        s[i] = 'b';
      }
    }
    if (s[0] == '?') {
      if (n > 1)
        s[0] = s[1] == 'a' ? 'b' : 'a';
      else
        s[0] = 'a';
    }
    if (s[n - 1] == '?')
      if (n - 2 >= 0)
        s[n - 1] = s[n - 2] == 'a' ? 'b' : 'a';
      else
        s[n - 1] = 'a';
    return s;
  }
};