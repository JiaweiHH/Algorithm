#include <list>
#include <map>
#include <stack>
#include <vector>
using namespace std;

template <int> class MaxStack;

/// 使用 vector
template <> class MaxStack<1> {
public:
  MaxStack() {}

  void push(int x) { stk.push_back(x); }

  int pop() {
    int val = stk.back();
    stk.pop_back();
    return val;
  }

  int top() { return stk.back(); }

  int peekMax() { return *max_element(stk.begin(), stk.end()); }

  int popMax() {
    auto max_iter = stk.begin();
    for (auto it = stk.begin(); it != stk.end(); ++it) {
      if (*it >= *max_iter)
        max_iter = it;
    }
    int val = *max_iter;
    stk.erase(max_iter);
    return val;
  }

private:
  vector<int> stk;
};

/// 双栈
template <> class MaxStack<2> {
public:
  MaxStack() {}

  void push(int x) {
    if (!max_stk.empty())
      max_stk.push(max(max_stk.top(), x));
    else
      max_stk.push(x);
    stk.push(x);
  }

  int pop() {
    int res = stk.top();
    stk.pop();
    max_stk.pop();
    return res;
  }

  int top() { return stk.top(); }

  int peekMax() { return max_stk.top(); }

  int popMax() {
    stack<int> tmp_stk;
    while (stk.top() != max_stk.top()) {
      tmp_stk.push(pop());
    }
    int res = stk.top();
    stk.pop();
    max_stk.pop();
    while (!tmp_stk.empty()) {
      push(tmp_stk.top());
      tmp_stk.pop();
    }
    return res;
  }

private:
  stack<int> stk, max_stk;
};

/// 链表 + 红黑树
template <> class MaxStack<3> {
public:
  MaxStack() {}

  void push(int x) {
    auto iter = list_.insert(list_.end(), x);
    map_[x].push_back(iter);
  }

  int pop() {
    int res = list_.back();
    list_.pop_back();
    map_[res].pop_back();
    if (map_[res].size() == 0)
      map_.erase(res);
    return res;
  }

  int top() { return list_.back(); }

  int peekMax() { return prev(map_.end(), 1)->first; }

  int popMax() {
    int key = prev(map_.end(), 1)->first;
    auto iter = map_[key].back();
    list_.erase(iter);
    map_[key].pop_back();
    if (map_[key].size() == 0)
      map_.erase(key);
    return key;
  }

private:
  list<int> list_;
  map<int, list<list<int>::iterator>> map_;
};