#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList,
                                           vector<vector<int>> &secondList) {
    int l = 0, r = 0;
    vector<vector<int>> res;
    while (l != firstList.size() && r != secondList.size()) {
      if (firstList[l][1] < secondList[r][1]) {
        if (firstList[l][0] >= secondList[r][0])
          res.push_back({firstList[l][0], firstList[l][1]});
        else if (firstList[l][0] <= secondList[r][0] &&
                 firstList[l][1] >= secondList[r][0])
          res.push_back({secondList[r][0], firstList[l][1]});
        ++l;
      } else {
        if (secondList[r][0] >= firstList[l][0])
          res.push_back({secondList[r][0], secondList[r][1]});
        else if (secondList[r][0] <= firstList[l][0] &&
                 secondList[r][1] >= firstList[l][0])
          res.push_back({firstList[l][0], secondList[r][1]});
        ++r;
      }
    }
    return res;
  }
};