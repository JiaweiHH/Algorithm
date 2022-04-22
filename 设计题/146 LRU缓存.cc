#include <list>
#include <unordered_map>
using namespace std;

template <int> class LRUCache;

/// 自己实现链表
template <> class LRUCache<1> {
public:
  LRUCache(int capacity) : _capacity(capacity), _size(0) {
    _dummy = new ListNode;
    _tail = _dummy;
  }

  void erase_first_node() {
    ListNode *del = _dummy->next;
    _dummy->next = del->next;
    if (del->next)
      del->next->prev = _dummy;
    _map.erase(del->_key);
    if (_tail == del)
      _tail = _dummy;
    delete (del);
    --_size;
  }

  void insert_kv(int k, int v) {
    ListNode *node = new ListNode(k, v);
    _tail->next = node;
    node->prev = _tail;
    _tail = node;
    _map[k] = _tail;
    ++_size;
  }

  void move_to_back(int key) {
    ListNode *node = _map[key];
    if (node->next == nullptr)
      return;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    node->prev = _tail;
    node->next = nullptr;
    _tail->next = node;
    _tail = node;
  }

  int get(int key) {
    // cout << "get " << key << "\n";
    if (!_map.count(key))
      return -1;
    move_to_back(key);
    return _map[key]->_val;
  }

  void put(int key, int value) {
    // cout << "put " << "{" << key << ", " << value << "}\n";
    if (_map.count(key)) {
      _map[key]->_val = value;
      move_to_back(key);
      return;
    }
    if (_size == _capacity)
      erase_first_node();
    insert_kv(key, value);
  }

private:
  struct ListNode {
    ListNode() : _key(-1), _val(-1), prev(nullptr), next(nullptr) {}
    ListNode(int k, int v) : _key(k), _val(v), prev(nullptr), next(nullptr) {}
    int _key, _val;
    ListNode *prev, *next;
  };
  unordered_map<int, ListNode *> _map;
  ListNode *_dummy, *_tail;
  int _size;
  int _capacity;
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


