#include <random>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

template <int> class Solution;

/// 二分
template <> class Solution<1> {
public:
  Solution(int n, vector<int> &blacklist)
      : blacklist_(blacklist), gen_(random_device{}()),
        dis_(1, n - blacklist.size()) {
    sort(blacklist_.begin(), blacklist_.end());
  }

  int pick() {
    int num = dis_(gen_);
    int l = 0, r = blacklist_.size() - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (blacklist_[mid] - mid >= num)
        r = mid - 1;
      else
        l = mid + 1;
    }
    return num + l - 1;
  }

private:
  mt19937 gen_;
  uniform_int_distribution<int> dis_;
  vector<int> blacklist_;
};

/// 哈希
template <> class Solution<2> {
public:
  Solution(int n, vector<int> &blacklist)
      : gen_(random_device{}()), dis_(0, n - blacklist.size() - 1) {
    int white_size = n - blacklist.size();
    unordered_set<int> st;
    for (int i = white_size; i < n; ++i)
      st.insert(i);
    for (auto num : blacklist)
      st.erase(num);
    auto it = st.begin();
    for (auto num : blacklist) {
      if (num < white_size)
        map[num] = *it++;
    }
  }

  int pick() {
    int idx = dis_(gen_);
    return !map.count(idx) ? idx : map[idx];
  }

private:
  mt19937 gen_;
  uniform_int_distribution<int> dis_;
  unordered_map<int, int> map;
};