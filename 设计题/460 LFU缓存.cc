#include <list>
#include <unordered_map>
using namespace std;

class LFUCache {
public:
  LFUCache(int capacity) : capacity(capacity), min_freq(0) {}

  void remove_from_freqtable(int key) {
    auto iter = key_table[key];
    int freq = iter->freq;
    for (auto it = freq_table[freq].begin(); it != freq_table[freq].end();
         ++it) {
      if (*it == iter) {
        freq_table[freq].erase(it);
        if (freq_table[freq].size() == 0) {
          freq_table.erase(freq);
          min_freq = min_freq == freq ? ++min_freq : min_freq;
        }
        break;
      }
    }
  }

  void move_to_newfreq(int key) {
    auto iter = key_table[key];
    freq_table[iter->freq].push_back(iter);
  }

  int get(int key) {
    // cout << "get " << key << "\n";
    if (!key_table.count(key))
      return -1;
    remove_from_freqtable(key);
    ++key_table[key]->freq;
    move_to_newfreq(key);
    return key_table[key]->v;
  }

  void put(int key, int value) {
    // cout << "put {" << key << ", " << value << "}\n";
    if (capacity == 0)
      return;
    if (key_table.count(key)) {
      remove_from_freqtable(key);
      ++key_table[key]->freq;
      key_table[key]->v = value;
      move_to_newfreq(key);
      return;
    }
    if (key_table.size() == capacity) {
      auto iter = freq_table[min_freq].front();
      freq_table[min_freq].pop_front();
      if (freq_table[min_freq].size() == 0)
        freq_table.erase(min_freq);
      key_table.erase(iter->k);
      list_.erase(iter);
    }
    Node node(key, value);
    auto iter = list_.insert(list_.end(), node);
    key_table[key] = iter;
    freq_table[1].push_back(iter);
    min_freq = 1;
  }

private:
  struct Node {
    Node() : k(0), v(0), freq(1) {}
    Node(int key, int value) : k(key), v(value), freq(1) {}
    int k, v, freq;
  };
  list<Node> list_;
  unordered_map<int, list<Node>::iterator> key_table;
  unordered_map<int, list<list<Node>::iterator>> freq_table;
  int capacity, min_freq;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */