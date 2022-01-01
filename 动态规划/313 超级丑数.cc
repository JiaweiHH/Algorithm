#include <vector>
using namespace std;

/// @brief 超级丑数满足，其所有的质因数都出现在质数数组 primes 中。
/// 现在给你一个整数 n 和 primes 数组，返回第 n 个超级丑数

/// @brief 动态规划，dp[n] 表示第 n 个超级丑数
/// 首先需要明确的是，dp[n] 肯定是由 dp[1], dp[2], ... ,dp[n - 1] 与 每一个 primes 元素相乘得到的
/// 用 nums 数组记录当前每个 primes 元素乘积的结果，pointers 数组记录当前 primes[k] 与第几个 dp 中的元素相乘
/// dp[i] 每次取 nums 数组中的最小值，然后将最小值对应的 prime 相乘的元素往后移动一个位置，即 pointers[] 加一
/// @brief 举例
/// 假如我们用 1, 2, 3, 4, 5, 6 去形成后面的丑数，我们可以将 1, 2, 3, 4, 5, 6 分别乘以 2, 3, 5
/// 这样得到一共 6 * 3 = 18 个新丑数。也就是说 1, 2, 3, 4, 5, 6 中的每一个丑数都有一次机会与 2 相乘，
/// 一次机会与 3 相乘，一次机会与 5 相乘，来得到更大的一个丑数。一共有 18 次机会形成 18 个新丑数。
/// 这样可以用三个指针：
/// pointer2, 指向 1, 2, 3, 4, 5, 6 中，还没使用乘 2 机会的丑数的位置。该指针的前一位已经使用完了乘以 2 的机会。
/// pointer3, 指向 1, 2, 3, 4, 5, 6 中，还没使用乘 3 机会的丑数的位置。该指针的前一位已经使用完了乘以 3 的机会。
/// pointer5, 指向 1, 2, 3, 4, 5, 6 中，还没使用乘 5 机会的丑数的位置。该指针的前一位已经使用完了乘以 5 的机会。
/// 下一次寻找丑数时，则对这三个位置分别尝试使用一次乘 2 机会，乘 3 机会，乘 5 机会，看看哪个最小，最小的那个就是下一个丑数。
/// 最后，那个得到下一个丑数的指针位置加一，因为它对应的那次乘法使用完了。
class Solution {
public:
  int nthSuperUglyNumber(int n, vector<int> &primes) {
    int m = primes.size();
    // nums 数组记录当前第 k 个质数相乘的结果，pointers 数组记录当前第 k
    // 个质数和第几个数相乘
    vector<long> nums(m, 1), dp(n + 1);
    vector<int> pointers(m, 0);
    for (int i = 1; i <= n; ++i) {
      long min_num = *min_element(nums.begin(), nums.end());
      dp[i] = min_num;
      for (int j = 0; j < m; ++j) {
        // 每次将最小的那个质数往后乘
        if (nums[j] == min_num) {
          // 第 j 个质数需要相乘的元素往后移一个位置
          pointers[j]++;
          nums[j] = dp[pointers[j]] * primes[j];
        }
      }
    }
    return dp[n];
  }
};