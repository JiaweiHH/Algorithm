#include <queue>
#include <vector>
using namespace std;

class KthLargest {
public:
  KthLargest(int k, vector<int> &nums) : k_(k) {
    for (int i = 0; i < nums.size(); ++i)
      add(nums[i]);
  }

  int add(int val) {
    if (largeValue_.size() < k_) {
      largeValue_.push(val);
      return largeValue_.top();
    }
    if (val > largeValue_.top()) {
      largeValue_.push(val);
      largeValue_.pop();
    }
    return largeValue_.top();
  }

private:
  priority_queue<int, vector<int>, greater<int>> largeValue_;
  int k_;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */