#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

template <int> class Solution;

class Trie_map {
public:
  Trie_map() : id(-1) {}
  void insert(string &str, int id) {
    Trie_map *node = this;
    for (int i = 0; i < str.size(); ++i) {
      if (!node->children.count(str[i]))
        node->children[str[i]] = new Trie_map;
      node = node->children[str[i]];
    }
    node->id = id;
  }
  int find(string &str, int l, int r) {
    Trie_map *node = this;
    for (int i = r; i >= l; --i) {
      if (!node->children.count(str[i]))
        return -1;
      node = node->children[str[i]];
    }
    return node->id;
  }

private:
  unordered_map<char, Trie_map *> children;
  int id;
};

/// 字典树写法一
template <> class Solution<1> {
public:
  bool isPalindrome(string &str, int l, int r) {
    int i = l, j = r;
    while (i <= j) {
      if (str[i] != str[j])
        return false;
      ++i;
      --j;
    }
    return true;
  }
  vector<vector<int>> palindromePairs(vector<string> &words) {
    Trie_map *root = new Trie_map;
    vector<vector<int>> res;
    for (int i = 0; i < words.size(); ++i)
      root->insert(words[i], i);
    for (int i = 0; i < words.size(); ++i) {
      int len = words[i].size();
      for (int j = 0; j <= len; ++j) {
        if (isPalindrome(words[i], j, len - 1)) {
          int idx = root->find(words[i], 0, j - 1);
          if (idx != -1 && idx != i)
            res.push_back({i, idx});
        }
        // 0 的时候不应该再去查找，否则会和前面一个判断重复
        if (j && isPalindrome(words[i], 0, j - 1)) {
          int idx = root->find(words[i], j, len - 1);
          if (idx != -1 && idx != i)
            res.push_back({idx, i});
        }
      }
    }
    return res;
  }
};

/// 字典树写法二
template <> class Solution<2> {
public:
  struct Node {
    Node() : id(-1), children(26, 0) {}
    vector<int> children;
    int id;
  };
  vector<Node> trie;
  void insert(string &str, int id) {
    int idx = 0;
    for (int i = 0; i < str.size(); ++i) {
      if (!trie[idx].children[str[i] - 'a']) {
        trie.emplace_back();
        trie[idx].children[str[i] - 'a'] = trie.size() - 1;
      }
      idx = trie[idx].children[str[i] - 'a'];
    }
    trie[idx].id = id;
  }
  int find(string &str, int l, int r) {
    int idx = 0;
    for (int i = r; i >= l; --i) {
      if (!trie[idx].children[str[i] - 'a'])
        return -1;
      idx = trie[idx].children[str[i] - 'a'];
    }
    return trie[idx].id;
  }
  bool isPalindrome(string &str, int l, int r) {
    int i = l, j = r;
    while (i <= j) {
      if (str[i] != str[j])
        return false;
      ++i;
      --j;
    }
    return true;
  }
  bool check(string &str, int l, int r) {
    int i = l, j = r;
    while (i <= j) {
      if (str[i] != str[j])
        return false;
      ++i;
      --j;
    }
    return true;
  }
  vector<vector<int>> palindromePairs(vector<string> &words) {
    trie.emplace_back();
    for (int i = 0; i < words.size(); ++i)
      insert(words[i], i);
    vector<vector<int>> res;
    for (int i = 0; i < words.size(); ++i) {
      int len = words[i].size();
      for (int j = 0; j <= len; ++j) {
        // 枚举判断 [j, len - 1] 是不是回文串
        if (check(words[i], j, len - 1)) {
          int idx = find(words[i], 0, j - 1);
          if (idx != i && idx != -1)
            res.push_back({i, idx});
        }
        // 枚举判断 [0, j] 是不是回文串
        if (j && check(words[i], 0, j - 1)) {
          int idx = find(words[i], j, len - 1);
          if (idx != -1 && idx != i)
            res.push_back({idx, i});
        }
      }
    }
    return res;
  }
};