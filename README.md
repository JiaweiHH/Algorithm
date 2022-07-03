[TOC]

## 模拟

[415.字符串相加]([415. 字符串相加 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/add-strings/))：给你两个字符串形式表示的非负整数 `num1` 和 `num2`，计算它们的和并返回字符串的形式。👉 [<u>字符串相加</u>](模拟/415%20字符串相加.cc)

简单的模拟过程

[38. 外观数列 - 力扣（LeetCode）](https://leetcode.cn/problems/count-and-say/)：给定一个正整数 `n`，输出外观数列的第 `n` 项，「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。👉 [解答](模拟/38%20外观数列.cc)

递归调用，如果 `n == 1` 返回 `"1"`，否则获取 `countAndSay(n - 1)`，然后遍历该字符串生成 `countAndSay(n)`

时间复杂度：$O(mn)$，$m$ 是生成字符串的最大长度；空间复杂度：$O(m)$

[7. 整数反转 - 力扣（LeetCode）](https://leetcode.cn/problems/reverse-integer/)：给你一个 32 位有符号整数 `x`，返回将 `x` 中的数字部分反转后的结果，如果反转后的数字超出 int 范围则返回 0。👉 [解答](模拟/7%20整数反转.cc)

1. 如果允许使用 long long，则使用 long long res 存储中间反转结果，最后判断 res 是否在 int 范围内
2. 如果不允许使用 long long，则在中间计算的每一步都判断 `x != 0 && (res > INT_MAX / 10 || x < INT_MIN / 10)`，满足条件的话返回 0，否则在最后返回 `res`

时间复杂度：$O(n)$，空间复杂度 $O(1)$，其中 $n$ 是 `x` 的十进制位数

[43.字符串相乘]([43. 字符串相乘 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/multiply-strings/))：给出两个字符串形式表示的整数 `num1`，`num2`，返回 `num1 * num2` 的字符串形式表示。👉 [<u>字符串相乘</u>](模拟/43%20字符串相乘.cc)

有下面两种方法可以处理

- 直接模拟乘法的执行过程。时间复杂度 `O(mn + n^2)`，字符串相乘的操作需要 `mn` 次，字符串相加的操作需要 `n` 次，每次的时间复杂度是 `O(m + n)`；空间复杂度 `O(m + n)`，即存储的中间字符串的长度，该长度最长为 `m + n`
- 利用 `vector` 来模拟，`vector[i + j + 1] += num1[i] * num2[j]; vec[i + j] += vec[i + j + 1] / 10; vec[i + j + 1] %= 10;`。即 `num1[i] * num2[j]` 保存在 `i + j + 1` 的位置上，对于超出 10 的部分进位保存到 `i + j` 的位置上。时间复杂度 `O(mn)`，空间复杂度 `O(m + n)`

## 链表

[2.两数相加](https://leetcode-cn.com/problems/add-two-numbers/)：链表 `l1` 和 `l2` 以逆序的形式存储两个整数，例如 `2->4->3` 表示整数 342。返回 `l1 + l2` 的结果，结果同样用链表逆序方式表示。👉 [<u>两数相加</u>](./hot100/2%20两数相加.cc)

直接模拟即可

[19.删除链表的倒数第 n 个节点](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/)：给你一个链表，删除链表的倒数第 `n` 个节点，并返回链表的头节点。👉 [<u>删除链表的倒数第 n 个节点</u>](链表/19%20删除链表的倒数第n个节点.cc)

倒数第 `n` 个节点和最后一个节点之间的距离为 `n`，因此如果我们使用两个指针，让第一个指针指向 `dummy` 节点，第二个指针位于它后面的 `n` 个位置。然后两个指针开始一起移动，这样当第二个指针移动到最后一个节点的时候，第一个指针的后继节点就是待删除的节点

[21. 合并两个有序链表 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/merge-two-sorted-lists/)：合并两个有序链表。👉 [<u>合并两个有序链表</u>](链表/21%20合并两个有序链表.cc)

需要掌握：迭代和递归两种方法

如果出现重复元素怎么去重：`prev` 每次记录上一个元素的值，如果 `list1` 和 `list2` 当前值等于 `prev` 就直接让它们向后移动即可，如果和 `prev` 不想等则考虑加入 `prev`

[23.合并 K 个升序链表](https://leetcode-cn.com/problems/merge-k-sorted-lists/)：给你一个链表数组，每个链表都按照升序排列，请你将所有的链表合并成一个升序链表，返回合并后的链表。👉 [<u>合并 K 个升序链表</u>](链表/23%20合并%20K%20个升序链表.cc)

1. 迭代归并排序。`left` 和 `right` 左右子链表两两合并
2. 堆排序。要求掌握手写堆排序。先将所有链表的头节点加入到堆中，按照节点值从小到大排序；然后每次从堆中取出一个元素，如果该元素还有 `next` 节点，就将 `next` 节点加入到堆中

[82. 删除排序链表中的重复元素 II - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/)：删除所有重复元素，重复的元素都不能出现。👉 [<u>删除排序链表中的重复元素II</u>](82%20删除排序链表中的重复元素II.cc)

对比 **83题** 需要删除所有的重复元素，使用 dummy node

[83. 删除排序链表中的重复元素 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/)：删除所有重复的元素，使得每个元素只出现一次。👉 [<u>删除排序链表中的重复元素</u>](链表/83%20删除排序链表中的重复元素.cc)

简单题

[86. 分隔链表 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/partition-list/)：给你一个链表的头节点 `head` 和一个特定值 `x`，请你对链表进行分隔，使得所有小于 `x` 的节点都出现在大于或等于 `x` 的节点之前，你应当保留两个分区中每个节点的初始相对位置。👉 [分隔链表](链表/86%20分隔链表.cc)

双指针，简单的模拟一下过程就可以了

[92.反转链表II]([92. 反转链表 II - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/reverse-linked-list-ii/))：给你单链表的头指针和两个整数 `left` 和 `right`，请你反转从位置 `left` 到 `right` 的链表节点，返回反转后的链表。👉 [<u>反转链表II</u>](92%20反转链表II.cc)

进阶：你可以使用一趟扫描完成反转吗

1. 头节点也可能被反转，因此需要使用一个哑节点 `dummy` 指向头节点，然后找到待反转的节点，反转链表即可

2. 头插法反转。`prev` 指针永远指向待反转节点的前一个节点，`curr` 指针永远指向原链表中第一个待反转的节点，然后每次执行

   - `next = prev->next;`
   - `prev->next = curr->next;`
   - `curr->next = prev->next->next;`
   - `prev->next->next = next;`

3. 递归

   初始的函数是 `reverseBetween(ListNode *head, int left, int right)`

   - 如果 `left == 1` 说明从 `head` 节点就开始反转，此时调用 `reverseN(head, right)`
     - 如果 `right == 1` 说明就反转这一个节点（或者说该节点是整个待反转了链表的最后一个节点），直接返回 `head`，并记录该节点的后驱节点 `successor = head->next`
     - 否则，递归调用 `reverse(head->next, right - 1)`，当递归函数返回的时候，全局变量 `successor` 已经指向了待反转链表中最后一个节点的后驱节点，并且 `last = reverse(head, right - 1)` 返回了后序链表已经反转了的链表的第一个节点
     - 然后执行 `head->next->next = head`，反转 `head` 和它的后驱节点的关系
     - `head->next = successor`，将 `head` 指向 `successor`
     - 返回 `last`，即返回已经反转了的链表的第一个节点
   - 否则递归调用 `reverseBetween(head->next, left - 1, right - 1)`，返回值存到 `last` 中
   - 然后执行 `head->next = last`，串联整个链表
   - 最后返回 `head`

[25.K个一组翻转链表]([25. K 个一组翻转链表 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/reverse-nodes-in-k-group/))：给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。如果节点总数不是 k 的整数倍，那么请将最后声誉的节点保持原有顺序。👉 [<u>K个一组翻转链表</u>](链表/25%20K个一组翻转链表.cc)

1. 迭代。`k` 个一组记录下待反转的区间，然后翻转这段区间的节点，迭代法比较麻烦的是需要记录较多的变量
2. 递归 + 双指针。初始的时候让 `left` 和 `right` 都指向链表的头节点，然后让 `right` 指针往后移动 `k` 个节点，然后翻转 `[left, right)` 的节点，并返回反转之后 `[left, right)` 的头节点 `node`。此时 `left` 就是该段的最后一个节点，我们递归的让 `left->next = reverseKGroup(right, k)`，最后返回 `node` 节点就是整个翻转之后链表的头节点

[61. 旋转链表 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/rotate-list/)：将链表中的每个节点都向后移动 `k` 个位置。👉 [<u>旋转链表</u>](链表/61%20旋转链表.cc)

首先计算链表的长度 `n`，`k % n` 就是需要向后移动的长度。然后使用双指针找到这个位置，此时 `pA` 指向这个位置，`pB` 是最后一个元素的位置。然后断开这个链表，将 `pB` 指向 `head`，并返回原先 `pA->next` 这个节点就是链表的头节点

[141.环形链表](https://leetcode-cn.com/problems/linked-list-cycle/)：给你一个链表 `head`，判断链表中是否存在环。👉 [<u>环形链表</u>](链表/141%20环形链表.cc)

有两种方法可以解决

1. 哈希。在遍历链表的同时将链表元素存入哈希表，每次遍历的时候判断该元素是否出现过一次，如果出现过则说明存在环
2. 快慢指针。让慢指针 `slow` 从 `head` 开始移动，快指针 `fast` 从 `head->next` 开始移动，慢指针每次移动一个元素，快指针每次移动两个元素。如果慢指针和快指针相遇了则说明存在环，如果快指针移动到了链表尾部则说明不存在环

[142.环形链表II](https://leetcode-cn.com/problems/linked-list-cycle-ii/)：给你一个链表，找出该链表出现环的起始位置，如果不存在环则返回 `nullptr`。👉 [<u>环形链表II</u>](链表/142%20环形链表II.cc)

慢指针从 `head` 开始移动，每次移动一个距离；快指针从 `head->next` 开始移动，每次移动两个距离。如果存在环，记链表起始位置到环的起始位置的距离为 `x`，快慢指针相遇的位置距离环起始位置的距离为 `y`，环的长度记为 `z`。则当快慢指针相遇的时候，慢指针已经移动了 `x + y` 的长度，快指针移动了 `2x + 2y` 的长度；快指针相对于环的起始位置的距离为 `2x + 2y - z - x = x + 2y - z`，这个值也等于 `y`，即

`x + 2y - z = y`，所以有 `x = z - y`，也就是说快指针「在环中相对于环的起始位置剩余的距离」就等于「链表起始位置到环起始位置的距离」。此时将慢指针移动到链表头部，然后快指针向后移动一个位置；然后快慢指针每次都移动一个位置，最后相遇的节点即为环的起始位置

[148.排序链表](https://leetcode-cn.com/problems/sort-list/)：给你链表的头节点 `head`，请将其按升序排列并返回排列后的链表。👉 [<u>排序链表</u>](链表/148%20排序链表.cc)

进阶：你可以在 `O(nlogn)` 时间复杂度和常数级空间复杂度下，对链表进行排序吗

需要掌握三种方法

1. 递归归并排序。时间复杂度 `O(nlogn)`，空间复杂度 `O(nlogn)`
   - 首先使用快慢指针找到链表的中间节点；
   - 然后分别对链表的左半部和右半部递归的执行排序；
   - 合并排序之后的链表
2. 迭代归并排序。时间复杂度 `O(nlogn)`，空间复杂度 `O(1)`
   - 第一步，将一个长度为 `length` 的链表拆分为多个长度为 `subLength` 的链表，`subLength` 初始的时候为 `1`
   - 然后两两合并，这样就得到了多个长度 `subLength * 2` 的有序子链表
   - 第二步，`subLength` 变为原来的两倍，回到第一步处理。这样以来就准备合并第一步得到的多个长度为 `subLength * 2` 的子链表
   - 当 `subLength > length` 的时候停止合并
3. **快排（面试的时候容易闻到）**。时间复杂度 `O(nlogn)`，空间复杂度 `O(logn)`
   - 第一步，每次选择链表的第一个元素即 `head` 作为 `pivot`，然后 new 两个 dummy node，`small` 用来保存比 `pivot` 小的元素，`large` 用来保存比 `pivot` 大的元素
   - 第二步，从 `head->next` 开始遍历链表，如果当前节点的值小于 `pivot->val` 将它链入 `small`，否则链入 `large`。执行完这一步之后 `small` 链表中的所有节点值都是小于 `pivot` 的，`large` 链表中所有节点的值都是大于 `pivot` 的
   - 第三步，分隔 `small` 和 `large` 链表，使它们成为两个孤立的链表，并将 `head` 加入其中一个链表中（这里我在实现的时候加入了 `small` 链表）
   - 对 `small` 和 `large` 都执行一次快排
   - 返回 `small` 快排返回的节点
4. 堆排序。时间复杂度 `O(nlogn)`，空间复杂度 `O(n)`
   - 对整个链表建小顶堆，然后每次从堆中弹出一个元素，连接到 `dummy` 后面

> 这里慢指针从 `head` 开始移动，快指针从 `head->next` 开始移动。快指针不能从 `head` 开始移动，考虑 `[1,2]`，此时得到的链表中间节点会是 `2`，然后对 `2->next = []` 和 `head = [1,2]` 排序。可以看到会进行无限的递归调用，因此快指针需要从 `head->next` 开始移动

[160.相交链表](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/)：给你两个链表，找出它们相交的起始点，如果两个链表不想交返回 `nullptr`

- 哈希。使用哈希表存储第一个链表的每一个节点，然后遍历第二个链表，如果在哈希表中找到了该节点则返回这个节点。时间复杂度 `O(m + n)`，空间复杂度 `O(m + n)`
- 双指针。指针 `pA` 从 `headA` 开始移动，指针 `pB` 从 `headB` 开始移动；如果 `pA` 移动到了链表尾部，则 `pA` 从 `headB` 重新开始移动，如果 `pB` 移动到了链表尾部，则 `pB` 从 `headA` 重新开始移动。记 `headA` 和 `headB` 相交部分的长度为 `c`，`headA` 不相交部分的长度为 `a`，`headB` 不相交部分的长度为 `b`，`headA` 的长度为 `m`，`headB` 的长度为 `n`
  - 如果两个链表相交。则按照上面的遍历方法，最后两个指针必定会在相交的点相遇，此时 `pA` 移动了 `a + c + b` 的距离，`pB` 移动了 `b + c + a` 的距离
  - 如果两个链表不相交。则最后 `pA` 和 `pB` 会同时变为 `nullptr`，此时两个指针都移动了 `m + n` 的距离
  - 时间复杂度 `O(m + n)`，空间复杂度 `O(1)`

[206.反转链表](https://leetcode-cn.com/problems/reverse-linked-list/)：给你一个链表的头节点 `head`，请你反转链表，并返回反转后的链表。👉 [<u>反转链表</u>](链表/206%20反转链表.cc)

分别使用 **迭代** 和 **递归** 实现。本题的递归写法比较简单，反转链表II 的递归写法比这道题难一些

[234.回文链表](https://leetcode-cn.com/problems/palindrome-linked-list/)：给你一个链表的头节点 `head`，请你判断该链表是否为回文链表。如果是，返回 `true`，否则返回 `false`。👉 [<u>回文链表</u>](链表/234%20回文链表.cc)

1. 迭代。使用快慢指针首先找到链表的中间节点，然后对后半部分链表翻转，之后遍历两个子链表，判断元素是否相等。`slow` 指针从 `head` 开始，`fast` 指针从 `head->next` 开始
2. 递归。当递归函数找到链表的最后一个节点的时候，开始判断 `head->val == node->val`，然后 `node = node->next`，递归函数返回上一层、即 `head` 变为它的前一个节点

```c++
/// 递归写法
ListNode *node;
bool isPalindrome(ListNode* head) {
  node = head;
  return palindrome(head);
}
bool palindrome(ListNode *head) {
  if (head == nullptr)
    return true;
  bool val = palindrome(head->next);
  val = val && (node->val == head->val);
  node = node->next;
  return val;
}
```



[138.复制带随机指针的链表]([138. 复制带随机指针的链表 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/copy-list-with-random-pointer/))：给你一个长度为 `n` 的链表，每个节点包含一个额外增加的随机指针 `random`，该指针指向链表中的任意一个随机节点。现在请你深度拷贝这个链表，要求保持所有指针的指向与原链表相同。👉 [<u>复制带随机指针的链表</u>](链表/138%20复制带随机指针的链表.cc)

1. 哈希（迭代），**时间复杂度 ` O(n)`，空间复杂度 `O(n)`**。第一遍遍历的时候一边创建新的链表，一边将原链表和新链表中对应的节点记录下来，存放在哈希表中。然后第二遍遍历的时候对于一个新链表中的节点 `node_new` 它的随机指针指向的节点为 `node_new->random = map[node_old->random]`
2. 哈希（递归），**时间复杂度 `O(n)`，空间复杂度 `O(n)`**。哈希的思路和第一种方法一样，就是想办法将第一个链表和第二个链表关联起来。递归的思路就是，我们可以将 `copy` 操作看成一个递归的子问题，`new_node->next = copy(head->next)`，同样的 `new_node->random = copy(head->random)`

```c++
/// 哈希（递归）
unordered_map<Node *, Node *> map;
Node* copyRandomList(Node* head) {
  if (head == nullptr)
    return nullptr;
  if (!map.count(head)) {
    Node *node = new Node(head->val);
    map[head] = node;
    node->next = copyRandomList(head->next);
    node->random = copyRandomList(head->random);
    return node;
  }
  return map[head];
}
```

3. 迭代 + 节点拆分，**时间复杂度 `O(n)`，空间复杂度 `O(1)`**。前面使用哈希的方法都有 `O(n)` 的空间复杂度，如果要求 `O(1)` 的空间复杂度则可以使用该方法。第一步首先将两个链表连接起来，按照 `A->A'->B->B'->...`；第二步遍历这个链表，`head->next->random = head->random->next; head = head->next->next`；第三步还原这两个链表
   - 本质上也是对两个链表建立连接，因为想要设置新链表的 `random` 指针必须要依赖原链表和新链表的联系

[143.重排链表]([143. 重排链表 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/reorder-list/))：给你一个链表 `L: L0->L1->...->Ln-1->Ln`，请你将其重新排序，变为 `L0->Ln->L1->Ln-1->...`。👉 [<u>重排链表</u>](链表/143%20重排链表.cc)

1. 首先使用快慢指针找到链表的中间节点，然后翻转链表的后半部分。然后遍历这两段链表，重新连接它们

## 树

[🌲树](./二叉树/README.md)

## 图

[207.课程表](https://leetcode-cn.com/problems/course-schedule/)：给你一个整数 `numCourses` 表示课程的数量，以及一组向量 `[ai, bi]` 表示如果要学习课程 `ai` 必须先学习课程 `bi`，判断是否可以修完所有的课程。如果可以返回 `true`，否则返回 `false`。👉 [<u>课程表</u>](图/207%20课程表.cc)

这题本质上就是判断图是否存在环，对应了图的「拓扑排序」算法。使用 `vector<vector<int>> edges` 表示图的所有边，`edges[i]` 表示节点 `i` 的所有边；使用 `vector<int> visited` 判断当前节点是否被加入到拓扑排序中，`visited[i] = 0` 表示没有被搜索到，`visited[i] = 1` 表示正在被搜索，`visited[i] = 2` 表示已经被加入到拓扑排序中

然后使用 `DFS` 对整个图进行搜索，对某一个节点搜索的时候首先设置 `visited[i] = 1` 表示正在搜索该节点的所有边，然后遍历边的所有节点继续搜索，当所有边的节点都搜索完毕的时候设置 `visited[i] = 2` 表示已经对该节点搜索完毕

如果在搜索某一个节点的边的另一个节点的时候，发现 `visited[i] = 1` 则说明存在一个环，此时返回 `false`。上一层 `DFS` 函数在收到 `false` 的时候也直接返回 `false`

[310. 最小高度树 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/minimum-height-trees/)：给定数字 n 和一个有 n - 1 条无向边的 edges 列表，请你找到所有最小高度树并按任意顺序返回它们的根节点标签。👉 [<u>最小高度树</u>](图/310%20最小高度树.cc)

广度优先搜索，首先需要通过题目给出的 edges 构建一个图，然后记录下每个节点的入度。首先将入度为 1 的节点放入队列，之后取出队列的元素，减少相连节点的入度，如果入度变为 1 那么也放入队列中。最后当剩余节点的数量小于等于 2 的时候，队列中剩余的元素就是最后的答案

## 栈

[394.字符串解码]([394. 字符串解码 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/decode-string/))：编码规则 `k[encoded_string]` 表示 `encoded_string` 出现 `k` 次。给你一个经过编码的字符串，返回它解码之后的字符串。👉 [<u>字符串解码</u>](栈/394%20字符串解码.cc)

分别使用 `stk_i` 保存数字，`stk_str` 保存字符串，一个整型变量 `num` 保存遇到的数字，字符串变量 `str` 保存当前解码得到的字符串，按照如下规则操作栈

- 如果遇到了 `[`，则将 `num` 和 `str` 都压入栈中，并初始化 `num` 和 `str`
- 如果遇到了 `[0-9]`，则更新 `num` 的值
- 如果遇到了 `[a-z]`，则更新 `str` 的值
- 如果遇到了 `]`，从栈中弹出数字 `repeat` 和字符串 `tmp`，循环 `repeat` 次将当前的 `str` 追加到 `tmp` 后面，然后让 `str = tmp`

最后返回 `str`

## 哈希

## 数组

[9.回文数]([9. 回文数 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/palindrome-number/))：给你一个整数 `x`，如果 `x` 是一个回文整数，返回 `true`，否则返回 `false`。👉 [<u>回文数</u>](数组/9%20回文数.cc)

进阶：你能不将整数转化为字符串来解决这个问题吗

1. 可以用数组
2. 构造一个反转的数与原数进行比较

[136.只出现一次的数字](https://leetcode-cn.com/problems/single-number/)：给定一个非空整数数组，除了某个元素出现一次之外，其余的元素均出现两次，找出那个只出现了一次的元素。要求时间复杂度为 `O(n)`，空间复杂度为 `O(1)`。👉 [<u>只出现一次的数字</u>](hot100/136%20只出现一次的数字.cc)

位运算。使用一个整数 `res` 与数组中的每个元素执行 `^` 运算，由于其余元素均出现了两次，因此 `res` 与其余元素 `^` 的结果还是 `res` 本身。最后 `res` 的值为只出现一次的元素

[238.除自身以外数组的乘积](https://leetcode-cn.com/problems/product-of-array-except-self/)：给你一个整数数组 `nums`，返回数组 `answer`，`answer[i]` 表示 `nums` 中除 `nums[i]` 以外元素的乘积。请不要使用除法，并且在 `O(n)` 时间复杂度内完成。👉 [<u>除自身以外数组的乘积</u>](数组/238%20除自身以外数组的乘积.cc)

使用两个数组 `left[i]` 和 `right[i]` 分别表示 `nums[i]` 左侧和右侧的所有元素的乘积

- `left[i] = left[i - 1] * nums[i - 1], left[0] = 1`
- `right[i] = right[i + 1] * nums[i + 1], right[n - 1] = 1`
- `answer[i] = left[i] * right[i]`

当空间复杂度除了 `answer` 以外是 `O(n)`，也可以优化为 `O(1)` 的空间复杂度，直接原地在 `answer` 上进行修改即可

- 初始的时候将 `answer` 作为 `left` 计算，然后计算 `right` 的时候使用一个变量 `R` 表示当前元素右侧所有元素的乘积
- 因此第二次遍历的时候，从右到左，`answer[i] = answer[i] * R, R = R * nums[i]`

[239.滑动窗口最大值]([239. 滑动窗口最大值 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/sliding-window-maximum/))：给你一个整数数组 `nums`，有一个大小为 `k` 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到窗口内的 `k` 个数字，窗口每次向右移动一位，返回滑动窗口中的最大值。👉 [<u>滑动窗口最大值</u>](数组/239%20滑动窗口最大值.cc)

有三种实现方法：

1. 使用一个数据结构比如 `vector` 保存当前窗口中的所有元素，然后每次窗口在移动的时候都获取当前窗口的最大元素。这样时间复杂度是 `O(nk)`，`n` 表示数组的大小，`k` 表示窗口的大小，会超时
2. 使用大顶堆（优先队列），堆中维护的数据结构是 `pair<int, int>`，其中 `first` 表示元素的值，`second` 表示元素在原数组中的下标，用来删除堆中在窗口之外的元素
   - 在窗口移动到下一个位置之前，堆顶的元素表示当前窗口的最大元素
   - 在窗口移动到下一个位置 `i` 之前，不断的判断堆顶元素是否在窗口之外，如果在下一个窗口之外了删除该元素、调整堆，直到当前堆顶元素在下一个窗口之内
   - 时间复杂度：`O(nlogn)`，空间复杂度：`O(n)`
3. 使用单调队列，单调队列的概念类似于单调栈。考虑下面的关系，如果 `i < j` 并且 `nums[i] < nums[j]`，那么 `nums[i]` 一定不会是窗口的最大值，因此可以直接移除 `nums[i]`
   - 所以使用单调队列维护这一关系式，队列中存放的是元素的下标，这样队列中的元素下标保持从小到大。不断的将新的元素放入队列中，并且不断的从队列的尾部弹出值小于当前值的元素
   - 另外也需要考虑队列中的元素在窗口之外了，因此还需要不断的从队列的首部弹出在窗口之外的元素
   - 时间复杂度：`O(n)`，空间复杂度：`O(k)`

[240.搜索二维矩阵]([240. 搜索二维矩阵 II - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/search-a-2d-matrix-ii/))：编写一个高效的算法来搜索 `m * n` 矩阵 `matrix` 中的一个目标值 `target`。👉 [<u>搜索二维矩阵</u>](数组/240%20搜索二维矩阵.cc)

1. 直接搜索。时间复杂度 `O(mn)`，空间复杂度 `O(1)`
2. 二分搜索。枚举每一行，对每一行进行二分查找。时间复杂度 `O(mlogn)`，空间复杂度 `O(1)`
3. Z 字型搜索。每次搜索的矩阵为以 `matrix` 为左下角，`[x, y]` 为右上角的矩阵，初始的时候 `[x, y] = [0, n - 1]`
   - 如果 `matrix[x][y] > target`，则 `y` 这一列都大于 `target`，因此 `y--`
   - 如果 `matrix[x][y] < target`，则在 `y` 这一列中需要向下寻找一个元素，因此 `x++`
   - 当 `x == m || y < 0` 的时候停止查找

### 连续子数组

这里列出这类题目，具体的题解到对应的专题去查看

- [152. 乘积最大子数组 - 力扣（LeetCode）](https://leetcode.cn/problems/maximum-product-subarray/)(DP)
- [209. 长度最小的子数组 - 力扣（LeetCode）](https://leetcode.cn/problems/minimum-size-subarray-sum/)(前缀和 + 二分 / 滑动窗口)
- [325. 和等于 k 的最长子数组长度 - 力扣（LeetCode）](https://leetcode.cn/problems/maximum-size-subarray-sum-equals-k/)(前缀和)
- [523. 连续的子数组和 - 力扣（LeetCode）](https://leetcode.cn/problems/continuous-subarray-sum/)(前缀和)
- [525. 连续数组 - 力扣（LeetCode）](https://leetcode.cn/problems/contiguous-array/)(前缀和)
- [560. 和为 K 的子数组 - 力扣（LeetCode）](https://leetcode.cn/problems/subarray-sum-equals-k/)(前缀和)
- [713. 乘积小于 K 的子数组 - 力扣（LeetCode）](https://leetcode.cn/problems/subarray-product-less-than-k/)(滑动窗口)
- [974. 和可被 K 整除的子数组 - 力扣（LeetCode）](https://leetcode.cn/problems/subarray-sums-divisible-by-k/)(前缀和)

## 双指针

[双指针](./双指针/README.md)

## 排序

## 优先队列

## 二分

## 贪心

[45. 跳跃游戏 II - 力扣（LeetCode）](https://leetcode.cn/problems/jump-game-ii/)：给你一个非负整数数组 `nums`，你最初位于数组的第一个位置。数组中的每个元素代表你在该位置可以跳跃的最大长度。你的目标是使用最少的跳跃次数到达数组的最后一个位置，假设你总是可以达到数组的最后一个位置。👉 [解答](贪心/45%20跳跃游戏II.cc)

**贪心**

分别使用 `right_max` 和 `end` 记录当前跳 `res` 步可以到达的最远距离，以及当前可以到达的最远距离。遍历数组 `nums`，更新 `end = max(end, nums[i] + i)`，如果 `i == right_max` 则 `++res` 并且 `right_max = end`

最后输出 `res`

时间复杂度：$O(n)$，空间复杂度：$O(1)$

**暴力**

反向查找，初始的时候从 `pos = nums[i] - 1` 开始，遍历 `[0...pos-1]` 如果 `nums[i] + i >= pos`，则更新 `pos = i`， `++res`

时间复杂度：$O(n^2)$，空间复杂度：$O(1)$

[55. 跳跃游戏 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/jump-game/)：给定一个非负整数数组，最初位于数组的第一个下标，数组中的每个元素代表你在该位置可以跳跃的最大长度。判断能否到达最后一个下标。👉 [<u>跳跃游戏</u>](贪心55%20跳跃游戏.cc)

使用 `right_most` 表示当前可以到达的最远距离，初始的时候为 0，`right_most = max(right_most, i + nums[i])`，并且数组的循环条件满足 `i <= right_most && i < nums.size()`

时间复杂度 O(n)，空间复杂度 O(1)

[135. 分发糖果 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/candy/)：`n` 个孩子站成一排。给你一个整数数组 `ratings` 表示每个孩子的评分。你需要按照以下要求，给这些孩子分发糖果：

- 每个孩子至少分配到一个糖果
- 相邻两个孩子评分更高的孩子会获得更多的糖果

计算需要准备的最少糖果数

1. 贪心（两遍遍历）。时间复杂度 `O(n)`，空间复杂度 `O(n)`。使用一个数组 `vec[i]` 表示编号为 `i` 的孩子分得的糖果数量，初始的时候 `vec[i] = 1`
   - 从左到右遍历 `ratings`，如果 `ratings[i] > ratings[i - 1]`，则更新 `vec[i] = vec[i - 1] + 1`
   - 然后从右到左遍历 `ratings`，如果 `ratings[i] > ratings[i + 1] && vec[i] <= vec[i + 1]`，则更新 `vec[i] = vec[i + 1] + 1`
2. `O(1)` 空间复杂度算法。我们无需显式地额外分配糖果，只需要记录当前的递减序列长度，即可知道需要额外分配的糖果数量
   - 使用 `pre` 记录前一个孩子分得的糖果数量，`dec` 表示当前递减序列长度，`inc` 表示当前递增序列长度，`res` 表示当前需要分配的糖果🍬数量
   - 初始化 `pre = 1, inc = 1`，从第二个孩子开始遍历
   - 如果 `ratings[i] > ratings[i - 1]`
     - 则增加递增序列长度 `inc`，递减序列设置为 `dec = 0`，当前孩子需要分配的🍬数量为 `pre + 1`，`pre = pre + 1`，`res += pre`
   - 如果 `raings[i] == ratings[i - 1]`
     - 则递增序列长度 `inc = 1`，递减序列设置为 `dec = 0`，当前孩子需要分配的🍬数量为 `1`，`pre = 1`，`res += 1`
   - 如果 `ratings[i] < ratings[i - 1]`
     - 则增加递减序列的长度 `dec++`，如果 `dec == inc`，**就把上一个递增序列的最后一个元素加入到递减序列中**，`res += dec`，`pre = 1`

如果所有孩子站成一个圈，例如 `[0, 3, 5, 3, 2, 1]`

1. 贪心（两遍遍历）。第一遍遍历从 `0->1->2->3->4->5`，第二遍遍历从 `0->5->4->3->2->1` 即可
2. `O(1)` 空间复杂度方法。过程和排成一排都一样，现在遍历到最后一个元素之后再往前看一个元素

站成一个矩阵？每个人和周围8个人都要比较？（CodeTop 字节面试）

[763. 划分字母区间 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/partition-labels/)：将一个字符串 `s` 尽可能多的划分成多个字符串，要求每个字符只能出现在一个子串中，返回划分出来的每个子串的长度。👉 [<u>划分字母区间</u>](贪心/763%20划分字母区间.cc)

1. 贪心方法一。找到每个字符最后一次出现的位置，然后遍历 `s`。对于 `s[i]` 在内部再遍历 `[i + 1, end]` 的字符 `s[j]`，不断的更新 end 的值。当内部循环结束的时候，相当于划分出了一个子串。时间复杂度 `O(n)`，空间复杂度 `O(n)`
2. 贪心方法二。找到每个字符第一次出现和最后一次出现的位置，然后按照首次出现的位置排序。之后就是类似合并区间的一个过程。时间复杂度 `O(nlogn)`，空间复杂度 `O(n)`

[767. 重构字符串 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/reorganize-string/)：给定一个字符串 `s`，检查能否重新排布其中的字母，使得两个相邻的字符不同。👉 [解答](贪心/767%20重构字符串.cc)

首先统计每个字母出现的次数，如果有字母出现的次数大于 `(n + 1) / 2`，则无法重新排布。否则的话可以使用贪心策略对字符串进行重新排布：

1. 贪心方法1：我们将所有字母和它的出现次数放到最大堆中，每次从堆中弹出两个字母追加到新排布的字符串后面，然后如果这两个字母的出现次数还是大于 0 的话就重新放入堆中。这样最后堆中可能会剩余一个字母，此时再追加到后面去。时间复杂度：$O(nlogW)$，W 是字母的种类，空间复杂度：$O(W)$
2. 贪心方法2：对于出现次数小于等于 n / 2 的字母来说，我们优先将其放在奇数位置，如果奇数位置放满了，再放到偶数位置。对于出现次数等于 (n + 1) / 2 的字母来说只能放在偶数位置。时间复杂度：$O(n + W)$，空间复杂度：$O(W)$

[1024. 视频拼接 - 力扣（LeetCode）](https://leetcode.cn/problems/video-stitching/)：给你一系列视频片段，这些片段来自一项持续时间为 `time` 秒的体育赛事，这些片段可能有所重叠，也有可能长度不一。使用数组 `clips` 描述所有的视频片段，其中 `clips[i] = [starti, endi]` 表示某个视频片段开始于 `starti` 并于 `endi` 结束。对于每个片段都可以自由的再剪辑，例如 `[0, 7]` 可以剪切成 `[0, 1] + [1, 3] + [3, 7]` 三部分。我们需要将这些片段进行再剪辑，并将剪辑后的内容重新拼接成 `[0, time]`，返回所需片段的最小数目，如果无法完成该任务，返回 -1。👉 [解答](贪心/1024%20视频拼接.cc)

这道题类似于 **45.跳跃数组II**

我们可以首先预处理 `clips` 数组，获取每个 `starti` 为起始可以到达的最远的 `end`，记为 `[vec[starti]] = max_end`

然后遍历 [0, time - 1]，每次更新可以到达的最远距离 `last = max(last, vec[i])`，然后判断是否到达极限距离了 `i == last`，最后如果 `i == pre` 表示需要使用下一个新的视频片段

时间复杂度：$O(n + time)$，空间复杂度：$O(time)$

[1330. 翻转子数组得到最大的数组值 - 力扣（LeetCode）](https://leetcode.cn/problems/reverse-subarray-to-maximize-array-value/)：给你一个整数数组 `nums`，「数组值」定义为所有满足 `0 <= i < nums.length-1` 的 `|nums[i]-nums[i+1]|` 的和。你可以选择给定数组的任意子数组，并将该子数组进行翻转，只能执行一次这个操作，请你找到可行的最大数组值。👉 [解答](贪心/1330%20翻转子数组得到最大的数组值.cc)

对于一个序列 `[K - 1, K, K + 1, X, L - 1, L, L + 1]`，如果我们翻转 `[K, L]` 部分的数组，新的数组变为   `[K - 1, L, L - 1, X, K + 1, K, L + 1]`，新数组的「数组值」的变化反映在 `L` 和 `L + 1` 的数组值变为了 `K` 和 `L + 1` 的数组值，`K - 1` 和 `K` 的数组值变为了 `K - 1` 和 `L` 的数组值。数组值的变化可以使用下面的公式反应：
$$
-max(L, L + 1) + min(L, L + 1) - max(K, K - 1) + min(K, K - 1)
+ max(L + 1, K) - min(L + 1, K) + max(L, K - 1) - min(L, K - 1)
$$
化简之后可以得到 $2 * min(L, L + 1) - 2 * max(K - 1, K)$，即相邻元素的最小值减去相邻元素的最大值，由于我们需要数组的变化值尽可能的大，因此相邻元素的最小值需要取最大值，相邻元素的最大值需要取最小值

另外还需要考虑任意元素和数组的第一个元素互换，以及任意元素和数组的最后一个元素互换的情况

时间复杂度：$O(n)$，空间复杂度：$O(1)$

[1642. 可以到达的最远建筑 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/furthest-building-you-can-reach/)：给你一个整数数组 `heights` 表示建筑物的高度，另外有一些砖块 `bricks` 和梯子 `ladders`。你从建筑物 `0` 开始旅程，当从建筑物 `i` 移动到 `i + 1` 时，如果建筑物的高度大于等于下一个建筑物的高度时不需要使用梯子或者砖块，如果当前建筑物的高度小于下一个建筑物的高度时可以使用一个梯子或者 `height[i + 1] - height[i]` 个砖块。如果以最佳方式使用梯子和砖块，返回可以达到的最远建筑物的下标。👉 [解答](贪心/1642%20可以到达的最远建筑.cc)

梯子相当于一组无限多的砖块，因此我们总是期望将梯子用在高度差最大的地方，基于这个贪心策略，使用一个大小等于 `ladders` 的优先队列维护当前梯子需要替换的高度。如果下一个高度差大于队列中的最小高度差，那么将最小的那个高度差改为使用砖头

当使用的砖头总数大于 `bricks` 的时候，表示这栋建筑物无法到达，最后返回 `i - 1` 表示最远可以到达的建筑物下标

### 合并区间类题目

[56.合并区间](https://leetcode-cn.com/problems/merge-intervals/)：以数组 `intervals` 表示若干个区间的集合，请你合并所有重叠的区间，返回一个不重叠的区间数组，该数组恰好覆盖输入中的所有区间。👉 [<u>合并区间</u>](贪心/56%20合并区间.cc)

对所有的区间按照开始时间排序。之后使用临时变量记录当前合并得到区间的开始位置 `start` 和结束位置 `end`，对后续的每一个区间，如果其开始位置在 `end` 之外，那么将 `{start, end}` 加入到结果集中，并创建一个新的合并区间

时间复杂度：$O(nlogn)$，空间复杂度：$O(n)$

[252. 会议室 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/meeting-rooms/)：给定一个会议的时间安排数组，每个会议都有开始时间和结束时间，请你判断一个人能否参加所有会议。👉 [解答](贪心/252%20会议室.cc)

判断是否有区间相交

[253.会议室II]([253. 会议室 II - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/meeting-rooms-ii/))：给你一个会议时间安排的数组 `intervals`，每个会议时间都会包含一个开始时间和结束时间，返回所需会议室的最小数量。👉 [<u>会议室II</u>](贪心/253%20会议室II.cc)

有如下两种思路可以解决该问题：

**堆 + 贪心**

使用堆来解决，堆中存放当前正在执行的会议的结束时间。每次有一个新的会议需要开始的时候，弹出堆中所有已经结束的会议，然后将当前会议的结束时间存放到堆中。该过程中，堆的最大大小就是所需会议室的最小数量

时间复杂度：$O(nlogn)$，空间复杂度：$O(n)$

**贪心**

将会议的开始时间和结束时间存放到一个数组中，使用 `{start, 1}` 存放开始时间，`{start, -1}` 存放结束时间。然后对数组进行排序，每次根据 1 和 -1 累加计数值，过程中计数值的最大值就是所需会议室的最小数量

时间复杂度：$O(nlogn)$，空间复杂度：$O(n)$

> 方法二实际上还可以看成另一个问题背景，即一辆公交车上最多有多少个乘客。会议的开始时间看成一名乘客的上车时间，会议的结束时间看成是一名乘客的下车时间。同样可以使用 `{start, 1}, {end, -1}` 排序累加的方法来解决

## 并查集

[261. 以图判树 - 力扣（LeetCode）](https://leetcode.cn/problems/graph-valid-tree/)：给定一个无向图，判断它是否是一颗树的结构。👉 [解答](并查集/261%20以图判树.cc)

重点在于判断是否存在环，以及连通分量是否只有一个。使用并查集解决这个问题

[305. 岛屿数量 II - 力扣（LeetCode）](https://leetcode.cn/problems/number-of-islands-ii/)：初始的时候矩阵为 0，每次将一个单元变为 1，返回每次变为 1 之后矩阵中连通块的数量。👉 [解答](并查集/305%20岛屿数量II.cc)

[323. 无向图中连通分量的数目 - 力扣（LeetCode）](https://leetcode.cn/problems/number-of-connected-components-in-an-undirected-graph/)：给定一个含有 `n` 个节点的无向图，和一个整数数组 `edges`，`edges[i] = [ai, bi]` 表示 `ai` 和 `bi` 之间有一条边。返回图中连通分量的数目。👉 [解答](并查集/323%20无向图中连通分量的数目.cc)

使用并查集保存同一个连通分量中的所有节点

时间复杂度：$O(ElogN)$，$E$ 是边的条数，$N$ 是节点的个数；空间复杂度：$O(N)$

[737. 句子相似性 II - 力扣（LeetCode）](https://leetcode.cn/problems/sentence-similarity-ii/)：可以将句子表示为一个单词数组，给定两个句子 `setence1` 和 `setence2`，以及一个字符串数组 `similarPairs`，`similarPairs[i] = [xi, yi]` 表示两个单词 `xi` 和 `yi` 是相似的。请你判断 `setence1` 和 `setence2` 是不是相似的。👉 [解答](并查集/737%20句子相似性II.cc)

可以将 `similarPairs` 看成是一个图的所有边，因此首先对 `similarPairs` 这张图构建并查集，然后分别查找 `setence1[i]` 和 `setence2[i]`，判断它们的根节点是不是一样的。如果是一样的就说明这两个单词是相似的，可以继续判断下一组单词，否则的话说明两个句子是不相似的

时间复杂度：$O((M + N)logA)$，其中 $M$ 和 $N$ 分别是 `similarPairs` 和 `setence` 数组的长度，$A$ 是 `similarPairs` 数组中字符串的数量；空间复杂度：$O(A)$

[765. 情侣牵手 - 力扣（LeetCode）](https://leetcode.cn/problems/couples-holding-hands/)：`n` 对情侣坐在连续排列的 `2n` 个座位上，想要牵到对方的手。`row[i]` 是坐在第 `i` 个座位上的人的 ID，每个人只能牵到并肩坐在一起的人。计算需要交换的次数，以便每对情侣都可以牵到对方的手。👉 [解答](并查集/765%20情侣牵手.cc)

**并查集**

通过观察我们可以发现，`n` 对情侣最多需要交换 `n - 1` 次即可，每当有一对情侣坐在正确的位置的时候需要交换的次数就减一。我们可以使用并查集计算连通分量的数量，最后返回 `n - count` 就是需要交换的次数

时间复杂度：$O(nlogn)$，$n$ 是情侣的对数；空间复杂度：$O(n)$

**贪心**

我们也可以间隔的遍历 `raw` 数组，对于 `raw[i]` 它的情侣是 `raw[i] ^ 1`。然后找到 `raw[i] ^ 1` 所在的位置，交换它和 `raw[i + 1]`，每次交换增加一次交换次数

可以首先预处理计算每个人所在的位置，这样在查找 `raw[i] ^ 1` 的位置的时候只需要 $O(1)$ 的时间复杂度

时间复杂度：$O(n)$，空间复杂度：$O(n)$

[面试题 17.07. 婴儿名字 - 力扣（LeetCode）](https://leetcode.cn/problems/baby-names-lcci/)：给定两个列表，一个是名字及对应的频率，另一个是本质相同的名字对。设计一个算法打印出每个真实名字的实际频率。👉 [解答](并查集/面试题17.07%20婴儿名字.cc)

- `UnionFind`：使用 `names` 数组初始化并查集
- `_find`：查找给定名字的 root 的时候，如果 `name` 不存在则创建一个新的指向自身的节点，并且 `count` 的值是 0
- `_union`：遍历 `synonyms` 合并里面的两个名字，字典序大的 root 往字典序小的 root 合并，并增加字典序小的 `count` 值
- `_result`：返回最后的结果，通过遍历 `st` 集合，添加 `count[st[i]]` 到结果集

时间复杂度：$(N + Q)logA$，其中 $N$ 是 `names` 数组的长度，$Q$ 是 `synonyms` 数组的长度，$A$ 是名字字符串的个数；空间复杂度：$O(A)$

### 方程等式

[399. 除法求值 - 力扣（LeetCode）](https://leetcode.cn/problems/evaluate-division/)：给你一个变量对数组 `equations` 和一个实数值数组 `values` 作为已知条件，其中 `equations[i] = [Ai, Bi]` 和 `values[i]` 共同表示等式 `Ai / Bi = values[i]`。每个 `Ai` 或 `Bi` 是一个表示单个变量的字符串。另外还有一些数组 `queries` 表示的问题，其中 `queries[i] = [Ci, Di]` 表示第 `i` 个问题，请你根据已知条件找出 `Ci / Di = ?` 的结果作为答案。返回所有问题的答案，如果存在某个无法确定的答案，则用 `-1.0` 替代这个答案，如果问题中出现了给定的已知条件中没有出现的字符串，也需要用 `-1.0` 替代这个答案。👉 [解答](并查集/399%20除法求值.cc)

使用并查集维护可以求的答案的所有变量，另外增加使用 `weight` 数组表示字符串 `str` 到它的直接相连接变量的倍数关系

当我们执行 `_find` 函数的时候进行路径压缩，一边压缩一边更新 `weight` 数组，注意这里路径压缩需要使用递归的方法，这样可以从上到下进行压缩，当压缩结束的时候所有连通的字符都指向了同一个 root，因此这个时候的权重就是这个字符可以转化为 root 字符的倍数

此时对于 `str1` 和 `str2`，求 `str1 / str2` 值的时候，可以直接返回 `weight[str1] / weight[str2]`

时间复杂度：$(N + Q)logA$，其中 $N$ 是方程的数量，$Q$ 是问题的数量，$A$ 是方程中出现的字符的数量。构建并查集的时候需要 $O(NlogA)$ 的时间复杂度，查询并查集的时候需要 $O(QlogA)$ 的时间复杂度

空间复杂度：$O(A)$

[990. 等式方程的可满足性 - 力扣（LeetCode）](https://leetcode.cn/problems/satisfiability-of-equality-equations/)：给定一个由表示变量之间关系的字符串方程组成的数组，每个字符串方程采用两种不同的形式：`"a==b"` 或 `"a!=b"`。只有当方程有解的时候返回 true，否则返回 false。👉 [解答](并查集/990%20等式方程的可满足性.cc)

首先对所有 `a==b` 形式的方程构建并查集，然后检查 `a!=b` 形式的方程，判断 `a` 和 `b` 是否在同一个集合中，如果是的话就返回 `false`。全部遍历完毕则返回 `true`

时间复杂度：$O(n + ClogC)$，$C$ 是变量的总数；空间复杂度：$O(C)$

### 最小生成树

[1135. 最低成本联通所有城市 - 力扣（LeetCode）](https://leetcode.cn/problems/connecting-cities-with-minimum-cost/)：给你一个整数 `n` 和一个数组 `connections`，其中 `connections[i] = [xi, yi, costi]` 表示将城市 `xi` 和城市 `yi` 连接所要的 `costi`，返回链接所有城市的最低成本，每队城市之间至少有一条路径，如果无法连接所有 `n` 个城市，返回 `-1`。👉 [解答](并查集/1135%20最低成本连通所有城市.cc)

Kruskal 算法，使用并查集记录生成树中的所有节点，最后如果连通分量只有一个则返回 cost，否则返回 -1

时间复杂度：$O(ElogN)$，其中 $E$ 是边的数量，$N$ 是节点的数量；空间复杂度 $O(N)$

[1168. 水资源分配优化 - 力扣（LeetCode）](https://leetcode.cn/problems/optimize-water-distribution-in-a-village/)：村里面一共有 `n` 栋房子，直接在房子内建造水井的成本为 `wells[i - 1]`，从另一口井铺设管道引水的成本为 `pips[j] = [house1j, house2j, costj]`，请返回为所有房子供水的最低成本。👉 [解答](并查集/1168%20水资源分配优化.cc)

我们可以将 `wells[i - 1]` 看成从编号为 0 的房子到编号为 `i` 的房子的管道成本，这样这道题就变为最小生成树问题

[1584. 连接所有点的最小费用 - 力扣（LeetCode）](https://leetcode.cn/problems/min-cost-to-connect-all-points/)：给你一个 `points` 数组，表示 2D 平面上的一些点，其中 `points[i] = [xi, yi]`，链接 `[xi, yi]` 和 `[xj, yj]` 的费用为它们之间的曼哈顿距离，请你返回将所有点🔗的最小费用。👉 [解答](并查集/1584%20连接所有点的最小费用.cc)

经典的最小生成树，这里可以使用 Kruskal 算法解决，使用并查集记录所有添加到集合中的点

时间复杂度：$O(n^2logn)$，空间复杂度：$O(n^2)$

### 练习

「力扣」第 547 题：省份数量（中等）；
「力扣」第 684 题：冗余连接（中等）；
「力扣」第 1319 题：连通网络的操作次数（中等）；
「力扣」第 1631 题：最小体力消耗路径（中等）；
「力扣」第 959 题：由斜杠划分区域（中等）；
「力扣」第 1202 题：交换字符串中的元素（中等）；
「力扣」第 947 题：移除最多的同行或同列石头（中等）；
「力扣」第 721 题：账户合并（中等）；
「力扣」第 803 题：打砖块（困难）；
「力扣」第 1579 题：保证图可完全遍历（困难）;
「力扣」第 778 题：水位上升的泳池中游泳（困难）。

## 搜索

[搜索](回溯/README.md)

## 数学

[204. 计数质数 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/count-primes/)：给定整数 `n`，返回所有小于非负整数 `n` 的质数的数量。👉 [解答](数学/204%20计数质数.cc)

**埃氏筛** 从 2 开始，如果某个数是质数则将这个数的所有倍数都标记为合数，当然对于 `x` 来说我们不需要从 `2x, 3x, ...` 开始标记，可以直接从 `x * x` 开始标记，因为 `2x` 一定是在之前就被 2 标记了，3x 一定是在之前就被 3 标记了，这些数之前一定是被某个小于 `x` 的质数标记了

时间复杂度：$O(nlog{logn})$，空间复杂度：$O(n)$

## 前缀和

*计算所有满足目标条件连续子数组的个数，哈希表需要记录 prefix 对应的子数组数量；计算子数组的长度，哈希表需要记录 prefix 出现的索引（最大或最小）*

[325. 和等于 k 的最长子数组长度 - 力扣（LeetCode）](https://leetcode.cn/problems/maximum-size-subarray-sum-equals-k/)：给定一个数组 `nums` 和一个目标值 `k`，找到和等于 `k` 的最长连续子数组的长度。如果不存在任意一个符合要求的子数组，则返回 0。👉 [解答](前缀和/325%20和等于K的最长子数组长度.cc)

使用哈希表记录前缀 prefix 出现的最小索引值。遍历数组：

1. 对于 `nums[i]` 计算其前缀和，然后判断哈希表中是否存在 `prefix - k`，如果存在的话 `res = max(res, i - map[prefix-  k])`
2. 判断 `prefix` 是否存在哈希表中，如果不存在更新 `map[prefix] = i`

时间复杂度：$O(n)$，空间复杂度：$O(n)$

[523. 连续的子数组和 - 力扣（LeetCode）](https://leetcode.cn/problems/continuous-subarray-sum/)：给你一个整数数组 `nums` 和一个整数 `k`，请你判断数组中是否含有同时满足下述条件的连续子数组：子数组大小至少为 2，且子数组元素总和为 `k` 的倍数。如果存在返回 `true`，否则返回 `false`。👉 [解答](前缀和/523%20连续的子数组和.cc)

与 **560题** 类似，区别在于这里放入哈希表需要延后一个元素，并且需要放入 %k 的结果。对于当前的前缀和 `cur_prefix`，如果哈希表中存在 `cur_prefix % k` 则直接返回 `true`。否则的话在哈希表中存入 `pre_prefix`，然后令 `pre_prefix = cur_prefix % k`。最后 `nums` 的所有元素遍历完毕就返回 `false`

时间复杂度：$O(n)$，空间复杂度：$O(n)$

> 也可以使用哈希表保存余数为 `remainder` 的最小下标，然后每次判断的时候取出 `map[cur_prefix % k]`，如果下标和当前下标相差大于等于 2 则直接返回 true

[525. 连续数组 - 力扣（LeetCode）](https://leetcode.cn/problems/contiguous-array/)：给定一个二进制数组 `nums`，找到含有相同数量的 `0` 和 `1` 的最长连续子数组，返回该子数组的长度。👉 [解答](前缀和/525%20连续数组.cc)

我们可以将数组中所有的 0 都改为 -1，这样问题就变为，找到数组中最长的和为 0 的连续子数组，那么这道题就变味了 **325题**

时间复杂度：$O(n)$，空间复杂度：$O(n)$

[560. 和为 K 的子数组 - 力扣（LeetCode）](https://leetcode.cn/problems/subarray-sum-equals-k/)：给你一个整数数组 `nums` 和一个整数 `k`，请你统计并返回该数组中和为 `k` 的子数组的个数。👉 [解答](前缀和/560%20和为K的子数组.cc)

这题不能用滑动窗口，因为 `nums[i]` 可以小于 0，因此右指针向右移动不能保证区间和一定会增大，同理收缩左指针也不能保证区间和一定会减小

这题可以使用前缀和 + 哈希表，对于前缀和为 `prefix` 的以 `nums[i]` 为结尾的元素来说，和为 `k` 的子数组的个数即是在 `j < i` 的元素里面找出前缀和为 `prefix - k` 的个数，那么 `prefix - k` 就是以 `nums[i]` 为结尾和为 `k` 的子数组的个数

使用哈希表保存当前可以看到的前缀和为 `prefix` 的个数，考虑 `nums[i]`，如果哈希表中存在 `prefix - k` 这个元素，那么令 `res += map[prefix - k]`。最后增加 `map[prefix]` 的个数

时间复杂度：$O(n)$，空间复杂度：$O(n)$

[724. 寻找数组的中心下标 - 力扣（LeetCode）](https://leetcode.cn/problems/find-pivot-index/)：数组中心下标的定义是，该元素左右两侧子数组的和相同。给你一个整数组 `nums`，请计算数组的中心下标，如果存在多个中心下标，返回最左侧的那个。👉 [解答](前缀和/724%20寻找数组的中心下标.cc)

简单使用前缀和计算即可，对于下标 `i`，计算 `prefix - nums[i] == total_cnt - prefix`，如果成立的话返回 `i`

时间复杂度：$O(n)$，空间复杂度：$O(1)$

[862.和至少为K的最短子数组]([862. 和至少为 K 的最短子数组 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/shortest-subarray-with-sum-at-least-k/))：给你一个整数数组 `nums` 和一个整数 `k`，找出 `nums` 中和至少为 `k` 的最短非空子数组，返回该数组的长度，如果不存在则返回 -1。👉 [<u>和至少为K的最短子数组</u>](前缀和/862%20和至少为K的最短子数组.cc)

这道题和 **209题** 不一样，209 题数组中不包含负数，因此可以使用滑动窗口来解决

本题采用前缀和 + 双端队列来解决。首先有一个基本的共识是，如果 `i < j` 并且数组前 `i` 个元素之和大于数组前 `j` 和元素之和，那么对于 `j` 后面的元素它必定不会采用 `nums[i - 1]` 作为该段子数组的起始位置。由于 `nums[i - 1]` 和 `nums[j - 1]` 之间的元素之和为负数，因此对于 `nums[j]` 之后的元素，如果可以采用 `nums[i - 1]` 那么必定可以采用 `nums[j]` 作为子数组的起始位置

我们使用一个队列来保存 `trie` 前缀和中的元素，队列中元素的下标是有序的

- 首先求出 `nums` 数组中每一个元素的前缀和，使用 `trie[i]` 表示 `nums` 数组中前 `i` 个元素之和，然后遍历 `trie` 数组。从队列尾部弹出 `trie[q.back()] >= trie[i]` 的元素，原因上面已经提到了。然后判断 `trie[i]` 和队列首部元素的差是否满足大于等于 `k`，如果满足该条件则更新 `len` 并弹出队列首部的元素

[974. 和可被 K 整除的子数组 - 力扣（LeetCode）](https://leetcode.cn/problems/subarray-sums-divisible-by-k/)：给定一个整数数组 `nums` 和一个整数 `k`，返回其中元素之和可被 `k` 整除的子数组的数目。👉 [解答](前缀和/974%20和可被K整除的子数组.cc)

这道题和 **523题** 的区别在于，首先这道题没有限制子数组的长度，并且数组元素是会出现负数的。我们使用哈希表 `map` 记录余数为 `remainder` 的前缀和的个数，使用 `res` 记录子数组的数目

遍历 `nums` 数组，计算前缀和 `prefix` 并对 `prefix` 取模，使得 `prefix % k` 保持为正数。然后检查 `map` 中是否含有 `prefix`，如果有的话 `res += map[prefix]`。最后 `++map[prefix]`

时间复杂度：$O(n)$，空间复杂度：$O(n)$

## 树状数组

**归并排序和树状数组都可以用来解决区间查询问题**

[剑指 Offer 51. 数组中的逆序对 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/)：在数组中的两个数字，如果前一个数字比后一个数字大，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中逆序对的总数。👉 [解答](树状数组/剑指Offer-51%20数组中的逆序对.cc)

这道题可以转化为求出数组中每个元素右边比它小的元素的个数

**使用归并排序**

对于两个有序序列，例如 `arr_1 = [8, 12, 16, 22, 100], arr_2 = [9, 26, 55, 64, 91]`，当我们进行归并排序的时候必定存在某个时刻 `pA` 指向 12，`pB` 指向 26，此时对于 12 这个数字来说右边比它小的元素的个数就是 `pB - arr_2.begin`。然后当下一个时刻 `pA` 移动到 `16`，对于 `16` 这个数字来说，右边比它小的元素的个数依旧是 `pB - arr_2.begin`

我们可以在每次移动 `pA` 的时候**增加** `pA - 1` 这个下标指向的元素「右边比它小的元素的个数」，即 `pB - arr_2.begin`。我们不必考虑 `pA - 1` 在 `arr_1` 中「右边比它小的元素个数」，因为这个值在对 `arr_1` 进行排序的时候已经计算过了

不断的进行归并，最终就可以找出所有元素右边比它小的元素的个数了，也就是数组中逆序对的总数

时间复杂度：归并排序 O(nlogn)，空间复杂度：归并排序 O(n)

**树状数组**

树状数组可以用来快速的求前缀和，其更新和查找的时间复杂度都是 logn。我们可以将数组 `nums` 按顺序离散到一个数组 `index` 中，`index` 不包含 `nums` 中重复的元素

然后从后往前遍历 `nums` 数组，找到 `nums[i]` 在 `index` 中的下标 `l`，然后计算 `index` 数组前 `l - 1` 项的前缀和就是 `nums[i]` 右边小于 `nums[i]` 元素的数量，这个前缀和可以使用树状数组快速计算。当然了，遍历了 `nums[i]` 之后也需要更新 `index` 数组前 `l` 项的前缀和、以及 `l + 1, ..., index.size()-1` 项的前缀和

这样我们就可以计算数组 `nums` 中所有逆序对的总数了

时间复杂度：排序的时间复杂度是 O(nlogn)；每次遍历 `nums` 都需要二分查找找到 index 中的下标，时间复杂度是 O(logn)，并且在树状数组中计算和更新的时间复杂度是 O(logn)，因此总的遍历的时间复杂度是 O(nlogn)。最后时间复杂度是 O(nlogn)

空间复杂度：O(n)

[树状数组详解 - Xenny - 博客园 (cnblogs.com)](https://www.cnblogs.com/xenny/p/9739600.html)

[树状数组 - OI Wiki (oi-wiki.org)](https://oi-wiki.org/ds/fenwick/)

[315. 计算右侧小于当前元素的个数 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/)：给你一个整数数组 `nums`，按要求返回一个新的数组 `counts`，`counts[i]` 表示 `nums[i]` 右侧小于 `nums[i]` 的元素数量。👉 [解答](树状数组/315%20计算右侧小于当前元素的个数.cc)

参考 剑指Offer-51 的解题方法，这两道题是一样的

1. 归并排序。额外区别是排序的对象需要记录每个元素的当前下标
2. 树状数组

[327. 区间和的个数 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/count-of-range-sum/)：给你一个整数数组 `nums` 以及两个整数 `lower` 和 `upper`。求数组中，值位于范围 `[lower, upper]` 之间的区间和的个数。👉 [解答](树状数组/327%20区间和的个数.cc)

区间和位于 `[lower, upper]` 可以转化为前缀和问题，记 `prefix[i]` 表示数组中前 `i` 个元素的前缀和，那么本题相当于：对于一个 `prefix` 数组中的元素 `prefix[i]` 来说，在其右边找到满足 `lower <= prefix[j] - prefix[i] <= upper` 的元素个数

这样就相当于转化为 **剑指 Offer 51**，我们可以分别使用归并排序和树状数组求解

1. 归并排序。在排序的过程中需要先计算 `[l, mid]` 中的每个元素，在 `[mid + 1, r]` 中有多少个元素满足差值在 `[lower, upper]` 之间，可以使用滑动窗口计算（时间复杂度是 O(n)）
2. 我们也可以使用树状数组来记录 `prefix[i]` 出现的次数，并用它来快速的查找区间值。将 `prefix` 数组离散化到 `index` 数组中，然后遍历 `prefix` 尝试在 `index` 中找到以 `prefix[i]` 为右边界的两个左边界，即 `[prefix[i] - upper, prefix[i] - lower]`。然后在树状数组中查找该区间内的元素数量，即 `tree.query(y) - tree.query(x - 1)`，并且还需要判断 `prefix[i]` 自身是不是满足 `[lower, upper` 的要求，如果满足则「区间和个数」加一。最后将 `prefix[i]` 更新到树状数组中

[406. 根据身高重建队列 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/queue-reconstruction-by-height/)：假设打乱顺序的一群人站成一个队列，数组 `people[i]` 表示队列中一些人的属性，`people[i] = [hi, ki]` 表示第 `i` 个人的身高是 `hi`，前面正好有 `ki` 个身高大于等于 `hi` 的人。现在请你根据每个人的属性信息，将他们排成一个正确的队列。👉 [解答](树状数组/406%20根据身高重建队列.cc)

**贪心**

我们可以使用简单的**贪心策略**，在对数组 `people` 按照 `hi` 和 `ki` 从小到大排好序之后，依次遍历 `people` 数组，给每个人安排位置。具体的贪心方法是：记 `people[i]` 的身高为 `hight`，他前面需要有 `space` 个身高大于等于他的人，`space = ki`。然后遍历结果集 `res`，当发现某个位置为空或者位置上的人的身高大于 `hight` 的时候，我们让 `space--`（空位置也执行 `space--` 可以理解为，将这个位置预留给一个身高大于等于 `hight` 的人）。当 `space = 0` 的时候，我们在下一个空位置给 `people[i]` 安排位置

时间复杂度：O(n^2^)，空间复杂度：排序的空间复杂度为 O(logn)

**树状数组**

还可以使用树状数组来解决该问题，对于每个人来说只需要在他前面找到包含 `ki + 1` 个空位置的位置，该位置就是这个人应该站的位置。而对于身高相同的人来说，我们应该优先为 `ki` 大的那个人安排位置，否则由于 `ki` 小的那个人占据了一个空位置会影响 `ki` 大的那个人的判断

初始的时候我们使用树状数组维护每个位置前面有多少个空位置，然后对于每个人二分查找找到它应该站的位置。再将该位置占据，由于占据位置会影响该位置及其后面位置的前缀，所以需要更新树状数组，即 `tree.update(idx, -1)`

时间复杂度：快排的时间复杂度 $O(nlogn)$ + 二分查找需要查找 $logn$ 次，每次都需要在树状数组中查找前缀和，树状数组查找的时间复杂度 $O(logn)$，因此二分查找的时间复杂度 $O(log^2n)$ ，一共需要 $n$ 次二分查找，所以这部分时间复杂度是 $O(nlog^2n)$。最终时间复杂度是 $O(nlog^2n)$

空间复杂度：树状数组需要 $O(n)$ 的空间，快排需要 $O(logn)$ 的空间，最终空间复杂度 $O(n)$

[493. 翻转对 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/reverse-pairs/)：给定一个数组 `nums`，如果 `i < j` 并且 `nums[i] > 2 * nums[j]`，我们就将 `(i, j)` 称作一个重要翻转对。你需要返回给定数组中的重要翻转对的数量。👉 [解答](树状数组/493%20翻转对.cc)

**树状数组**

这道题和 **327. 区间和的个数** 很像，我们需要在给定元素 `nums[i]` 的右侧寻找小于 `nums[i] / 2` 的元素个数。【注意】如果 `nums[i]` 是正数并且是偶数，小于 `nums[i] / 2` 的第一个数是 `nums[i] / 2 - 1`。如果 `nums[i]` 是奇数或者 `nums[i] < 0`，则小于 `nums[i] / 2` 的第一个数就是 `nums[i] / 2`

首先对 `nums` 数组离散化到 `index` 数组，然后从后往前依次遍历 `nums[i]`，找到小于 `nums[i] / 2` 的第一个元素在 `index` 中的位置，然后从树状数组中找到其前缀和累加到 `res` 中，最后更新树状数组

时间复杂度：$O(nlog^2n)$，空间复杂度：$O(n)$

**归并排序**

对于两个已经排好序的数组来说我们很容易就可以在右边的数组中找到满足 `nums[j] * 2 < nums[i]` 的元素个数，因此可以在归并排序的过程中统计对于每一个第一个数组中的元素 `nums[i]`，在第二个数组中满足该条件的元素个数

### 区域和检索问题

[303. 区域和检索 - 数组不可变 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/range-sum-query-immutable/)：给定一个整数数组，处理以下类型的多个查询：计算 `left` 到 `right` 之间 `nums` 元素的和。👉 [解答](前缀和/303%20区域和检索-数组不可变.cc)

使用一个 `prefix` 数组保存前缀和，如果 `left == 0` 则返回 `prefix[right]`，否则的话返回 `prefix[right] - prefix[left - 1]`

[307. 区域和检索 - 数组可修改 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/range-sum-query-mutable/)：给定一个整数数组，请你完成以下两类操作：1. 更新 `nums` 下标对应的值；2. 查询下标 `[left, right]` 之间的元素和。👉 [解答](树状数组/307%20区域和检索-数组可修改.cc)

本题仅仅使用一个前缀和数组无法解决 `update` 操作引起的变化，考虑到前面元素的 `update` 会影响后面元素的前缀和，我们可以使用树状数组来解决这个变化

树状数组中存储每个下标的前缀和，当 `update` 的之后更新 `i` 后面所有下标的前缀和变化为 `val - nums_[i]`，并且更新 `nums_[i] = val`。查询操作的时候返回 `query(right + 1) - query(left)`

时间复杂度：初始化的时间复杂度是 $O(n)$，`update` 的时间复杂度是 $O(logn)$，查询的时间复杂度是 $O(logn)$

空间复杂度：树状数组需要 $O(n)$ 的空间，`nums_` 数组需要 $O(n)$ 的空间，总的空间复杂度是 $O(n)$

[308. 二维区域和检索 - 可变 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/range-sum-query-2d-mutable/)：给你一个二维矩阵 `matrix`，需要处理以下两类操作：1. 更新某个单元的值；2. 查询一个子矩阵的元素和。👉 [解答](树状数组/308%20二维区域和检索-可变.cc)

使用二维的树状数组就可以了，update 使用两层循环，每一层循环变量的变化和一维的相同

时间复杂度：update 时间复杂度 $O(logm * logn)$，查询的时间复杂度 $O(logm * logn)$；空间复杂度：$O(mn)$

## 字典树

## 单调栈

单调栈理解难度可能稍微大一点，但是题目做多了就融会贯通了

单调栈找某个元素右边第一个比它大的值：

```c++
for (int i = 0; i < n; ++i) {
  while (!stk.empty() && nums[i] > nums[stk.top()]) {
    int idx = stk.top();
    stk.pop();
    res[idx] = i;
  }
  stk.push(i);
}
```

> 在此单调栈中的现有元素的特点是：`top` 元素的后面一个元素是它左侧第一个大于等于自己的元素，因为当 `nums[i] > nums[stk.top()]` 的时候将所有比自己小的元素都弹出栈了，所以当把自己压入栈中的时候满足自己后面的元素是左侧「第一个高度不下降」大于等于自己的元素

单调栈找到左侧第一个比自己小的元素：

```c++
for (int i = 0; i < n; ++i) {
  while (!stk.empty() && heights[i] <= heights[stk.top()])
    stk.pop();
  if (!stk.empty())
    left[i] = stk.top();
  stk.push(i);
}
```

> 在这里由于每次都把栈中高度大于等于自己的元素弹出了，因此最后的栈顶元素就是左侧第一个高度小于自己的元素

[739.每日温度](https://leetcode-cn.com/problems/daily-temperatures/)：根据每日气温列表 `temperatures`，计算出在每一天需要等待几天才会有更高的温度。如果这个气温都不会升高就使用 0 来替代。👉 [每日温度.cc](./单调栈/739%20每日温度.cc)

栈 `stk` 的栈顶元素表示当前需要计算「等待多少天」的 `temperatures` 下标。我们顺序遍历 `temperatures` 数组，每次遍历到一个新的气温 `temperatures[i]` 的时候判断

1. `stk` 是不是空的
2. `temperatures[i]` 的温度是否大于栈顶那一天的温度

如果满足以上两个条件，那么弹出栈顶的元素并更新栈顶元素所求的「等待多少天」。然后继续尝试弹出栈顶元素

最后将遍历到的这一天在数组中的下标压入栈中，表示下一个需要计算「等待多少天」的下标

[496.下一个更大元素I](https://leetcode-cn.com/problems/next-greater-element-i/)：`nums1` 中数字 `x` 的下一个更大元素定义为，在 `nums2` 中找到 `x` 所在的位置，然后从该位置往后找到第一个比它大的元素。现在给出 `nums1` 和 `nums2` 返回 `nums1` 中所有元素的「下一个更大元素」。👉 [下一个更大元素I.cc](。/../单调栈/496%20下一个更大元素I.cc)

本题单调栈的使用方法和 **739.每日温度** 一样，首先使用单调栈计算出所有的 `nums2` 中元素的下一个更大元素的值，并建立哈希映射。然后遍历 `nums1`，在哈希表中查找答案放入 `vector` 中。最后返回 `vector` 即可

[503.下一个更大元素II](https://leetcode-cn.com/problems/next-greater-element-ii/)：给出一个循环数组 `nums` 找到 `nums` 中所有元素的下一个更大元素值。👉 [下一个更大元素II.cc](./单调栈/503%20下一个更大元素II.cc)

执行两遍单调栈的操作，第一遍求出了所有在非循环数组的情况下的「下一个更大元素」；然后第二遍对剩余没有求出的所有元素从 `nums` 的第一个元素再执行一边单调栈操作，因为栈顶的元素的下标必定是大于下面的元素的下标的，因此这样就相当于考虑了循环数组的情况，但是这一遍执行的时候不进行 `stk.push(i)` 操作，因为这一遍如果没有发现「下一个更大元素」的话就返回 `-1` 

> 另一个思路：我们可以把这个循环数组「拉直」，即复制该序列的前 `n - 1` 个元素拼接在原序列的后面，这样我们就可以将这个新序列当作普通序列；「拉直」的另一种体现就是遍历 `2 * n - 1` 个元素而不是 `n` 个元素，然后对下标取模即可

[42.接雨水](https://leetcode-cn.com/problems/trapping-rain-water/)：给定 `n` 个数字表示宽度为 1 的柱子的高度，计算按此排列的柱子下雨之后能够接到多少雨水。👉 [接雨水.cc](./单调栈/42%20接雨水.cc)

两三种方法可以解：

1. **动态规划** 我们可以分别先求出某一个柱子左侧和右侧「第一个高度不下降」大于等于自己的元素，然后对于这跟柱子来说能够接到的雨水量就是 `min(left[i], right[i]) - height[i]`。这种方法计算是「竖着累加」的
   - `left[i] = max(left[i - 1], height[i])`
   - `right[i] = max(right[i + 1], height[i])`
   
2. **单调栈** 在遇到 `heights[i] > heights[stk.top()]` 弹出栈顶元素之后，「后续的栈顶元素」是弹出元素左侧的「第一个高度不下降」大于等于自己的元素记为 `left`，因此我们可以使用 `left` 和 `i` 将 `mid` 围起来，这样一来就可以计算接到雨水的量了，即 `(i - left - 1) * (min(height[left], height[i]) - height[mid])`。这种方法计算是按照一层一层累加的，也即「横着累加」
3. **双指针** `left` 指针从左向右移动，`right` 指针从右向左移动，两个指针相遇的时候停止移动。每次移动一个指针的时候更新 `leftMax` 和 `rightMax`，每次移动的指针是高度较低的那个下标。这种方法相当于是对动态规划方法的一种优化
   - 如果 `height[left] < height[right]`，那么一定有 `leftMax < rightMax`。这是因为只有高度较低的指针才会被移动，而一旦高度低的指针移动之后高度大于另一个指针了，那么此时另一个指针的 `Max` 就是较小的一个。那么在下标 `left` 处能够接到的雨水量就是 `leftMax - height[left]`
   - 如果 `height[left] >= height[right]`，那么一定有 `rightMax >= leftMax`。此时在下标 `right` 处能够接到的雨水量就是 `rightMax - height[right]`

[84.柱状图中最大的矩形](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/)：给定 `n` 个非负整数表示柱状图中各个柱子的高度，每根柱子彼此相邻并且高度为 1，求在该柱状图中能够勾勒出来矩形的最大面积

这道题也有很多种方法，这里只介绍单调栈的做法，其他做法的代码见 👉 [柱状图中最大的矩形](./单调栈/84%20柱状图中最大的矩形.cc)

我们可以使用单调栈先求出每根柱子左侧和右侧第一个高度低于它的柱子下标，然后对于改柱子 `i` 来说，能够勾勒出来的矩形最大面积就是 `(right[i] - left[i] - 1) * heights[i]`。`while (!stk.empty() && heights[i] <= heights[stk.top()])` 可以保证把栈中所有高度大于等于自己的元素都弹出，这样最后的栈顶就是高度小于自己的元素了，因此最后 `left[i] = stk.top()` 或者 `right[i] = stk.top()`

[402.移掉K位数字]([402. 移掉 K 位数字 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/remove-k-digits/))：给你一个以字符串表示的非负整数 `num` 和一个整数 `k`，移除这个数中的 `k` 位数字，使得剩下的数字最小。返回这个数字的字符串形式。👉 [<u>移掉K位数字</u>](单调栈/402%20移掉K位数字.cc)

对于一个给定的字符串整数 `num` 来说，我们肯定是希望当前一位大于后一位的时候移除前面这位数字，这样才能使得 `num` 最快的下降

因此可以使用一个单调栈来维护 `num` 中每一位数字的关系，对于每一位数字判断此时栈中有没有比它小的数字，如果有的话则弹出，并且增加计数器 `count`，当 `count` 达到 `k` 的时候就不需要在栈中弹出元素了

最后遍历完 `num` 的时候在判断一次 `count` 是不是达到了 `k`，因为有可能 `num` 中的数字是基本有序的，此时可以弹出的元素就比较少。如果 `count != k` 则不断的弹出栈中最后的元素。最后拼接栈中的数字就是最后的结果

## 滑动窗口

## 设计题

## hot100

[17.电话号码的字母组合](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/)：给定一个仅包含数字 `2-9` 的字符串，返回所有它能表示的字母组合。👉 [<u>电话号码的字母组合</u>](回溯/17%20电话号码数字组合.cc)

[20.有效的括号](https://leetcode-cn.com/problems/valid-parentheses/)：给定一个字符串，判断该字符串表示的括号组合是不是有效的。👉 [<u>有效的括号</u>](hot100/20%20有效的括号.cc)，使用栈来匹配就可以了

[22.括号生成](https://leetcode-cn.com/problems/generate-parentheses/)：数字 `n` 代表生成括号的对数，设计一个函数，用于能够生成所有可能的并且有效的括号组合。👉 [<u>括号生成</u>](回溯/22%20括号生成.cc)

- 方法一：回溯。需要注意两个条件，`left < num` 的时候可以添加左括号，`right < left` 的时候可以添加右括号
- 方法二：动态规划。`n` 对括号可以看成 `(a)b` 的组合，其中 `a` 字符串中有 `i` 对括号，`b` 字符串中有 `n - i - 1` 对括号。使用 `generate(int n)` 生成 `n` 对括号的所有可能组合，我们可以枚举 `a` 中括号的对数 `0~n-1`。递归调用 `generate(i)` 生成 `a`，递归调用 `generate(n - i - 1)` 生成 `b`，然后组合所有的 `a` 和 `b` 得到所有的括号组合

方法二的代码如下

```c++
class Solution_1 {
  shared_ptr<vector<string>> cache[100] = {nullptr};  // 缓存中间结果，避免重复调用

public:
  shared_ptr<vector<string>> generate(int n) {
    if (cache[n] != nullptr)
      return cache[n];
    if (n == 0) {
      cache[0] = shared_ptr<vector<string>>(new vector<string>{""});
    } else {
      auto result = shared_ptr<vector<string>>(new vector<string>);
      for (int i = 0; i != n; ++i) {
        auto lefts = generate(i);
        auto rights = generate(n - i - 1);
        // 组合所有的 `a` 和 `b`，得到 `n` 对括号组合
        for (const string &left : *lefts)
          for (const string &right : *rights)
            result->push_back("(" + left + ")" + right);
      }
      cache[n] = result;
    }
    return cache[n];
  }
  vector<string> generateParenthesis(int n) { return *generate(n); }
};
```

[39.组合总和](https://leetcode-cn.com/problems/combination-sum/)：给你一个无重复元素的整数数组 `candidates` 和一个目标整数 `target`，找出 `candidates` 中可以使数字和为目标数 `target` 的所有不同组合。`candidates` 中同一个数字可以被无限选取。👉 [组合总和](回溯/组合问题/39%20组合总和.cc)

[48.旋转图像](https://leetcode-cn.com/problems/rotate-image/)：给定一个 `n * n` 的矩阵，请你将矩阵旋转 90 度，必须在原地旋转不能使用另一个矩阵存储。👉 [<u>旋转图像</u>](hot100/48%20旋转图像.cc)

对于一个 `n * n` 的矩阵，可以将它一层一层剥开，对每一层进行旋转
- 这里一共需要剥开的层次为 `n / 2` 层
- 其中第 `i` 层正方形的上下边界和左右边界为 `left = i, right = n - 1 - i`
- 使用函数 `subRotate(matrax, left, right)` 该正方形向右旋转 **一个单位**
- 对其移动 `n - 1 - i - i` 个单位就是旋转 90 度的结果

[53.最大子数组和](https://leetcode-cn.com/problems/maximum-subarray/)：解题思路见 **动态规划——子序列问题——最大子数组和**

[55.跳跃游戏](https://leetcode-cn.com/problems/jump-game/)：给定一个非负整数数组 `nums`，你最初位于数组的第一个下标，数组中的每个元素表示你在该位置可以跳跃的最大长度，判断能否到达最后一个下标。👉 [<u>跳跃游戏</u>](动态规划/55%20跳跃游戏.cc)

- 方法一：动态规划。记 `dp[i]` 表示从下标 `i` 出发能否到达最后一个下标，则我们只需要判断 `j = [i + 1, i + nums[i]]` 能否到达即可，如果从 `j` 出发可以到达那么就可以先从 `i` 到达 `j`，再从 `j` 到达最后一个下标。这里需要从后往前遍历 `nums` 数组
- 方法二：贪心。从前往后遍历 `nums` 数组，并且维护一个最远可以到达的位置 `rightmost`，每次迭代的时候更新 `rightmost`，如果 `rightmost >= nums.size() - 1` 则返回 `true`，否则在循环结束的时候返回 `false`

[62.不同路径](https://leetcode-cn.com/problems/unique-paths/)：一个机器人位于 `m * n` 网格的左上角，机器人每次只能向下或者向右移动一步，到达右下角一共有多少种不同的路径。👉 [<u>不同路径</u>](动态规划/62%20不同路径.cc)

[64.最小路径和](https://leetcode-cn.com/problems/minimum-path-sum/)：给定一个包含非负整数的 `m * n` 网格 `grid`，请找出一条从左上角到右下角的路径，使得路径上的数字之和最小。👉 [<u>最小路径和</u>](动态规划/64%20最小路径和.cc)

`dp[i][j]` 表示从 `grid[i][j]` 到达右下角的最小数字之和，`dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + grid[i][j]`

[70.爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/)：每次可以爬 `1` 或 `2` 个台阶，爬到第 `n` 个台阶有多少种不同的方法。👉 [<u>爬楼梯</u>](动态规划/70%20爬楼梯.cc)

[72.编辑距离](https://leetcode-cn.com/problems/edit-distance/)：给你两个单词 `word1` 和 `word2`，请返回将 `word1` 转化为 `word2` 所使用的最小步数。👉 [<u>编辑距离</u>](动态规划/72 编辑距离.cc)，具体的思路在 **动态规划——子序列问题——编辑距离** 有详细介绍

[75.颜色分类](https://leetcode-cn.com/problems/sort-colors/)：给定一个包含红色、白色和蓝色，共 `n` 个元素的数组 `nums`，原地对它们进行排序，使颜色相同的元素相邻，并按照红色、白色、蓝色顺序排列。分别使用整数 `0, 1, 2` 表示红色、白色、蓝色，不能	使用标准库的 `sort` 函数。👉 [<u><颜色分类</u>](hot100/75%20颜色分类.cc)

时间复杂度为 `O(n)` 的三种方法

1. 采用单指针扫描的方法，使用指针 `ptr` 表示当前准备交换的元素。遍历 `nums` 数组，如果发现元素 `0`，则执行 `swap(nums[i], nums[ptr++])`；当遍历完一遍数组的时候，指针 `ptr` 前面的所有元素都是 `0`，然后遍历 `nums[ptr...n-1]`，发现元素 `1` 则执行 `swap(nums[i], nums[ptr++])`；当第二遍遍历结束的时候 `ptr` 前面的 `0` 和 `1` 已经排好序了，最后剩下的 `2` 不需要执行额外操作了
2. 双指针扫描，使用指针 `p0` 指向准备和 `0` 交换的下标，使用指针 `p1` 指向准备和 `1` 交换的下标。遍历数组 `nums`
   - 如果发现元素 `1` 则执行 `swap(nums[i], nums[p1++])`
   - 如果发现元素 `0`
     - 如果此时 `p0 < p1`，则说明 `p1` 前面的 `1` 都是已经排好序的。那么先交换 `swap(nums[i], nums[p0])`，再交换 `swap(nums[i], nums[p1])`
     - 如果此时 `p0 == p1` 直接执行 `swap(nums[i], nums[p0])`
     - 最后 `p0++, p1++`
3. 双指针扫描，与前面一种方法不同的是，这里使用两个指针 `p0` 和 `p2`。`p0` 从左向右移动，`p2` 从右向左移动
   - 如果找到了 `2`，那么需要不停的交换 `nums[i]` 和 `nums[p2]`，并且 `p2--`
   - 最后交换完 `p2` 的时候判断当前 `nums[i]` 是不是 `0`，如果是的话则交换 `nums[i]` 和 `nums[p0]`，并且 `p0++`

[78.子集](https://leetcode-cn.com/problems/subsets/)：给你一个整数数组 `nums`，数组中的元素各不相同，返回该数组的所有子集。👉 [<u>子集</u>](回溯/子集/78%20子集.cc)

[79.单词搜索](https://leetcode-cn.com/problems/word-search/)：给定一个 `m * n` 的二维字符网格 `board` 和一个字符串单词 `word`，如果 `word` 存在于网格中返回 `true`，否则返回 `false`。👉 [<u>单词搜索</u>](回溯/79%20单词搜索.cc)

[84.柱状图中最大的矩形](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/)：给定 `n` 个非负整数，用来表示柱状图中各个柱子的高度，每个柱子彼此相邻并且宽度为 1，求在该柱状图中能够勾勒出来的矩形的最大面积。👉 [<u>柱状图中的最大矩形</u>](单调栈/84%20柱状图中最大的矩形.cc)

对于每一根柱子 `height[i]` 求出它左侧和右侧第一个高度低于它的柱子下标 `left[i]` 和 `right[i]`，因此对于柱子 `i` 能够勾勒出来的矩形的最大面积为 `(right[i] - left[i] - 1) * height[i]`。`left[i]` 和 `right[i]` 可以使用单调栈求出来

除了单调栈也可以使用暴力的方法来求解，对于每一根柱子每次向左遍历其余的柱子，使用 `width` 表示当前的最低高度，`area` 表示当前最大面积。`width = min(width, height[j])`，`area = max(area, (i - j + 1) * width)`

[85.最大矩形](https://leetcode-cn.com/problems/maximal-rectangle/)：给你一个仅包含 `0` 和 `1` 的二维矩阵，找出只包含 `1` 的最大矩形并返回其面积。👉 [<u>最大矩形</u>](单调栈/85%20最大矩形.cc)

1. 使用 `dp[i][j]` 表示 `matrix[i][j]` 左侧有多少个连续的 `1`（包含它自身）
2. 然后按列遍历，对于每一列 `j` 我们在第一步中得到了 `matrix[i][j]` 左侧有多少个连续的 `1`，相当于我们知道了柱状图的高度，因此就可以转化为 **84.柱状图中最大的矩形** 使用单调栈来求出每一列上的柱状图最大矩形面积
3. 在所有列的柱状图中求出最大的面积

[121.买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)：👉 [<u>买卖股票的最佳时机</u>](动态规划/股票问题/121%20买卖股票最佳时机.cc)

