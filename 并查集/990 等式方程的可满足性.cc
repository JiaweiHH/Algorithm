#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class UnionFind {
public:
  UnionFind(vector<string> &equations) {
    for (auto &str : equations) {
      char ch1 = str[0], ch2 = str[3];
      parent[ch1] = ch1;
      parent[ch2] = ch2;
    }
  }
  char _find(char ch) {
    while (ch != parent[ch]) {
      parent[ch] = parent[parent[ch]];
      ch = parent[ch];
    }
    return ch;
  }
  void _union(char ch1, char ch2) {
    char root1 = _find(ch1), root2 = _find(ch2);
    if (root1 != root2)
      parent[root1] = root2;
  }

private:
  unordered_map<char, char> parent;
};

class Solution {
public:
  bool equationsPossible(vector<string> &equations) {
    UnionFind uf(equations);
    for (auto &str : equations) {
      if (str[1] == '=')
        uf._union(str[0], str[3]);
    }
    for (auto &str : equations) {
      if (str[1] == '!') {
        char root1 = uf._find(str[0]), root2 = uf._find(str[3]);
        if (root1 == root2)
          return false;
      }
    }
    return true;
  }
};