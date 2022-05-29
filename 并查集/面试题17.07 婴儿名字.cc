#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class UnionFind {
public:
  UnionFind(vector<string> &names) {
    for (int i = 0; i < names.size(); ++i) {
      int pos_1 = names[i].find_first_of("(");
      string name = names[i].substr(0, pos_1);
      int pos_2 = names[i].find_first_of(")");
      int num = stoi(names[i].substr(pos_1 + 1, pos_2 - pos_1 - 1));
      parent[name] = name;
      count[name] = num;
      st.insert(name);
    }
  }
  string _find(string str) {
    if (!parent.count(str)) {
      parent[str] = str;
      count[str] = 0;
      st.insert(str);
      return str;
    }
    while (str != parent[str]) {
      parent[str] = parent[parent[str]];
      str = parent[str];
    }
    return str;
  }
  void _union(string &str1, string &str2) {
    string root1 = _find(str1), root2 = _find(str2);
    if (root1 > root2) {
      parent[root1] = root2;
      count[root2] += count[root1];
      st.erase(root1);
    } else if (root1 < root2) {
      parent[root2] = root1;
      count[root1] += count[root2];
      st.erase(root2);
    }
  }
  vector<string> _result() {
    vector<string> res;
    for (auto it = st.begin(); it != st.end(); ++it) {
      int cnt = count[*it];
      res.push_back(*it + "(" + to_string(cnt) + ")");
    }
    return res;
  }

private:
  unordered_map<string, string> parent;
  unordered_map<string, int> count;
  unordered_set<string> st;
};

class Solution {
public:
  vector<string> trulyMostPopular(vector<string> &names,
                                  vector<string> &synonyms) {
    UnionFind uf(names);
    for (int i = 0; i < synonyms.size(); ++i) {
      int pos = synonyms[i].find_first_of(",");
      string name1 = synonyms[i].substr(1, pos - 1),
             name2 = synonyms[i].substr(pos + 1, synonyms[i].size() - pos - 2);
      uf._union(name1, name2);
    }
    return uf._result();
  }
};