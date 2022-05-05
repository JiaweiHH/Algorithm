#include <numeric>
#include <random>
#include <vector>
using namespace std;

class Solution {
public:
  Solution(vector<int> &w)
      : gen(random_device{}()), dis(1, accumulate(w.begin(), w.end(), 0)),
        prefix(w.size()) {
    int sum = 0;
    for (int i = 0; i < w.size(); ++i) {
      sum += w[i];
      prefix[i] = sum;
    }
  }
  int binary_search(int target) {
    int l = 0, r = prefix.size();
    while (l <= r) {
      int mid = (l + r) / 2;
      if (prefix[mid] >= target)
        r = mid - 1;
      else
        l = mid + 1;
    }
    return l;
  }
  int pickIndex() {
    int target = dis(gen);
    return binary_search(target);
  }

private:
  vector<int> prefix;
  mt19937 gen;
  uniform_int_distribution<int> dis;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */