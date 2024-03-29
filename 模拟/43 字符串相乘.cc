#include <string>
#include <vector>
using namespace std;

template <int> class Solution;

/// 直接模拟
template <> class Solution<1> {
public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0")
      return "0";
    int m = num1.size(), n = num2.size();
    string res;
    for (int i = n - 1; i >= 0; --i) {
      string curr;
      for (int j = n - 1; j > i; --j)
        curr.append("0");
      int tag = 0;
      for (int j = m - 1; j >= 0; --j) {
        int lhs = num1[j] - '0', rhs = num2[i] - '0';
        int num = lhs * rhs + tag;
        tag = num / 10;
        curr.push_back(num % 10 + '0');
      }
      if (tag)
        curr.push_back(tag + '0');
      reverse(curr.begin(), curr.end());
      res = add_string(res, curr);
    }
    return res;
  }
  string add_string(const string &lhs, const string &rhs) {
    int i = lhs.size() - 1, j = rhs.size() - 1;
    int tag = 0;
    string res;
    while (i >= 0 && j >= 0) {
      int num = lhs[i] - '0' + rhs[j] - '0' + tag;
      res.push_back(num % 10 + '0');
      tag = num / 10;
      --i;
      --j;
    }
    while (i >= 0) {
      int num = lhs[i] - '0' + tag;
      res.push_back(num % 10 + '0');
      tag = num / 10;
      --i;
    }
    while (j >= 0) {
      int num = rhs[j] - '0' + tag;
      res.push_back(num % 10 + '0');
      tag = num / 10;
      --j;
    }
    if (tag)
      res.push_back(tag + '0');
    reverse(res.begin(), res.end());
    return res;
  }
};

/// 利用 vector 模拟
template <> class Solution<2> {
public:
  string multiply(string num1, string num2) {
    int m = num1.size(), n = num2.size();
    vector<int> vec(m + n, 0);
    for (int i = m - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        int lhs = num1[i] - '0', rhs = num2[j] - '0';
        vec[i + j + 1] += lhs * rhs;
        vec[i + j] += vec[i + j + 1] / 10;
        vec[i + j + 1] %= 10;
      }
    }
    string res;
    int i = 0;
    while (i != vec.size() && vec[i] == 0)
      ++i;
    for (; i < vec.size(); ++i) {
      res.push_back(vec[i] + '0');
    }
    return res.empty() ? "0" : res;
  }
};