#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

template <int> class Solution;

/// DFS 暴力建图，超时
template <> class Solution<1> {
public:
  int res = INT_MAX;
  vector<bool> visited;
  bool check(string &str1, string &str2) {
    int cnt = 0;
    for (int i = 0; i < str1.size(); ++i) {
      if (str1[i] != str2[i]) {
        if (cnt == 1)
          return false;
        ++cnt;
      }
    }
    return true;
  }
  void dfs(vector<vector<int>> &map, int index, int dst, int cur) {
    if (index == dst) {
      res = min(res, cur);
      return;
    }
    visited[index] = true;
    for (int i = 0; i < map.size(); ++i) {
      if (map[index][i] == 1 && !visited[i])
        dfs(map, i, dst, cur + 1);
    }
    visited[index] = false;
  }
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    int n = wordList.size(), dst = -1;
    vector<vector<int>> map(n, vector<int>(n, 0));
    // 预处理，构建图
    for (int i = 0; i < n; ++i) {
      if (wordList[i] == endWord)
        dst = i;
      for (int j = i + 1; j < n; ++j) {
        if (check(wordList[i], wordList[j]))
          map[i][j] = map[j][i] = 1;
      }
    }
    if (dst == -1)
      return 0;
    visited.resize(n, false);
    for (int i = 0; i < n; ++i) {
      if (check(beginWord, wordList[i])) {
        dfs(map, i, dst, 1);
      }
    }
    return res == INT_MAX ? 0 : res + 1;
  }
};

/// 优化建图
template <> class Solution<2> {
public:
  int sequence = 0;
  int get_id(vector<vector<int>> &graph, unordered_map<string, int> &word_id,
             string &str) {
    if (!word_id.count(str)) {
      word_id[str] = sequence++;
      graph.emplace_back();
    }
    return word_id[str];
  }
  void build_graph(vector<vector<int>> &graph,
                   unordered_map<string, int> &word_id,
                   vector<string> &wordList) {
    for (auto &str : wordList) {
      int id_1 = get_id(graph, word_id, str);
      for (auto &ch : str) {
        char tmp = ch;
        ch = '*';
        int id_2 = get_id(graph, word_id, str);
        graph[id_1].push_back(id_2);
        graph[id_2].push_back(id_1);
        ch = tmp;
      }
    }
  }
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    // 优化建图
    wordList.emplace_back(beginWord);
    unordered_map<string, int> word_id;
    vector<vector<int>> graph;
    build_graph(graph, word_id, wordList);
    wordList.pop_back();
    if (!word_id.count(endWord))
      return 0;
    // BFS
    queue<int> que;
    que.push(word_id[beginWord]);
    vector<bool> visited(word_id.size());
    int cnt = 0;
    visited[word_id[beginWord]] = true;
    while (!que.empty()) {
      ++cnt;
      int len = que.size();
      for (int i = 0; i < len; ++i) {
        int node = que.front();
        que.pop();
        if (node == word_id[endWord])
          return (cnt + 1) / 2;
        for (auto x : graph[node]) {
          if (!visited[x]) {
            visited[x] = true;
            que.push(x);
          }
        }
      }
    }
    return 0;
  }
};