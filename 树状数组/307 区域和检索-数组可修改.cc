#include <vector>
using namespace std;

class NumArray {
public:
  NumArray(vector<int> &nums) : tree(nums.size()), nums_(nums) {
    for (int i = 0; i < nums.size(); ++i)
      tree.update(i + 1, nums[i]);
  }

  void update(int index, int val) {
    tree.update(index + 1, val - nums_[index]);
    nums_[index] = val;
  }

  int sumRange(int left, int right) { return tree.query(left + 1, right + 1); }

private:
  struct binaryIndexedTree {
    vector<int> tree;
    int n;
    binaryIndexedTree(int n) : n(n) { tree.resize(n + 1); }
    int low_bit(int x) { return x & -x; }
    int query(int x) {
      int res = 0;
      while (x) {
        res += tree[x];
        x -= low_bit(x);
      }
      return res;
    }
    int query(int x, int y) { return query(y) - query(x - 1); }
    void update(int x, int val) {
      while (x <= n) {
        tree[x] += val;
        x += low_bit(x);
      }
    }
  };
  binaryIndexedTree tree;
  vector<int> nums_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */