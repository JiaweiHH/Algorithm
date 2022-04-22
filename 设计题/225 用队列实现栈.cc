#include <queue>
using namespace std;

template <int> class MyStack;

/// 两个队列，push O(n)，pop O(1)
template <> class MyStack<1> {
public:
  MyStack() {}

  void push(int x) {
    queue<int> &ref_q1 = que_1.empty() ? que_1 : que_2; // 空队列
    queue<int> &ref_q2 = que_1.empty() ? que_2 : que_1; // 非空队列
    ref_q1.push(x);
    while (!ref_q2.empty()) {
      int v = ref_q2.front();
      ref_q2.pop();
      ref_q1.push(v);
    }
  }

  int pop() {
    queue<int> &ref_q = !que_1.empty() ? que_1 : que_2;
    int res = ref_q.front();
    ref_q.pop();
    return res;
  }

  int top() { return que_1.empty() ? que_2.front() : que_1.front(); }

  bool empty() { return que_1.empty() && que_2.empty(); }

private:
  queue<int> que_1, que_2;
};

/// 一个队列
template <> class MyStack<2> {
public:
  MyStack() : num(0) {}

  void push(int x) {
    que.push(x);
    for (int i = 0; i < num; ++i) {
      int v = que.front();
      que.pop();
      que.push(v);
    }
    ++num;
  }

  int pop() {
    int v = que.front();
    que.pop();
    --num;
    return v;
  }

  int top() { return que.front(); }

  bool empty() { return num == 0; }

private:
  queue<int> que;
  int num;
};