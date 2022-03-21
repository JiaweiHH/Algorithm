#include <string>
#include <vector>
using namespace std;

template <int> class Solution;

/// 字符串处理函数
template <> class Solution<1> {
public:
  int compareVersion(string version1, string version2) {
    vector<int> vec1 = substring(version1), vec2 = substring(version2);
    int i = 0;
    while (i != vec1.size() && i != vec2.size()) {
      if (vec1[i] > vec2[i])
        return 1;
      if (vec1[i] < vec2[i])
        return -1;
      i++;
    }
    if (i != vec1.size()) {
      while (i != vec1.size()) {
        if (vec1[i] != 0)
          return 1;
        i++;
      }
    } else {
      while (i != vec2.size()) {
        if (vec2[i] != 0)
          return -1;
        i++;
      }
    }
    return 0;
  }
  vector<int> substring(const string &version) {
    int start = 0;
    vector<int> vec;
    while (version.find(".", start) != string::npos) {
      int pos = version.find(".", start);
      string str = version.substr(start, pos - start);
      start = pos + 1;
      int not_pos = str.find_first_not_of("0");
      if (not_pos != string::npos) {
        str = str.substr(not_pos);
      } else {
        str = "0";
      }
      vec.push_back(stoi(str));
    }
    string str = version.substr(start);
    int not_pos = str.find_first_not_of("0");
    if (not_pos != string::npos) {
      str = str.substr(not_pos);
    } else {
      str = "0";
    }
    vec.push_back(stoi(str));
    return vec;
  }
};

/// 双指针
template <> class Solution<2> {
public:
  int compareVersion(string version1, string version2) {
    int m = version1.size(), n = version2.size();
    int i = 0, j = 0;
    while (i < m || j < n) {
      int x = 0, y = 0;
      for (; i < m && version1[i] != '.'; ++i)
        x = x * 10 + (version1[i] - '0');
      for (; j < n && version2[j] != '.'; ++j)
        y = y * 10 + (version2[j] - '0');
      if (x != y)
        return x < y ? -1 : 1;
      i++;
      j++;
    }
    return 0;
  }
};