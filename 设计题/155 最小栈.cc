#include <vector>
using namespace std;

class MinStack {
public:
  vector<int> stk;
  int size;
  MinStack() {
    stk.clear();
    size = 0;
  }

  void push(int val) {
    if (!stk.empty()) {
      int tmp = stk[size - 1];
      stk.push_back(val);
      stk.push_back(min(val, tmp));
    } else {
      stk.push_back(val);
      stk.push_back(val);
    }
    size += 2;
  }

  void pop() {
    if (size == 0)
      return;
    stk.pop_back();
    stk.pop_back();
    size -= 2;
  }

  int top() { return stk[size - 2]; }

  int getMin() { return stk[size - 1]; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */