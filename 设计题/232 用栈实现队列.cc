#include <stack>
using namespace std;

class MyQueue {
public:
  MyQueue() {}

  void push(int x) { stk1.push(x); }

  int pop() {
    if (stk2.empty()) {
      while (!stk1.empty()) {
        int val = stk1.top();
        stk1.pop();
        stk2.push(val);
      }
    }
    int val = stk2.top();
    stk2.pop();
    return val;
  }

  int peek() {
    if (empty())
      return -1;
    if (stk2.empty()) {
      while (!stk1.empty()) {
        int val = stk1.top();
        stk1.pop();
        stk2.push(val);
      }
    }
    return stk2.top();
  }

  bool empty() { return stk1.empty() && stk2.empty(); }

private:
  stack<int> stk1, stk2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */