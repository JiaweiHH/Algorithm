#include <iostream>
#include <vector>
using namespace std;

int get_zero_numbers(int &val) {
  int cnt = 0;
  while (val > 0 && val % 10 == 0) {
    ++cnt;
    val /= 10;
  }
  return cnt;
}

int main() {
  int n;
  cin >> n;
  vector<int> nums(n), vec(n), zero_cnt(n);
  for (int i = 0; i < n; ++i)
    cin >> nums[i];
  int val = 1, res = 0, prev_zero = 0;
  for (int i = 0; i < n; ++i) {
    val *= nums[i];
    int cnt = get_zero_numbers(val);
    cout << "[1, " << i + 1 << "], cnt = " << cnt + prev_zero << "\n";
    prev_zero += cnt;
    res += prev_zero;
    vec[i] = val;
    zero_cnt[i] = prev_zero;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j < i; ++j) {
      int zero_num = zero_cnt[i] - zero_cnt[j];
      int tmp_1 = vec[i], tmp_2 = vec[j];
      int tmp_3 = tmp_1 * pow(10, zero_num) / tmp_2;
      int cnt = get_zero_numbers(tmp_3);
      cout << "[" << j + 1 << ", " << i + 1 << "], cnt = " << cnt + zero_num << "\n";
      res += cnt + zero_num;
    }
  }
  cout << res << "\n";
}