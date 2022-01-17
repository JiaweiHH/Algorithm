#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string simplifyPath(string path) {
    vector<string> vec;
    int start = 0;
    for (int i = 0; i < path.size(); ++i) {
      if (path[i] == '/') {
        string str = path.substr(start, i - start);
        start = i + 1;
        deal(vec, str);
      }
    }
    if (start != path.size()) {
      string str = path.substr(start, path.size() - start);
      deal(vec, str);
    }
    string res;
    for (auto &str : vec) {
      res += "/" + str;
    }
    return res == "" ? "/" : res;
  }
  void deal(vector<string> &vec, string str) {
    if (str == ".")
      return;
    else if (str == "..") {
      if (vec.size())
        vec.pop_back();
    } else {
      if (str.size())
        vec.push_back(str);
    }
  }
};