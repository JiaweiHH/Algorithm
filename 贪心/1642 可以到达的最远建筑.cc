#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
    priority_queue<int, vector<int>, greater<int>> heap;
    int sum = 0, i;
    for (i = 1; i < heights.size(); ++i) {
      if (heights[i] - heights[i - 1] <= 0)
        continue;
      int diff = heights[i] - heights[i - 1];
      heap.push(diff);
      if (heap.size() > ladders) {
        sum += heap.top();
        heap.pop();
        if (sum > bricks)
          break;
      }
    }
    return i - 1;
  }
};