#include <vector>
#include <string>
#include <numeric>
using namespace std;

/// 首先计算今年距离 1970.12.31 过了多少天，然后计算今年里面过了多少天，这样得到了今天距离 1970.12.31 过了多少天
/// 然后由于 1970.12.31 是星期四，就可以计算出今天是星期几了
class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
      vector<string> week = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
      vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
      // 计算 year 之前距离 1970.12.31 过了多少天，减去 1969 是因为 1968 年是闰年，
      // 所以当 year = 1972 的时候刚好不多加 1 天，当 year = 1973 的时候需要多加一天
      int count = 365 * (year - 1971) + (year - 1969) / 4;
      // 计算 year 这一年过了多少天
      count += accumulate(months.begin(), months.begin() + month - 1, 0);
      count += day;
      if (isLeapYear(year) && month > 2)
        count++;
      // 1970.12.31 是周四
      return week[(count + 4) % 7];
    }
    bool isLeapYear(int year) {
      return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
};