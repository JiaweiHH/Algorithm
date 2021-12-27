#include <vector>
#include <string>
using namespace std;

/// 给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你不能重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案

/// 回溯
class Solution {
public:
  vector<string> res;
  vector<string> restoreIpAddresses(string s) {
    vector<string> cur;
    backtracing(0, s, cur);
    return res;
  }
  void backtracing(int index, string s, vector<string> &cur) {
    if (index == s.size()) {
      if (cur.size() == 4) {
        string str = cur[0];
        for (int i = 1; i < cur.size(); ++i) {
          str += ".";
          str += cur[i];
        }
        res.push_back(str);
      }
      return;
    }
    if (s[index] == '0') {
      cur.push_back("0");
      backtracing(index + 1, s, cur);
      cur.pop_back();
    } else {
      for (int i = index; i < s.size(); ++i) {
        string str = s.substr(index, i - index + 1);
        if (stoi(str) > 255)
          break;
        cur.push_back(str);
        backtracing(i + 1, s, cur);
        cur.pop_back();
      }
    }
  }
};