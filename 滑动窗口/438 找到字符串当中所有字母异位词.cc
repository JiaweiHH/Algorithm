#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> res;
    // 记录每个目标字符的个数
    unordered_map<char, int> target;
    for (const auto &c : p)
      target[c]++;
    // 记录当前窗口每个字符的数量
    unordered_map<char, int> cur;
    int left = 0, right = 0, valid = 0;
    while (right != s.size()) {
      char c = s[right++];
      if (target.count(c)) {
        cur[c]++;
        if (cur[c] == target[c])
          valid++;
      }
      // 收缩窗口
      while (right - left >= p.size()) {
        if (valid == target.size())
          res.push_back(left);
        char tmp = s[left++];
        if (cur.count(tmp)) {
          if (cur[tmp] == target[tmp])
            valid--;
          cur[tmp]--;
        }
      }
    }
    return res;
  }
};