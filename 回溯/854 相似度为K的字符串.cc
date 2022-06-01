#include <string>
using namespace std;

class Solution {
public:
  int res = INT_MAX, len;
  void dfs(string &s1, string &s2, int index, int cur_count) {
    if (cur_count > res)
      return;
    if (index == len) {
      res = min(res, cur_count);
      return;
    }
    if (s1[index] == s2[index])
      dfs(s1, s2, index + 1, cur_count);
    else {
      for (int i = index + 1; i < len; ++i) {
        if (s2[i] == s1[index]) {
          swap(s2[i], s2[index]);
          dfs(s1, s2, index + 1, cur_count + 1);
          swap(s2[i], s2[index]);
        }
      }
    }
  }
  int kSimilarity(string s1, string s2) {
    len = s1.size();
    dfs(s1, s2, 0, 0);
    return res;
  }
};