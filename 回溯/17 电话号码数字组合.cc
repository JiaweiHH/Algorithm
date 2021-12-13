#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// 手机九宫格键盘上每个数字都对应一组英文字符串，现在给出一个数字组合，输出所有可能的字符组合

// 这题比较简单，一开始先做好哈希映射，随后正常 dfs 就好了
class Solution {
public:
  unordered_map<int, vector<char>> map;
  vector<string> res;
  vector<string> letterCombinations(string digits) {
    if (digits.empty())
      return res;
    map[2] = {'a', 'b', 'c'};
    map[3] = {'d', 'e', 'f'};
    map[4] = {'g', 'h', 'i'};
    map[5] = {'j', 'k', 'l'};
    map[6] = {'m', 'n', 'o'};
    map[7] = {'p', 'q', 'r', 's'};
    map[8] = {'t', 'u', 'v'};
    map[9] = {'w', 'x', 'y', 'z'};
    vector<int> nums;
    for (const auto &ch : digits) {
      nums.push_back(ch - '0');
    }
    string tmp;
    dfs(nums, 0, tmp);
    return res;
  }
  void dfs(const vector<int> &nums, int index, string &tmp) {
    if (index == nums.size()) {
      res.push_back(tmp);
      return;
    }
    int num = nums[index];
    for (const auto &ch : map[num]) {
      tmp.push_back(ch);
      dfs(nums, index + 1, tmp);
      tmp.pop_back();
    }
  }
};