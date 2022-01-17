#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> construct2DArray(vector<int> &original, int m, int n) {
    if (original.size() != m * n)
      return vector<vector<int>>();
    vector<vector<int>> res(m);
    for (int i = 0; i < original.size(); ++i) {
      res[i / n].push_back(original[i]);
    }
    return res;
  }
};