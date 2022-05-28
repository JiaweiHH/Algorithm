#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class UnionFind {
public:
  UnionFind(vector<vector<string>> &equations) {
    for (auto &eq : equations) {
      parent[eq[0]] = eq[0];
      parent[eq[1]] = eq[1];
      weight[eq[0]] = 1;
      weight[eq[1]] = 1;
    }
  }
  string _find(string str) {
    if (!parent.count(str))
      return "";
    while (str != parent[str]) {
      string tmp = _find(parent[str]);
      weight[str] *= weight[parent[str]];
      parent[str] = parent[parent[str]];
      str = parent[str];
    }
    return str;
  }
  void _union(string &str1, string &str2, double value) {
    string root1 = _find(str1), root2 = _find(str2);
    if (root1 != root2) {
      parent[root1] = root2;
      weight[root1] = value * weight[str2] / weight[str1];
    }
  }
  double is_connected(string &str1, string &str2) {
    string root1 = _find(str1), root2 = _find(str2);
    if (root1 != "" && root2 != "" && root1 == root2)
      return weight[str1] / weight[str2];
    return -1.0;
  }

private:
  unordered_map<string, string> parent;
  unordered_map<string, double> weight;
};

class Solution {
public:
  vector<double> calcEquation(vector<vector<string>> &equations,
                              vector<double> &values,
                              vector<vector<string>> &queries) {
    UnionFind uf(equations);
    vector<double> res;
    for (int i = 0; i < equations.size(); ++i)
      uf._union(equations[i][0], equations[i][1], values[i]);
    for (int i = 0; i < queries.size(); ++i) {
      res.push_back(uf.is_connected(queries[i][0], queries[i][1]));
    }
    return res;
  }
};