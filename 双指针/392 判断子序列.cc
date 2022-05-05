#include <string>
#include <vector>
using namespace std;

template <int> class Solution;

/// 双指针
template <> class Solution<1> {
public:
  bool isSubsequence(string s, string t) {
    int pA = 0, pB = 0;
    while (pA < s.size() && pB < t.size()) {
      if (t[pB] == s[pA])
        ++pA;
      ++pB;
    }
    return pA == s.size();
  }
};

// 动态规划
template <> class Solution<2> {
public:
  bool isSubsequence(string s, string t) {
    int n = t.size();
    vector<vector<int>> vec(n + 1, vector<int>(26));
    for (int i = 0; i < 26; ++i)
      vec[n][i] = n;
    for (int i = n - 1; i >= 0; --i) {
      for (int j = 0; j < 26; ++j) {
        if (t[i] == j + 'a')
          vec[i][j] = i;
        else
          vec[i][j] = vec[i + 1][j];
      }
    }

    int ptr = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (vec[ptr][s[i] - 'a'] == n)
        return false;
      ptr = vec[ptr][s[i] - 'a'] + 1;
    }
    return true;
  }
};