#include <string>
using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    int pA = 0, pB = s.size() - 1;
    while (pA <= pB) {
      int ch1, ch2;
      if (s[pA] >= 'A' && s[pA] <= 'Z')
        ch1 = s[pA] - 'A';
      else if (s[pA] >= 'a' && s[pA] <= 'z')
        ch1 = s[pA] - 'a';
      else if (s[pA] >= '0' && s[pA] <= '9')
        ch1 = s[pA];
      else {
        ++pA;
        continue;
      }

      if (s[pB] >= 'A' && s[pB] <= 'Z')
        ch2 = s[pB] - 'A';
      else if (s[pB] >= 'a' && s[pB] <= 'z')
        ch2 = s[pB] - 'a';
      else if (s[pB] >= '0' && s[pB] <= '9')
        ch2 = s[pB];
      else {
        --pB;
        continue;
      }
      if (ch1 != ch2)
        return false;
      ++pA;
      --pB;
    }
    return true;
  }
};