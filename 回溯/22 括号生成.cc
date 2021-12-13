#include <string>
#include <vector>

using namespace std;

// 给定一个数字 n，返回生成 n 对括号的所有组合，要求左括号必须以正确的顺序闭合
// input: n = 3
// output: ["((()))","(()())","(())()","()(())","()()()"]

// DFS
// note: 搜索的时候需要注意只有当右括号的数量小于左括号的时候才可以压入右括号
// 当右括号数量等于 num 的时候就是一个组合方式
// 空间复杂度 O(n)，时间复杂度 O(4^n / sqrt(n))
class Solution {
public:
  vector<string> res;
  vector<string> generateParenthesis(int n) {
    string tmp;
    dfs(0, 0, n, tmp);
    return res;
  }
  void dfs(int left_n, int right_n, int num, string &tmp) {
    if (right_n == num) {
      res.push_back(tmp);
      return;
    }
    if (left_n < num) {
      tmp.push_back('(');
      dfs(left_n + 1, right_n, num, tmp);
      tmp.pop_back();
    }
    if (right_n < left_n) {
      tmp.push_back(')');
      dfs(left_n, right_n + 1, num, tmp);
      tmp.pop_back();
    }
  }
};

// 递归，generate(n) 函数表示生成 n 对括号的所有可能
// 括号序列可以使用 (a)b 表示，其中 a 和 b 分别是一个合法的括号序列
// 1. 枚举第一个 '(' 对应的 ')' 的位置 2*i+1
// 2. 调用 generate(i) 生成 a 的 i 对括号
// 3. 调用 generate(n - i - 1) 生成 b 的 n - i - 1 对括号
// 4. 组合所有的 a 和 b
class Solution_1 {
  shared_ptr<vector<string>> cache[100] = {nullptr};

public:
  shared_ptr<vector<string>> generate(int n) {
    if (cache[n] != nullptr)
      return cache[n];
    if (n == 0) {
      cache[0] = shared_ptr<vector<string>>(new vector<string>{""});
    } else {
      auto result = shared_ptr<vector<string>>(new vector<string>);
      for (int i = 0; i != n; ++i) {
        auto lefts = generate(i);
        auto rights = generate(n - i - 1);
        for (const string &left : *lefts)
          for (const string &right : *rights)
            result->push_back("(" + left + ")" + right);
      }
      cache[n] = result;
    }
    return cache[n];
  }
  vector<string> generateParenthesis(int n) { return *generate(n); }
};