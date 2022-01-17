#include <vector>

/// 数学
/// 每次都将整数列表看成一个等差数列，并且每次删除之后的数列还是一个等差数列，k 表示第 k 次删除，初始时 k = 0
/// 
/// 如果 k 是偶数，表示从左到右删除元素，此时
/// 1. 如果元素数目 cnt 是奇数，那么两端的元素都会被删除。a1 = a1 + step, an = an - step
/// 2. 如果元素数目 cnt 是偶数，那么首端的元素会被删除，末端的元素会被保留，a1 = a1 + step, an = an
/// 
/// 如果 k 是奇数，表示从右到左删除元素，此时
/// 1. 如果元素数目 cnt 是奇数，那么 a1 = a1 + step, an = an - step
/// 2. 如果元素数目 cnt 是偶数，那么 a1 = a1, an = an - step
/// 
/// k++，step <<= 1，cnt >>= 1
/// 当等差数列只剩下一个元素的时候，返回 a1
class Solution {
public:
  int lastRemaining(int n) {
    int a1 = 1, step = 1;
    int k = 0, cnt = n;
    while (cnt > 1) {
      if (k % 2 == 0) {
        a1 = a1 + step;
      } else {
        a1 = (cnt % 2 == 0) ? a1 : a1 + step;
      }
      k++;
      cnt = cnt >> 1;
      step = step << 1;
    }
    return a1;
  }
};