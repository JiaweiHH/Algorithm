#include <queue>
#include <vector>
using namespace std;

class SummaryRanges {
public:
  SummaryRanges() {}

  void addNum(int val) { q.push({val, val}); }

  vector<vector<int>> getIntervals() {
    if (q.empty())
      return {};
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        new_q;
    pair<int, int> cur = q.top();
    q.pop();
    vector<vector<int>> res;
    while (!q.empty()) {
      pair<int, int> val = q.top();
      q.pop();
      if (val.first > cur.second + 1) {               
        new_q.push(cur);
        res.push_back({cur.first, cur.second});
        cur.first = val.first;
      }
      cur.second = max(cur.second, val.second);
    }
    new_q.push({cur.first, cur.second});
    res.push_back({cur.first, cur.second});
    q = new_q;
    return res;
  }

private:
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      q;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */