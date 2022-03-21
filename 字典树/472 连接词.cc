#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  class Trie {
  public:
    Trie() : last(false) {}
    void insert(string word) {
      if (word.empty())
        return;
      Trie *node = this;
      for (auto &ch : word) {
        if (!node->children.count(ch))
          node->children[ch] = new Trie;
        node = node->children[ch];
      }
      node->last = true;
    }
    bool searchPrefix(string word) {
      Trie *node = this;
      for (int i = 0; i < word.size(); ++i) {
        if (node->last && i < word.size()) {
          bool tmp = searchPrefix(word.substr(i));
          if (tmp)
            return true;
        }
        if (!node->children.count(word[i]))
          return false;
        node = node->children[word[i]];
      }
      return node->last;
    }

  private:
    unordered_map<char, Trie *> children;
    bool last;
  };
  vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
    sort(words.begin(), words.end(), [](const string &lhs, const string &rhs) {
      return lhs.size() < rhs.size();
    });
    vector<string> res;
    Trie *trie = new Trie;
    int i = 0;
    for (auto &w : words) {
      if (trie->searchPrefix(w))
        res.push_back(w);
      else
        trie->insert(w);
    }
    return res;
  }
};