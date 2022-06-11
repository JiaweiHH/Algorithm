#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  unordered_map<string, vector<string>> graph, from;
  unordered_set<string> middle_node;
  vector<vector<string>> res;
  void build_graph(vector<string> &wordList) {
    for (auto &str : wordList) {
      if (graph.count(str))
        continue;
      string cur_str = str;
      for (auto &ch : str) {
        char tmp = ch;
        ch = '*';
        graph[str].push_back(cur_str);
        graph[cur_str].push_back(str);
        middle_node.insert(str);
        ch = tmp;
      }
    }
  }
  void dfs(string &cur_str, string &beginWord, vector<string> &cur_res) {
    if (cur_str == beginWord) {
      res.push_back({cur_res.rbegin(), cur_res.rend()});
      return;
    }
    for (auto &from_str : from[cur_str]) {
      if (!middle_node.count(from_str))
        cur_res.push_back(from_str);
      dfs(from_str, beginWord, cur_res);
      if (!middle_node.count(from_str))
        cur_res.pop_back();
    }
  }
  vector<vector<string>> findLadders(string beginWord, string endWord,
                                     vector<string> &wordList) {
    // 构建图
    wordList.push_back(beginWord);
    build_graph(wordList);
    wordList.pop_back();
    if (!graph.count(endWord))
      return {};
    // BFS
    queue<string> que;
    que.push(beginWord);
    unordered_set<string> visited{beginWord};
    while (!que.empty()) {
      bool tag_find = false;
      int len = que.size();
      unordered_set<string> this_round;
      for (int i = 0; i < len; ++i) {
        string cur_str = que.front();
        que.pop();
        for (auto &str : graph[cur_str]) {
          if (!visited.count(str)) {
            if (str == endWord)
              tag_find = true;
            from[str].push_back(cur_str);
            visited.insert(str);
            this_round.insert(str);
            que.push(str);
          } else if (this_round.count(str)) {
            from[str].push_back(cur_str);
          }
        }
      }
      if (tag_find) {
        break;
      }
    }
    // DFS 构建转换路径
    vector<string> cur_res{endWord};
    dfs(endWord, beginWord, cur_res);
    return res;
  }
};