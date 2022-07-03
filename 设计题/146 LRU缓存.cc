#include <list>
#include <unordered_map>
using namespace std;

template <int> class LRUCache;

/// 自己实现链表
struct Node {
  Node(int key, int value)
      : key_(key), value_(value), prev(nullptr), next(nullptr) {}
  Node() : prev(nullptr), next(nullptr) {}
  int key_;
  int value_;
  Node *prev, *next;
};

template <> class LRUCache<1> {
public:
  LRUCache(int capacity)
      : capacity_(capacity), size_(0), dummy(new Node), tail(dummy) {}

  void erase_last_node() {
    hash_.erase(tail->key_);
    if (size_ == 1) {
      auto node = dummy->next;
      // cout << "erase key " << node->key_ << ", " << node->value_ << "\n";
      dummy->next = nullptr;
      delete (node);
      tail = dummy;
      --size_;
      return;
    }
    tail = tail->prev;
    delete (tail->next);
    tail->next = nullptr;
    --size_;
  }

  void move_to_first(int key) {
    if (size_ == 1)
      return;
    Node *node = hash_[key];
    node->prev->next = node->next;
    if (node->next)
      node->next->prev = node->prev;
    if (node == tail)
      tail = node->prev;
    node->next = dummy->next;
    dummy->next->prev = node;
    dummy->next = node;
    node->prev = dummy;
  }

  int get(int key) {
    // cout << "get " << key << "\n";
    if (!hash_.count(key))
      return -1;
    move_to_first(key);
    return hash_[key]->value_;
  }

  void put(int key, int value) {
    // cout << "put " << key << ", " << value << "\n";
    if (hash_.count(key)) {
      hash_[key]->value_ = value;
      move_to_first(key);
      return;
    }
    if (size_ == capacity_) {
      erase_last_node();
    }
    Node *node = new Node(key, value);
    ++size_;
    hash_[key] = node;
    tail->next = node;
    node->prev = tail;
    tail = node;
    move_to_first(key);
  }

private:
  Node *dummy, *tail;
  unordered_map<int, Node *> hash_;
  int capacity_, size_;
};

/// 使用 STL list
template <> class LRUCache<2> {
public:
  LRUCache(int capacity) : _capacity(capacity) {}

  void move_to_back(int key) {
    auto kv = *_map[key];
    _list.erase(_map[key]);
    _map[key] = _list.insert(_list.end(), kv);
  }

  int get(int key) {
    if (!_map.count(key))
      return -1;
    move_to_back(key);
    return _map[key]->second;
  }

  void put(int key, int value) {
    if (_map.count(key)) { // key 存在
      _map[key]->second = value;
      move_to_back(key);
      return;
    }
    // key 不存在
    if (_list.size() == _capacity) { // 判断容量是否超出上限了
      int key = _list.front().first;
      _list.pop_front();
      _map.erase(key);
    }
    auto it = _list.insert(_list.end(), {key, value});
    _map[key] = it;
  }

private:
  using node = list<pair<int, int>>::iterator;
  list<pair<int, int>> _list;
  unordered_map<int, node> _map;
  int _capacity;
};
