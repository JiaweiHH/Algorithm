#include <string>
#include <vector>
using namespace std;

/// @brief 给你一份航线列表 tickets ，其中 tickets[i] = [fromi, toi] 表示飞机出发和降落的机场地点
/// 请你对该行程进行重新规划排序，所有行程从 “JFK” 出发，每张票只能使用一次

/// @brief 回溯算法
/// 需要注意的是，需要进行剪枝，不然会超时。这里我的剪枝方法是对 tickets 当 from 相同的时候，按照 to 从小到大排序
/// 这样的话，在 dfs 中一旦找到了一条路径，那么之后的所有路径都不需要尝试了
/// 没剪枝之前因为不知道前面找到的路径是不是最小的路径，因此还需要遍历寻找后面的路径，这样就造成了时间上的开销
class Solution {
public:
  vector<vector<string>> res;
  vector<string> cur;
  vector<bool> visit;
  vector<string> findItinerary(vector<vector<string>> &tickets) {
    visit.resize(tickets.size(), false);
    int count = (tickets.size() * 2 - 2) / 2 + 2;
    // 优化回溯算法时间
    sort(tickets.begin(), tickets.end(),
         [](const vector<string> &lhs, const vector<string> &rhs) {
           if (lhs[0] < rhs[0])
             return true;
           if (lhs[0] == rhs[0]) {
             return lhs[1] < rhs[1];
           }
           return false;
         });
    dfs(tickets, "JFK", count);
    return *min_element(res.begin(), res.end());
  }
  bool dfs(const vector<vector<string>> &tickets, string from,
           const int &count) {
    if (cur.size() == count - 1) {
      cur.push_back(from);
      res.push_back(cur);
      cur.pop_back();
      return true;
    }
    for (int i = 0; i < tickets.size(); ++i) {
      if (!visit[i] && tickets[i][0] == from) {
        visit[i] = true;
        cur.push_back(from);
        // 优化回溯算法时间
        if (dfs(tickets, tickets[i][1], count))
          return true;
        cur.pop_back();
        visit[i] = false;
      }
    }
    return false;
  }
};