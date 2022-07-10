#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

template <int> class Solution;

/// 字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。返回一个表示每个字符串片段的长度的列表

/// 贪心，时间复杂度 O(n)，空间复杂度 O(n)
/// 首选找出所有字母最后结束的位置，记录到 map 中
/// 然后遍历一遍 s，对于 s[i] 找到 s[i] 最后结束的位置 end，然后内层再用一个循环遍历 i 到 end 之间的字母，如果发现中间字母的 end 比 s[i] 的 end 更远就实时的更新 end
/// 内层循环遍历结束的时候就得到了一个字符串片段，记录片段长度，然后 i 从 end + 1 开始
template <> class Solution<1> {
public:
  vector<int> partitionLabels(string s) {
    unordered_map<char, int> map;
    for (int i = 0; i < s.size(); ++i)
      map[s[i]] = i;
    vector<int> res;
    int i = 0;
    while (i != s.size()) {
      int k = map[s[i]];
      for (int j = i + 1; j <= k; ++j)
        k = max(k, map[s[j]]);
      res.push_back(k - i + 1);
      i = k + 1;
    }
    return res;
  }
};

/// 贪心，这里采用合并区间的方式
template <> class Solution<2> {
public:
  vector<int> partitionLabels(string s) {
    unordered_map<char, vector<int>> map;
    for (int i = 0; i < s.size(); ++i)
      map[s[i]].push_back(i);
    vector<pair<int, int>> intervals;
    // 提取每个字符出现的第一个和最后一个位置，作为区间
    for (auto [key, val] : map)
      intervals.push_back({val.front(), val.back()});
    // 区间合并
    sort(intervals.begin(), intervals.end());
    vector<int> res;
    int l = intervals[0].first, r = intervals[0].second;
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i].first > r) {
        res.push_back(r - l + 1);
        l = intervals[i].first;
      }
      r = max(r, intervals[i].second);
    }
    res.push_back(r - l + 1);
    return res;
  }
};