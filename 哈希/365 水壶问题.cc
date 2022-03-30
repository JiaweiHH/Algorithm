#include <stack>
#include <unordered_set>
using namespace std;

class Solution {
public:
  bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
    stack<pair<int, int>> stk;
    stk.push({0, 0});
    auto pair_hash = [](const pair<int, int> val) {
      return hash<int>()(val.first) ^ hash<int>()(val.second);
    };
    unordered_set<pair<int, int>, decltype(pair_hash)> st(0, pair_hash);
    while (!stk.empty()) {
      if (st.count(stk.top())) {
        stk.pop();
        continue;
      }
      auto [remain_x, remain_y] = stk.top();
      st.insert({remain_x, remain_y});
      stk.pop();
      if (remain_x == targetCapacity || remain_y == targetCapacity ||
          remain_x + remain_y == targetCapacity)
        return true;
      stk.push({jug1Capacity, remain_y});
      stk.push({remain_x, jug2Capacity});
      stk.push({0, remain_y});
      stk.push({remain_x, 0});
      stk.push({remain_x - min(remain_x, jug2Capacity - remain_y),
                remain_y + min(remain_x, jug2Capacity - remain_y)});
      stk.push({remain_x + min(remain_y, jug1Capacity - remain_x),
                remain_y - min(remain_y, jug1Capacity - remain_x)});
    }
    return false;
  }
};