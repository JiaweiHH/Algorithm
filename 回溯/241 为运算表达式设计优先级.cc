#include <string>
#include <vector>
using namespace std;

/// @brief 给定一个含有数字和运算符的表达式，为表达式添加括号，改变其运算优先级以求出不同的结果。输出所有可能的结果

template <int> class Solution {};

/// @brief 分治
/// 遍历 expression 每次遇到一个运算符 op 就去递归的计算其左边表达式的所有可能结果，以及右边表达式的所有可能计算结果
/// 然后分别循环左边和右边的所有结果，计算 expression 以 op 为分界线的所有可能结果
/// 当 expression 遍历结束的时候就得到了所有可能的计算结果
template <> class Solution<1> {
public:
  vector<int> res;
  vector<int> diffWaysToCompute(string expression) {
    return calculate(expression);
  }

  vector<int> calculate(string expression) {
    vector<int> temp_res;
    for (int i = 0; i < expression.size(); ++i) {
      if (expression[i] == '+' || expression[i] == '-' ||
          expression[i] == '*') {
        vector<int> left = calculate(expression.substr(0, i));
        vector<int> right = calculate(expression.substr(i + 1));
        for (auto &l : left) {
          for (auto &r : right) {
            switch (expression[i]) {
            case '+':
              temp_res.push_back(l + r);
              break;
            case '-':
              temp_res.push_back(l - r);
              break;
            case '*':
              temp_res.push_back(l * r);
              break;
            }
          }
        }
      }
    }
    if (temp_res.empty()) {
      temp_res.push_back(stoi(expression));
    }
    return temp_res;
  }
};
