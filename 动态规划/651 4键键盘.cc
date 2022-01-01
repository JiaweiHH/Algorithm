#include <vector>

using namespace std;

/// 假设有一个键盘只能按下：一个字母 A、Ctrl-A、Ctrl-C、Ctrl-V
/// 现在给出按键次数 n 求出能够打印的 A 的最大数量

/// @brief 为了获取最多的 'A' 其实就是两种情况：
/// 1. 当按键次数较少的时候只需要一直按 A
/// 2. 当按键次数比较多的时候，可以先一直按 A，然后到了一定次数之后开始 Ctrl-A、Ctrl-C，然后开始不停的 Ctrl-V
/// @param dp[i] 表示可以按下 i 次能获取的最大数量
/// 在计算 dp[i] 的时候，可以考虑 2 <= j < i 是第一次按下 Ctrl-C 的时候
/// dp[i] = max(dp[j - 2] * (i - j + 1)), 2 <= j < i，其中 i - j + 1 表示按下 Ctrl-V 的次数加上前面初始的 dp[j - 2]
class Solution {
public:
  int maxA(int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      dp[i] = dp[i - 1] + 1;
      for (int j = 2; j < i; ++j) {
        dp[i] = max(dp[i], dp[j - 2] * (i - j + 1));
      }
    }
    return dp[n];
  }
};