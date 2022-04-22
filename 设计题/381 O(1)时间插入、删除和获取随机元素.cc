#include <list>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

template <int> class RandomizedCollection;

/// 使用 list 保存同一个元素的所有索引，remove
/// 的时间复杂度会高一点但是逻辑上简单一点
template <> class RandomizedCollection<1> {
public:
  RandomizedCollection() {}

  bool insert(int val) {
    map[val].push_back(vec.size());
    vec.push_back(val);
    return map[val].size() == 1;
  }

  bool remove(int val) {
    if (!map.count(val))
      return false;
    int idx = map[val].back();
    int last_val = vec[vec.size() - 1];
    swap(vec[idx], vec[vec.size() - 1]);
    // 修改 last_val 原来的索引值
    for (auto it = map[last_val].begin(); it != map[last_val].end(); ++it)
      if (*it == vec.size() - 1)
        *it = idx;
    // 删除 val
    vec.pop_back();
    map[val].pop_back();
    if (map[val].size() == 0)
      map.erase(val);
    return true;
  }

  int getRandom() {
    int random_idx = rand() % vec.size();
    return vec[random_idx];
  }

private:
  unordered_map<int, list<int>> map;
  vector<int> vec;
};

/// 使用 unordered_set 保存同一个 val 的所有索引，remove 的时间复杂度低
template <> class RandomizedCollection<2> {
public:
  RandomizedCollection() {}

  bool insert(int val) {
    map[val].insert(vec.size());
    vec.push_back(val);
    return map[val].size() == 1;
  }

  bool remove(int val) {
    if (!map.count(val))
      return false;
    int idx = *map[val].begin();
    swap(vec[idx], vec[vec.size() - 1]);
    map[vec[idx]].erase(vec.size() - 1);
    map[val].erase(idx);
    if (idx < vec.size() - 1)
      map[vec[idx]].insert(idx);
    if (map[val].size() == 0)
      map.erase(val);
    vec.pop_back();
    return true;
  }

  int getRandom() { return vec[rand() % vec.size()]; }

private:
  unordered_map<int, unordered_set<int>> map;
  vector<int> vec;
};