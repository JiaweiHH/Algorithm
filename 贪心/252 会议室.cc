#include <vector>
using namespace std;

class Solution {
public:
  bool canAttendMeetings(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end());
    int cur = 0;
    for (int i = 0; i < intervals.size(); ++i) {
      if (intervals[i][0] >= cur)
        cur = intervals[i][1];
      else
        return false;
    }
    return true;
  }
};