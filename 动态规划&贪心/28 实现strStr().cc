#include <string>
#include <vector>

using namespace std;

// 给定字符串 haystack 和 needle，在 haystack 中找出 needle 出现的第一个位置

// 使用 KMP 算法，采用动态规划的思想
// 使用 KMP 数组即 dp 数组表示状态的转移，这里的状态是指对于 needle 字符串匹配到哪个状态了
// 另外在构建 dp 数组的时候需要记住当前状态的一个前缀子状态，当前状态不能推进到下一个状态的时候，
// 需要借助前缀子状态来回退，保证回退的字符数量最少
// 最后使用这个状态转移数组，遍历 haystack 字符串，找出出现 needle 的位置
// 时间复杂度 O(m + n)
class Solution {
public:
  vector<vector<int>> dp;
  int strStr(string haystack, string needle) {
    if (needle.empty())
      return 0;
    int n = needle.size();
    dp.resize(n, vector<int>(256));
    KMP(needle);
    return search(haystack, needle);
  }
  // 构建 KMP 数组
  void KMP(const string &needle) {
    int n = needle.size();
    // 0 状态只有遇到 needle[0] 才能转移到 1 状态
    dp[0][needle[0]] = 1;
    // 记录当前状态的一个前缀状态，用来委托状态转移
    int last_state = 0;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < 256; ++j) {
        if (j == needle[i])
          dp[i][j] = i + 1;
        else
          dp[i][j] = dp[last_state][j];
      }
      last_state = dp[last_state][needle[i]];
    }
  }
  int search(const string &haystack, const string &needle) {
    int m = haystack.size();
    int n = needle.size();
    int state = 0;
    for (int i = 0; i < m; ++i) {
      state = dp[state][haystack[i]];
      if (state == n)
        return i - n + 1;
    }
    return -1;
  }
};