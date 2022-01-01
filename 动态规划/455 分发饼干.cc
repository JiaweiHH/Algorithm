#include <vector>
using namespace std;

/// @brief 对每个孩子 i，都有一个胃口值 g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j，都有一个尺寸 s[j]
/// 如果 s[j] >= g[i]，我们可以将这个饼干 j 分配给孩子 i，这个孩子会得到满足。你的目标是尽可能满足越多数量的孩子，并输出这个最大数值

/// 对 g 和 s 排序，然后使用双指针的方法，每次 s[j] 满足了 g[i] 就让 i 和 j 都指向下一个位置，并增加计数值
/// 如果 s[j] 不能满足 g[i] 则让 j 指向下一块饼干
class Solution {
public:
  int findContentChildren(vector<int> &g, vector<int> &s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int count = 0, i = 0, j = 0;
    while (i != g.size() && j != s.size()) {
      if (g[i] <= s[j]) {
        i++;
        j++;
        count++;
      } else {
        j++;
      }
    }
    return count;
  }
};