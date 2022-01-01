#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/// 字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。返回一个表示每个字符串片段的长度的列表

/// 贪心，时间复杂度 O(n)，空间复杂度 O(n)
/// 首选找出所有字母最后结束的位置，记录到 map 中
/// 然后遍历一遍 s，对于 s[i] 找到 s[i] 最后结束的位置 end，然后内层再用一个循环遍历 i 到 end 之间的字母，如果发现中间字母的 end 比 s[i] 的 end 更远就实时的更新 end
/// 内层循环遍历结束的时候就得到了一个字符串片段，记录片段长度，然后 i 从 end + 1 开始
class Solution {
public:
  vector<int> partitionLabels(string s) {
    unordered_map<char, int> map;
    for (int i = 0; i < s.size(); ++i)
      map[s[i]] = i;
    vector<int> res;
    for (int i = 0; i < s.size();) {
      int end = map[s[i]];
      // 遍历 i + 1 到 end 之间的所有字符，确定一个字符串片段
      for (int j = i + 1; j <= end; ++j) {
        // 如果 map[s[j]] > end，由于 j 已经被包含在片段内部了，因此 end 必须要扩展到 map[s[j]]
        if (map[s[j]] > end)
          end = map[s[j]];
      }
      // 更新片段长度
      res.push_back(end - i + 1);
      // 下一个片段的开始位置是 end + 1
      i = end + 1;
    }
    return res;
  }
};