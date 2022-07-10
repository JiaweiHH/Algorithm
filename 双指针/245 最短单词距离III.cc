#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int shortestWordDistance(vector<string> &wordsDict, string word1,
                           string word2) {
    if (word1 != word2) {
      int res = wordsDict.size(), l = -1, r = -1;
      for (int i = 0; i < wordsDict.size(); ++i) {
        if (wordsDict[i] == word1)
          l = i;
        if (wordsDict[i] == word2)
          r = i;
        if (l != -1 && r != -1)
          res = min(res, abs(r - l));
      }
      return res;
    }
    int prev = -1, res = INT_MAX;
    for (int i = 0; i < wordsDict.size(); ++i) {
      if (wordsDict[i] == word1) {
        if (prev >= 0)
          res = min(res, i - prev);
        prev = i;
      }
    }
    return res;
  }
};