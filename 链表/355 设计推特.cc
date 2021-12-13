#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

/// @brief 设计一个简化版的推特(Twitter)，可以让用户实现发送推文，
/// 关注/取消关注其他用户，能够看见关注人（包括自己）的最近 10 条推文

class Twitter {
public:
  struct ListNode {
    int val;
    int time; // time 用来标识全局时间
    ListNode *next;
    ListNode() : val(0), time(0), next(nullptr) {}
    ListNode(int x) : val(x), time(0), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), time(0), next(next) {}
  };

  Twitter() {}

  /// @brief 发送推文
  /// 每条推文的时间是全局时间 +1，确保时间的顺序性
  /// 一个用户最新的推文总是在列表的最前面
  void postTweet(int userId, int tweetId) {
    ListNode *node = new ListNode(tweetId);
    node->time = ++time;
    auto &ele = user_to_twitters[userId];
    node->next = ele;
    ele = node;
  }

  /// @brief 用户自己和关注的人，当中的最新的 10 条推文
  /// 1. 把所有关注人推文列表的第一个节点放入 vector 中（第一个节点总是最近的推文）
  /// 2. 把自己推文列表的第一个节点放入 vector 中
  /// 3. 调用合并 k 个有序列表的算法
  vector<int> getNewsFeed(int userId) {
    vector<int> followed = user_to_follows[userId];
    vector<ListNode *> lists;
    for (const auto &id : followed) {
      if (user_to_twitters.count(id)) {
        lists.push_back(user_to_twitters[id]);
      }
    }
    // 放入自己的第一个节点
    if (user_to_twitters.count(userId))
      lists.push_back(user_to_twitters[userId]);
    vector<int> res = merge(lists);
    return res;
  }

  /// @brief 关注一个人
  void follow(int followerId, int followeeId) {
    vector<int> &followed = user_to_follows[followerId];
    // 如果已经关注过了则不再关注
    if (find(followed.begin(), followed.end(), followeeId) != followed.end())
      return;
    followed.push_back(followeeId);
  }

  /// @brief 取消关注一个人
  void unfollow(int followerId, int followeeId) {
    vector<int> &followed = user_to_follows[followerId];
    auto res = find(followed.begin(), followed.end(), followeeId);
    if (res != followed.end()) {
      followed.erase(res);
    }
  }

  /// @brief 合并 k 个链表算法，使用大顶堆，因为时间越大表示推文越新
  /// 1. 将 lists 中所有的头节点放入堆中
  /// 2. 每次从堆中取出一个节点，将节点的值放入 res 中，如果该节点还有 next 节点，则将 next 节点继续放入堆中
  /// 3. 直到 res 中包含了 10 个元素
  vector<int> merge(vector<ListNode *> &lists) {
    vector<int> res;
    auto cmp = [](ListNode *lhs, ListNode *rhs) {
      return rhs->time > lhs->time;
    };
    priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> que(cmp);
    for (auto head : lists)
      que.push(head);
    while (!que.empty() && res.size() != 10) {
      ListNode *head = que.top();
      que.pop();
      if (head->next)
        que.push(head->next);
      res.push_back(head->val);
    }
    return res;
  }

private:
  unordered_map<int, ListNode *> user_to_twitters; // 用户自己的推文列表
  unordered_map<int, vector<int>> user_to_follows; // 用户的关注列表
  static int time;                                 // 全局时间，越大表示时间越近
};
int Twitter::time = 0;

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */