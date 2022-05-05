#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> topKFrequent(vector<string> &words, int k) {
    unordered_map<string, int> map;
    for (auto &w : words)
      ++map[w];
    auto cmp = [&](string &lhs, string &rhs) {
      return map[lhs] > map[rhs] || (map[lhs] == map[rhs] && lhs < rhs);
    };
    priority_queue<string, vector<string>, decltype(cmp)> heap(cmp);
    for (auto it = map.begin(); it != map.end(); ++it) {
      heap.push(it->first);
      if (heap.size() > k)
        heap.pop();
    }
    vector<string> res(k);
    for (int i = 0; i < k; ++i) {
      res[i] = heap.top();
      heap.pop();
    }
    reverse(res.begin(), res.end());
    return res;
  }
};