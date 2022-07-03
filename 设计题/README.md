## 设计题

[146.LRU缓存]([146. LRU 缓存 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/lru-cache/))：请你设计并实现一个满足 LRU 缓存约束的数据结构，实现 LRUCache 类。👉 [<u>LRU缓存</u>](146%20LRU缓存.cc)

1. 自定义链表。使用链表来管理 LRU Cache，越靠近链表尾部的元素越新。为了实现 O(1) 时间复杂度的 get 和 put，使用哈希表建立 key 和 ListNode 的映射，这样可以方便快速找到节点。put、get 一个已经存在的元素需要将该节点从链表中摘除并插入到链表尾部
   - **需要考虑** `erase_first_node()` 的时候如果后续没有元素了的特殊情况，以及要判断 `_tail` 是否需要修改
2. 使用 STL list 容器实现，这样比较简单

两种方法都需要掌握，避免面试官需要手动实现链表

- 线程安全实现：线程安全只需要在操作链表的时候加锁就可以了
- 带时间戳自动过期：两种方法
  1. lazy 删除。实际用到某个 key、或者 Cache 容量满了的时候再进行删除
  2. 后台线程定时去删除

[155.最小栈]([155. 最小栈 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/min-stack/))：设计一个支持 `push`，`pop`，`top` 操作，并能在常数时间内检索到最小元素的栈

进阶：使用一个栈实现

1. 我们可以使用两个栈，第一个栈存放元素，第二个栈存放当前元素为栈顶的时候，栈中的最小元素。这样当我们在获取栈中最小元素的时候，只需要从第二个栈中获取即可
2. 如果要求只使用一个栈，那么在 `push` 一个元素的时候，同时也将此时栈中的最小值压入栈中

[208.实现Trie(前缀树)]([208. 实现 Trie (前缀树) - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/implement-trie-prefix-tree/))：实现一棵前缀树。👉 [<u>实现Trie前缀树</u>](208%20实现Trie(前缀树).cc)

每一个节点有一个 `unordered_map<char, Trie> children` 用来保存以该层为前缀的时候，下一个字符所在的指针。另外还有一个 `last` 变量来标记以该层字符为结尾的字符串是不是存在

- 这样在查找一个字符串 `word` 是不是存在字典树中的时候，只需要沿着 `children` 不断的向下寻找即可，如果遍历完了 `word` 发现此时的节点的 `last` 变量为 `true`，则说明 `word` 存在于字典树中
- 插入一个字符串 `word` 的时候也只需要沿着字典树的 `children` 不断的向下查找，如果发现某一个字符不存在则新建一个节点表示该字符
- 查找一个前缀的时候和查找一个 `word` 是否存在于字典树中类似，只不过不需要判断最后的节点的 `last` 变量是否为 `true`

[225. 用队列实现栈 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/implement-stack-using-queues/)：请使用两个队列实现栈。👉 [用队列实现栈](225%20用队列实现栈.cc)

**关键是实现队列头部就是栈顶**

1. 两个队列实现，push 的时间复杂度是 O(n)，其余操作的时间复杂度均为 O(1)
   - push：将新元素放入其中一个空的队列中，然后将另一个队列中的所有元素都放入这个队列。这样队列头部就是栈顶了
   - pop：将非空队列的第一个元素弹出，并返回该值
   - peek：直接返回非空队列第一个元素的值
   - empty：只有两个队列同时为空的时候“栈”才是空的
2. 使用一个队列实现，push 的时间复杂度是 O(n)，其余操作的时间复杂度均为 O(1)。我们需要一个额外的变量 `num` 记录当前“栈”中的元素个数
   - push：将新元素放入队列中，然后从队列首部依次弹出 `num` 个元素，重新放入队列中。这样队列头部就是栈顶了
   - pop：从队列首部弹出元素，并返回该值
   - peek：返回队列首部元素的值
   - empty：que.empty()

[232. 用栈实现队列 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/implement-queue-using-stacks/)：请你仅使用两个栈实现队列，要求每个操作的均摊时间复杂度是 O(1)。👉 [用栈实现队列](232%20用栈实现队列.cc)

**关键是实现栈顶就是队列头部**

- push：不断的将新的元素添加到 stack1
- pop：如果 stack2 不为空，那么直接从 stack2 栈顶弹出元素，然后返回元素的值。如果 stack2 为空，那么先将 stack1 中的元素全都放到 stack2 中，这个时候 stack2 的栈顶就是队列首部，然后从 stack2 栈顶弹出元素并返回元素值
- peek：和 pop 相同，只是不需要从 stack2 栈顶弹出元素了
- empty：stack1.empty() && stack2.empty()

[295. 数据流的中位数 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/find-median-from-data-stream/)：设计一个数据结构保存用户插入的数字，并且能够快速的返回这些数字的中位数。👉 [<u>数据流的中位数</u>](295%20数据流的中位数.cc)

不能直接使用 `vector` 保存元素，然后每次在需要获取中位数的时候进行一次快速排序，这样会超时

使用两个堆管理用户提供的数据，其中一个堆保存较小的一半数据、采用大顶堆，另一个堆保存较大的一半数据、采用小顶堆。这样在需要返回中位数的时候，如果元素的数量是奇数那么直接返回小顶堆的堆顶元素，否则返回小顶堆的堆顶元素和大顶堆的堆顶元素的平均值

插入一个新元素 `num` 的时候有以下三种情况：

1. `num < queMin.top()`，这个时候使用一个变量 `val` 记录当前 `queMin` 的堆顶元素，然后弹出该元素并把 `num` 插入 `queMin`
2. `num > queMax.top()`，这个时候使用一个变量 `val` 记录当前 `queMax` 的堆顶元素，然后弹出该元素并把 `num` 插入 `queMax`
3. `num >= queMin.top() && num <= queMax.top()`，记录 `val = num`，此时不做任何处理

然后判断 `queMin.size()` 和 `queMax.size()`，如果 `queMin.size() > queMax.size()`，那么将 `val` 插入 `queMax`，否则的话将 `val` 插入 `queMin`

`addNum` 时间复杂度：`O(logn)`，`findMedian` 时间复杂度：`O(1)`，空间复杂度：`O(n)`

[297.二叉树的序列化与反序列化]([297. 二叉树的序列化与反序列化 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/))：实现二叉树的序列化与反序列化函数。👉 [<u>二叉树的序列化与反序列化</u>](二叉树/297%20二叉树的序列化与反序列化.cc)

- 序列化：按照层序的方式保存，每个节点用 `','` 分隔，如果是 `nullptr` 则使用 `'.'` 表示
- 反序列化：利用队列，每次从队列中弹出一个元素，然后构建它的左节点和右节点

[352. 将数据流变为多个不相交区间 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/data-stream-as-disjoint-intervals/)：给你一个由非负整数组成的数据流输入，请你将目前为止看到的数字总结为不相交的区间列表。👉 [<u>将数据流变为多个不相交区间</u>](设计/352%20将数据流变为多个不相交区间.cc)

**方法一：使用堆来保存区间**

- 使用堆来保存插入的数字，例如对于一个数字 `num`，保存为 `{num, num}`
- 当获取不相交区间列表的时候对堆中的元素进行合并，合并的过程就是区间合并。每次从堆中弹出一个元素，并记录当前已经合并得到的区间的范围 `cur`，对于后续的每个堆中元素，如果 `val.first > cur.second` 说明该元素不能被合并进 `cur`，此时需要创建一个新的合并区间并把旧的合并区间保存到新的堆中以及结果集中
- 使用新的堆保存后续插入的元素

`addNum` 时间复杂度：`O(logn)`，即堆中插入元素的时间复杂度

`getIntervals` 时间复杂度： `O(nlogn)` ，需要遍历整个堆中的元素，每次弹出一个元素都需要调整堆

空间复杂度 `O(n)`

**方法二：使用有序映射来保存区间**

首先对于一个准备插入的 `val` 来说，总共有 5 种可能会执行的操作

1. 已经存在一个区间已经完全包含了 `val`，此时不需要执行任何操作
2. 存在一个区间 `[l, r]`，满足 `r + 1 = val`，此时该区间变为 `[l, r + 1]`
3. 存在一个区间 `[l, r]`，满足 `l - 1 = val`，此时该区间变为 `[l - 1, r]`
4. 存在两个区间 `[l0, r0], [l1, r1]`，满足 `val = r0 + 1, val = l1 - 1`，此时合并得到区间 `[l0, r1]`
5. 以上情况之外，插入一个新的区间 `[val, val]`

我们可以用有序映射 `map<l, r>` 来保存 `l` 到 `r` 的映射。首先在 map 中找到第一个大于 `val` 的区间 `[l1, r1]`，那么该区间前面的区间就是第一个小于等于 `val` 的区间 `[l0, r0]`

1. 然后判断 `[l0, r0]` 是否包含了 `val`，即是否满足情况 1
2. 进一步判断 `[l0, r0], [l1, r1]` 是否满足情况 4
3. 进一步判断 `[l0, r0]` 是否满足情况 2
4. 进一步判断 `[l1, r1]` 是否满足情况 3
5. 否则就是情况 5

`addNum` 时间复杂度：`O(logn)`，红黑树插入一个元素的时间复杂度

`getIntervals` 时间复杂度：`O(n)`，遍历一遍有序映射返回所有的 `[l, r]`

空间复杂度 `O(n)`

[355. 设计推特 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/design-twitter/)：设计一个简化版的推特，可以让用户实现发送推文，关注/取消关注其它用户，能够看见关注人的最近 10 条推文。👉 [解答](355%20设计推特.cc)

对于用户关注列表，为了实现快速的添加和删除一个关注用户，使用 `unordered_map<int, unordered_set<int>>` 保存每个用户的关注列表，这样可以保证：

- follow 时间复杂度 `O(1)`
- unfollow 时间复杂度 `O(1)`

每个用户发送的推文使用 `unordered_map<int, list<pair<int, int>>>` 保存，为了给每条推特按照时间顺序排序，使用一个单调递增的全局 sequence 表示，sequence 越大表示这条推文距离现在越近。当用户查看最近的 10 条推文的时候，使用 `priority_queue` 来对多个有序 `list` 进行排序，选择前 10 条数据

`getNewsFeed` 时间复杂度：`O(nlogn)`，体现在初始建堆的时候

[381. O(1) 时间插入、删除和获取随机元素 - 允许重复 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/insert-delete-getrandom-o1-duplicates-allowed/)：实现 `RandomizedCollection` 类，能够插入和删除元素，并且能够随机的返回一个元素，每个元素被随机到的概率和元素出现的次数线性相关。👉 [O(1)时间插入、删除和获取随机元素](381%20O(1)时间插入、删除和获取随机元素.cc)

为了实现随机概率和元素出现次数线性相关，使用 vector 来保存元素，这样随机返回元素的时候只需要 vec[rand() % vec.size()] 就可以了

但是使用 vector 会带来删除元素的时间复杂度比较高，因此可以使用哈希表保存每个元素的所有索引位置，删除一个元素 val 的时候我们可以找到**该元素的其中一个索引位置**并且**和 vector 的最后一个位置的元素交换**，**然后 pop_back 最后一个元素就可以了**。最后更新 val 和 last_val 的索引

[460. LFU 缓存 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/lfu-cache/)：实现 LFUCache（最不经常使用缓存算法）。元素每被访问到一次就增加一次使用频率， 当缓存达到容量上限的时候移除频率最小的元素中最久未使用的 kv 节点。👉 [LFU缓存](460%20LFU缓存.cc)

在实现 LRU 缓存的时候使用了一个双向链表和一个哈希表，其中哈希表用来快速索引双向链表中的节点，达到 O(1) 时间复杂度的 put 和 get

LFU 需要额外记录节点的访问频率，因此需要额外再使用一个哈希表来记录 「频率」和「节点集合」的映射，我们使用 `unordered_map<int, list<list<Node>::iterator>>` 用来保存某个频率所有节点的迭代器集合

**Get 操作**

如果 key 存在的话，首先需要将节点从原来频率的 list 中移除，然后增加访问频率并放入新的频率的 list 中，最后返回 value

**Put 操作**

- 如果 key 存在的话，也是先从原来频率的 list 移除，然后增加访问频率放入新的 list 中，并且修改  value
- 如果 key 不存在的话，则需要判断是否达到了缓存容量上限
  - 达到了容量上限则需要找到 min_freq 对应的 list 上的第一个节点，获取该迭代器。然后分别从 key_table、freq_table[min_freq]、list_ 中删除这个节点
  - 最后创建一个新的节点，分别加入 key_table、freq_table[1] 以及 list_ 中

当我们从 key_table 中移除元素的时候需要判断当前 freq 对应的 list 是否为空了，如果为空并且 min_freq == freq，则需要将 min_freq 加一

[622. 设计循环队列 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/design-circular-queue/)：设计一个循环队列。👉 [设计循环队列](622%20设计循环队列.cc)

可以分别采用链表和数组的形式实现，时间复杂度均为 O(1)

1. 链表形式。使用 head 指针记录链表的第一个元素，tail 指针记录链表的最后一个元素，当链表为空的时候 head = tail = nullptr，当链表只有一个节点的时候 head = tail = node，并且 next 指针和 tail 指针指向自身。链表中的元素个数和链表的容量需要分别使用 size 和 capacity 来记录
   - enQueue，判断队列是不是满了，没有满的话还需要判断当前 head 和 tail 是否是 nullptr，如果是的话直接使用新创建的节点初始化 head 和 tail，否则的话建立双向链表
   - deQueue，判断队列是不是空的，不为空的话还需要判断 head 是否等于 tail，想等的话 head = tail = nullptr 然后删除节点，否则的话正常的修改链表
   - Front，队列不为空的时候返回 head->val
   - Rear，队列不为空的时候返回 tail->val
   - isEmpty，head == nullptr 或者 size == 0 也可以
   - isFull，size == capacity
2. 数组形式。初始的时候根据循环队列的容量将数组的空间设置为 k（k 是循环队列的容量），同样使用 head 记录队列第一个元素在数组中的下标，使用 tail 记录队列最后一个元素的下一个位置在数组中的下标。初始的时候 head = tail = 0，使用 size 记录当前循环队列中元素的个数
   - enQueue，首先判断当前队列是不是满了，没有满的话 vec[tail] = value，tail = (tail + 1) % vec.size()，并且 ++size
   - deQueue，首先判断当前队列是不是空的，不是空的话 head = (head + 1) % vec.size()，并且 --size
   - Front，队列不为空的时候返回 vec[head]
   - Rear，队列不为空的时候返回 tail == 0 ? vec[vec.size() - 1] : vec[tail - 1]
   - isEmpty，size == 0
   - isFull，size == vec.size()

**线程安全**：使用 mutex 加锁就可以了

[692. 前K个高频单词 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/top-k-frequent-words/)：给定一个单词列表 `words` 和一个整数 `k`，返回前 `k` 个出现次数最多的单词，如果两个单词有相同的出现频率则按字典序排序。👉 [解答](优先队列/692%20前K个高频单词.cc)

首先保存所有单词的出现次数，然后构建一个大小为 `k` 的小根堆，用来保存频率前 `k` 的所有单词，遍历 `words` 数组，然后从堆中弹出元素并保存到 `res` 中。由于是小根堆，所以最后的输出结果还需要 `reverse`

时间复杂度：$O(nlogk)$，空间复杂度：$O(n)$

[703. 数据流中的第 K 大元素 - 力扣（LeetCode）](https://leetcode.cn/problems/kth-largest-element-in-a-stream/) -> [code](703%20数据流中的第K大元素.cc)

[716. 最大栈 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/max-stack/)：设计一个最大栈的数据结构，除了常用的栈操作之外还需要支持 peekMax 获取栈中最大元素，popMax 移除栈中最靠近栈顶的最大元素并返回该值。👉 [最大栈](716%20最大栈.cc)

1. 使用 vector 模拟栈。peekMax 和 popMax 的时间复杂度都是 O(n)，其余操作时间复杂度 O(1)
   - peekMax 和 popMax，遍历 vector 找到最大值的迭代器，并删除该最大值
2. 使用双栈模拟最大栈。popMax 的时间复杂度是 O(n)，其余操作时间复杂度 O(1)。第一个栈是正常的栈，第二个栈存储第一个栈对应元素的位置到栈底的最大值
   - popMax，不断的弹出两个栈的元素存储到一个临时的栈上，当两个栈的元素相等的时候，说明此时第一个栈的栈顶就是最大值，弹出该元素，然后将临时栈上的元素全都放回去
3. 使用链表 + 红黑树模拟最大栈，红黑树中保存每个 value 对应的在 list 中的迭代器。除了 top 方法，其余方法的时间复杂度都是 O(logn)
   - push，需要在 list 的最后插入元素，并且还需要在 map[x] 的最后插入一个元素，找到 map[x] 的时间复杂度是 O(logn)
   - pop，从 list 的最后弹出元素，并且还需要在 map[x] 的最后弹出元素，当 map[x].size() = 0 的时候还需要从 map 中移除 x，找到 map[x] 的时间复杂度是 O(logn)
   - peekMax，返回 prev(map.end(), 1)->first，时间复杂度 O(logn)
   - popMax，找到 max_value 之后，从 map[max_value] 中找到最后的那个 list 迭代器，然后从 list 中移除这个元素，时间复杂度 O(logn)