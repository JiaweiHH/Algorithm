#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

template <int> class Solution;

/// 堆 + 贪心
template <> class Solution<1> {
public:
  string reorganizeString(string s) {
    unordered_map<char, int> map;
    for (int i = 0; i < s.size(); ++i)
      ++map[s[i]];
    auto cmp = [](pair<char, int> &lhs, pair<char, int> &rhs) {
      return lhs.second < rhs.second;
    };
    priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)>
        heap(cmp);
    for (auto it = map.begin(); it != map.end(); ++it)
      heap.push({it->first, it->second});
    string res;
    while (heap.size() > 1) {
      auto val_1 = heap.top();
      heap.pop();
      auto val_2 = heap.top();
      heap.pop();
      res.push_back(val_1.first);
      res.push_back(val_2.first);
      if (--val_1.second > 0)
        heap.push(val_1);
      if (--val_2.second > 0)
        heap.push(val_2);
    }
    if (heap.empty())
      return res;
    if (heap.top().second > 1)
      return "";
    res.push_back(heap.top().first);
    return res;
  }
};

/// 贪心
template <> class Solution<2> {
public:
  string reorganizeString(string s) {
    unordered_map<char, int> map;
    int n = s.size(), max_cnt = 0;
    for (int i = 0; i < s.size(); ++i) {
      ++map[s[i]];
      max_cnt = max(max_cnt, map[s[i]]);
    }
    if (max_cnt > (n + 1) / 2)
      return "";
    string res(n, ' ');
    int pA = 0, pB = 1;
    for (auto it = map.begin(); it != map.end(); ++it) {
      int cnt = it->second;
      while (cnt > 0 && cnt <= n / 2 && pB < n) {
        res[pB] = it->first;
        --cnt;
        pB += 2;
      }
      while (cnt > 0) {
        res[pA] = it->first;
        --cnt;
        pA += 2;
      }
    }
    return res;
  }
};