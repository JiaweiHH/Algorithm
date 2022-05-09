#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

template <int> class Solution;

/// 堆排序
template <> class Solution<1> {
public:
  string frequencySort(string s) {
    unordered_map<char, int> map;
    for (auto w : s)
      ++map[w];
    auto cmp = [](pair<char, int> &lhs, pair<char, int> &rhs) {
      return lhs.second < rhs.second;
    };
    priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)>
        heap(cmp);
    for (auto it = map.begin(); it != map.end(); ++it)
      heap.push({it->first, it->second});
    string res(s.size(), ' ');
    int p = 0;
    while (!heap.empty()) {
      auto top_ch = heap.top();
      for (int i = p; i < p + top_ch.second; ++i)
        res[i] = top_ch.first;
      p += top_ch.second;
      heap.pop();
    }
    return res;
  }
};

/// 桶排序
template <> class Solution<2> {
public:
  string frequencySort(string s) {
    unordered_map<char, int> map;
    for (auto w : s)
      ++map[w];
    int max_freq = 0;
    for (auto it = map.begin(); it != map.end(); ++it)
      max_freq = max(max_freq, it->second);
    vector<string> vec(max_freq + 1);
    for (auto it = map.begin(); it != map.end(); ++it)
      vec[it->second].push_back(it->first);
    string res;
    for (int i = max_freq; i > 0; --i) {
      string &str = vec[i];
      for (auto w : str) {
        string tmp(i, w);
        res.append(tmp);
      }
    }
    return res;
  }
};