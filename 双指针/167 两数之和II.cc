#include <vector>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    int l = 0, r = numbers.size() - 1;
    vector<int> res;
    while (l < r) {
      if (numbers[l] + numbers[r] > target)
        --r;
      else if (numbers[l] + numbers[r] < target)
        ++l;
      else {
        res.push_back(l + 1);
        res.push_back(r + 1);
        return res;
      }
    }
    return res;
  }
};