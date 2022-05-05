#include <list>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Twitter {
public:
  Twitter() : id(0) {}

  void postTweet(int userId, int tweetId) {
    // cout << "post\n";
    contents[userId].push_front({++id, tweetId});
  }

  vector<int> getNewsFeed(int userId) {
    // cout << "get\n";
    auto cmp = [](pair<It, It> &lhs, pair<It, It> &rhs) {
      return lhs.first->first < rhs.first->first;
    };
    priority_queue<pair<It, It>, vector<pair<It, It>>, decltype(cmp)> heap(cmp);
    auto followeds = maps[userId];
    for (auto &user : followeds)
      heap.push({contents[user].begin(), contents[user].end()});
    heap.push({contents[userId].begin(), contents[userId].end()});
    vector<int> res;
    while (!heap.empty() && res.size() < 10) {
      auto top_element = heap.top();
      heap.pop();
      if (top_element.first != top_element.second) {
        res.push_back(top_element.first->second);
        heap.push({++top_element.first, top_element.second});
      }
    }
    return res;
  }

  void follow(int followerId, int followeeId) {
    // cout << "follow\n";
    if (!maps[followerId].count(followeeId))
      maps[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    // cout << "unfollow\n";
    auto &followers = maps[followerId];
    followers.erase(followeeId);
  }

private:
  using It = list<pair<int, int>>::iterator;
  int id;
  unordered_map<int, unordered_set<int>> maps;
  unordered_map<int, list<pair<int, int>>> contents;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */