#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class UnionFind {
public:
  UnionFind(vector<vector<string>> &similarPairs) {
    for (auto &pair : similarPairs) {
      parent[pair[0]] = pair[0];
      parent[pair[1]] = pair[1];
    }
  }
  string _find(string str) {
    if (!parent.count(str))
      return "";
    while (str != parent[str]) {
      parent[str] = parent[parent[str]];
      str = parent[str];
    }
    return str;
  }
  void _union(string &str1, string &str2) {
    string root1 = _find(str1), root2 = _find(str2);
    if (root1 != root2)
      parent[root1] = root2;
  }
  int _count() const { return count; }

private:
  unordered_map<string, string> parent;
  int count;
};

class Solution {
public:
  bool areSentencesSimilarTwo(vector<string> &sentence1,
                              vector<string> &sentence2,
                              vector<vector<string>> &similarPairs) {
    if (sentence1.size() != sentence2.size())
      return false;
    UnionFind uf(similarPairs);
    for (auto &pair : similarPairs)
      uf._union(pair[0], pair[1]);
    for (int i = 0; i < sentence1.size(); ++i) {
      string str1 = sentence1[i], str2 = sentence2[i];
      if (str1 == str2)
        continue;
      string root1 = uf._find(sentence1[i]), root2 = uf._find(sentence2[i]);
      if (root1 != root2 || (root1 == "" && root2 == ""))
        return false;
    }
    return true;
  }
};