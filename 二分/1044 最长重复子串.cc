#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
  struct hash_func {
    template <typename T1, typename T2>
    size_t operator()(const pair<T1, T2> &p) const {
      size_t val_1 = std::hash<T1>()(p.first);
      size_t val_2 = std::hash<T2>()(p.second);
      return val_1 ^ val_2;
    }
  };
  int index_1 = random() % 1000 + 100, index_2 = random() % 1000 + 100;
  string longestDupSubstring(string s) {
    int l = 1, r = s.size();
    int start = -1, len = 0;
    auto count = [&](int target) {
      unordered_set<pair<uint64_t, uint64_t>, hash_func> hash_set;
      uint64_t hash_1 = 0, hash_2 = 0;
      uint64_t p_1 = 1, p_2 = 1;
      for (int i = 0; i < target; ++i) {
        hash_1 = hash_1 * index_1 + s[i];
        p_1 *= index_1;
        hash_2 = hash_2 * index_2 + s[i];
        p_2 *= index_2;
      }
      hash_set.insert({hash_1, hash_2});
      for (int i = target; i < s.size(); ++i) {
        hash_1 = hash_1 * index_1 - p_1 * s[i - target] + s[i];
        hash_2 = hash_2 * index_2 - p_2 * s[i - target] + s[i];
        pair<uint64_t, uint64_t> pr = make_pair(hash_1, hash_2);
        if (hash_set.count(pr)) {
          if (target > len) {
            start = i - target + 1;
            len = target;
          }
          return true;
        }
        hash_set.insert(pr);
      }
      return false;
    };
    while (l <= r) {
      int mid = (l + r) / 2;
      if (count(mid))
        l = mid + 1;
      else
        r = mid - 1;
    }
    return len == 0 ? "" : s.substr(start, len);
  }
};