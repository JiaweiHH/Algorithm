#include <vector>
using namespace std;

class NumArray {
public:
  NumArray(vector<int> &nums) {
    prefix.resize(nums.size());
    prefix[0] = nums[0];
    for (int i = 1; i < nums.size(); ++i)
      prefix[i] = prefix[i - 1] + nums[i];
  }

  int sumRange(int left, int right) {
    return left == 0 ? prefix[right] : prefix[right] - prefix[left - 1];
  }

private:
  vector<int> prefix;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */