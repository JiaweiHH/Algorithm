#include <queue>
using namespace std;

class MedianFinder {
public:
  /** initialize your data structure here. */
  MedianFinder() {}

  void addNum(int num) {
    if (min_heap.empty() && max_heap.empty())
      min_heap.push(num);
    else {
      int min_top = min_heap.top();
      int sz = min_heap.size() + max_heap.size() + 1;
      if (num >= min_heap.top()) {
        min_heap.push(num);
        if (min_heap.size() > (sz + 1) / 2) {
          max_heap.push(min_heap.top());
          min_heap.pop();
        }
      } else {
        max_heap.push(num);
        if (max_heap.size() > sz / 2) {
          min_heap.push(max_heap.top());
          max_heap.pop();
        }
      }
    }
  }

  double findMedian() {
    int sz = min_heap.size() + max_heap.size();
    return sz % 2 == 1 ? min_heap.top()
                       : (min_heap.top() + max_heap.top()) * 1.0 / 2;
  }

private:
  priority_queue<int, vector<int>, greater<int>> min_heap;
  priority_queue<int, vector<int>, less<int>> max_heap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */