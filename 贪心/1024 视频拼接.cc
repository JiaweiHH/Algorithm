#include <vector>
using namespace std;

template <int> class Solution;

/// 排序 + 贪心
template <> class Solution<1> {
public:
  int videoStitching(vector<vector<int>> &clips, int time) {
    sort(clips.begin(), clips.end(),
         [](vector<int> &lhs, vector<int> &rhs) { return lhs[0] < rhs[0]; });
    int res = 0, right_max = 0, end = 0;
    for (int i = 0; end < time && i != clips.size() && clips[i][0] <= end;
         ++i) {
      if (clips[i][0] > right_max) {
        ++res;
        right_max = end;
      }
      end = max(end, clips[i][1]);
    }
    return end >= time ? ++res : -1;
  }
};

/// 贪心
template <> class Solution<2> {
public:
  int videoStitching(vector<vector<int>> &clips, int time) {
    vector<int> vec(time);
    for (int i = 0; i < clips.size(); ++i) {
      if (clips[i][0] < time)
        vec[clips[i][0]] = max(vec[clips[i][0]], clips[i][1]);
    }
    int last = 0, res = 0, pre = 0;
    for (int i = 0; i < time; ++i) {
      last = max(last, vec[i]);
      if (i == last)
        return -1;
      if (i == pre) {
        ++res;
        pre = last;
      }
    }
    return res;
  }
};