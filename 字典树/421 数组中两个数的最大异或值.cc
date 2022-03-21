#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

template <int> class Solution;

/// 前缀 + 哈希
template <> class Solution<1> {
public:
  int findMaximumXOR(vector<int> &nums) {
    int res = 0;
    for (int i = 30; i >= 0; --i) {
      unordered_set<int> st;
      // 记录所有 nums 的前缀
      for (int k = 0; k < nums.size(); ++k)
        st.insert(nums[k] >> i);
      // 假设 res 的下一位是 1
      res = res * 2 + 1;
      // 寻找数组中能否有两个数的前缀异或刚好等于 res
      bool found = false;
      for (int k = 0; k < nums.size(); ++k)
        if (st.count(res ^ (nums[k] >> i))) {
          found = true;
          break;
        }
      if (!found)
        res--;
    }
    return res;
  }
};

/// 字典树
template <> class Solution<2> {
public:
  class Trie {
  public:
    void insert(int num) {
      Trie *node = this;
      for (int i = 31; i >= 0; --i) {
        int bit = (num >> i) & 1;
        if (!node->children.count(bit))
          node->children[bit] = new Trie;
        node = node->children[bit];
      }
    }
    int search(int num) {
      Trie *node = this;
      int x = 0;
      for (int i = 31; i >= 0; --i) {
        int bit = (num >> i) & 1;
        int s_bit = bit == 0 ? 1 : 0;
        x = x * 2 + 1;
        if (!node->children.count(s_bit)) {
          x--;
          node = node->children[bit];
        } else {
          node = node->children[s_bit];
        }
      }
      return x;
    }

  private:
    unordered_map<int, Trie *> children;
  };
  int findMaximumXOR(vector<int> &nums) {
    int res = 0;
    Trie *root = new Trie;
    for (auto num : nums)
      root->insert(num);
    for (auto num : nums) {
      int x = root->search(num);
      res = max(res, x);
    }
    return res;
  }
};