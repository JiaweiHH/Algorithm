#include <string>
#include <unordered_map>
using namespace std;

class Trie {
public:
  Trie() : last(false) {}

  void insert(string word) {
    Trie *node = this;
    for (int i = 0; i < word.size(); ++i) {
      char ch = word[i];
      if (!node->children.count(ch))
        node->children[ch] = new Trie;
      node = node->children[ch];
    }
    node->last = true;
  }

  bool search(string word) {
    Trie *node = searchPrefix(word);
    return node && node->last;
  }

  bool startsWith(string prefix) {
    Trie *node = searchPrefix(prefix);
    return node != nullptr;
  }

private:
  unordered_map<char, Trie *> children;
  bool last;

  Trie *searchPrefix(string prefix) {
    Trie *node = this;
    for (auto &ch : prefix) {
      if (!node->children.count(ch))
        return nullptr;
      node = node->children[ch];
    }
    return node;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */