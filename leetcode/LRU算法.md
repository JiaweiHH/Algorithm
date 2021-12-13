## LRU

[146. LRU 缓存机制](https://leetcode-cn.com/problems/lru-cache/)

- `class Node` 负责存储一对 `key-value`
-  `class DoubleList` 连接所有的 `Node`
- `class LRUCache::map` 完成 `key` 到 `Node` 的 hash 映射

最终形成 hash list 实现 O(1) 时间复杂度的查找和添加新元素

```c++
// Node 存储 key-value
struct Node {
  shared_ptr<Node> prev, next;
  int key, val;
  Node() : prev(nullptr), next(nullptr), key(0), val(0) {}
  Node(int k, int v) : key(k), val(v) {}
};

// 组织 Node 的双向链表
// head 表示最久未访问的，tail 表示最近访问的
struct DoubleList {
  shared_ptr<Node> tail, head;
  DoubleList() {
    tail.reset(new Node());
    head.reset(new Node());
    head->next = tail;
    tail->prev = head;
  }
  // 添加 key-value 到尾部
  void addTail(shared_ptr<Node> node) {
    tail->prev->next = node;
    node->prev = tail->prev;
    tail->prev = node;
    node->next = tail;
  }
  // 移除头部 key-value
  void removeFirst() {
    auto node = head->next;
    head->next = node->next;
    node->next->prev = head;
    node->prev = node->next = nullptr;
  }
  // 移除特定的 key-value
  void removeNode(shared_ptr<Node> node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    node->prev = node->next = nullptr;
  }
};

// 对外提供 LRU 接口
class LRUCache {
public:
  LRUCache(int capacity) : _capacity(capacity) {
    list.reset(new DoubleList());
  }

  // 提升 key 对应的 key-value 为最近使用过的
  void promoteToRecently(int key) {
    auto node = map[key];
    list->removeNode(node);
    list->addTail(node);
  }
  // 删除最久未使用的 key-valye
  void removeUnused() {
    auto node = list->head->next;
    list->removeFirst();
    map.erase(node->key);
  }
  // 添加一个新的 key-value
  void putRecently(int key, int value) {
    shared_ptr<Node> node = make_shared<Node>(key, value);
    map[key] = node;
    list->addTail(node);
  }

  // 获取 key 对应的 value，该操作会对 key-value 提升为最近使用过的
  int get(int key) {
    if(!map.count(key))
      return -1;
    promoteToRecently(key);
    return map[key]->val;
  }

  void put(int key, int value) {
    // 如果 key 已经存在，那么修改对应的 value，并提升为最近使用过的
    if(map.count(key)) {
      auto node = map[key];
      node->val = value;
      promoteToRecently(key);
    } else {
      // 容量满了，需要先移除最久未使用的 key-value
      if(map.size() == _capacity) {
        removeUnused();
      }
      putRecently(key, value);
    }
  }
private:
  // 使用 hash list 完成 O(1) 时间的查找和删除
  shared_ptr<DoubleList> list;
  unordered_map<int, shared_ptr<Node>> map;
  int _capacity;
};
```

