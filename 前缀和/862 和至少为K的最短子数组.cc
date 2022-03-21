#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
  int shortestSubarray(vector<int> &nums, int k) {
    vector<int64_t> trie(nums.size() + 1);
    int64_t sum = 0;
    for (int i = 1; i <= nums.size(); ++i) {
      sum += nums[i - 1];
      trie[i] = sum;
    }
    deque<int> q;
    int len = INT_MAX;
    for (int i = 0; i <= nums.size(); ++i) {
      while (!q.empty() && trie[i] <= trie[q.back()])
        q.pop_back();
      while (!q.empty() && trie[i] - trie[q.front()] >= k) {
        len = min(len, i - q.front());
        q.pop_front();
      }
      q.push_back(i);
    }
    return len == INT_MAX ? -1 : len;
  }
};