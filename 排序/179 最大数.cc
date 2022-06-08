#include <string>
#include <vector>
using namespace std;

template <int> class Solution;

/// 使用 string API 实现 a > b
template <> class Solution<1> {
public:
  string largestNumber(vector<int> &nums) {
    sort(nums.begin(), nums.end(), [](int lhs, int rhs) {
      string str_1 = to_string(lhs) + to_string(rhs),
             str_2 = to_string(rhs) + to_string(lhs);
      return str_1 > str_2;
    });
    string res;
    for (auto num : nums)
      res.append(to_string(num));
    return res[0] == '0' ? "0" : res;
  }
};

/// 使用整数运算实现 a > b 比较
template <> class Solution<2> {
public:
  string largestNumber(vector<int> &nums) {
    sort(nums.begin(), nums.end(), [](int x, int y) {
      long sx = 10, sy = 10;
      while (sx <= x)
        sx *= 10;
      while (sy <= y)
        sy *= 10;
      return x * sy + y > y * sx + x;
    });
    string res;
    for (auto num : nums)
      res.append(to_string(num));
    return res[0] == '0' ? "0" : res;
  }
};