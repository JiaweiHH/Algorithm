#include <vector>
using namespace std;

template <int> class MyCircularQueue;

/// 链表形式
template <> class MyCircularQueue<1> {
public:
  MyCircularQueue(int k) : capacity(k), size(0), head(nullptr), tail(nullptr) {}

  bool enQueue(int value) {
    // cout << "enQueue " << value << "\n";
    if (size == capacity)
      return false;
    ListNode *node = new ListNode(value);
    if (head == nullptr) {
      node->next = node;
      node->prev = node;
      head = tail = node;
    } else {
      node->next = head;
      node->prev = tail;
      tail->next = node;
      tail = node;
      head->prev = tail;
    }
    ++size;
    return true;
  }

  bool deQueue() {
    // cout << "deQueue\n";
    if (isEmpty())
      return false;
    ListNode *node = head;
    if (head == tail) {
      head = tail = nullptr;
    } else {
      head->next->prev = head->prev;
      head->prev->next = head->next;
      head = head->next;
    }
    delete (node);
    --size;
    return true;
  }

  int Front() {
    if (isEmpty())
      return -1;
    return head->val;
  }

  int Rear() {
    if (isEmpty())
      return -1;
    return tail->val;
  }

  bool isEmpty() { return head == nullptr; }

  bool isFull() { return size == capacity; }

private:
  struct ListNode {
    ListNode() : val(-1), prev(nullptr), next(nullptr) {}
    ListNode(int val) : val(val), prev(nullptr), next(nullptr) {}
    int val;
    ListNode *prev, *next;
  };
  ListNode *head, *tail, *dummy;
  int size, capacity;
};

/// 数组形式
template <> class MyCircularQueue<2> {
public:
  MyCircularQueue(int k) : size(0), head(0), tail(0) { vec.resize(k); }

  bool enQueue(int value) {
    if (isFull())
      return false;
    vec[tail] = value;
    tail = (tail + 1) % vec.size();
    ++size;
    return true;
  }

  bool deQueue() {
    if (isEmpty())
      return false;
    head = (head + 1) % vec.size();
    --size;
    return true;
  }

  int Front() {
    if (isEmpty())
      return -1;
    return vec[head];
  }

  int Rear() {
    if (isEmpty())
      return -1;
    return tail == 0 ? vec[vec.size() - 1] : vec[tail - 1];
  }

  bool isEmpty() { return size == 0; }

  bool isFull() { return size == vec.size(); }

private:
  vector<int> vec;
  int head, tail;
  int size;
};