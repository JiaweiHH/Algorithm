#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList,
                                           vector<vector<int>> &secondList) {
    vector<vector<int>> res;
    int pA = 0, pB = 0;
    int start = -1, end = -1;
    while (pA != firstList.size() && pB != secondList.size()) {
      if (firstList[pA][1] < secondList[pB][1]) {
        if (firstList[pA][0] >= secondList[pB][0])
          res.push_back({firstList[pA][0], firstList[pA][1]});
        else if (firstList[pA][0] <= secondList[pB][0] &&
                 secondList[pB][0] <= firstList[pA][1])
          res.push_back({secondList[pB][0], firstList[pA][1]});
        ++pA;
      } else {
        if (secondList[pB][0] >= firstList[pA][0])
          res.push_back({secondList[pB][0], secondList[pB][1]});
        else if (secondList[pB][0] <= firstList[pA][0] &&
                 firstList[pA][0] <= secondList[pB][1])
          res.push_back({firstList[pA][0], secondList[pB][1]});
        ++pB;
      }
    }
    return res;
  }
};