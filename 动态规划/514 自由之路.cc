#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// 字符串 ring 表示圆环上的字符，求出转动圆环拼写出 key 字符串所需的最少步数
// 初始阶段圆环指针指向 ring[0] 的位置，可以顺时针转动也可以逆时针转动
// 每次转动完需要按下按钮，这也算做一步


// dp[i][j] 表示拼写出 key 的 j + 1 个字符，并且最后圆环停留在 i 位置，此时的步数
// 1. 存储 ring 中所有字符到其位置的映射到一个哈希表中
// 2. 每次拼写字符 j，可以从哈希表中找出字符 j 的所有位置
// 3. 拼写完字符 j 更新 prev 数组，用于拼写 j + 1 的时候知道圆环上一步在什么位置
// 对于每个 key[j], 它在圆环中所有的位置用 cur[] 表示，
// dp[i][j] = 
// if prev = empty, min{顺时针从 cur[k] 转到 0, 逆时针从 cur[k] 转到 0} + 1
// else, min{prev[p] 顺指针转到 cur[k], prev[p] 逆时针转到 cur[k]} + 1 + dp[prev[p]][j - 1]
class Solution {
public:
  int findRotateSteps(string ring, string key) {
    int m = ring.size(), n = key.size();
    // 记录圆环中所有字符出现的位置
    unordered_map<char, vector<int>> map;
    for (int i = 0; i < ring.size(); ++i) {
      map[ring[i]].push_back(i);
    }
    // dp[i][j] 表示拼写出 key 的前 j 个字符并且圆环在停在 i 处的步数
    vector<vector<int>> dp(ring.size(), vector<int>(key.size(), INT_MAX));
    vector<int> prev, cur;
    for (int j = 0; j < n; ++j) {
      cur = map[key[j]];
      for (const auto &idx : cur) {
        if (prev.empty()) {
          // 圆环停留在初始状态
          // 计算顺时针和逆时针从 idx 转到初始位置的步数，然后按下按钮
          auto count = min((idx + m) % m, (-idx + m) % m) + 1;
          dp[idx][j] = min(dp[idx][j], count);
        } else {
          // 圆环已经转动过了，上一步停留在 prev[] 的位置
          for (const auto &pre_idx : prev) {
            // 计算从 pre_idx 转到 idx 并且按下按钮所需的步数
            auto count =
                min((idx - pre_idx + m) % m, (pre_idx - idx + m) % m) + 1;
            dp[idx][j] = min(dp[idx][j], count + dp[pre_idx][j - 1]);
          }
        }
      }
      // 更新 prev 数组
      prev = cur;
    }
    int res = INT_MAX;
    for (const auto &idx : map[key[n - 1]]) {
      res = min(res, dp[idx][n - 1]);
    }
    return res;
  }
};