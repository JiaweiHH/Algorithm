#include <queue>
using namespace std;

class MedianFinder {
public:
  MedianFinder() {}

  void addNum(int num) {
    if (queMin.empty() && queMax.empty()) {
      queMin.push(num);
      return;
    }
    int val = num;
    if (num < queMin.top()) {
      val = queMin.top();
      queMin.pop();
      queMin.push(num);
    } else if (!queMax.empty() && num > queMax.top()) {
      val = queMax.top();
      queMax.pop();
      queMax.push(num);
    }
    if (queMax.size() < queMin.size())
      queMax.push(val);
    else
      queMin.push(val);
  }

  double findMedian() {
    int size = queMin.size() + queMax.size();
    if (size % 2 == 1)
      return queMin.top();
    return (queMin.top() + queMax.top()) * 1.0 / 2;
  }

private:
  priority_queue<int, vector<int>, less<int>> queMin;
  priority_queue<int, vector<int>, greater<int>> queMax;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */