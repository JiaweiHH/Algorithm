#include <vector>
#include <list>
using namespace std;

/// 假设有打乱顺序的一群人站成一个队列，数组 people 表示队列中一些人的属性（不一定按顺序）。每个 people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，前面 正好 有 ki 个身高大于或等于 hi 的人
/// 对 people 进行排序，使得所有人满足 people[i] 的要求

template <int> class Solution;

/// 贪心，时间负载度 O(n^2)，空间复杂度 O(n)
/// 对 people 按照身高从高到低进行排序，相同身高的按照 ki 从小到大排序
/// 
/// 这样一来我们就可以对排序之后的 people 数组进行插入排序，生成 queue，当我们放置第 i 个人时
/// 1. 第 0, ..., i - 1 个人已经在队列中被安排了位置，他们只要站在第 i 个人的前面，就会对第 i 个人产生影响，因为他们都比第 i 个人高（正是利用这一条规则进行插入排序）
/// 2. 而第 i + 1, ..., n - 1 个人还没有被放入队列中，并且他们无论站在哪里，对第 i 个人都没有任何影响，因为他们都比第 i 个人矮
/// 所以最后只需要对排好序的 people 数组按照顺序进行插入排序到 queue 中即可，这里使用 list 表示 queue，可以减少 vector 因为空间不足进行扩容而导致时间复杂度上升的问题
template <> class Solution<1> {
public:
  vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
    auto cmp = [](const vector<int> &lhs, const vector<int> &rhs) {
      return lhs[0] == rhs[0] ? lhs[1] < rhs[1] : lhs[0] > rhs[0];
    };
    sort(people.begin(), people.end(), cmp);
    list<vector<int>> queue;
    for (auto &p : people) {
      auto it = queue.begin();
      int position = p[1];
      while (position--)
        it++;
      queue.insert(it, p);
    }
    return vector<vector<int>>(queue.begin(), queue.end());
  }
};

/// 官方给出的另一种方法，首先对 people 数组按照身高从低到高排序，对于相同身高的按照 ki 大的放在前面
/// 对于 ki 大的放在前面的原因是，相同身高 ki 大的那个人最后肯定是排在 ki 小的那个人后面的，
/// 因此可以看成在原来的身高基础上减少了一个很小很小的身高，类似于微积分的那个无穷小
/// 
/// 当我们放置第 i 个人时
/// 1. 第 0, ..., i − 1 个人已经在队列中被安排了位置，并且他们无论站在哪里，对第 i 个人都没有任何影响，因为他们都比第 i 个人矮
/// 2. 而第 i + 1, ..., n − 1 个人还没有被放入队列中，但他们只要站在第 i 个人的前面，就会对第 i 个人产生影响，因为他们都比第 i 个人高（正是利用这一条规则进行放置）
/// 因此从前往后遍历 people 数组，对于第 i 个人只需要将其放在最终的队列 ans 中的 ki 位置即可，给前面空出 ki 个人的位置，放置比他高的人
template <> class Solution<2> {
public:
  vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
    sort(people.begin(), people.end(),
         [](const vector<int> &u, const vector<int> &v) {
           return u[0] < v[0] || (u[0] == v[0] && u[1] > v[1]);
         });
    int n = people.size();
    vector<vector<int>> ans(n);
    for (const vector<int> &person : people) {
      int spaces = person[1] + 1;
      for (int i = 0; i < n; ++i) {
        if (ans[i].empty()) { // 不为空的话说明这个位置已经被占了，需要继续往下搜索
          --spaces;
          if (!spaces) {
            ans[i] = person;
            break;
          }
        }
      }
    }
    return ans;
  }
};
