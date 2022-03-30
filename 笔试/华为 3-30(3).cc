// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here.
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, int> subtree;
int root = -1;
string str;
vector<int> tree;
string dfs(int idx) {
  if (idx >= tree.size() || tree[idx] == -1)
    return "#";
  string left = dfs(idx * 2);
  string right = dfs(idx * 2 + 1);
  string res = left + "," + right + "," + to_string(tree[idx]);
  if (subtree[res]++ == 1) {
    if (res.size() > str.size()) {
      str = res;
      root = idx;
    }
  }
  return res;
}

int main() {
  tree.push_back(-1);
  string ss;
  cin >> ss;
  for (int i = 0; i < ss.size(); ++i) {
    if (ss[i] == ',' || ss[i] == '[' || ss[i] == ']')
      continue;
    if (ss[i] == 'n') {
      while (i < ss.size() && ss[i] != ',')
        ++i;
      tree.push_back(-1);
      continue;
    }
    tree.push_back(ss[i] - '0');
  }
  string tmp = dfs(1);
  if (root == -1)
    cout << -1 << "\n";
  else {
    string res = "[";
    queue<int> que;
    que.push(root);
    res.append(to_string(tree[root]));
    res.append(",");
    while (!que.empty()) {
      int idx = que.front();
      que.pop();
      if (idx * 2 < tree.size()) {
        if (tree[idx * 2] == -1)
          res.append("null");
        else {
          res.append(to_string(tree[idx * 2]));
          que.push(idx * 2);
        }
        res.push_back(',');
      }
      if (idx * 2 + 1 < tree.size()) {
        if (tree[idx * 2 + 1] == -1)
          res.append("null");
        else {
          res.append(to_string(tree[idx * 2 + 1]));
          que.push(idx * 2 + 1);
        }
        res.push_back(',');
      }
    }
    res.pop_back();
    res.push_back(']');
    cout << res << "\n";
  }
  return 0;
}