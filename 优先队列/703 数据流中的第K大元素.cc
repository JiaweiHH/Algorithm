#include <queue>
#include <vector>
using namespace std;

class KthLargest {
public:
  KthLargest(int k, vector<int> &nums) : _k(k) {
    for (int i = 0; i < nums.size(); ++i)
      add(nums[i]);
  }

  int add(int val) {
    heap.push(val);
    if (heap.size() > _k)
      heap.pop();
    return heap.top();
  }

private:
  priority_queue<int, vector<int>, greater<int>> heap;
  int _k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */