#include <vector>
using namespace std;

class Solution {
public:
  int get_count(int prefix, int64_t n) {
    int64_t cur = prefix, next = prefix + 1;
    int count = 0;
    // 按层计算每一层有多少个节点
    while (cur <= n) {
      count += min(next, n + 1) - cur;
      cur *= 10;
      next *= 10;
    }
    return count;
  }
  int findKthNumber(int n, int k) {
    int prefix = 1, ptr = 1;
    while (ptr < k) {
      int count = get_count(prefix, n);
      if (ptr + count <= k) {
        ++prefix;
        ptr += count;
      } else {
        prefix = prefix * 10;
        ++ptr;
      }
    }
    return prefix;
  }
};