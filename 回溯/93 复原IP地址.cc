#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<string>> tmp_res;
  vector<string> restoreIpAddresses(string s) {
    vector<string> cur;
    dfs(s, cur, 0);

    vector<string> res;
    for (auto &vec_s : tmp_res) {
      string str;
      for (int i = 0; i < vec_s.size(); ++i) {
        str += vec_s[i];
        if (i != vec_s.size() - 1)
          str += ".";
      }
      res.push_back(str);
    }
    return res;
  }
  void dfs(const string &s, vector<string> &cur, int index) {
    if (cur.size() == 4) {
      if (index == s.size())
        tmp_res.push_back(cur);
      return;
    }
    string str;
    for (int i = index; i < s.size(); ++i) {
      if (i == index && s[i] == '0') {
        cur.push_back("0");
        dfs(s, cur, i + 1);
        cur.pop_back();
        break;
      }
      str.push_back(s[i]);
      if (stoi(str) < 256) {
        cur.push_back(str);
        dfs(s, cur, i + 1);
        cur.pop_back();
      } else {
        break;
      }
    }
  }
};