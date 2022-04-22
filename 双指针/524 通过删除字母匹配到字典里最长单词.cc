#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string findLongestWord(string s, vector<string> &dictionary) {
    string str;
    for (auto &dic : dictionary) {
      if (dic.size() < str.size())
        continue;
      else if (dic.size() == str.size() && dic > str)
        continue;
      int i = 0, j = 0;
      while (i < s.size() && j < dic.size()) {
        if (s[i] == dic[j])
          ++j;
        ++i;
      }
      if (j == dic.size())
        str = dic;
    }
    return str;
  }
};