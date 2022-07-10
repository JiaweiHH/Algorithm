#include <map>
#include <queue>
#include <vector>
using namespace std;

template <int> class SummaryRanges;

/// @brief 堆
template <> class SummaryRanges<1> {
public:
  SummaryRanges() {}

  void addNum(int val) { que.push({val, val}); }

  // 获取所有区间的时候堆区间进行合并
  vector<vector<int>> getIntervals() {
    vector<vector<int>> res;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        new_que;
    pair<int, int> cur = que.top();
    que.pop();
    while (!que.empty()) {
      auto interval = que.top();
      que.pop();
      // 下一个区间不能继续合并，所以应该创建一个新的区间
      // 这里对于重复的区间也有去除重复的作用
      if (interval.first > cur.second + 1) {
        new_que.push(cur);
        res.push_back({cur.first, cur.second});
        cur.first = interval.first;
      }
      cur.second = max(cur.second, interval.second);
    }
    new_que.push(cur);
    res.push_back({cur.first, cur.second});
    que = std::move(new_que);
    return res;
  }

private:
  // 堆中保存不同的区间
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      que;
};

/// @brief 有序映射
template <> class SummaryRanges<2> {
public:
  SummaryRanges() {}

  // 添加元素的时候对区间进行合并
  void addNum(int val) {
    // 找到第一个大于 val 的区间
    auto it = vals.upper_bound(val);
    // prev_it 是第一个小于等于 val 的区间
    auto prev_it = it == vals.begin() ? vals.end() : prev(it);
    // 1. val 已经被现有的区间包含了
    if (prev_it != vals.end() && prev_it->first <= val &&
        val <= prev_it->second)
      return;
    bool left_side = it != vals.end() && it->first - 1 == val,
         right_side = prev_it != vals.end() && prev_it->second + 1 == val;
    int l = val, r = val;
    if (left_side && right_side) {
      // 2. val 可以合并两个区间
      l = prev_it->first, r = it->second;
      vals.erase(prev_it);
      vals.erase(it);
    } else if (left_side) {
      // 3. val 可以合并它右侧的区间
      l = val, r = it->second;
      vals.erase(it);
    } else if (right_side) {
      // 4. val 可以合并它左侧的区间
      l = prev_it->first, r = val;
      vals.erase(prev_it);
    }
    // 5. val 不能和任何区间合并

    vals.insert({l, r});
  }

  vector<vector<int>> getIntervals() {
    vector<vector<int>> res;
    for (auto [l, r] : vals)
      res.push_back({l, r});
    return res;
  }

private:
  // vals 记录所有的区间 [l, r]
  map<int, int> vals;
};