#include <string>
#include <vector>

using namespace std;

// 给出 n 个字符串，求他们的最长公共前缀

// 比较简单，应该一看就能懂
class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    string res = strs[0];
    for (int i = 1; i < strs.size() && !res.empty(); ++i) {
      string str = strs[i];
      int index1 = 0, index2 = 0;
      while (index1 != res.size() && index2 != str.size()) {
        if (res[index1] == str[index2]) {
          ++index1;
          ++index2;
        } else {
          res.erase(index1, res.size() - index1);
        }
      }
      if (index1 != res.size())
        res.erase(index1, res.size() - index1);
    }
    return res;
  }
};