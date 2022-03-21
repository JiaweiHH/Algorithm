#include <unordered_map>
using namespace std;

class LRUCache {
public:
  struct ListNode {
    int key, val;
    ListNode *prev, *next;
    ListNode(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
  };

  void promoteToRecently(int key) {
    ListNode *node = _map[key];
    if (node == _tail)
      return;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    _tail->next = node;
    node->prev = _tail;
    node->next = nullptr;
    _tail = node;
  }

  void removeUnused() {
    ListNode *node = _list->next;
    node->prev->next = node->next;
    if (node != _tail)
      node->next->prev = node->prev;
    else
      _tail = _list;
    _map.erase(node->key);
    delete (node);
    --_size;
  }

  void insertToList(int key, int val) {
    ListNode *node = new ListNode(key, val);
    _tail->next = node;
    node->prev = _tail;
    node->next = nullptr;
    _tail = node;
    _map[key] = node;
    ++_size;
  }

  LRUCache(int capacity) : _capacity(capacity), _size(0) {
    ListNode *dummy = new ListNode(-1, -1);
    _list = dummy;
    _tail = _list;
    _map.clear();
  }

  int get(int key) {
    if (!_map.count(key))
      return -1;
    int val = _map[key]->val;
    promoteToRecently(key);
    return val;
  }

  void put(int key, int value) {
    if (!_map.count(key)) {
      if (_size == _capacity)
        removeUnused();
      insertToList(key, value);
    } else {
      _map[key]->val = value;
      promoteToRecently(key);
    }
  }

private:
  ListNode *_list, *_tail;
  unordered_map<int, ListNode *> _map;
  int _capacity;
  int _size;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */