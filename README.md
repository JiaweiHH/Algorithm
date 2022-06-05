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

[剑指 Offer 34. 二叉树中和为某一值的路径 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/)：给你一棵二叉树 `root` 和一个目标整数 `targetSum`，找出所有从根节点到叶子节点路径总和等于 `targetSum` 的路径。👉 [<u>二叉树中和为某一值的路径</u>](剑指Offer%2934%20二叉树中和为某一值的路径.cc)

1. 深度优先搜索，时间复杂度 `O(n^2)`，空间复杂度 `O(n)`
2. 广度优先搜索，时间复杂度 `O(n^2)`，空间复杂度 `O(n)`

[94.二叉树的中序遍历](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)：👉 [<u>二叉树的中序遍历</u>](二叉树/94%20二叉树的中序遍历.cc)

需要掌握的：

1. 递归方法
2. 使用栈的迭代方法
3. Morris 遍历方法
   - 对于 `root`，如果 `root` 存在左子树，那么就找到左子树中最右边的那个节点，让它的 `right` 指针指向 `root`，类似二叉线索树，这样之后可以回到 `root` 并访问 `root->val`。然后让 `root = root->left` 并断开 `root` 和 `root->left` 的指针，这样做是为了防止循环遍历
   - 如果不存在左子树，那么就将 `root->val` 加入到 `res` 中，然后让 `root = root->right`

[96.不同二叉搜索树](https://leetcode-cn.com/problems/unique-binary-search-trees/)：给你一个整数 `n`，求恰由 `n` 个节点组成且节点值从 `1` 到 `n` 互不相同的二叉搜索树有多少种。👉 [<u>不同二叉搜索树</u>](二叉树/96%20不同二叉搜索树.cc)

动态规划。使用 `dp[i]` 表示当 `n = i` 的时候有多少种不同的二叉搜索树，我们可以将 `j = [1...i]` 作为根节点，`[1...j-1]` 作为左子树，`[j+1...i]` 作为右子树。因此以 `j` 作为根节点的二叉搜索树的种类有 `dp[j - 1] * dp[i - j]` 个，累加所有的 `j = [1...i]` 计算出 `dp[i]`

[98.验证二叉搜索树](https://leetcode-cn.com/problems/validate-binary-search-tree/)：给你一个二叉树 `root` 判断它是不是一棵有效的二叉搜索树。👉 [<u>验证二叉搜索树</u>](二叉树/98%20验证二叉搜索树.cc)

1. 递归（后序遍历）。需要记录左右子数的 `{min_val, left_val, isValid}`，然后和根节点进行对比，返回数据结构
2. 递归（中序遍历）。使用一个全局变量记录前一个节点的值，中序遍历的时候每次判断当前节点的值和前一个节点值的大小
3. 迭代（中序遍历）。也使用一个变量记录上一个节点的值，和递归的思路大致相同

[99. 恢复二叉搜索树 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/recover-binary-search-tree/)：给你二叉搜索树的根节点 `root`，该树中的恰好两个节点值被错误的交换，请你在不改变树的结构的情况下，恢复这棵树。👉 [<u>恢复二叉搜索树</u>](二叉树/99%20恢复二叉搜索树.cc)

1. 方法一：中序遍历，使用 `vector` 按顺序保存所有的节点，然后在数组中找到两个不按顺序的节点，交换它们的值
2. 方法二：Morris 遍历，记录前一个遍历节点值小于当前节点值的节点，然后交换两个节点的值

```c++
/// Morris 遍历记录方法，first 记录 prev->val < root->val，中的 prev，second 记录 root
/// 初始的时候 first 和 second 都为 nullptr
if (!first)
  first = prev;
second = root;
```

[101.对称二叉树](https://leetcode-cn.com/problems/symmetric-tree/)：给你一个二叉树 `root`，判断它是否轴对称。👉 [<u>对称二叉树</u>](二叉树/101%20对称二叉树.cc)

- 迭代。使用一个队列 `que` 保存左右两颗子树的两个待判断的节点，每次从队列中弹出两个元素判断值是否相等，并按照如下顺序压入队列 `left->left, right->right, right->left, left->right`
- 递归。判断左右两颗子树是不是相同的二叉树

[102.二叉树的层序遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)：👉 [<u>二叉树的层序遍历</u>](二叉树/102%20二叉树的层序遍历.cc)

需要掌握的：

1. 使用队列，迭代处理
2. 递归处理。前序遍历的时候记录二叉树的高度，然后 `res[level].push_back(root->val)` 就可以了，如果 `res[level]` 不存在的话，则 `res.push_back({root->val})`

[103.二叉树的锯齿形层序遍历]([103. 二叉树的锯齿形层序遍历 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/))：返回二叉树节点值的锯齿形层序遍历（先从左往右，再从右往左进行下一层遍历，交替执行）。👉 [<u>二叉树的锯齿形层序遍历</u>](二叉树/103%20二叉树的锯齿形层序遍历.cc)

标记奇偶行，对于偶数行对该层结果进行反转即可

[104.二叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)：👉 [<u>二叉树的最大深度</u>](二叉树/104%20二叉树的最大深度.cc)

[105.从前序与中序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)：给出一棵二叉树的前序遍历数组和中序遍历数组，请你根据这两个数组构造二叉树。👉 [<u>从前序与中序遍历序列构造二叉树</u>](二叉树/105%20从前序与中序遍历序列构造二叉树.cc)

递归构造，首先在中序数组中找到前序数组的根节点，然后递归的构造左子树和右子树

```c++
TreeNode *buildT(const vector<int> &preorder, int l_pre, int r_pre, const vector<int> &inorder, int l_in, int r_in) {
  if (l_pre > r_pre)
    return nullptr;
  TreeNode *root = new TreeNode(preorder[l_pre]);
  auto it_in = find(inorder.begin() + l_in, inorder.begin() + r_in + 1, root->val);
  int pos = it_in - inorder.begin();
  int len = pos - l_in;
  root->left = buildT(preorder, l_pre + 1, l_pre + len, inorder, l_in, pos - 1);
  root->right = buildT(preorder, l_pre + len + 1, r_pre, inorder, pos + 1, r_in);
  return root;
}
```

**进阶**

- 如果有重复元素怎么办：有重复元素构造出来的树不是唯一的
- 根据前序和中序输出后序：与这道题一样的方法，先找到前序数组中根节点在中序数组的位置，然后递归的对中序数组的左子树进行处理、对中序数组的右子树进行处理、对中序数组的根节点进行处理

```c++
/// 从前序遍历和中序遍历输出后序遍历
void postOrder(const vector<int> &preorder, int l_pre, int r_pre, const vector<int> &inorder, int l_in, int r_in) {
  if (l_pre > r_pre)
    return;
  int root = preorder[l_pre];
  auto it = find(inorder.begin() + l_in, inorder.begin() + r_in + 1, root);
  int pos = it - inorder.begin();
  int len = pos - l_in;
  postOrder(preorder, l_pre + 1, l_pre + len, inorder, l_in, pos - 1);
  postOrder(preorder, l_pre + len + 1, r_pre, inorder, pos + 1, r_in);
  res.push_back(root);
}
```

[114.二叉树展开为链表](https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/)：给你一棵二叉树 `root`，将它展开为链表，二叉树的 `right` 指针作为链表的 `next` 指针。👉 [<u>二叉树展开为链表</u>](二叉树/114%20二叉树展开为链表.cc)

- 前序遍历。使用 `vector<TreeNode *> list` 记录前序遍历的所有节点，然后遍历 `list` 展开为链表。时间复杂度 `O(n)`，空间复杂度 `O(n)`
- 前序遍历一边遍历一边展开。另一种前序遍历的写法，使用 `prev` 记录上一次遍历到的节点，然后 `prev->right = cur; prev->left = nullptr;`。时间复杂度 `O(n)`，空间复杂度 `O(n)`
- 寻找左子树最右边的节点。记当前节点为 `cur`，每次判断 `cur->left` 是不是为空，如果不为空寻找 `cur->left` 子树最右边的节点记为 `next`；然后执行 `next->right = cur->right; cur->right = cur->left; cur->left = nullptr;`；最后更新 `cur = cur->right;`。时间复杂度 `O(n)`，空间复杂度 `O(1)`

[124.二叉树中的最大路径和](https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/)：路径被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径中至多出现一次，该路径最少包含一个节点，且不一定经过根节点。给你一棵二叉树 `root`，返回其最大路径和。👉 [二叉树中的最大路径和](二叉树/124%20二叉树中的最大路径和.cc)

递归。使用 `dfs(TreeNode *root)` 返回经过节点 `root` 的最大路径和，该路径可能有三种情况

- 只有 `root` 一个节点
- `root` 节点加上它的左子树
- `root` 节点加上它的右子树

并且在执行递归函数的时候更新全局最大路径值 `res = max(res, max({root->val, root->val + left, root->val + right, root->val + left + right}))`。再更新 `res` 的时候考虑了 `root->val + left + right`，但是在返回的时候没有考虑这个值，这是因为当返回到上一层函数的时候，父节点需要用到经过子节点的路径此时子节点的左右子树不能同时考虑

**进阶：打印出路径。只需要更改 `dfs` 函数的返回值从 `int` 改为 `pair<vector<TreeNode *>, int>` 就可以了，然后在 `dfs` 中判断 `res` 需要更新的时候同时更新全局的最优路径**

[129. 求根节点到叶节点数字之和 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/)：从根节点到叶节点的路径 `1->2->3` 组成数字 123，计算所有根节点到叶子节点生成的数字之和。👉 [<u>求根节点到叶节点数字之和</u>](129%20求根节点到叶节点数字之和.cc)

**方法一：递归**

```c++
void dfs(TreeNode *root, int cur) {
  cur = cur * 10 + root->val;
  if (!root->left && !root->right) {
    res += cur;
    return;
  }
  if (root->left)
    dfs(root->left, cur);
  if (root->right)
    dfs(root->right, cur);
}
```

**方法二：深搜迭代**

在前序遍历的基础上进行更改，栈中保存 `pair<TreeNode *, int>`，即当前节点的指针和到当前节点为止组成的数字。从栈中弹出元素的时候更新当前数字 `cur = stk.top().second`，然后判断节点的左右指针是否都为空，如果确定是叶子节点则增加全局和。其余就是前序遍历的过程

**方法三：广搜**

类似深搜迭代的形式，在层序遍历的基础上，更改队列中保存的是 `pair<TreeNode *, int>` 即可

[199. 二叉树的右视图 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/binary-tree-right-side-view/)：给你一个二叉树，返回从右侧能看到的节点值。👉 [<u>二叉树的右视图</u>](二叉树/199%20二叉树的右视图.cc)

1. **层序遍历** 只保留每一层的最后一个元素
2. **深搜** 按照 `root, root->right, root->left` 的顺序遍历。将当前层深度作为深搜的参数传递，如果结果集的元素小于当前层深度，说明当前层还没有被遍历到，则把当前层的结果加入结果集

```c++
vector<int> res;
vector<int> rightSideView(TreeNode *root) {
  dfs(root, 1);
  return res;
}
void dfs(TreeNode *root, int depth) {
  if (root == nullptr)
    return;
  if (res.size() < depth)
    res.push_back(root->val);
  dfs(root->right, depth + 1);
  dfs(root->left, depth + 1);
}
```

[222. 完全二叉树的节点个数 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/count-complete-tree-nodes/)：给你一颗完全二叉树，请你找出树中有多少个节点。👉 [完全二叉树的节点个数](二叉树/222%20完全二叉树的节点个数.cc)

1. 二叉树的遍历计算节点的数量。时间复杂度 O(n)
2. 二分查找
   - **方法描述：**我们可以先计算二叉树的层数 `h`，对于一个 `h` 层的完全二叉树来说，它的节点数量在 `[2^(h - 1), 2^h - 1]`。这样我们就可以在这个范围内进行二分查找，判断指定的节点是否存在于二叉树中。对于某个编号为 k 的节点我们可以将 k 转化为二进制，通过哈夫曼编码的方式，二进制比特位为 1 的时候向右走，为 0 的时候向左走，如果最后走到的不是 nullptr 节点则说明编号为 k 的节点存在，此时可以判断出该二叉树的节点数量大于等于 k。最终需要找到最后一个出现在二叉树中的编号
   - 复杂度计算：二叉树最后一层的节点数量最大为 2^h 个，因此二分查找需要查找的次数是 log(2^h) = h，每次查找需要遍历一条长度为 h 的路径，所以总的时间复杂度是 O(h^2) = O((logn)^2)

[226.翻转二叉树](https://leetcode-cn.com/problems/invert-binary-tree/)：给你一棵二叉树，翻转这棵二叉树。👉 [<u>翻转二叉树</u>](二叉树/226%20翻转二叉树.cc)

递归调用函数即可

[230. 二叉搜索树中第K小的元素 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/)：找到二叉搜索树中第K小的元素。👉 [题解](二叉树/230%20二叉搜索树中第k小的元素.cc)

中序遍历，每次遍历了一个节点令 k--，当 k = 0 的时候，该节点就是第K小的元素。时间复杂度 O(H + k)，H 是二叉树的高度，空间复杂度 O(H)

1. 如果你需要频繁地查找第 k 小的值，如何优化。可以进行一次预处理，将每个节点为根的子树节点的个数记录在哈希表中，查找的时候可以直接通过哈希表判断元素是否在该子树中。预处理时间复杂度 O(N)，查找的时间复杂度 O(N)
2. 如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化。将二叉搜索树转化为平衡二叉树，并记录每个节点为根的子树节点数量到哈希表中。预处理时间复杂度 O(N)，插入、查找、删除时间复杂度 O(log N)

[236.二叉树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/)：给定一棵二叉树以及它的两个节点 `p` 和 `q`，返回这两个节点的最近公共祖先。👉 [<u>二叉树的最近公共祖先</u>](二叉树/236%20二叉树的最近公共祖先.cc)

两种方法可以解决：

1. 首先搜索整棵树，使用哈希表记录每个节点的父节点；然后从 `p` 出发不断向上遍历，并记录每个遍历过的节点；然后从 `q` 出发不断向上遍历，如果碰到某一个节点已经遍历过了，那么该节点就是它们的最近公共祖先
2. 后序遍历递归。`lowestCommonAncestor` 函数返回值表示的是 `p` 和 `q` 最近的公共祖先
   - 如果我们遍历的时候发现 `root == p || root == q` 那么直接返回 `root`
   - 否则继续遍历左子树和右子树
     - 如果左子树的返回值不为 `nullptr` 说明在左子树中发现了 `p` 或者 `q`，并且右子树的返回值不为 `nullptr` 说明在右子树中发现了 `p`  或者 `q`，此时 `root` 就是它们的公共祖先，返回 `root`
     - 如果左子树或者右子树的返回值有一个为 `nullptr` 那么返回另一个值，表示当前 `root` 这颗子树发现了一个节点
     - 如果左右子树的返回值都为 `nullptr` 那么返回 `nullptr` 说明当前 `root` 这颗子树没有找到任何一个和 `p` 或者 `q` 相等的节点

[450.删除二叉搜索树中的节点]([450. 删除二叉搜索树中的节点 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/delete-node-in-a-bst/))：给定一个二叉搜索树 `root` 和一个值 `key`，删除二叉搜索树中 `key` 对应的节点，返回删除后的二叉搜索树。👉 [<u>删除二叉搜索树中的节点</u>](二叉树/450%20删除二叉搜索树中的节点.cc)

- 如果 `key > root->val`，`root->right = deleteNode(root->right, key)`
- 如果 `key < root->val`，`root->left = deleteNode(root->left, key)`
- 如果 `key == root->val`
  - 如果 `root` 左右子树都为空，那么返回 `nullptr`
  - 如果左子树为空，右子树不为空，返回右子树
  - 如果左子树不为空，右子树为空，返回左子树
  - 如果左右子树都不为空，找到右子树最左边的那个节点，将它的值赋给 `root`，然后执行 `root->right = deleteNode(root->right, node->val)`

[652. 寻找重复的子树 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/find-duplicate-subtrees/)：给你一棵二叉树，返回所有重复的子树。👉 [<u>寻找重复的子树</u>](二叉树/652%20寻找重复的子树.cc)

对二叉树的所有节点进行一个序列化，然后保存到一个哈希表中，如果某一个节点序列化的结果已经出现过了，就说明出现重复的子树了。序列化采用后续遍历的方式构建

```c++
unordered_map<string, int> map;
vector<TreeNode *> vec;
vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
  string tmp = dfs(root);
  return vec;
}
string dfs(TreeNode *root) {
  if (root == nullptr)
    return "#";
  string left = dfs(root->left), right = dfs(root->right);
  string res = left + "," + right + "," + to_string(root->val);
  if (map[res]++ == 1)
    vec.push_back(root);
  return res;
}
```

[662. 二叉树最大宽度 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/maximum-width-of-binary-tree/)：给定一个二叉树，获取这棵树的最大宽度。👉 [<u>二叉树最大宽度</u>](二叉树/662%20二叉树最大宽度.cc)

层序遍历的时候对每一个节点按照完全二叉树的形式编号，每一层队列尾部的编号和队列首部的编号之差再加一就是该层的最大宽度

[669.修剪二叉搜索树]([669. 修剪二叉搜索树 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/trim-a-binary-search-tree/))：给你一棵二叉搜索树，同时给定一个最小边界 `low` 和最大边界 `high`，删除二叉树中在这段区间之外的节点，并且需要保持现有节点的相对位置。👉 [<u>修剪二叉搜索树</u>](二叉树/669%20修剪二叉搜索树.cc)

几个边界情况

- `root->val == low`，此时需要让 `root->left = nullptr`
- `root->val == high`，此时需要让 `root->right = nullptr`
- `root->val > high`，返回 `trimBST(root->left, low, high)`
- `root->val < low`，返回 `trimBST(root->right, low, high)`
- 否则的话说明 `root->val` 在区间范围内，因此执行 `root->left = trimBST(root->left, low, high)`，`root->right = trimBST(root->right, low, high)`

[958.二叉树的完全性检验]([958. 二叉树的完全性检验 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/check-completeness-of-a-binary-tree/))：给你一棵二叉树，判断它是否是一棵完全二叉树。👉 [<u>二叉树的完全性检验</u>](二叉树/958%20二叉树的完全性检验.cc)

层序遍历，每次记录前一个遍历的元素，如果某一个节点是 `nullptr`，则记录 `prev = -1`。后序遍历的过程中如果 `prev == -1` 并且某一个节点不是 `nullptr` 则说明不是一棵完全二叉树。如果整棵树都正常遍历完毕，那么就是一棵完全二叉树

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

[41.缺失的第一个正数]([41. 缺失的第一个正数 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/first-missing-positive/))：给你一个未排序的数组 `nums`，请你找出其中没有出现的最小的正整数。请你实现时间复杂度为 `O(n)` 并且只使用常数级别额外空间的解决方案。👉 [<u>缺失的第一个正数</u>](数组/41%20缺失的第一个正数.cc)

考虑如果没有限制空间复杂度，我们可以使用一个哈希表记录数组中出现的所有元素，然后遍历 `1 ~ n` 的正整数，判断其是否在哈希表中，`n` 是数组的大小。如果某一个正整数没有出现，那么直接返回；否则返回 `n + 1`

数组的大小只有 `n`，因此缺失的这个正整数必定出现在 `1 ~ n+1` 之间，所以上述哈希的做法时间复杂度为 `O(n)`

1. “哈希“，我们可以在原数组上原地哈希。如果某一个正整数出现了，就将数组中下标为 `num-1` 的元素值置为负数。初始的时候，将数组中所有小于等于 0 的元素设置为 `n+1`，设置为 `n+1` 的理由在于避免这些元素干扰其他正整数的“哈希”运算
   - 当遍历一边数组将所有的下标都标记之后，在遍历数组查看是否存在正整数。如果存在下标为 `i` 的正整数，说明 `i + 1` 这个正整数没有出现在数组中，否则的话说明 `1~n` 都出现在数组中了，那么没有出现的正整数就是 `n+1`
2. 置换法（也类似上面的 “哈希” 方法）
   - 对于每一个数组中的元素 `x = nums[i]`，我们将其放在数组下标为 `x-1` 的位置，并且递归的将原来在 `x - 1` 位置上的元素也放到对应的位置。一直到 `nums[x - 1] == x` 或者 `nums[x - 1] <= 0` 或者 `nums[x - 1] > n` 为止
   - 遍历数组，如果 `nums[i] != i + 1` 说明 `i + 1` 这个元素没有出现，否则如果全部元素都正确的话说明 `1~n` 这些元素全都出现了，这个时候返回 `n+1`

[128.最长连续序列](https://leetcode-cn.com/problems/longest-consecutive-sequence/)：给你一个未排序的数组 `nums`，找出数字连续的最长序列的长度，请你设计并实现一个时间复杂度为 `O(n)` 的算法。👉 [<u>最长连续序列</u>](哈希/128%20最长连续序列.cc)

可以分别使用 `unordered_map` 和 `unordered_set` 来实现

1. 使用 `unordered_map`，`map[key]` 用来表示当前 `key` 所在的序列的长度，因此对于一个新的元素 `val` 来说我们可以在 map 中找到 `val - 1` 和 `val + 1` 然后根据它们的长度插入 `map[val]` 并更新 `map[val - 1]` 和 `map[val + 1]`
2. 使用 `unordered_set`，初始的时候将所有的元素都放入 set 中。然后遍历每个元素 val，计算以 `val` 为起点的序列的长度

```c++
/// 方法一
unordered_map<int, int> map;
for (int i = 0; i < nums.size(); ++i) {
  if (!map.count(nums[i])) {
    int left = map.count(nums[i] - 1) ? map[nums[i] - 1] : 0;
    int right = map.count(nums[i] + 1) ? map[nums[i] + 1] : 0;
    map[nums[i]] = left + right + 1;
    map[nums[i] - left] = map[nums[i] + right] = left + right + 1;
  }
}

/// 方法二，时间复杂度依旧是 O(n)，因为每个元素最多只被遍历到一次
unordered_set<int> st;
for (auto &val : nums)
  st.insert(val);
for (auto &val : nums) {
  if (!st.count(val - 1)) {
    int cur = val + 1;
    int len = 1;
    while (st.count(cur)) {
      cur++;
      len++;
    }
    res = max(res, len);
  }
}
```

3. 并查集。所有相邻的元素属于一个集合中，不断的对集合进行合并，并记录每个集合当前大小

[365. 水壶问题 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/water-and-jug-problem/)：有两个水壶的容量分别是 `jug1Capacity` 和 `jug2Capacity`，现在问能否使用这两个水壶量出 `targetCapacity` 升水，每次可以执行的操作有：装满任意一壶水、清空任意一壶水、将一壶水倒入另一壶水直到装满或者倒空。👉 [<u>水壶问题</u>](365%20水壶问题.cc)

使用 dfs 搜索，保存当前两壶水剩余容量的状态，每次可以执行

1. 清空第一壶水
2. 清空第二壶水
3. 倒满第一壶水
4. 倒满第二壶水
5. 将第一壶水倒入第二壶水
6. 将第二壶水倒入第一壶水

由于会出现无限递归，因此对于重复的状态需要使用哈希表去重。如果对于某个中间状态有 `remain_1 == target || remain_2 == target || remain_1 + remain_2 == target` 那么说明此时可以量取 target，返回 true

[454. 四数相加 II - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/4sum-ii/)：给你四个整数数组 `nums1`、`nums2`、`nums3`、`nums4`，数组的长度都是 `n`，请你计算有多少个元组 `(i, j, k, l)` 能满足 `nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0`。👉 [解答](哈希/454%20四数相加II.cc)

使用哈希表记录 `nums1` 和 `nums2` 两个数组中所有元素和出现的次数，然后遍历 `nums3` 和 `nums4`，在哈希表中寻找 `-(nums3[k] + nums4[l])` 是否存在，并添加响应的次数

时间复杂度：$O(n^2)$，空间复杂度：$O(n^2)$

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

[1.两数之和](https://leetcode-cn.com/problems/two-sum/)：给出一个数组 `nums` 和一个目标整数 `target`，从数组中找出两个元素之和等于 `target` 的元素下标，要求时间复杂度小于 `O(n^2)`。👉 [<u>两数之和</u>](./双指针/1%20两数之和.cc)

- 方法一：排序。创建一个新的数组 `vector<pair<int, int>> arr`，`pair` 的第一个元素是数组下标，第二个元素是数组值，然后对 `arr` 按照数组值从小到大排序。最后使用双指针，指针 `i` 从 `0` 开始，指针 `j` 从 `arr.size() - 1` 开始

  - 如果 `target - arr[i].second == arr[j].second`，那么返回 `{arr[i].first, arr[j].first}`
  - 如果 `target - arr[i].second < arr[j].second`，`j--`
  - 否则，`i++`
- 方法二：哈希映射。创建一个 `unordered_map<int, int> map` 存储 `<nums[i], i>` 的映射。然后遍历 `nums` 数组

  - 对于每个 `nums[i]` 首先寻找 `target - nums[i]` 是否能在哈希表中找到其迭代器 `it`，如果找到了就返回 `{i, it->second}`
  - 如果没找到，将 `<nums[i], i>` 添加到哈希表中

[167. 两数之和 II - 输入有序数组 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/)：数组 `numbers` 已经按照非递减排序，请你从数组中找出两个数使得它们的和等于 `target`，返回这两个数的下标。👉 [两数之和II](双指针/167%20两数之和II.cc)

类似**两数之和**，更加简单一点

[15.三数之和](https://leetcode-cn.com/problems/3sum/)：给你一个整数数组 `nums`，判断数组中是否存在三个元素 `a, b, c`，使得 `a + b + c = 0`，返回所有不重复的三元组。👉 [<u>三数之和</u>](./双指针/15%20三数之和.cc)

双指针 + 排序。我们可以先确定一个数 `x`，这样问题就转化为从原数组中找到两个元素满足 `y + z = -x`。两数之和的问题就可以使用双指针或者哈希映射来解决，参考 **1.两数之和** 这道题。

本题额外需要解决的是如何去除重复的三元组，下面两处代码可以剔除重复三元组：

1. 确定 `x` 的时候，如果 `nums[i] == nums[i - 1]` 那么跳过 `nums[i]`，因为已经在上一个 `nums[i - 1]` 计算过了
2. 当 `x` 确定下来，寻找 `y` 和 `z` 的时候，为了避免 `[-2, 0, 0, 2, 2]` 这种情况重复添加 `[-2, 0, 2]` 三元组，当找到一个三元组的时候执行 `while (left > 0 && left < right && nums[left] == nums[left - 1]) ++left;` 和 `while (right < nums.size() - 1 && right > left && nums[right] == nums[right + 1]) --right;`

[16. 最接近的三数之和 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/3sum-closest/)：从 `nums` 数组中找出和最接近 `target` 的三个数，并返回它们的和。👉 [<u>最接近的三数之和</u>](双指针/16%20最接近的三数之和.cc)

基本和 **15题** 相同，根据绝对值差值来更新全局解

[259. 较小的三数之和 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/3sum-smaller/)：从 `nums` 数组中找出和小雨 `target` 的三个数，返回一共有多少组满足该条件的三元组。👉 [<u>较小的三数之和</u>](双指针/259%20较小的三数之和.cc)

还是采用和 **15题** 一样的思路，但是不需要取出重复的元素，并且当计算出三数之和小于 `target` 的时候，`res += right - left` 表示以 `left` 为其中一个数的时候，另一个数在 `(left, right]` 之间都可以

```c++
for (int i = 0; i < nums.size(); ++i) {
  int val = target - nums[i];
  int left = i + 1, right = nums.size() - 1;
  while (left < right) {
    int tmp = nums[left] + nums[right];
    if (tmp < val) {
      res += right - left;
      ++left;
    } else {
      --right;
    }
  }
}
```

[18. 四数之和 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/4sum/)：给你一个整数数组 `nums` 和一个目标值 `target`，找出其中的四个元素满足它们的和是 `target`，返回所有不重复的组合。👉 [<u>四数之和</u>](双指针/18%20四数之和.cc)

转化为三数之和就可以了

[11.盛水最多的容器](https://leetcode-cn.com/problems/container-with-most-water/)：给定一个长度为 `n` 的整数数组 `height`，有 `n` 条垂线，找出其中的两条线使得它们与 `x` 轴构成的容器能够容纳最多的水。👉 [<u>盛水最多的容器</u>](双指针/11%20盛水最多的容器.cc)

两个指针分别从 `0` 和 `n - 1` 开始，每次计算当前两个柱子能够获得的最大面积。然后

- 如果 `height[l] < height[r]`，则只有增大 `height[l]` 才有可能增大面积，因此 `++l`
- 否则的话，同理只有增大 `height[r]` 才有可能增大面积，因此 `--r`

[26. 删除有序数组中的重复项 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)：给你一个升序排列的数组 `nums`，删除其中的重复元素。要求所有不重复的元素需要排列在数组的前面，并返回删除后数组的长度。👉 [<u>删除有序数组中的重复项</u>](26%20删除有序数组中的重复项.cc)

前面的指针 `ptr` 用来交换元素，后面的指针 `i` 用来比较 `nums[i]` 和 `nums[ptr - 1]` 是否是相等的，如果想等则跳过，否则与 `ptr` 交换之后、`ptr++`

[27. 移除元素 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/remove-element/)：删除数组中所有值等于 `val` 的元素，必须原地删除，并且不能使用额外空间。👉 [移除元素](双指针/27%20移除元素.cc)

和 **26题** 同样的方法，判断 `nums[i] != val` 的时候，`nums[l++] = nums[r]`。其他情况下只需要 `++r` 即可

[31.下一个排列](https://leetcode-cn.com/problems/next-permutation/)：给出一个整数数组 `nums`，找出 `nums` 的下一个排列。👉 [<u>下一个排列</u>](hot100/31%20下一个排列.cc)

例如 `[4,5,2,6,3,1]` 的下一个排列是 `[4,5,3,1,2,6]`。我们可以首先从后往前找到第一个满足 `nums[i] < nums[i + 1]` 条件的组合，此时记下 `nums[i]` 的索引 `left = i`，并且 `[left + 1, nums.size() - 1]` 的所有元素都是降序的。然后从 `[left + 1, nums.size() - 1]` 从后往前寻找第一个满足 `nums[j] > nums[left]` 的元素，记下该元素的下标 `right = j`。之后交换 `nums[left]` 和 `nums[right]`，交换之后 `nums` 数组满足 `[left + 1, nums.size() - 1]` 是降序的，最后只需要翻转 `left` 之后的所有元素为升序即可

[54.螺旋矩阵]([54. 螺旋矩阵 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/spiral-matrix/))：给你一个 `m` 行 `n` 列的矩阵 `matrix`，请你按照顺时针顺序，返回矩阵中的所有元素。👉 [<u>螺旋矩阵</u>](双指针/54%20螺旋矩阵.cc)

<img src="https://assets.leetcode.com/uploads/2020/11/13/spiral1.jpg" alt="img" style="zoom:50%;" />

使用两个指针 `ptr_r1`，`ptr_r2` 来表示行数的范围，两个指针 `ptr_c1`，`ptr_c2` 来表示列数的范围。因此我们可以先遍历 `[ptr_r1][ptr_c1...ptr_c2]`，然后遍历 `[ptr_r1+1...ptr_r2][ptr_c2]`，然后遍历 `[ptr_r2][ptr_c2-1...ptr_c1]`，然后遍历 `[ptr_r2-1...ptr_r1+1][ptr_c1]`。当遍历完成之后 `ptr_r1++, ptr_r2--, ptr_c1++, ptr_c2--`

另外需要注意一下边界条件，如果 `ptr_r1 == ptr_r2` 此时不需要执行第三步遍历，如果 `ptr_c1 == ptr_c2` 此时不需要执行第四步遍历

[80. 删除有序数组中的重复项 II - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/)：给你一个有序数组 `nums`，请你原地删除重复出现的元素，使每个元素最多出现两次，返回删除后数组的新长度，不要使用额外的空间。👉 [删除有序数组中的重复项II](双指针/80%20删除有序数组中的重复项II.cc)

类似**26题**，相同的做法，只是多了一个记录当前元素有多少个的变量 `cnt`

[88.合并两个有序数组]([88. 合并两个有序数组 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/merge-sorted-array/))：给你两个按非递减顺序排列的整数数组 `num1` 和 `nums2`，请你合并两个数组变成一个有序数组，要求时间复杂度为 `O(m + n)`。👉 [<u>合并两个有序数组</u>](双指针/88%20合并两个有序数组.cc)

1. 新开辟一个空间用来存放有序数组，指针 `ptr_1` 指向 `num1` 的起点，指针 `ptr_2` 指向 `nums2` 的起点，然后不断的将 `nums1` 和 `nums2` 较小的那个元素放入新数组
2. 第一种方法需要 `O(n)` 的空间复杂度，我们可以将指针逆向遍历，这样可以直接利用 `nums1` 后半部分的空间

[125. 验证回文串 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/valid-palindrome/)：给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略大小写。👉 [验证回文串](双指针/125%20验证回文串.cc)

双指针，模拟即可

[165.比较版本号]([165. 比较版本号 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/compare-version-numbers/))：给你两个版本号 `version1` 和 `version2`，请比较它们。👉 [<u>比较版本号</u>](双指针/165%20比较版本号.cc)

1. 双指针。不断的计算 `version1` 到 `'.'` 之前的整数值 `num1`，以及 `version2` 到 `'.'` 之前的整数值 `num2`，比较它们的数值
2. 字符串处理。分别对 `version1` 和 `version2` 按照 "." 切分，并转化为整数，比较切分后的数组

[283.移动零]([283. 移动零 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/move-zeroes/))：给定一个数组 `nums`，请将 `nums` 中的所有 `0` 移动到数组的末尾，同时保持非零元素的相对顺序。👉 [<u>移动零</u>](数组/283%20移动零.cc)

双指针解决，数组中所有的 0 元素和指针 `ptr` 交换

[349. 两个数组的交集 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/intersection-of-two-arrays/)：给定两个数组 `nums1` 和 `nums2`，返回它们的交集，重复的元素只需要添加一次即可。👉 [两个数组的交集](双指针/349%20两个数组的交集.cc)

1. 双指针 + 排序。时间复杂度 `O(mlogm + nlogn)`，空间复杂度 `O(logm + logn)`
2. 哈希集合。时间复杂度 `O(m + n)`，空间复杂度 `O(min(m, n))`

[350. 两个数组的交集 II - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/)：给你两个数组 `nums` 和 `nums2`，返回它们的交集，重复元素按照交集的次数添加。👉 [解答](双指针/350%20两个数组的交集II.cc)

1. 双指针 + 排序（不需要去除重复元素），比起上一题更加简单。时间复杂度 $O(mlogm + nlogn)$，空间复杂度 $O(logm + logn)$
2. 哈希（unordered_map），添加其中一个数组中的元素到哈希表中并记录每个元素出现的次数，然后遍历另一个数组，对于出现在哈希表中的元素添加到结果中，并减少该元素在哈希表中出现的次数，当次数为 0 的时候 erase 该元素。时间复杂度：$O(m + n)$，空间复杂度：$O(min(m, n))$

[360. 有序转化数组 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/sort-transformed-array/)：给你一个已经排好序的整数数组 `nums` 和整数 `a`、`b`、`c`，对于数组的每一个元素 `nums[i]`，计算函数值 `f(x) = a*x^2 + b*x + c`，请按照升序返回数组。👉 [有序转化数组](双指针/360%20有序转化数组.cc)

本质上是对二次函数分类讨论的题目

- a > 0，则找到对称轴，双指针从对称轴左右两侧出发，每次将函数值较小的放入 `res` 中
- a < 0，同样找到对称轴，双指针从 `0` 和 `nums.size() - 1` 出发，每次将函数值较小的放入 `res` 中
- a = 0
  - b > 0，直接按照顺序遍历 `nums` 计算函数值
  - b < 0，逆序遍历 `nums` 计算函数值
  - b = 0，`res.resize(num.size(), c)`

[392. 判断子序列 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/is-subsequence/)：给定字符串 `s` 和 `t`，判断 `s` 是否是 `t` 的子序列。👉 [解答](双指针/392%20判断子序列.cc)

**双指针**

指针 `pA` 从 `s` 的第一个字符出发，指针 `pB` 从 `t` 的第一个字符出发、每次向后移动一个字符。如果 `s[pA] == t[pB]` 则 `pA` 向后移动一个字符。最后判断 `pA == s.size()`

时间复杂度：$O(m + n)$，空间复杂度：$O(1)$

**动态规划**

问题：如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？

如果采用双指针会重复遍历 `t`，造成时间浪费。这个时候可以对 `t` 字符串进行预处理，提取出每个字符第一次出现的位置。使用 $dp[i][j]$ 表示从下标 `i` 开始往后字符 `j` 第一次出现的位置，可以得到状态转移方程：
$$
dp[i][j] = \left\{
\begin{array}{**lr**}
i, t[i] == j \\
dp[i + 1][j], t[i] \neq j
\end{array}
\right.
$$
对 `t` 字符串完成预处理之后就可以遍历每个 `s` 字符串：在 `t` 中找到每个字符的开始位置，然后从该位置开始往后找下一个字符

时间复杂度：$O(m * \Sigma + n)$，空间复杂度：$O(m * \Sigma)$，其中 $\Sigma$ 表示字符集的大小

[457. 环形数组是否存在循环 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/circular-array-loop/)：存在一个不含 0 的环形数组 `nums`，数组中的每个元素表示从当前元素出发向前或者向后移动的步数。现在请你判断数组中是否存在循环，满足循环中的所有元素符号相同，循环中元素的个数必须大于 1，如果存在返回 true，否则返回 false。👉 [环形数组是否存在循环](双指针/457%20环形数组是否存在循环.cc)

1. 双指针。使用快慢指针来寻找环。首先我们从数组的任意一个位置出发，必定能够找到一个环，因为数组是一个环形数组，那么我们要么将所有的元素都遍历完了然后遍历重复的元素，要么还没有遍历完的时候就出现了重复元素
   - 对于双指针循环的判断条件是 `nums[l] * nums[r] > 0 && nums[l] * num[next(r)] > 0`，这样就可以保证整条路径上所有元素的值符号都是相同的
   - 当出现 `l == r` 的时候，进一步判断 `l == next(l)`，如果不相等那么就说明存在一个长度大于 1 的循环，否则的话该循环不满足题目条件
   - 对于不满足条件的遍历来说，我们可以将当前路径上所有遍历过的元素置为 0，避免后续的遍历再走一遍该路径。这是可行的，因为后续路径如果接入了该条路径，那么最后必定会在该条路径的循环中进行循环，因此最后也不满足条件
   - 综上分析，对于每条不满足条件的路径，我们需要遍历两次，因此时间复杂度是 `O(n)`
2. dfs。依次根据数组元素遍历下去，dfs 的思路比较简单。时间复杂度 `O(n^2)`，空间复杂度 `O(n)`

[524. 通过删除字母匹配到字典里最长单词 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/)：给你一个字符串 `s` 和一个字符串数组 `dictionary`，找出并返回 `dictionary` 中最长的字符串，该字符串可以通过删除 `s` 中的某些字符得到。返回长度最长且字母序最小的字符串，如果不存在则返回空字符串。👉 [通过删除字母匹配到字典里最长单词](双指针/524%20通过删除字母匹配到字典里最长单词.cc)

起初以为要在 `s` 中匹配最短，就觉的不能用双指针做，后面发现只要在 `s` 中能够找到就可以了。因此可以使用双指针匹配 `s` 和 `dictionary` 的单词即可，比较简单

[845. 数组中的最长山脉 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/longest-mountain-in-array/)：给你一个整数数组 `arr`，在数组中找到一个子数组满足，子数组中的元素先单调递增、然后再单调递减。如果存在这样的子数组，返回子数组的长度，否则的话返回 0。👉 [数组中的最长山脉](双指针/845%20数组中的最长山脉.cc)

**采用一趟遍历，O(1) 的空间复杂度**

**枚举山脚。**首先在 ` arr` 中找到 `arr[i] > arr[i - 1]` 的那个元素，然后从该元素开始查找山脉数组，分为两个阶段，首先是上升阶段，然后是下降阶段

- 如果在上升阶段，出现了 `arr[r] == arr[r - 1]` 此时直接退出内循环
- 如果在下降阶段出现了 `arr[r] >= arr[r - 1]`，此时更新当前「窗口」的长度，然后退出内循环
- 退出内循环之后需要额外判断边界条件，`r == arr.size() && !upper`，满足该条件的时候再次更新「窗口」长度
- 设置外层循环 `i = r - 1`

**枚举山顶。**`left[i]` 和 `right[i]` 分别表示从 `i` 出发可以向左和向右扩展多少距离。当 `arr[i] > arr[i - 1]` 的时候，`left[i] = left[i - 1] + 1`。当 `arr[i] > arr[i + 1]` 的时候，`right[i] = right[i + 1] + 1`

然后只需要遍历 `arr`，计算 `res = max(res, left[i] + right[i] + 1)`

[881. 救生艇 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/boats-to-save-people/)：给定数组 `people` 表示每个人的体重，每艘船的最大承重为 `limit`，每艘船最多可以载两人，返回承载所有人需要多少艘船。👉 [救生艇](双指针/881%20救生艇.cc)

贪心 + 双指针。首先对 `people` 排序，如果 `people[l] + people[r] > limit`，此时载最重的人即 `r`，船的数量加一，然后 `--r`。如果 `people[l] + people[r] <= limit` 此时 `l` 和 `r` 都可以被载，船的数量加一，`++l, --r`

[927. 三等分 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/three-equal-parts/)：给定一个由 0 和 1 组成的数组 `arr`，将数组分为三个非空的部分，使得所有这些部分表示相同的二进制值，返回 `[i, j]`，其中 `arr[0], arr[1], ..., arr[i]` 表示一部分，`arr[i + 1], arr[i + 1], ..., arr[j - 1]` 表示一部分，`arr[j], arr[j + 1], ..., arr[arr.length - 1]` 表示一部分。👉 [解答](双指针/927%20三等分.cc)

首先需要确定 1 的个数是不是 3 的倍数，如果不是的话直接返回 `{-1, -1}`，如果是三的倍数：

1. 找到最后一段可能开始的位置，具体的方法是从后往前遍历 `arr` 数组，找到第 `cnt_one / 3` 个 1 所在的位置 `idx`。此时尽管有可能最后一段数组开始位置会比 `idx1` 要往前，但是二进制的值是不会变的
2. 遍历第一段数组 `pA` 和最后一段数组 `pB` 的二进制值（需要跳过第一段数组的前置 0），如果中途出现不相等则直接返回 `{-1, -1}`，否则的话遍历结束的时候 `pA - 1` 的位置就唯一确定了第一段数组的最后位置
3. 然后遍历第二段数组 `pA` 和最后一段数组 `pB = idx` 的二进制值，如果中途不相等则直接返回 `{-1, -1}`，否则的话遍历结束的时候第二段数组的结束位置就唯一的确定了，等于 `pA - 1`
4. 然后继续检查 `pA` 到 `idx` 之间的值是否等于 0，这中间的数组元素只能作为第三段数组的前置 0，如果中间有元素不为 0 则直接返回 `{-1, -1}`，否则的话第三段数组的开始位置就唯一确定为第三步结束时候的 `pA`

[977. 有序数组的平方 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/squares-of-a-sorted-array/)：给你一个按非递减顺序排序的整数数组 `nums`，返回每个数字平方之后组成的新数组，要求新数组也要按照非递减顺序排序。要求时间复杂度 `O(n)`。👉 [<u>有序数组的平方</u>](双指针/977%20有序数组的平方.cc)

首先找到数组中绝对值最小的元素 `idx`，然后让 `left` 指针从 `idx - 1` 开始，`right` 指针从 `idx` 开始。不断的将 `left` 和 `right` 中绝对值较小的元素的平方放入 `res` 数组中

[986. 区间列表的交集 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/interval-list-intersections/)：给出两个由闭区间去成的列表，返回两个链表中区间的交集。👉 [区间列表的交集](双指针/986%20区间列表的交集.cc)

指针 `l` 从 `firstList` 出发，指针 `r` 从 `secondList` 出发

- 如果 `firstList[l][1] < secondList[r][1]`，下一步需要移动 `l` 指针
  - 第一种情况，区间 r 完全包裹了区间 l，此时`firstList[l][0] >= secondList[r][0]`
  - 第二种情况，区间 r 和区间 l 相交，此时 `firstList[l][0] <= secondList[r][0] && firstList[l][1] >= secondList[r][0]`
- 如果 `firstList[l][1] >= secondList[r][1]`，下一步需要移动 `r` 指针
  - 同上分析过程

[剑指 Offer 04. 二维数组中的查找 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/)：在一个 m*n 的矩阵中，每一行都是递增的，每一列也是递增的，现在给你一个整数 `target` 判断矩阵中是否存在 `taregt`。👉 [二维数组中的查找](双指针/剑指%20Offer-04%20二维数组中的查找.cc)

矩阵的行列为 `m` 和 `n`，`x` 和 `y` 初始的时候分别等于 `0` 和 `n - 1`，然后每次判断 `matrix[x][y]`

- 如果 `matrix[x][y] > target` 则说明这一列中可能存在 `taregt`，因此 `++x`
- 如果 `matrix[x][y] < target` 则说明这一列必定不存在 `target`，因此 `--y`
- 想等的话直接返回 `true`

类似二叉搜索树的搜索过程

[面试题 16.06. 最小差 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/smallest-difference-lcci/)：给定两个整数数组，计算具有最小差绝对值的一对数值，并返回该对数值的差。👉 [最小差](双指针/面试题16.06%20最小差.cc)

很基础的双指针算法

## 排序

[1424.对角线遍历II]([1424. 对角线遍历 II - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/diagonal-traverse-ii/))：给你一个列表 `nums`，里面每个元素都是整数列表，按照以下方式，按顺序返回 `nums` 中对角线上的整数。👉 [<u>对角线遍历II</u>](排序/1424%20对角线遍历II.cc)

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/04/23/sample_1_1784.png)

1. 使用 `map<int, vector<int>>` 保存和为 `key` 的所有 `values`，`nums` 数组按照从下往上从左到右的方式遍历，保存元素到 `map` 中。然后按顺序遍历 `map` 中的每一个 `key` 保存 `values` 到结果中即可。本质上是利用了 `map` 红黑树有序的特点
2. 使用堆排序。堆中保存的是 `pair<int, int>`，其中 first 表示横坐标，second 表示纵坐标。堆中按照 `first + second` 的和排序，相同的时候按照 `first` 越大的越靠前。然后从堆中依次弹出元素，保存 `nums[first][second]` 到结果中即可

## 优先队列

[218. 天际线问题 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/the-skyline-problem/)：城市的天际线是从远处观看城市中所有建筑物形成的轮廓的外部轮廓，给你所有建筑物的位置和高度，返回由这些建筑物形成的天际线，天际线应该是由关键点组成的列表，关键点是水平线段的左端点。👉 [解答](优先队列/218%20天际线问题.cc)

关键点的横坐标只有可能是矩形上面一条边的左端点，并且对于一个关键点来说它的纵坐标应该是包含了该关键点的最大高度。我们可以对矩形的所有横坐标进行排序，然后遍历每一个点，将所有包含该点的矩形放入大根堆中，堆顶的元素的高度就是这个点的纵坐标

需要注意的是，如果前一个坐标已经用过某个纵坐标了，此时对于当前的关键点来说需要忽略当前的关键点

时间复杂度：$O(nlogn)$，空间复杂度：$O(n)$

[264. 丑数 II - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/ugly-number-ii/)：给你一个整数返回第 `n` 个丑数，丑数指的是只包含质因数 2, 3, 5 的正整数。👉 [解答](优先队列/264%20丑数II.cc)

不管是动态规划的解法还是优先队列的解法，本质上思路都是一样的：新的丑数可以从一个已经计算出来的丑数，通过乘以质因数获得

我们可以维护 2, 3 和 5，它们当前和第几个丑数相乘了。每次从相乘的结果中选择最小的一个丑数，然后将该指针往后移动一个位置。如果有多个相乘的结果相同，此时有两种方法：1. 预先计算出相同的结果不存入数组中；2. 通过选择得到的最小丑数，然后去数组中判断有哪些值是相等的，将这些值的指针都往后移动

时间复杂度：$O(n)$，空间复杂度：$O(n)$

[313. 超级丑数 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/super-ugly-number/)：超级丑数是一个正整数，满足所有的质因数都在数组 `primes` 中，给你一个整数 `n` 和整数数组 `primes`，返回第 `n` 个超级丑数。👉 [解答](优先队列/313%20超级丑数.cc)

这道题重点是所有的超级丑数都可以从一个较小的超级丑数乘以 `primes[i]` 得到，每个 `primes[i]` 都可以和前面已经得到的超级丑数相乘从而获得一个更大的超级丑数

我们可以使用优先队列维护每个 `primes[i]` 当前乘到第几个前面已经得到的超级丑数了，每次从小根堆中弹出一个元素然后将它乘以下一个超级丑数得到新的丑数 `new_ugly`。为了减少时间复杂度我们需要额外使用一个集合 `set` 来存储当前堆中的元素，如果新的丑数 `new_ugly` 已经出现在集合中了，那么 `primes[i]` 继续乘以下一个超级丑数，直到新得到的丑数不出现在 `set` 中，此时将新的元素插入到堆和 `set` 中。每次弹出元素的时候需要从 `set` 中移除该元素，以节省空间

时间复杂度：需要找到 `n` 个超级丑数，每次找的时候都需要往堆中插入一个新的丑数，堆的大小为 `primes` 数组的大小 `m`，这部分时间复杂度是 $O(nlogm)$，初始构建堆的时候时间复杂度 $O(mlogm)$，最终时间复杂度 $O(max(m, n)logm)$

空间复杂度：维护堆中元素的集合大小为 $O(m)$，存储前 `n` 个丑数的数组大小为 $O(n)$，总的时间复杂度为 $O(m + n)$

[451. 根据字符出现频率排序 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/sort-characters-by-frequency/)：给定一个字符串 `s`，根据字符出现的频率对其进行降序排序，返回已经排序的字符串。👉 [解答](优先队列/451%20根据字符出现频率排序.cc)

**堆排序**

每个字符和该字符出现的次数放入大根堆中，每次从堆中弹出一个字符，在 `res` 中追加该字符

时间复杂度：$O(n + klogk)$，其中 n 是字符串 `s` 的长度，k 是字符的种数，空间复杂度：$O(n)$

**桶排序**

将每个字符放到对应出现频率的桶中，然后从大到小遍历每个桶，对于 buckets[i] 中的每个字符，在 `res` 中添加 `i` 个字符

时间复杂度：$O(n + k)$，空间复杂度：$O(n + k)$

[759. 员工空闲时间 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/employee-free-time/)：给定员工的 `schedule` 列表，表示每个员工的工作时间。每个员工都有一个非重叠的时间段 `Intervals` 列表，这些时间段已经排好序。返回表示所有员工的共同空闲时间段。👉 [解答](优先队列/759%20员工空闲时间.cc)

**堆 + 贪心**

我们可以将每个员工的第一个空闲时间放到堆中，堆中按照 Interval 的 start 进行排序。使用指针 ptr 表示初始的时间，初始化为堆顶 Interval 的开始时间

每次从堆中弹出 Interval，如果 Interval.start > ptr 则表示 [ptr, Interval.start] 这段时间是所有人的空闲时间。贪心策略的正确性证明：堆中剩余的 Interval 的开始时间必定会大于 cur_Interval.start，所以对于后面的工人来说 [ptr, cur_Interval.start] 必定是他的空闲时间

然后更新 ptr 为 max(ptr, cur_Interval.end)，并将 cur_Interval 对应工人的下一个 Interval 放入堆中

时间复杂度：$O(ClogN)$，C 是所有区间的数量，N 是区间数组的数量；空间复杂度：$O(N)$

**扫描线**

这道题目可以转化为：求和所有区间不相交的区间

我们将所有的区间的开始时间和结束时间抽离出来，给开始时间打上标签 1，结束时间打上标签 -1。然后对所有的时间进行排序，之后遍历这些时间，使用 `prev_time` 记录上一个遍历到的时间，使用 `cnt` 记录当前的计数值。对于开始时间 `cnt += 1`，结束时间 `cnt += -1`，如果某个时刻 `cnt == 0` 则说明从 `prev_time` 到 `cur_time` 是一段空闲时间，记录到结果数组中

时间复杂度：$O(ClogC)$，C 是所有区间的数量；空间复杂度：$O(C)$

[871. 最低加油次数 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/minimum-number-of-refueling-stops/)：汽车从起点出发驶向目的地，目的地位于 `target`。途中有很多加油站，加油站 `i` 的位置是 `stations[i][0]`，可以加油 `stations[i][1]` 升。请你计算行驶到目的地所需的最少加油次数，如果不能到达目的地则返回 -1。👉 [解答](优先队列/871%20最低加油次数.cc)

**优先队列 + 贪心**

对于可以到达的加油站我们先选择不加油，将其保存起来。当发现某个加油站不可到达的时候可以选择从保存的加油站中选择汽油最多的一个加油

遍历完所有的加油站之后如果还没有到达目的地，则判断此时是否还有保存的加油站，如果还有的话则依旧选择汽油最多的一个加油，直到可以到达目的地

对于加油站的保存可以使用大根堆

时间复杂度：$O(nlogn)$，空间复杂度：$O(n)$

**动态规划**

$dp[i]$ 表示加油 $i$ 次可以到达的最远距离，我们依次增加对加油站的考虑，则状态转移方程为：$dp[j + 1] = max(dp[j + 1], dp[j] + stations[i][0]), 0 \leq i < n, 0 \leq j \leq i$（`if dp[j] >= stations[i][0]`）

[1675. 数组的最小偏移量 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/minimize-deviation-in-array/)：给你一个由 `n` 个正整数组成的数组 `nums`，你可以对数组执行任意次数的以下操作：1. 如果元素是偶数，则可以除以 2；2. 如果元素是奇数，则可以乘以 2。定义数组的偏移量是数组中两个元素的最大差值，返回数组在执行某次操作之后可以拥有的最小偏移量。👉 [解答](优先队列/1675%20数组的最小偏移量.cc)

我们可以将所有的奇数操作都转化为偶数操作，具体的实现为：如果 `nums[i]` 是奇数，则将 `nums[i] * 2` 放入大根堆中

维护一个变量 `min_value` 表示堆中元素的最小值，每次从堆中弹出一个元素，计算其和 `min_value` 的差值，并更新 `res`。然后将该元素除以 2 放入堆中，当堆顶元素是奇数的时候此时不能再将最大元素变小，结束操作

时间复杂度：$O(nlogn)$，空间复杂度：$O(n)$

[剑指 Offer 41. 数据流中的中位数 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof/)：设计一个支持以下两种操作的数据结构，1. addNum - 从数据流中添加一个元素到数据结构中，2. findMedian - 返回目前所有元素的中位数。👉 [解答](优先队列/剑指Offer41%20数据流中的中位数.cc)

使用小根堆加大根堆实现这种数据结构，小根堆中存放后面一半的数据，大根堆中存放前面一半的数据。如果数据的个数是奇数，则小根堆中比大根堆中多存放一个元素

添加元素的时候，如果小根堆为空则添加到小根堆中，否则的话获取小根堆的堆顶元素

1. 如果 `num` 大于等于堆顶元素，则添加到小根堆中。此时还需要判断小根堆中的元素个数是否大于 `(sz + 1) / 2`，如果满足该条件则将堆顶元素弹出放到大根堆中；
2. 如果 `num` 小于小根堆的堆顶元素，则将元素放到大根堆中，并判断大根堆中的元素个数是否大于 `sz / 2`，如果是的话将堆顶元素放到小根堆中

时间复杂度分析：addNum 操作的时间复杂度是 `O(logn)`，findMedian 操作的时间复杂度是 `O(1)`

空间复杂度：`O(n)`

### 前 K 个元素

[215.数组中的第K个最大元素](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/)：给你一个数组 `nums`，返回其中第 `k` 个最大整数。👉 [解答](优先队列/215%20数组中的第k个最大元素.cc)

1. 堆排序。建立大顶堆之后进行 `k - 1` 次调整
2. 快速选择。利用快速排序的 `partition` 确定 `nums[n - k]`

[347. 前 K 个高频元素 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/top-k-frequent-elements/)：给你一个整数数组 nums 和一个整数 k，请你返回其中出现的频率前 k 高的元素，你可以按任意顺序返回答案。👉 [解答](优先队列/347%20前K个高频元素.cc)

和 **215题** 一样

[703. 数据流中的第 K 大元素 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/kth-largest-element-in-a-stream/)：设计一个找到数据流中第 `k` 大元素的类。👉 [解答](优先队列/703%20数据流中的第K大元素.cc)

和 **215题** 一样

1. 堆：大小为 K 的小根堆保存前 K 大的元素
2. 快速选择

[973. 最接近原点的 K 个点 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/k-closest-points-to-origin/)：给定一个数组 `points`，找出离原点最近的 `k` 个点。👉 [解答](优先队列/973%20最接近原点的K个点.cc)

1. 堆
2. 快速选择

[面试题 17.14. 最小K个数 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/smallest-k-lcci/)：设计一个算法，找出数组中最小的 `k` 个数，以任意顺序返回这 `k` 个数均可。👉 [解答](优先队列/面试题17.14%20最小K个数.cc)

和 **215题** 一样

1. 快速选择：分割出前 `k` 个元素。时间复杂度：`O(n)`，空间复杂度：`O(logn)`
2. 堆：使用大小为 `k` 的大根堆保存前 `k` 个元素。时间复杂度：`O(nlogk)`，空间复杂度：`O(k)`

## 二分

### 旋转数组

[33.搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)：整数数组 `nums` 按升序排列，数组的值互不相同。对 `nums` 在某一个位置 `k` 上进行旋转之后的结果是 `[nums[k], nums[k + 1], ..., nums[n - 1], nums[0], nums[1], ..., nums[k - 1]`。现在给出旋转之后的数组 `nums` 和一个整数 `target`，如果 `nums` 中存在 `target` 返回 `target` 的下标，否则返回 -1。要求时间复杂度为 `O(log n)`，👉 [<u>搜索旋转排序数组</u>](二分/33%20搜索旋转排序数组.cc)

1. 判断 `nums[mid]` 是在第一段区间还是在第二段区间
2. 如果 `nums[mid]` 在第一段区间，判断 `nums[l] <= target < nums[mid]` 是否成立，如果成立的话 `l = mid + 1`，否则 `r = mid - 1`
3. 如果 `nums[mid]` 在第二段区间，判断 `nums[mid] <= target <= nums[r]` 是否成立，如果成立的话 `l = mid + 1`，否则 `r = mid - 1`

最后返回 `r < 0 || nums[r] != target ? -1 : r`

**进阶：如果在旋转一次应该要怎么做，做法还是一样的，无论旋转几次最多只有两段递增序列**

[81.搜索旋转排序数组II]([81. 搜索旋转排序数组 II - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/))：与 **33题** 的区别在于，现在数组中存在重复的元素。👉 [<u>搜索旋转排序数组II</u>](二分/81%20搜索旋转数组II.cc)

1. 处理方法和 **154题** 相同，跳过所有 `left` 重复的元素，然后 `right` 再跳过和 `left` 重复的元素。之后就是和 **33题** 相同的解法了。最坏的情况下时间复杂度 `O(n)`，此时需要遍历跳过所有的元素
2. 在 **33题** 的基础上，增加判断 `nums[mid] == nums[r]` 的情况，因为当 `nums[mid] == nums[r]` 的时候，我们并不能确定 `mid` 是在第一段区间还是在第二段区间，但是我们知道即便 `nums[r]` 是需要找的值，它也有一个替代品，所以这个时候 `--r`
   - 【一些细节】只有当 `nums[mid] == nums[r] && r != l` 的时候才执行 `--r`，当 `r == l` 的时候放到 **33题** 的处理代码中处理就好了，不然的话会造成只有一个元素的时候 `r` 并不是指向` target`

[面试题 10.03. 搜索旋转数组 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/search-rotate-array-lcci/)：搜索旋转数组，找到数组中的某个元素，如果元素出现多次，则返回最小的索引值。👉 [解答](二分/面试题10.03.搜索旋转数组.cc)

这题和 **81题** 的区别在于，本题需要返回重复元素的最小下标，而 **81题** 只需要判断是否存在这个元素就可以了

**两段式搜索**

这里集成了：1. 找到数组中旋转位置的下标；2. 给定一个 target 找到 target 的最小下标，这两个问题的方法

1. 首先找到数组旋转的下标，可以对 **154题** 的代码稍作修改（原本这题的代码只保证找到数组中的最小元素值，这个值既可能是 nums[0]，也可能是 nums[routate]）
2. 判断 target 位于哪一段区间
3. 二分查找 target

```c++
// 找到数组中的旋转位置下标
int n = arr.size();
int l = 0, r = n - 1, start_idx = 0;
while (l <= r) {
  int mid = (l + r) / 2;
  if (arr[mid] > arr[r])
    l = mid + 1;
  else if (arr[mid] < arr[r]) {
    start_idx = max(start_idx, r + 1);
    r = mid;
  } else {
    --r;
  }
}
start_idx = start_idx == n || arr[start_idx] != arr[l] ? l : start_idx;
```

**一遍搜索**

直接在 **81题** 的基础上修改，增加判断 `arr[l] == target` 的时候直接返回 `l`，以及 `arr[mid] == target` 的时候 `r = mid`。其余的保持和 **81题** 相同（`nums[mid] == nums[r] && r != l` -> `nums[mid] == nums[r]`）

[153.寻找旋转排序数组中的最小值]([153. 寻找旋转排序数组中的最小值 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/))：给你一个数组 `nums`，数组中不包含重复元素，它是由一个有序数组旋转若干次得到的，请找出原数组中的最小值。👉 [<u>寻找旋转排序数组中的最小值</u>](二分/153%20寻找旋转排序数组中的最小值.cc)

直接使用二分查找，如果 `nums[mid] > nums[r]` 说明 `mid` 在左边的递增区间上，此时 `l = mid + 1`。如果 `nums[mid] <= nums[r]` 说明 `mid` 此时在右边的递增区间上，由于 `mid` 有可能是最小值，因此让 `r = mid`。循环的出口是 `l < r`

[154.寻找旋转排序数组的最小值II]([154. 寻找旋转排序数组中的最小值 II - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/))：这题相比于 **153题** 的区别在于现在数组中可能会包含重复的元素。👉 [<u>寻找旋转排序数组的最小值II</u>](二分/154%20寻找旋转排序数组的最小值II.cc)

下面提供两种二分查找的方法

1. 自己写的方法。跳过 `left` 左端的所有重复元素，然后判断 `left` 和 `right` 是否一样，如果一样的话 `right` 向左移动。之后就是 **153题** 的解法了
2. 直接在 **153题** 的基础上修改，唯一的区别在于现在当 `nums[mid] = nums[r]` 的时候并不能确定应该丢弃左半区间还是丢弃右半区间，但是唯一可以确定的是这个时候即便 `nums[r]` 是最小值，它也有替代值，因此 `--r`。其余的都和 **153题** 一样，当 `nums[mid] > nums[r]` 的时候 `l = mid + 1`。当 `nums[mid] < nums[r]` 的时候，由于 `nums[mid]` 也有可能是最小值，因此 `r = mid`。循环的出口是 `l < r`

### 对题目给出的目标属性进行二分查找

[373. 查找和最小的 K 对数字 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/find-k-pairs-with-smallest-sums/)：给你两个以升序排列的整数数组 `nums1` 和 `nums2`，以及一个整数 k，请你找到和最小的 k 对数对，并返回它们。👉 [解答](二分/373%20查找和最小的K对数字.cc)

这道题类似 **378题**

优先队列。我们可以把 `[0, {0, 1, ..., nums2.size() - 1}], [1, {0, 1, ..., nums2.size() - 1}], [nums1.size() - 1, {0, 1, ..., nums2.size() - 1}]`，看成 m 个链表，然后转化为 m 个链表求出最小的 k 对数对。这样初始的时候将每个链表的第一个元素放入小根堆，然后每次弹出一个元素，并将它的下一个元素放入堆中。循环条件：`while (k-- && !heap.empty()）`

时间复杂度：O(klogn)，n 是 nums2 的大小，空间复杂度 O(n)

同 **378题**，也可以使用二分查找。我们只需要找到满足「小于等于某个目标值的数对和的个数刚好大于等于 k」这样的数对和 `target_sum` 就可以了，然后从数组中首先将和小于 `target_sum` 的数对存入答案中，再按照下标索引的顺序将等于 `target_sum` 的数对和存入答案中

> 必须先存入小于 target_sum，再存入等于 target_sum，因为数对和等于 target_sum 的数对的个数可能会大于题目要求的 k。这个时候只有将小于 target_sum 的答案全都保存下来了，才可以考虑等于 target_sum 的答案

[378. 有序矩阵中第 K 小的元素 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/)：给你一个 n*n 的矩阵，其中每行和每列都是升序的，请你找出矩阵中第 k 小的元素值。👉 [有序矩阵中第K小的元素](二分/378%20有序矩阵中第K小的元素.cc)

1. 对所有的元素排序，然后返回第 k 小的元素。时间复杂度 O(n^2 * logn)，空间复杂度 O(n^2)
2. 优先队列 + k 指针。可以将 n*n 的矩阵看成是 n 个有序的数组，我们将每个数组的第一个「元素」放入到堆中，每次从堆中弹出最小的元素，然后将它的下一个元素压入堆中，当我们弹出了 k-1 个元素的时候，此时堆顶元素就是第 k 小的元素。时间复杂度 O(klogn)，空间复杂度 O(n)
3. 二分查找。我们确定二分查找的边界为 `[matrix[0][0], matrix[n - 1][n - 1]]`，然后每次取区间中间的值，在矩阵中找到有多少个元素是小于等于这个值的。具体的查找过程为：从最后一行出发，如果元素值小于目标值，那么就往右走并统计此时有 x + 1 个元素是小于目标值的（x 是此时所在的行号），如果元素值大于目标值就往上走。最后如果小于等于目标值的数量要大于等于 k，则右边界收缩，否则左边界收缩

[668. 乘法表中第k小的数 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/kth-smallest-number-in-multiplication-table/)：找到一个 m*n 的乘法表中第 k 小的数。👉 [解答](二分/668%20乘法表中第K小的数.cc)

解法和 **378题** 相同，确定二分查找的边界 `[1, m*n]` 在乘法表中恰好有 k 的数字小于等于某个值的目标值 target 就可以了

这道题不需要建立二维数组，因为对于乘法表来说，某一行小于等于某个值的元素个数为 `min(target / i, n)`

[719. 找出第 k 小的距离对 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/find-k-th-smallest-pair-distance/)：给定一个整数数组，返回所有数对之间的第K个最小距离，(A, B) 的距离被定义为 abs(A - B)。👉 [解答](二分/719%20找出第K小的距离对.cc)

通过二分查找找到某个距离 target，满足恰好有 k 个数对距离小于等于 target，此时返回 target 就是最后的答案

首先对 `nums` 排序，确定二分查找的边界为 `[0, nums[n - 1] - nums[0]]`，每次通过滑动窗口计算距离小于等于 `mid` 的数对的个数，如果 `count(nums, mid) >= k` -> `r = mid - 1`，否则的话 `l = mid + 1`

count 函数的计算方法有两种

1. 采用滑动窗口计算：当 `nums[r] - nums[l] >= target` 的时候需要收缩窗口。并且对于一个给定的 `r`，满足要求的数对的另一个值的个数是 `r - l`，即窗口中所有以 `r` 为第二个元素的数对都满足要求（因为 `nums[r] - nums[l] <= target`）
2. 采用前缀和计算：使用数组 `prefix` 表示对于一个给定的值 `v`，`prefix[v]` 表示数组中小于等于 `v` 的元素有多少个。另外对于一个数组中给定的元素 `v`，`repeat[v]` 表示 `v` 最后出现的位置。这样对于给定的 `mid` 来说，距离小于等于 `mid` 的数对的数量就等于 `(prefix[nums[i] + mid] - prefix[nums[i]]) + repeat[nums[]] - i`，其中前半部分表示不同元素组成的数对的个数，后半部分表示相同元素组成的数对个数

最后给出时间复杂度：

1. 如果采用滑动窗口计算 count 函数：O(nlog diff + nlogn)，log diff 是二分查找的次数，diff 是数组中最大值和最小值的差值，每次二分查找滑动窗口的时间复杂度都是 O(n)，因此整个查找的过程时间复杂度是 O(nlog diff)，最后再加上排序的时间复杂度
2. 如果采用前缀和计算 count 函数：O(max_value + diff + nlog diff + nlogn)，其中 diff 为数组中最大值和最小值的元素之差，max_value 为数组中的最大值，计算 prefix 数组的时候时间复杂度是 O(max_value + max_value - min_value)，排序的时间复杂度是 O(nlogn)，二分查找的时间复杂度是 O(nlog diff)，所以最后的时间复杂度是 O(max_value + diff + nlog diff + nlogn)

空间复杂度：

1. 如果采用滑动窗口计算 count 函数：O(1)
2. 如果采用前缀和计算 count 函数：O(max_value + diff + n)

[786. 第 K 个最小的素数分数 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/k-th-smallest-prime-fraction/)：给你一个按递增顺序排列的数组 `arr` 和一个整数 `k`。数组 `arr` 由 1 和若干素数组成，其中所有整数互不相同。对于每对满足 `0 <= i < j < arr.length` 的 `i` 和 `j`，可以得到分数 `arr[i] / arr[j]`，那么第 `k` 个最小的分数是多少呢，返回组成这个分数的 `arr[i]` 和 `arr[j]`。👉 [解答](二分/786%20第K个最小的素数分数.cc)

**二分查找**

对于所有可以组成的分数，我们可以将它排列成矩阵的一半，其中第 `i` 行是所有以 `arr[i + 1]` 为分母的分数，第 `i` 行第 `j` 列表示的分数是 `arr[j] / arr[i + 1]`，这样以来该矩阵满足从左到右单调递增、从上到下单调递减，此时这道题就转化为了 **378题**

将二分查找的左右边界设置为 `[0, 1]`，对于每个 `mid` 我们计算出小于等于这个浮点数的分数有多少个（`cnt`），并且在沿着矩阵查找的时候记录下 `res_x` 和 `res_y`，满足 `res_x / res_y` 是小于等于 `mid` 的最大分数

如果 `cnt == k`，返回 `{res_x, res_y}`；如果 `cnt < k`，`l = mid`；如果 `cnt > k`，`r = mid`

时间复杂度：O(nlogC)，n 是数组的长度，每次二分查找需要 O(n) 的时间复杂度；C 是数组的元素的最大值，最多需要进行 logC^2 的查找次数。所以最后的时间复杂度是 O(nlogC)

空间复杂度：O(1)

**堆**

将所有 `arr[i] / arr[n - 1]` 看成一个链表，链表的第一个元素就是 `arr[i] / arr[n - 1]`，链表的下一个元素是 `arr[i] / arr[n - 2]`，因此我们可以得到 `n - 1` 个链表。此时这道题就变成了 k 个有序链表求前 ? 最小的值，可以将所有链表的第一个元素放到堆中，每次弹出一个节点然后将它的下一个节点放入堆中

时间复杂度：O(klogn)，需要弹出 k 次，每次弹出之后插入元素的时间复杂度是 O(logn)

空间复杂度：O(logn)

[875. 爱吃香蕉的珂珂 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/koko-eating-bananas/)：有 `n` 堆香蕉，第 `i` 堆中有 `piles[i]` 根香蕉，警卫将在 `h` 小时候回来，珂珂吃香蕉的速度是 `k`，每个小时会选择一堆香蕉从中吃掉 `k` 根，如果这堆香蕉少于 `k` 根则会吃掉所有香蕉。请你计算珂珂在 `h` 小时之内吃完所有香蕉的最小速度 `k`。👉 [解答](二分/875%20爱吃香蕉的珂珂.cc)

对速度 `k` 进行二分查找，每次计算以 `mid` 速度吃完所有香蕉所需要的时间 `cnt`。如果 `cnt <= h`，则让 `r = mid - 1`，否则的话 `l = mid + 1`

时间复杂度：$O(nlogW)$，W 是所有堆中最多的香蕉数量

[1044. 最长重复子串 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/longest-duplicate-substring/)：给你一个字符串 `s`，返回任意一个具有最长长度的重复子串，如果 `s` 中不包含重复子串则返回 ""。👉 [解答](二分/1044%20最长重复子串.cc)

重复子串的长度最短为 1，最长为 `s.size()`，随着长度的增加出现重复的次数会减少，所有具有单调性。因此我们可以使用二分查找，找出最大的重复子串的长度

查找的方法可以直接暴力查找，时间复杂度是 O(nL)，L 是当前查找的子串的长度，如果采用暴力查找会超时。我们可以使用「滚动哈希」的方法进行优化：例如当前查找的子串长度为 `L`，我们可以 `s` 中所有长度为 `L` 的子串进行编码，具体的编码规则为 $c_0 * a^{L-1} + c_1 * a^{L - 2} + ... + c_{L - 1} * a^1$，`ci` 是子串中的字符，`a` 是随机的一个底数。如果有两个子串的编码相同，就说明出现了重复的子串，我们记录下当前子串的长度和起始位置，然后返回就可以了

如果前一个子串的编码为 $hash\_val$，则当前子串的编码为 $hash\_val * index - a^{L - 1} * s_{i - L} + s_i$

尽管上面说了编码的方法，但是实际编码的时候可能会溢出，因此需要取模，但是取模了之后不同子串的编码就会重复。此时可以使用两个底数计算子串的哈希值（两个哈希值来判断编码是否相同），以此来降低哈希冲突的概率，对于取模我们可以使用 `unsigned` 类型的整数，它们在溢出之后会自动取模

> `pair<>` 类型使用 `unordered_set` 的时候需要自己手动实现 hash function 函数对象，具体参考本题的代码
>
> [std::pair作为unordered_map的key_给我一瓶AC钙的博客-CSDN博客_pair作为map的key](https://blog.csdn.net/TDD_Master/article/details/99083702)

### 「...... 最大值最小」或「......最小值最大」

[410. 分割数组的最大值 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/split-array-largest-sum/)：给定一个非负整数数组 `nums` 和一个整数 `m`，你需要将这个数组分割成 `m` 个非空子数组，使得每个**子数组各自和**的最大值最小。👉 [解答](二分/410%20分割数组的最大值.cc)

**采用动态规划解决**

「数组分割为 m 段，求......」一般都可以用动态规划解决

`dp[i][j]` 表示将数组的前 `i` 个元素分割成 `j` 段，能获得的各自和最大值的最小值（后面简称最优值）。该问题可以转化为子问题：将前 `k` 个元素（`k < i`）分割成 `j - 1` 段，然后 `[k, i - 1]` 分割为第 `j` 段。所以 $dp[i][j] = min(max(dp[k][j - 1], sum(nums, k, i - 1))), j - 1 \leq k < i, j = min(i, m)$，在求 `sum` 的时候可以使用前缀和加速

时间复杂度：O(mn^2^)，空间复杂度：O(n * m)

**二分查找 + 贪心**

「使......的最大值尽可能小」一般可以用二分查找解决

对于数组 `nums` 来说，子数组和最大值的最小值的范围是 `[max_val,  sum_val]`，对于每一个区间内的值 `target` 可以采用贪心的方法计算出可以划分出子数组的数量：从前往后遍历 `nums`，如果当前连续子数组的和 `sum` 加上 `nums[i]` 大于 `target`，则增加子数组的数量，并让 `sum = nums[i]`，最后可以统计出以 `target` 为最大值可以划分出的子数组的数量

我们的目标是找到最小的 `target`，使得划分出的子数组的数量等于 `m`。划分子数组的数量随着 `target` 的变大是单调递减的，因此可以用二分查找找到最小的 `target`

[475. 供暖器 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/heaters/)：给出位于一条水平线上的房屋 `houses` 和供暖器 `heaters` 的位置，请你找出并返回可以覆盖所有房屋的最小加热半径。👉 [解答](二分/475%20供暖器.cc)

**二分**

对所有的供暖器进行排序，然后遍历每一个房屋，找到距离它最近的两个供暖器，房屋距离这两个供暖器距离的最小值就是这个房屋所需要的最小加热半径。最后取所有房屋最小加热半径的最大值作为供暖器的最小加热半径

我们可以使用二分查找找到房屋左侧最近的供暖器的下标 `idx`，此时 `idx + 1` 就是房屋右侧的第一个供暖器，通过计算这两个供暖器距离房屋的距离决定该房屋需要的最小加热半径

时间复杂度：$O(nlogn + mlogn)$，$m$ 是房屋的数量，$n$ 是供暖器的数量，空间复杂度：$O(logn)$

**双指针**

前面的二分方法中只对 `heaters` 数组进行了排序，我们也可以对 `heaters` 和 `houses` 数组都进行排序，然后依旧是找到每个房屋最近的供暖器

此时假如距离房屋 $i_0$ 最近的供暖器是 $j_0$，那么对于在 $i_0$ 右侧的房子 $i_1(i_1 > i_0)$ 距离它最近的供暖器 $j_1$ 必定满足 $j_1 \geq j_0$，因此可以使用双指针遍历 `houses` 和 `heaters`

时间复杂度：$O(mlogm + nlogn)$，空间复杂度：$O(logm + logn)$

[774. 最小化去加油站的最大距离 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/minimize-max-distance-to-gas-station/)：整数数组 `stations` 表示水平数轴上各个加油站的位置，给你一个整数 `k` 请你在数轴上增设 `k` 个加油站，加油站可以放在数轴上的任何位置而不必放在整数位置上。请你返回增设 ` k` 个加油站之后，相邻两个加油站之间的最大距离的最小值。👉 [解答](二分/774%20最小化去加油站的最大距离.cc)

**二分查找**

**410分割数组** 那题有提到过，「......最大值的最小值」通常可以使用二分查找，本题采取和 **410题** 相同的思路

对于每一个给定的相邻加油站之间的「最大距离的最小值」`target`，计算需要增设多少个新的加油站才可以达到该要求，每两个相邻加油站需要增设的新加油站的数量是 `diff/target`，然后判断整体上新增的加油站数量 `count` 是否超过 `k` 个。对于给定的 `target` 关于新增加油站数量 `count` 是单调递减的，因此可以通过二分查找计算「最大距离的最小值」，如果 `count <= k` 则收缩右边界 `r = mid`，否则的话收缩左边界 `l = mid`

由于是浮点数二分查找永远不会终止，所以在 `r - l < 10^-6` 的时候退出循环，返回此时的 `l` 或者 `r` 就是最终「相邻加油站之间距离最大值的最小值」

时间复杂度：$O(NlogW)$，其中 W 是数组的最大值，空间复杂度：$O(1)$

**堆**

堆中存放 `<diff_i, count_i>` 表示第 `i` 个原始加油站间隔的距离是多少，当前这个间隔里面有多少个加油站。每次从堆中弹出 `diff_i/count_i` 最小的元素，然后增加一个加油站数量，放回堆中

时间复杂度：$KlogN$，空间复杂度：$O(N)$。本题该方法会超时

**动态规划**

定义 $dp[i][j]$ 表示增加 `j` 个加油站之后前 `i` 个间隔获得的最小的最大距离，这个问题可以分解为子问题：将 `x` 个加油站放在第 `i` 个间隔，那么剩余的 `j-x` 个加油站就需要放到前 `i-1` 个间隔中，所以可以得到状态转移方程：
$$
dp[i][j] = min(diff[i] / x, dp[i - 1][j - x]), 0 \leq i \leq n-1, 0 \leq j \leq k
$$
时间复杂度：$O(NK^2)$，空间复杂度：$O(NK)$

[1011. 在 D 天内送达包裹的能力 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/capacity-to-ship-packages-within-d-days/)：给出一组包裹，`weights[i]` 表示第 `i` 个包裹的重量，返回能在 `days` 天内将传送带上的所有包裹送达的船的最低运载能力。👉 [解答](二分/1011%20在D天内送达包裹的能力.cc)

这道题目的意思等价于：将数组 `weights` 分成 `days` 段，求出每段数组和的最大值的最小值。**410题** 做的就是这个事情，因此这道题和 **410题** 完全一样

[1231. 分享巧克力 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/divide-chocolate/)：你有一大块巧克力，它由一些甜度不完全的小块组成，我们用数组 `sweetness` 表示每一小块的甜度，你打算和 `K` 名朋友一起分享巧克力，所以需要将巧克力分为 `K + 1` 块，你将会吃掉总甜度最小的一块，请你找出最佳的切割策略，使得你所分得的巧克力的总甜度最大，并返回这个最大总甜度。👉 [解答](二分/1231%20分享巧克力.cc)

典型的「......最小值最大」，这道题的解法类似于 **1552题**。我们需要找到甜度最小的巧克力 `res`，使得可以将所有的巧克力分为甜度大于等于 `res` 的 `K + 1` 块

确定二分查找的边界为 $[min_{sweetnexx}, sum_{sweetness}]$，对于最小甜度 `mid` 来说，计算可以将巧克力分为 `cnt` 块。如果 `cnt > k + 1` 则表明此时的最小甜度太小了，因此 `l = mid + 1`；如果 `cnt < k + 1` 则表明此时的最小甜度太大了，因此 `r = mid - 1`；如果 `cnt == k + 1` 由于我们需要尽可能的让最小甜度最大，因此 `l = mid + 1`

最后二分查找结束的时候 `l` 就是满足题目要求的「最小甜度的最大值」

时间复杂度：$O(NlogS)$，二分查找需要进行 $logS$ 次，每次需要遍历 `sweetness` 数组，空间复杂度：$O(1)$

[1552. 两球之间的磁力 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/magnetic-force-between-two-balls/)：给你 `n` 个篮子，`m` 个球，请将 `m` 个球放入 `n` 个篮子中使得相邻两个球之间最小距离最大化。👉 [解答](二分/1552%20两球之间的磁力.cc)

「......最小值的最大值」这类问题和「......最大值的最小值」是一样的，都可以使用二分查找来解决，本题是求两个之间距离最小值的最大值

首先对篮子的位置进行排序，这样相邻两个球之间距离的左右边界就是 `[1, position[n - 1] - position[0]]`，对于某个距离 `mid`，我们可以统计当按照最小距离是 `mid` 的时候篮子中最多可以放几个球。具体的统计方法为贪心的思想：第一个球放在第一个篮子中，第二个球放在距离刚好大于等于第一个球的篮子中，以此类推

由于最多可以放置的球的数量随最小距离的值是单调递减的，如果对于距离 `mid` 统计出来可以放置的球的数量 `count >= m` 则尝试将距离增大，即 `l = mid + 1`，否则的话将距离减小，即 `r = mid - 1`

最后二分查找结束时候 `r` 就是最小距离的最大值

时间复杂度：$O(nlogn + nlogK)$，其中 $nlogn$ 是对篮子排序的时间复杂度；$K$ 是两个篮子距离的最大值，二分查找的次数是 $logK$ 次，每次需要遍历所有的篮子，因此二分查找总的时间复杂度是 $nlogK$，最终的时间复杂度就是 $nlogn + nlogK$

空间复杂度：$O(logn)$，仅仅是排序的空间复杂度

### 子序列

[300.最长递增子序列]([300. 最长递增子序列 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/longest-increasing-subsequence/))：给你一个整数数组 `nums`，找到其中最长严格递增的子序列长度。👉 [<u>最长严格递增子序列</u>](二分/300%20最长递增子序列.cc)

进阶：你可以将算法的时间复杂度降低到 `O(nlogn)` 吗

1. 最直接的使用动态规划来解决该问题。`dp[i]` 表示以 `nums[i]` 为结尾的子序列的最长长度。计算 `dp[i]` 的时候需要向前寻找 `j` 满足 `nums[j] < nums[i], dp[i] = max(dp[i], dp[j] + 1)`。时间复杂度 `O(n^2)`
2. 贪心 + 二分。贪心策略：要使得子序列尽可能的长，只要我们的子序列上升的足够慢即可。使用数组 `vec[len]` 表示长度为 `len` 的子序列的最后一个元素值。遍历 `nums` 数组，如果 `nums[i] > vec[len]`，此时子序列的长度可以增加一个 `vec[++len] = nums[i]`；否则的话就需要在 `vec` 数组中找到第一个大于 `nums[i]` 的元素，更新其值为 `nums[i]`（保证子序列上升的足够慢）

[354. 俄罗斯套娃信封问题 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/russian-doll-envelopes/)：给你一个二维整数数组 `envelopes`，其中 `envelopes[i] = [wi, hi]`，表示第 `i` 个信封的宽度和高度。当另一个信封的宽度和高度都比这个信封大的时候，这个时候就可以放进另一个信封里面。请计算最多能有多少个信封能组成一组套娃信封。👉 [解答](二分/354%20俄罗斯套娃信封问题.cc)

我们可以考虑当 `wi <= wj, i < j` 的时候，这个时候由于前面信封的宽度一定是小于等于后面信封的，那么前面信封能不能装进后面信封的问题就变成了一个最长子序列的问题。我们对 `hi` 需要按照递减的顺序排列，否则的话就会将宽度一样的信封装在一起了

因此该问题的解决方法如下：

1. 对所有的信封按照宽度从小到大，高度从大到小排序
2. 转变为一个最长递增子序列问题，可以使用动态规划或者二分查找 + 贪心的方法解决

### 子串/子数组

[1574. 删除最短的子数组使剩余数组有序 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/)：给你一个整数数组 `arr`，请你删除一个连续的子数组（可以为空），使得剩下的元素是非递减的，请你返回最短子数组的长度。👉 [<u>删除最短的子数组使剩余数组有序</u>](二分/1574%20删除最短的子数组使剩余数组有序.cc)

首先找到左边开始递减的位置 `left`，以及右边开始递减的位置`right`。然后查找 ` arr[:left]` 在 `arr[right:]` 中出现的位置 `idx`， `idx - i - 1` 即为要删除的长度

注意初始的时候 `res` 需要设置为 `r`，表示默认 `r` 左边的子数组都需要删除

### 重复数问题

[169.多数元素](https://leetcode-cn.com/problems/majority-element/)：给定一个大小为 `n` 的数组，找到其中的多数元素，即出现次数大于 `n/2` 的元素。👉 [<u>多数元素</u>](hot100/169%20多数元素.cc)

有以下几种方法可以解决该问题：

1. 哈希。使用一个 `unordered_map<int, int>` 记录每个元素出现的次数，如果一个元素出现的次数大于 `n/2` 则返回该元素。时间复杂度 `O(n)`，空间复杂度 `O(n)`
2. 排序。对 `nums` 数组排序，然后返回数组的中间元素，即 `nums[nums.size()/2]`。时间复杂度 `O(nlogn)`，空间复杂度 `O(logn)`
3. 分治。如果元素 `target` 为众数，那么将 `nums` 分为两部分，`target` 必定为某一部分的众数，可以用反证法证明该理论，即假设 `target` 不是这两部分的众数，最后可以得出 `target` 不是 `nums` 的众数，与假设矛盾
   - 记左半部分的众数为 `target1`，右半部分区间的众数为 `target2`。此时只需要遍历左半部分区间和右半部分区间统计 `target1` 的数量和 `target2` 的数量即可知道 `target1` 和 `target2` 哪个是 `nums` 的众数了
   - 当区间长度为 `1` 的时候，直接返回该元素即可
   - 时间复杂度 `O(n)`，空间复杂度 `O(1)`
4. 投票。如果已知某一个数是众数，那么我们遇到该数的时候对计数值 `count` 加一，遇到不是该数的时候对计数值减一，最后 `count` 的值必定大于 0。基于该理论，初始时 `count = 0`。然后开始扫描数组元素，如果 `count = 0` 则目标数 `target = nums[i]` 并增加 `count`。如果后续遍历到和 `target` 相等的元素则 `count++`，否则 `count--`。时间复杂度 `O(n)`，空间复杂度 `O(1)`

[268. 丢失的数字 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/missing-number/)：给定一个包含 `[0, n]` 中 `n` 个数的数组 `nums`，请找出 `[0, n]` 这个范围内没有出现在数组中的那个数。👉 [解答](二分/268%20丢失的数字.cc)

**排序 + 二分**

先对 `nums` 数组进行排序，如果下标 `i` 对应的数字 `i` 丢失了，此时 `nums[i] > i`，因此可以使用二分查找找到第一个满足 `nums[i] > i` 的下标，该下标就是丢失的数字

时间复杂度：$O(nlogn)$，空间复杂度 $O(logn)$

**位运算**

首先将 `nums` 数组中的所有数亦或到一起，然后再亦或 `[0, n]` 中的数，最后的结果就是丢失的数字

[剑指 Offer 53 - II. 0～n-1中缺失的数字 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof/)：一个长度为 `n - 1` 的递增排序的数组中，所有的数字都是唯一的，并且每个数字都在反胃 0 到 n - 1 之间，请你找出 0 到 n - 1 之间不再数组中的那个数字。👉 [解答](二分/剑指Offer%2053-II%200~n-1中缺失的数字.cc)

二分查找找到第一个 `nums[i] > i` 的那个下标就是缺失的那个数字

[287.寻找重复数]([287. 寻找重复数 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/find-the-duplicate-number/))：给定一个包含有 `n + 1` 个整数的数组 `nums`，其数字都在 `[1, n]` 范围内，因此至少存在一个重复的数字。假设 `nums` 只有一个重复的整数，找出这个整数，你的解决方案必须不修改数组 `nums` 并且只用常量级 `O(1)` 的额外空间。👉 [<u>寻找重复数</u>](287%20寻找重复数.cc)

**二分查找**

假设重复的数字是 `target`，使用 `cnt[i]` 表示数组中小于等于 `i` 的元素出现的次数。因此当 `1 <= i <= target - 1` 的时候，`cnt[i] <= i`；当 `i >= target` 的时候，`cnt[i] > i`

- 最简单直接的就是 `[1, target - 1]` 重的数字都出现了一次，然后 `target` 出现了两次，然后 `[target + 1, n]` 之间的数字出现了一次。这样的话，当 `i < target` 的时候，`cnt[i] = i`；当 `i == target` 的时候，`cnt[i] > i`；当 `i > target` 的时候，`cnt[i] > i`
- 然后如果 `target` 出现了超过一次，那么 `[1, n]` 中的数字必定有些数字没有出现。如果这些数字中有小于 `target` 的数字，那么当 `i < target` 的时候 `cnt[i] < i`；如果这些数字中有大于 `target` 的数字，那么当 `i > target` 的时候 `cnt[i]` 依旧大于 `i`

综上所述，只要 `i < target`，`cnt[i] <= i`；只要 `i >= target`，`cnt[i] > i`

所以 `cnt` 数组形成了一个单调递增的序列，前面有一部分满足 `cnt[x] <= x`，后面一部分满足 `cnt[x] > x`，我们的目标就是找到这个分界点，即第一个满足 `cnt[x] > x` 的 `x`。因此可以使用二分查找完成该任务

时间复杂度 `O(nlogn)`

**位运算**

本题还可以使用位运算的思想。对于一个给定的数字集，每个数字只出现一次，这样的话可以知道每一个比特上面出现的 `1` 的总数

我们假设原来 `[1, n]` 中第 `bit` 个比特上出现的 `1` 的总数为 `x`，现在将 `[1, n]` 考虑又加进来一个数字 `target`

- 如果 `target` 第 `bit` 个比特上是 `0`，如果 `target` 在 `nums` 中只出现两次，那么最后第 `bit` 位上的 `1` 的总数 `y` 满足 `y = x`；如果 `target` 在 `nums` 中出现了大于两次（此时需要替换某些元素），那么最后第 `bit` 位上的 `1` 的总数 `y` 满足 `y <= x`。因此最后满足 `y <= x`
- 如果 `target` 第 `bit` 个比特上是 `1`，如果 `target` 在 `nums` 中只出现了两次，那么最后第 `bit` 位上 `1` 的总数 `y` 满足 `y > x`；如果 `target` 在 `nums` 中出现了大于两次（此时需要替换某些元素），那么最后第 `bit` 位上 `1` 的总数 `y` 满足 `y > x`。因此最后满足 `y > x`

综上所述，我们只需要统计第 `bit` 位上 `1` 的个数 `y`，和原来的 `[1, n]` 上第 `bit` 位上 `1` 的个数 `x` 进行对比，如果 `y > x` 就说明 `target` 第 `bit` 位的值为 `1`，否则就是 `0`。最后按位拼接到一起就可以得出 `target` 的值

时间复杂度 `O(nlogn)`，其中 `logn` 是求出 `n` 的最大比特位的值 `bitmax`，然后循环 `bitmax`

**快慢指针**

本题还可以使用双指针（快慢指针）的方法来解决。首先如果不存在重复的元素例如 `[1, 3, 4, 2]`，以下标 `n` 和 `nums[n]` 建立映射我们可以得到 `1->3->2->4->nullptr`。现在出现了一个重复的元素，此时必定会存在环

[540. 有序数组中的单一元素 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/single-element-in-a-sorted-array/)：给你一个仅由整数组成的有序数组，其中每个元素都会出现两次，只有一个元素只会出现一次，请你找出这个元素，要求必须使用 $O(logn)$ 的时间复杂度和 $O(1)$ 的空间复杂度。👉 [解答](二分/540%20有序数组中的单一元素.cc)

当没有单一数字的时候，对于每一个元素，第一个出现的位置是在奇数位置，第二个出现的位置是在偶数位置。一旦出现一个单一元素，该元素后面的每对重复元素，第一个元素出现在偶数位置，第二个元素出现在奇数位置

所以我们可以利用这个特性来判断给定下标 `mid` 和单一元素的左右关系，通过二分查找确定单一元素的下标，得到单一元素的值

[1060. 有序数组中的缺失元素 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/missing-element-in-sorted-array/)：有一个按照升序排列的整数数组 `nums`，其中每个数字都不相同，给你一个整数 `k`，请你找出并返回从数组最左边开始第 `k` 个缺失数字。👉 [解答](二分/1060%20有序数组中的缺失元素.cc)

我们可以计算出 `nums[i]` 前面缺失元素的个数为 `nums[i] - nums[0] + 1 - (i + 1) = nums[i] - nums[0] - i`，因此我们可以通过二分查找确定比第 `k` 的缺失数字大的数字在 `nums` 数组中的下标：如果 `nums[mid] - nums[0] - mid >= k`，`r = mid - 1`，否则的话 `l = mid + 1`

当二分查找结束的时候我们就找到了 `nums` 中比第 `k` 个缺失数字大的那个元素下标，我们计算到该元素的前一个元素为止一共丢失了多少个数字 `cnt = nums[l - 1] - nums[0] - (l - 1)`

最后第 `k` 个缺失数字就是 `nums[l - 1] + k - cnt`

### 数组查找问题

[4.寻找两个正序数组的中位数](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/)：给定两个正序数组 `nums1` 和 `nums2` 找出并返回两个正序数组的中位数，时间复杂度要求小于等于 `O(log(m + n))`。👉 [<u>寻找两个正序数组的中位数</u>](./二分/4%20寻找两个正序数组的中位数.cc)

如果题目没有要求时间复杂度小于等于 `O(log(m + n))`，那么可以采用以下两种方法

- 合并 `nums1` 和 `nums2`，然后返回合并之后数组的中位数。时间复杂度 `O(m + n)`，空间复杂度 `O(m + n)`
- 不需要合并，使用两个指针分别指向两个数组的起始位置，每次将元素值较小的那个指针向后移动一个位置。时间复杂度 `O(m + n)`，空间复杂度 `O(1)`

还可以采用二分查找的方法。如果 `m + n` 是奇数，那么中位数是合并之后数组的「第 `(m + n + 1) >> 1`」个元素；如果 `m + n` 是偶数，那么中位数就是「第 `(m + n) >> 1`」和「第 `(m + n) >> 1 + 1`」个元素的平均值。记 `k` 表示需要查找合并之后数组的第 `k` 个元素

我们可以判断 `pivot1 = nums1[k/2 - 1]` 和 `pivot2 = nums2[k/2 - 1]` 的大小

- `if pivot1 < pivot2`，由于 `nums1[k/2 - 1]` 和 `nums2[k/2 - 1]` 前面都有 `k/2 - 1` 个元素，那么 `nums1[k/2 - 1]` 在合并之后数组中的位置最大为 `第 k/2 - 1 + k/2 - 1 + 1 <= k - 1`。因此 `nums1[0...k/2-1]` 全都可以跳过，因此 `nums1` 数组从 `nums1[k/2]` 开始
- 同理 `if pivot1 > pivot2`，跳过 `nums2[0...k/2-1]`，`nums2` 数组从 `nums2[k/2]` 开始
- 如果 `pivot1 == pivot2`，转化为第一种或者第二种其中一种情况处理即可

实际代码处理的时候有一些特殊情况需要处理

- 在计算 `nums1[idx1 + k/2 - 1]` 的时候 `idx1 + k/2 - 1` 有可能越界了，此时 `new_idx1 = min(idx1 + k/2 - 1, m - 1)`；`idx2` 的处理方式同理。这里 `new_idx` 表示需要计算比较的 `pivot` 的下标，而不是下一轮二分查找时候到的起始下标，下一轮二分查找的起始下标等于 `new_idx + 1`
- 由于 `idx` 的更新不总是等于 `idx + k/2 - 1 + 1`，因此 `k` 每次需要删除 `new_idx - old_idx + 1` 个元素，即每次更新 `k -= new_idx - old_idx + 1` 
- 每一轮二分查找之后需要判断 `idx1 == m`，此时返回 `nums2[idx2 + k - 1]`；同理判断 `idx2 == n`，返回 `nums1[idx1 + k - 1]`
- 如果 `k == 1`，返回 `min(nums1[idx1], nums2[idx2])`

[34.在排序数组中查找元素第一个和最后一个位置](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/)：给你一个按照升序排列的数组 `nums`，和一个目标值 `target`，找出给定目标值在数组中出现的第一个和最后一位置，如果不存在返回 `[-1,-1]`。👉 [<u>在排序数组中查找元素第一个和最后一个位置</u>](二分/34%20在排序数组中查找元素的第一个和最后一个位置.cc)

- 对于第一个出现的位置，当 `nums[mid] == target` 的时候，`r = mid - 1`，最后返回 `l == nums.size() || nums[l] != target ? -1 : l`
- 对于最后一个出现的位置，当 `nums[mid] == target` 的时候，`l = mid + 1`，最后返回 `r < 0 || nums[r] != target ? -1 : r`

[35. 搜索插入位置 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/search-insert-position/)：给定一个排序数组和一个目标值，在数组中查找目标值，并返回索引，如果没有找到的话返回目标值插入数组中的索引。👉 [解答](二分/35%20搜索插入位置.cc)

查找第一个大于等于目标值索引

[74. 搜索二维矩阵 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/search-a-2d-matrix/)：给你一个矩阵，其中矩阵的每一行是递增的并且下一行的第一个元素大于前一行的最后一个元素。现在给你一个目标值 `target`，判断矩阵中是否存在目标值。👉 [搜索二维矩阵](二分/74%20搜索二维矩阵.cc)

1. 二分查找。首先对行做二分查找，找到最后一个小于 target 的元素，如果没有找到的话直接返回 false。然后在该行内进行二分查找。时间复杂度 O(logm + logn)
2. Z 字型查找，从矩阵的右上角开始，如果 `matrix[x][y] > taregt` 则说明这一列中不会有答案，我们让 --y；如果 `matrix[x][y] < target` 则说明这一列中可能会有答案，我们让 ++x；如果 `matrix[x][y] == target` 返回 true

[162.寻找峰值]([162. 寻找峰值 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/find-peak-element/))：给你一个整数数组 `nums`，保证 `nums[i] != nums[i + 1]`，请你找出数组中峰值元素的下标。👉 [<u>寻找峰值</u>](二分/162%20寻找峰值.cc)

对于一个给定的元素，如果 `nums[i] < nums[i + 1]` 那么说明 `i` 的右侧必定存在一个峰值，如果 `nums[i] > nums[i + 1]` 那么就说明 `i` 的左侧一定有一个峰值

因此，如果 `nums[i] < nums[i + 1]`，我们就向右遍历；如果 `nums[i] > nums[i + 1]`，我们就向左遍历。这样的话刚好可以用类似二分查找的方法进行遍历

[436. 寻找右区间 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/find-right-interval/)：给你一个区间数组 `intervals`，找到每个区间的右侧区间，右侧区间的起始位置刚好大于给定的区间，并且是最小的。👉 [解答](二分/436%20寻找右区间.cc)

首先对 `intervals` 中所有区间的 `start` 和区间的下标 `i` 组合到一起的数组 `vec` 进行排序，然后遍历 `intervals` 通过二分查找找到 `vec` 中第一个大于等于 `intervals[i][1]` 的元素下标 `l`。如果 `l == vec.size()` 则说明不存在右侧区间，否则的话 `vec[l][1]` 就是右侧区间在原数组中的下标

时间复杂度：$O(nlogn)$，空间复杂度：$O(n)$

[658. 找到 K 个最接近的元素 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/find-k-closest-elements/)：给定一个排好序的数组 `arr`，两个整数 `x` 和 `k`，从数组中找到最靠近 `x` 的 `k` 个数，返回的结果必须是按升序排好的。👉 [解答](二分/658%20找到K个最接近的元素.cc)

二分查找找到第一个大于等于 `x` 的元素下标，然后使用双指针找到 `k` 个结果

1. 双指针从中间向两端扩展，初始的时候 `pA = l - 1`，`pB = l`，然后不停的判断 `abs(arr[pA] - x) > abs(arr[pB] - x)` 收缩区间
2. 双指针从两端往中间收缩，初始的时候由于并不知道 `arr[l]` 和 `arr[l - 1]` 哪个元素更加接近 `x`，因此 `pA = l - k`，保证 `[pA, l - 1]` 之间的元素都有可能是结果集；`pB = l + k - 1`，保证 `[l, pB]` 之间的元素也都有可能是结果集。然后不断的判断 `abs(arr[pA] - x) > abs(arr[pB] - x)` 收缩区间

时间复杂度：$O(logn + k)$，空间复杂度：$O(k)$

[852. 山脉数组的峰顶索引 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/peak-index-in-a-mountain-array/)：找出山脉数组的峰顶元素的下标。👉 [解答](二分/852%20山脉数组的峰顶索引.cc)

判断 `nums[mid]` 和 `nums[mid - 1]`，更新 `l` 和 `r`

[1095. 山脉数组中查找目标值 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/find-in-mountain-array/)：给你一个山脉数组，数组满足前半部分元素严格单调递增，后半部分元素满足严格单调递减。现在请你在不超过 100 次访问数组元素的情况下，找出给定目标值 `target` 在数组中出现的最小下标，数组长度最长为 10000。👉 [山脉数组中查找目标值](二分/1095%20山脉数组中查找目标值.cc)

1. 先使用二分找到山峰元素
2. 在山峰的左半部分二分查找 target
3. 上一步如果没有找到，在山峰的右半部分查找 taregt

### 数学

[50. Pow(x, n) - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/powx-n/)：实现 `pow(x, n)`，计算 `x` 的 `n` 次幂函数。👉 [解答](二分/50%20Pow(x,n).cc)

快速幂。递归计算 `tmp = Pow(x, n / 2)`，如果 `n` 是偶数，返回 `tmp * tmp`，否则的话返回 `tmp * tmp * x`

[69.x的平方根]([69. x 的平方根 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/sqrtx/))：给你一个非负整数 `x`，计算并返回 `x` 的算术平方根，结果只保留整数部分。不允许使用内置函数直接计算。👉 [<u>x的平方根</u>](二分/69%20x的平方根.cc)

1. 可以选择直接顺序遍历 `i * i <= x` 找到 `i` 返回即可

可以优化为二分查找 `left = 1, right = x`，每次判断 `mid * mid <= x, left = mid + 1`，否则 `right = mid - 1`，最后返回 `left - 1`

需要注意的是 `mid = (left + right) >> 1` 不能这么计算，这样会溢出；也不能 `mid = left + (right - left) >> 1`，这样会超时；只能 `mid = left + (right - left) / 2`

另外 `mid * mid` 需要先将一个 `mid` 转化为 `uint64_t` 这样两个 `mid` 的乘积就是 `uint64_t` 的，否则的话还是 `int` 类型会溢出

[367. 有效的完全平方数 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/valid-perfect-square/)：给你一个正整数 `num`，编写一个函数判断 `num` 是不是完全平方数，不能使用内置库。👉 [解答](二分/367%20有效的完全平方数.cc)

通过二分查找找到第一个 `mid * mid >= num` 的数，判断 `mid * mid` 是否等于 `num`

[441. 排列硬币 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/arranging-coins/)：总共有 `n` 个硬币，对于一个由 `k` 行组成的阶梯，其第 `i` 行正好有 `i` 枚硬币，阶梯的最后一行可能是不完整的，计算可以形成完整阶梯行的总行数。👉 [解答](二分/441%20排列硬币.cc)

二分查找行数，找到最大的硬币数量小于等于 `n` 的行数就是最后可以形成完整阶梯行的总行数，左边界为 `1`，右边界为 `n`

[878. 第 N 个神奇数字 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/nth-magical-number/)：一个正整数如果能被 `a` 或 `b` 整除，那么它是神奇的，给定三个整数 `n`，`a`，`b`，返回第 `n` 个神奇的数字，答案对 `10^9 + 7` 取模。👉 [解答](二分/878%20第N个神奇数字.cc)

解法和 **1201题** 相同，重点是求 `gcd` 和 `lcm`

[1201. 丑数 III - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/ugly-number-iii/)：给你四个整数 `n`，`a`，`b`，`c`，请你设计一个算法来找出第 `n ` 个丑数，丑数是可以被 `a` 或 `b` 或 `c` 整除的正整数。👉 [解答](二分/1201%20丑数III.cc)

可以使用二分查找找到前面刚好有 `n` 个丑数的最小整数，这个整数就是第 `n` 个丑数，具体的查找方法为：对于一个给定的数 $target$，它前面的丑数个数有：
$$
target / a + target/b + target / c - target / LCM(a, b) - target / LCM(b, c) - target / LCM(a, c) + target / LCM(a, b, c)
$$
所以这道题就转变为了求任意两个数和三个数的最小公倍数问题，首先对于两个数的最小公倍数可以通过最小公约数 `gcd(a, b)` 来求出它们的最小公倍数 `lcm(a, b) = a * b / gcd(a, b)`。对于 `a, b, c` 三个数的最小公倍数，可以转化为 `lcm(a, b)` 和 `c` 的最小公倍数，这样就是两个数的最小公倍数

> 丑数问题也可以使用堆来解决

### 随机

[528. 按权重随机选择 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/random-pick-with-weight/)：给你一个从下标 0 开始的正整数数组 `w`，其中 `w[i]` 表示第 `i` 个下标的权重。请你实现函数 `pickIndex`，它可以随机的从范围 `[0, w.length - 1]` 选出一个下标，选取下标 `i` 的概率为 `w[i] / sum(w)`。👉 [解答](二分/528%20按权重随机选择.cc)

我们可以在 `[1, sum(w)]` 上产生随机数 `r`，然后根据 `r` 的范围来输出对应的下标。例如 `[1, 3, 3]`，下标 0 对应的范围是 [1, 1]，下标 1 对应的范围是 [2, 4]，下标 2 对应的范围是 [5, 7]，可以看到每个下标范围的最大值刚好是一个前缀和，我们可以通过二分查找来快速找到大于等于 `r` 的最小的下标

[710. 黑名单中的随机数 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/random-pick-with-blacklist/)：给定一个整数 `n` 和一个无重复黑名单整数数组 `blacklist`。设计一种算法，从 `[0, n - 1]` 范围内的任意整数中选取一个未加入黑名单 `blacklist` 的整数，任何在上述范围内切不在黑名单中的整数都应该有同等的可能性被返回。👉 [解答](二分/710%20黑名单中的随机数.cc)

**二分**

我们可以确定在黑名单之外的整数有 `n - blacklist.size()` 个，然后可以产生随机数 `num` 表示黑名单之外的整数的下标，即第 `num` 个

为了找到黑名单之外的第 `num` 个整数，我们可以遍历 `blacklist` 中的每一个数，确定它前面有多少个不在名单中的数，对于 `blacklist[i]`，它前面不在名单中的数有 `blacklist[i] - i` 个

因此只要找到了第一个满足 `blacklist[i] - i >= num` 的整数就可以确定名单外的第 `num` 个数是：`blacklist[i] - (blacklist[i] - i - num + 1) = num + i - 1`（在名单中没有找到满足条件的 `blacklist[i]` 也是一样的）

时间复杂度：初始化的时间复杂度是 $O(mlogm)$，每次 pick 操作的时间复杂度是 $O(logm)$，空间复杂度：$O(logm)$

**哈希**

由于白名单中元素的数量是确定的，有 `n - blacklist.size()` 个。由于 `[0, white_size)`  中有元素是黑名单中的元素，此时可以将这其中存在于黑名单中的元素映射到 `[white_size, n)` 中白名单上的元素，这样我们只需要在 `[0, white_size)` 中产生随机数，然后判断该元素是否存在映射，如果存在的话就返回映射的元素，否则就返回原来的数

具体映射的方法：首先将 `[white_size, n)` 中的所有元素加到 `hash_set` 中，然后遍历 `blacklist` 在 `hash_set` 中删除存在于 `blacklist` 中的元素，此时 `hash_set` 中剩余的元素都是大于 `white_size` 存在于白名单中的元素。然后再次遍历 `blacklist` 如果元素的值小于 `white_size`，则在 `hash_map` 中将该元素按顺序映射到 `hash_set` 中的元素

时间复杂度：初始化的时间复杂度是 $O(m)$，$m$ 是 blacklist 的长度，pick 操作的时间复杂度是 $O(1)$；空间复杂度：$O(m)$

### 动态规划 + 二分

[887. 鸡蛋掉落 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/super-egg-drop/)：给你 `k` 枚相同的鸡蛋，以及一栋有 `n` 层高的楼，现在请你找出鸡蛋在哪一层楼 `f` 掉落刚好会碎。你可以尝试将鸡蛋在某一层扔下，如果鸡蛋没有碎则可以再次尝试，请返回需要尝试的最小次数。👉 [解答](二分/887%20鸡蛋掉落.cc)

初始的时候我们的状态为 `(k, n)` 表示有 `k` 个鸡蛋，`n` 层楼需要尝试。如果我们将鸡蛋从某一层楼 `x` 扔下去，则鸡蛋可能会碎，如果鸡蛋碎了则说明我们需要在 `[1, x-1]` 层楼继续尝试，此时我们的状态变为 `(k - 1, x - 1)`。如果鸡蛋没有碎，则说明我们需要在 `[x + 1, n]` 层楼继续尝试，此时我们的状态变为 `(k, n - x)`

所以对于我们的某个尝试，可能会产生两种结果，两种结果其实是一个递归的子问题。由于 `f` 的值我们并不知道，所以我们需要选择最坏的、也就是需要尝试次数最多的那个结果，这样可以保证无论 `f` 为什么值，计算得到的次数总是最小值。综上分析，如果我们使用 `dp(k, n)` 表示拥有 `k` 个鸡蛋、有 `n` 层楼需要尝试的情况下最少需要多少「尝试次数」才可以找出「鸡蛋刚好会碎的楼层」，则当我们在任意一层 `x` 扔下鸡蛋后 `dp(k, n) = max{dp(k - 1, x - 1), dp(k, n - x)}`，`x` 在 `[1, n]` 之间

`x` 可以在 `[1, n]` 之间任意取值，必定会存在某一个 `x`，`dp(k, n)` 是最小的。所以 `dp(k, n) = min (max{dp(k - 1, x - 1), dp(k, n - x)}), 1 <= x <= n`

`dp(k - 1, x - 1)` 是一个单调递增的函数，`dp(k, n - x)` 是一个单调递减的函数，上述状态转移方程表示成图像就类似下面这样，其中 T1 就是递增的那个函数，T2 就是递减的那个函数，蓝色线条表示的就是状态转移方程函数。我们需要找到这两个函数的交点，就是 `dp(k, n)` 的最小值，由于交点左侧 `T2 - T1 > 0`，交点右侧 `T2 - T1 < 0`，因此可以使用二分查找来找到这个交点左右两侧的离散点，进而确定 `dp(k, n)` 的最小值

<img src="https://assets.leetcode-cn.com/solution-static/887_fig1.jpg" alt="fig1" style="zoom: 25%;" />

[1235. 规划兼职工作 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/maximum-profit-in-job-scheduling/)：这里有 `n` 份兼职工作，每份工作预计从 `startTime[i]` 开始到 `endTime[i]` 结束，报酬为 `profit[i]`，重叠的工作不能同时进行，请你计算可以获得的最大报酬。👉 [解答](二分/1235%20规划兼职工作.cc)

使用 $dp[i]$ 表示考虑兼职工作 $i$ 可以获得的最大报酬，此时有两种选择：1. 执行第 $i$ 份工作，那么就需要向前找到第一个不和第 $i$ 份工作重叠的工作 $j$，获得的报酬就是 $dp[j] + profit[i]$；2. 不执行第 $i$ 份工作，获得的报酬和 $dp[i - 1]$ 相等。因此状态转移方程为：
$$
dp[i] = max(dp[j] + profit[i], dp[i - 1])
$$
在计算 `dp` 数组之前我们需要先按照 endTime 对所有工作进行排序，向前查找不重叠的工作可以使用二分查找加快查询速度
[2008. 出租车的最大盈利 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/maximum-earnings-from-taxi/)：你驾驶出租车行驶在一条有 `n` 个地点的路上，乘客信息用 `rides` 数组表示，`rides[i] = [starti, endi, tipi]` 表示乘客 `i` 需要从地点 `starti` 出发前往地点 `endi`，愿意支付 `tipi` 元的小费。每一位你选择的乘客 `i`，你可以盈利 `endi - starti + tipi`，你最多同时只能接一个订单，请你计算最多可以盈利多少元。👉 [解答](二分/2008%20出租车的最大盈利.cc)

与 **1235** 一样的解法

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

[46.全排列](https://leetcode-cn.com/problems/permutations/)：给定一个不包含重复数字的数组 `nums`，返回其所有可能的全排列。👉 [<u>全排列</u>](回溯/排列/46%20全排列.cc)

深搜，额外使用空间来记录当前元素是否被访问过

[47.全排列II](https://leetcode-cn.com/problems/permutations-ii/)：现在 `nums` 数组中包含了重复的元素，但是要求返回所有不重复的排列。👉 [<u>全排列II</u>](回溯/排列/47%20全排列II.cc)

这里首先对 `nums` 数组排序，然后有两种方法可以去除重复的排列

- 使用 `unordered_set` 记录当前被使用过的元素值，在后序的 `for` 循环迭代中不再使用该元素值
- `i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]` 的时候跳过该元素。说明一下 `!visited[i - 1]` 的用意，因为 `nums[i - 1]` 有可能是在上一层函数调用中被使用的元素，但是当前的 `nums[i] = nums[i - 1]` 此时是不能跳过 `nums[i]` 的，例如 `[1,1,2]`

[93.复原IP地址]([93. 复原 IP 地址 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/restore-ip-addresses/))：给你一个由数字组成的字符串，请使用 `"."` 对该字符串进行分割，使得分割出的字符串能够组成一个有效的 IP 地址。👉 [<u>复原IP地址</u>](93%20复原IP地址.cc)

深搜。每一层搜索从索引 `index` 开始拼接字符，如果拼接得到的字符串 `str` 转化为 `int` 之后的结果大于 256 了，那么直接结束本层搜索，否则的话尝试将 `str` 放入结果中，继续搜索下一层。另外如果 `s[index] == '0'` 此时这一层使用 `"0"`，然后进入下一层搜索

```c++
void dfs(const string &s, vector<string> &cur, int index) {
  if (cur.size() == 4) {
    if (index == s.size())
      tmp_res.push_back(cur);
    return;
  }
  string str;
  for (int i = index; i < s.size(); ++i) {
    if (i == index && s[i] == '0') {
      cur.push_back("0");
      dfs(s, cur, i + 1);
      cur.pop_back();
      break;
    }
    str.push_back(s[i]);
    if (stoi(str) < 256) {
      cur.push_back(str);
      dfs(s, cur, i + 1);
      cur.pop_back();
    } else {
      break;
    }
  }
}
```

[130. 被围绕的区域 - 力扣（LeetCode）](https://leetcode.cn/problems/surrounded-regions/)：给你一个 `m * n` 的矩阵 `board`，找到所有被 `X` 包围的 `O`，并将其修改为 `X`。👉 [解答](回溯/130%20填充矩阵中间被围绕的区域.cc)

从矩阵边界的 `O` 出发，将所有相邻的 `O` 都修改为 `#`，然后遍历矩阵如果遇到 `O` 就修改为 `X`，再次遍历矩阵如果遇到 `#` 就修改为 `O`

时间复杂度：$O(mn)$，空间复杂度 $O(mn)$

[200.岛屿数量](https://leetcode-cn.com/problems/number-of-islands/)：给你一个由 `1`（陆地） 和 `0`（水） 组成的二维网格，请你计算网格中岛屿的数量。👉 [<u>岛屿数量</u>](回溯/200%20岛屿数量.cc)

1. dfs 和 bfs 两种方法
2. 并查集，将所有邻接的 1 都合并

并查集：每次填充块的时候判断相邻的块是不是 1，如果是 1 的话就进行合并。时间复杂度：$O(klog(mn))$，其中 k 是操作的次数，每次操作查找的 root 的时间复杂度是 log(mn)。空间复杂度：$O(mn)$

[329. 矩阵中的最长递增路径 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/)：给定一个 m * n 的矩阵，找出其中最长递增路径的长度，对于每个单元格，你可以往上、下、左、右四个方向移动。👉 [<u>矩阵中的最长递增路径</u>](回溯/329%20矩阵中的最长递增路径.cc)

采用**记忆化搜索**的方式避免重复的搜索。对于每个单元格记录从当前单元格出发的最长递增路径，在深搜遍历的过程中如果发现某个单元格已经被计算过，那么直接备忘录 memo 中的值

时间复杂度 `O(mn)`，空间复杂度 `O(mn)`

> 还可以采用拓扑排序的方法

[547. 省份数量 - 力扣（LeetCode）](https://leetcode.cn/problems/number-of-provinces/)：找出省份的数量，即连通块的数量。👉 [解答](回溯/574%20省份数量.cc)

岛屿数量相同的解法

[695. 岛屿的最大面积 - 力扣（LeetCode）](https://leetcode.cn/problems/max-area-of-island/)：岛屿是由一些相邻的 `1` 构成的组合，岛屿的面积是岛上值为 `1` 的单元格的数目，计算并返回` grid` 中最大的岛屿面积。👉 [解答](回溯/695%20岛屿的最大面积.cc)

深搜、广搜、并查集都可以解决

[854. 相似度为 K 的字符串 - 力扣（LeetCode）](https://leetcode.cn/problems/k-similar-strings/)：字符串 `s1` 和 `s2` 是 `k` 相似，如果我们可以交换 `s1` 中两个字母的位置正好 `k` 次，使结果字符串等于 `s2`。给定两个字符串 `s1` 和 `s2`，返回 `s1` 和 `s2` 的相似度。👉 [解答](搜索/854%20相似度为K的字符串.cc)

这道题虽然是困难题，但是思路比较简单，可以直接通过 dfs 解决。对于 `s1[i]` 如果 `s2[i] == s1[i]` 则继续搜索下一个位置。否则的话遍历 `s2[i+1...len-1]`，如果 `s2[j] == s1[i]` 则交换 `s2[i]` 和 `s2[j]`，然后继续搜索下一个位置

注意需要使用剪枝，否则会超时，当判断 `cur_count` 即当前交换次数大于 `res` 的时候，直接停止搜索，返回上一层搜索

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

[421.数组中两个数的最大异或值]([421. 数组中两个数的最大异或值 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/maximum-xor-of-two-numbers-in-an-array/))：给你一个整数数组 `nums`，返回 `nums[i] XOR num[j]` 的最大运算结果。👉 [<u>数组中两个数的最大异或值</u>](字典树/421%20数组中两个数的最大异或值.cc)

首先需要明确的是异或运算的规则，`x = a XOR b` 等价于 `b = x XOR a`

1. 方法一：哈希。基于上述规则，我们可以从高位到低位不断的假设 `x`  的每一位的数位 1，此时 `x` 已经确定了 `k` 位，然后和 `nums[i]` 的前 `k` 位数异或，如果异或的结果在 `nums` 数组中，那么说明这一位可以是 1，否则的话这一位只能是 0。为了能够快速的找到异或的结果是否出现在 `nums` 数组中，可以使用哈希表记录 `nums` 数组中所有元素的前 `k` 位前缀。时间复杂度 `O(nlogc)`，其中 `c` 表示最大数的二进制位数，空间复杂度 `O(1)`
1. 方法二：字典树。既然需要前缀来判断，那么很容易的想到使用字典树来处理，我们可以初始的时候讲所有的 `nums` 转化为二进制存入字典树中。然后枚举每一个 `num`，如果 `num` 的第 `k` 位是 0，则在字典树中寻找 1，找不到的话就找 0；如果 `num` 的第 `k` 位是 1，则在字典树中寻找 0，找不到的话就找 1。最后将找到的所有二进制拼接起来就是对于 `num` 而言最大的异或值。时间复杂度 `O(nlogc)`，其中 `c` 表示最大数的二进制位数，空间复杂度 `O(nlogc)`

[472.连接词]([472. 连接词 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/concatenated-words/))：给你一个不含重复单词的字符串数组 `words`，请你找出并返回 `words` 中的所有连接词。连接词的定义是：一个完全由给定数组中的至少两个较短单词组成的字符串。[<u>连接词</u>](字典树/472%20连接词.cc)

- 首先对 `words` 中的所有字符串按照字符串长度进行排序
- 然后遍历每一个字符串 `w`，在字典树中搜索 `w` 是否可以由 `words` 中的其他单词拼接。具体搜索的过程为在字典树中逐字符的查找，如果在字典树中找到了 `w[i]` 是某一个字符串的最后一个单词，那么说明 `w[0...i]` 是一个 `words` 中存在的单词，此时进一步查找 `w[i+1...]`，如果 `w[i+1...]` 也能够拼接得到，那么返回 `true`，否则的话继续逐个字符的遍历 `w`
- 如果在字典树中找不到 `w` 可以由已经存在的字符串拼接，那么将 `w` 插入到字典树中

```c++
/// 字典树查找函数
bool searchPrefix(string word) {
  Trie *node = this;
  for (int i = 0; i < word.size(); ++i) {
    if (node->last && i < word.size()) {
      bool tmp = searchPrefix(word.substr(i));
      if (tmp)
        return true;
    }
    if (!node->children.count(word[i]))
      return false;
    node = node->children[word[i]];
  }
  return node->last;
}

/// 判断逻辑
for (auto &w : words) {
  if (trie->searchPrefix(w))
    res.push_back(w);
  else
    trie->insert(w);
}
```

[440.字典序的第K小数字]([440. 字典序的第K小数字 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/k-th-smallest-in-lexicographical-order/))：给你两个整数 `n` 和 `k`，请你按照字典序返回第 `k` 小的数字。👉 [<u>字典序的第K小数字</u>](字典树/440%20字典序的第K小数字.cc)

如果我们对 `[1...n]` 的数字建立字典树，我们可以统计每一个前缀的下一层有多少个节点，这样就可以知道当前有多少个元素在字典树中了。如果当前前缀后序的节点数 `ptr <= k` 那么此时应该直接跳过后面的子树，因此让前缀 `prefix++`，否则的话说明第 `k` 个数字在当前前缀的子树中，此时我们让 `prefix` 往后移动一层，即 `prefix = prefix * 10`

## 动态规划

动态规划的题目分为两大类，一种是求最优解类，典型问题是背包问题，另一种就是计数类。对于最优解类问题，它的递推性质被称为「最优子结构」，表示当前问题的最优解可以从子问题的最优解中得到；对于计数类问题，当前问题的方案数量，取决于子问题的方案数量

动态规划的五个步骤：

1. 确定 dp 数组下标的含义
2. 确定递推公式
3. dp 数组如何初始化
4. 确定 dp 数组遍历顺序
5. 举例推导 dp 数组

### 基础题目

[509.斐波那契数](https://leetcode-cn.com/problems/fibonacci-number/)，👉 [斐波那契数.cc](./动态规划/509%20斐波那契数.cc)
`dp[i] = dp[i - 1] + dp[i - 2]`，其中 `dp[0] = dp[1] = 1`。由于每一个状态只和前面的两个状态有关，因此可以把空间优化成常数级别的

[70.爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/)，👉 [爬楼梯.cc](./动态规划/70%20爬楼梯.cc)
这道题属于 [509.斐波那契数](https://leetcode-cn.com/problems/fibonacci-number/) 的变种，递推公式和 509 题一样

[746.使用最小花费爬楼梯](https://leetcode-cn.com/problems/min-cost-climbing-stairs/)，👉 [使用最小花费爬楼梯.cc](./动态规划/746%20使用最小花费爬楼梯.cc)

`dp[i]` 表示爬到第 `i` 层楼梯需要的开销，可以从 `dp[i - 1]` 和 `dp[i - 2]` 推导出来。如果从第 `i - 1` 层爬上来，那么此时的花费是 `dp[i - 1] + cost[i - 1]`；如果从第 `i - 2` 层爬上来，那么此时的花费是 `dp[i - 2] + cost[i - 2]`。因此 `dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2])`

[62.不同路径](https://leetcode-cn.com/problems/unique-paths/)：一个机器人位于 m*n 网格的左上角，每次机器人只能向下或者向右移动一步，那么机器人到达右下角总共有多少种不同的路径。👉 [不同路径.cc](./动态规划/62%20不同路径.cc)

`dp[i][j]` 表示到达第 `i` 行、第 `j` 列有多少种不同的路径。由于机器人可以从第 `i - 1` 行、第 `j` 列到达，也可以从第 `i` 行、第 `j - 1` 列到达，所以 `dp[i][j] = dp[i - 1][j] + dp[i][j - 1]`

- 初始的时候 `dp[i][0]` 和 `dp[0][i]` 都是 1

[63.不同路径II](https://leetcode-cn.com/problems/unique-paths-ii/)：题目描述和 `62题` 一样，区别在于多了障碍物，障碍物是不可到达的。因此在原先的 `dp[i][j]` 的定义下，如果遇到障碍物了，那么 `dp[i][j] = 0`，其余推到过程和 `62题` 一样。👉 [不同路径II.cc](./动态规划/63%20不同路径II.cc)

[343.整数拆分](https://leetcode-cn.com/problems/integer-break/)：给定一个整数 `n`，将其拆分为至少两个正整数的和，求所有拆分数乘积的最大值。👉 [整数拆分.cc](./动态规划/343%20整数拆分.cc)

- 第一种思路：`dp[i]` 表示对于正整数 `i` 能够获得的最大乘积。我们可以将 `i` 拆分为 `i = (i - j) + j, 1 <= j < i`，那么 `dp[i]` 要么等于 `dp[i - j] * j`，要么等于 `(i - j) * j`（这里表示将 `i - j ` 就拆分为自己）。因此遍历所有的 `j`，`dp[i] = max({dp[i], dp[i - j] * j, (i - j) * j})`
  - 该方法时间负载度为 `O(n^2)`
- 官方题解还有一种在上述基础上优化的方法，时间负载度降到 `O(n)`。另外还有一种数学方法

> **补充：整数拆分问题** 将一个正整数 `n` 拆分成至少两个数的和，有多少种方案数
> 例如 `n = 5` 的时候，`5 = 5 = 4 + 1 = 3 + 2 = 3 + 1 + 1 = 2 + 2 + 1 = 2 + 1 + 1 + 1 = 1 + 1 + 1 + 1 + 1`
> 可以定义 `dp(n, k)` 表示将 `n` 拆分为最大的数不超过 `k` 的拆分方案数，则有
>
> 1. 当处理边界情况 `n = 1` 或者 `k = 1` 的时候，`dp(n, k) = 1`
> 2. 当 `n = k` 的时候，如果包含了数字 `k`，则只有一种方案数；如果不包含数字 `k`，则 `dp(n, k) = dp(n, k - 1)`。因此 `dp(n, k)` 是两种情况的和，`dp(n, k) = dp(n, k - 1) + 1`
> 3. 当 `n > k` 的时候，如果包含了数字 `k`，则 `dp(n, k) = dp(n - k, k)`，注意这里 `n - k` 还是有可能大于 `k` 的；如果不包含数字 `k`，则 `dp(n, k) = dp(n, k - 1)`。因此 `dp(n, k) = dp(n - k, k) + dp(n, k - 1)`
> 最后给出一个正整数 n，返回 `dp(n, n - 1)` 即可

[96.不同二叉搜索树](https://leetcode-cn.com/problems/unique-binary-search-trees/)：给出一个整数 `n`，求出由 1 到 n 的值作为节点的二叉搜索树有多少种。👉 [不同二叉搜索树.cc](./动态规划/96%20不同二叉搜索树.cc)

我们可以知道树的节点由 `[1, 2, 3, ..., n]` 组成，那么可以以其中一个值作为二叉树的根节点，此时左子树就是 `[1, 2, ..., j - 1]` 共有 `j - 1` 个节点，右子树就是 `[j + 1, j + 2, ..., n]` 共有 `n - j` 个节点。如果用 `dp[i]` 表示对于整数 `i` 的拆分个数，那么 `dp[i]` 就等于 `dp[j - 1] * dp[i - j]`；遍历所有的 `1 <= j <= i`，将所有结果都累加起来；即 `dp[i] += dp[j - 1] * dp[i - j], 1 <= j <= i`

- 初始的时候 `dp[0] = dp[1] = 1`

### 背包

#### 0-1 背包

背包容量 `v`，物品价值 `w[]`，每个物品的体积 `v[]`。每个物品只有一件，求该背包能装入的最大价值。
##### 二维数组 DP

`dp[i][j]` 表示从下标 `[0...i]` 物品中挑选物品装入容量为 `j` 的背包，能够装入的最大价值。对于物品 `i` 考虑以下情况：

1. 不放物品 `i`，此时相当于从 `[0...i-1]` 中挑选物品，背包容量还是 `j`。即 `dp[i][j] = dp[i - 1][j]`
2. 放物品 `i`，此时剩余物品是 `[0...i-1]`，背包容量剩余 `j - weight[i]`。因此 `dp[i][j] = dp[i - 1][j - weight[i]] + value[i]`

结合上述两种情况，`dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i])`。

初始化情况：当背包容量为 0 的时候，能够装入的物品价值是 0，即 `dp[i][0] = 0`；另外由于 `dp[i][j]` 需要从 `dp[i - 1][]` 推导而来，因此 `dp[0][]` 也需要初始化，`dp[0][j] = j < weight[0] ? 0 : value[0]`

```c++
void test_2_wei_bag_problem1() {
  vector<int> weight = {1, 3, 4};
  vector<int> value = {15, 20, 30};
  int bagWeight = 4;

  // 二维数组
  vector<vector<int>> dp(weight.size(), vector<int>(bagWeight + 1, 0));

  // 初始化
  for (int j = weight[0]; j <= bagWeight; j++) {
    dp[0][j] = value[0];
  }

  // weight数组的大小 就是物品个数
  for (int i = 1; i < weight.size(); i++) { // 遍历物品
    for (int j = 0; j <= bagWeight; j++) {  // 遍历背包容量
      if (j < weight[i])
        dp[i][j] = dp[i - 1][j];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
    }
  }

  cout << dp[weight.size() - 1][bagWeight] << endl;
}
```

##### 一维 DP

从前面的递推公式可以看出 `dp[i][j]` 只和 `dp[i - 1][]` 相关，因此可以优化成一维的 DP 数组，即 `dp[j]`。这就是滚动数组的由来，当前层只和上一层的状态相关，可以直接把上一层的状态拷贝到当前层，重复利用。这样 `dp[j] = max(dp[j], dp[j - weight[i]] + value[i])`（即考虑装入或者不装入第 `i` 件物品）

另外需要注意，与二维不同的是这里的背包重量遍历顺序必须是从大到小，因为在一维里面是会保存上一次的结果的，而在二维里面本层并不会出现上一层的结果，也就不会被影响到。所以如果一维里面从小到大遍历的话，会导致同一件物品被多次放入，考虑背包容量是 2，物品重量是 1 的情况。如果从小到大 `dp[0] = value[0], dp[1] = dp[0] + value[0]`，就重复放入了；如果从大到小 `dp[2] = dp[1] + value[0] = value[0], dp[1] = value[0]`

另外也不可以先遍历背包在遍历物品，因为一维情况下背包容量是从大到小遍历的，如果放在外层循环的话就表示背包中只放入一件物品了、因为没有前面的状态、而一旦想要先考虑前面的状态就会重复放入物品（只有背包容量从小到大遍历的时候才可以放在外层，因为这样子遍历到大容量背包的时候前面已经考虑过在小容量的背包上放入物品了，也就已经得到子问题的最优解了）

```c++
for(int i = 0; i < weight.size(); i++) { // 遍历物品
  for(int j = bagWeight; j >= weight[i]; j--) { // 遍历背包容量
      dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
  }
}
```

[416.分割等和子集](https://leetcode-cn.com/problems/partition-equal-subset-sum/)：给出一个只包含正整数的非空数组 `nums`，判断 `nums` 能否拆分成两个数组，并且两个数组的元素和相等。👉 [分割等和子集.cc](./动态规划/416%20分割等和子集.cc)

本题可以转化为0-1背包问题，如果 `nums` 数组的所有元素只和记为 `sum`，那么这道题目可以转化为：给出一个容量为 `v = sum / 2` 的背包，以及 `n` 件物品，物品 `i` 的重量是 `nums[i]`，问是否存在一种装法使得刚好可以装满背包。因此我们需要快速判断出能否装满容量为 `v` 的背包，我们可以将物品的价值看作等于物品的重量，这样一来背包装了多重的物品就拥有多大的价值，因此可以先按照0-1背包问题求出最大能装下的价值，然后继续判断该价值是否等于 `v`；如果价值等于 `v` 那说明刚好可以装满，如果小于 `v` 那说明没法刚好装满

> 注意本题不能先排序，然后从前往后计算元素和，如果碰到元素和等于 `nums` 所有元素和的一半就返回 true，当超过 `nums` 所有元素和的一半就返回 false。这种思路是错误的，因为理论上来说该问题是一个 NP 完全问题，没有多项式时间解，因此总可以找出反例，例如 `[2, 2, 1, 1]`

[1049.最后一块石头的重量II](https://leetcode-cn.com/problems/last-stone-weight-ii/)：有一堆石头 `stones[]`，其中 `stones[k]` 表示第 `k` 块石头的重量；如果 `stones[i] <= stones[j]` 则两块石头相撞之后重量较大的那块石头的重量会变成 `stones[j] - stones[i]`。求出这堆石头两两相撞之后最后剩下的那块石头的最小重量。

本质上这道题就是想办法将石头分成质量相近的两堆，这样一来题目所求的值就是两堆石头相撞之后剩余的质量。因此总体执行思路和 *416.分割等和子集* 类似，加入 `sum` 表示所有 `stone` 的重量之和，那么相当于现在有一个容量为 `sum / 2` 的背包，物品的重量是 `stones[i]`，物品的价值也设置为 `stones[i]`（这是为了方便计算），求背包能够装入的最大重量（也就是最大价值），背包装入的重量就是分出来的一堆石头。最后只需返回 `sum - dp[v] - dp[v]` 就是两堆石头相撞的结果。👉 [最后一块石头的重量II.cc](./动态规划/416%20分割等和子集.cc)

[494.目标和](https://leetcode-cn.com/problems/target-sum/)：给你一个整数数组 `nums`，你的任务是给每个元素添加符号 `+` 或者 `-`，然后对 `nums` 中的元素求和，使得新的元素和等于 `target`，添加符号的方案数量。

首先这道题目本质上也是将 `nums` 分成两堆，可以理解为其中一堆的符号是 `-`，另一堆的符号是 `+`，使得两堆数字和做差的绝对值等于 `target` 的绝对值（因为这里 `target` 可能会是负数，但是 `-target` 的题目结果和 `target` 的题目结果是一致的，因此只需要做差结果等于 `abs(target)` 即可）。👉 [目标和.cc](./动态规划/494%20目标和.cc)

- 方法一（回溯）：暴力搜索所有可能的划分方案，最后判断是否满足题目要求即可。唯一需要注意的是，如果题目给出的 `target = 0`，那么最后的结果需要乘以 2，例如 `nums = [1, 2, 1], target = 0`
- 方法二（动态规划）：首先需要明确分成的两堆中有一堆的数字和是 `v = (sum + target) / 2`，因此目标问题就变为装满一个容量为 `v` 的背包有几种装法。使用 `dp[j]` 表示装满容量为 `j` 的背包的装法数量，初始条件 `dp[0] = 1`，因此 `dp[j] += dp[j - nums[i]]`。

> 这里的动态规划虽然是背包问题，但是属于方案数量类别的动态规划问题了，不再是最有子结构类别的动态规划

[474.一和零](https://leetcode-cn.com/problems/ones-and-zeroes/)：给出一个包含二进制字符串的数组 `strs`，以及两个整数 `m` 和 `n`，找出 `strs` 的一个子集，使得其中的 0 的个数不超过 `m`，1 的个数不超过 `n`，并且子集的元素应该尽可能多。返回该子集的元素个数

这里的背包容量是二维的，现在我们有一个容量为 `<m, n>` 的背包，以及一堆物品 `strs`，每件物品的重量是 `<str.get_zero_num(), str.get_one_num()>`，每件物品的价值是 1（因为目标是元素的个数，因此就把元素个数看成价值，所以每个元素贡献的价值都是 1）。从而该问题就转化为一个很普通的0-1背包问题。👉 [一和零.cc](./动态规划/474%20一和零.cc)

我们使用 `dp[j][k]` 表示容量为 `<j, k>` 的背包能够装入的最大价值，那么就有递推公式 `dp[j][k] = max(dp[j][k], dp[j - nums[i].first][k - nums[i].second] + 1)`

[879.盈利计划](https://leetcode-cn.com/problems/profitable-schemes/)：第 `i` 中工作会产生 `profit[i]` 的利润，并且需要 `group[i]` 的人参与，并且每个人一旦参加完一个工作就不能再参加后续的工作。现在给出可以用的总人数 `n`，以及需要产生的最少利润 `minProfit`，求出有多少种工作计划可以选择，使得产生的利润不低于 `minProfit`

本题和 *494.目标和* 一样都是背包问题求方案数量，⚠️ *494.目标和* 求的是刚好装满背包的方案数，而本题求的是大于等于 `minProfit` 的方案数。因此我们可以把 `profit` 也当成一个背包容量的维度，这样一来背包容量就被两个维度限制住了——人数和利润。

使用 `dp[j][k]` 表示背包容量为——最多只允许有 `j` 个人，利润大于等于 `k`，情况下的方案数。因此在该背包容量下的方案数我们可以这样计算：

1. 考虑每一个任务 `i`，它的人数要求是 `group[i]`，能够产生 `profit[i]` 的利润
2. 因此 `dp[j][k] += dp[j - group[i]][]`，注意第二个维度应该怎么确定。第二个维度不能是 `k - profit[i]`，这是因为当带来的收益 `profit[i] > k` 时也是满足要求的，因此此时可以把 `k - profit[i]` 映射到 0。所以最终 `dp[j][k] += dp[j - group[i]][max(0, k - profit[i])]`

👉 [盈利计划.cc](./动态规划/494%20目标和.cc)

```c++
vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1));
for (int i = 0; i <= n; ++i)
  dp[i][0] = 1;
for (int i = 0; i < group.size(); ++i) {
  for (int j = n; j >= group[i]; --j) {
    // 因为可以 profit 超标，因此 k 没有必要将下限设置为 profit[i]
    for (int k = minProfit; k >= 0; --k) {
      dp[j][k] = (dp[j][k] + dp[j - group[i]][max(0, k - profit[i])]) % MOD;
    }
  }
}
```

> 🎉 小结：当问题可以转化为背包问题的时候
> 
> 1. 需要考虑背包容量的限制因素，背包物品的重量因素
> 2. 问题是最优子结构类问题，还是方案数问题
> 3. 背包物品的价值设置为多少。方案数问题一般不需要考虑价值，最优子结构类问题需要考虑物品的价值；对于尽可能装满背包的容量这类问题，物品的价值就设置为物品的重量；对于尽可能装更多的物品，这类问题，物品价值就设置为 1
> 4. 方案数类问题，背包的容量限制因素由所有的限制条件组成。例如 **494.目标和、879.盈利计划**

#### 完全背包

完全背包的问题描述上和0-1背包的唯一区别就是，完全背包问题中物品的数量是不受限制的。代码实现上和0-1背包的不同之处：

- 0-1背包的一维DP中，背包的遍历顺序是从大到小的，这是为了防止同一件物品被重复多次放入。而完全背包是可以重复添加物品的，因此需要从小到大遍历背包
- 0-1背包的一维DP中，物品必须放在外层遍历，这是因为在前置条件背包从大到小遍历下，如果物品放在内层循环遍历就会变成背包只放入一件物品了（原因在于背包从大到小遍历没有之前小容量背包的状态，具体可以看 **0-1背包** 那里的解释）。而完全背包由于背包就是从小到大遍历的，因此物品无论放在内层还是放在外层都是可以的，只要保证下标 `j` 之前的 `dp[j]` 都是经过计算的就可以了

```c++
// 先遍历物品，在遍历背包
void test_CompletePack() {
  vector<int> weight = {1, 3, 4};
  vector<int> value = {15, 20, 30};
  int bagWeight = 4;
  vector<int> dp(bagWeight + 1, 0);
  for (int i = 0; i < weight.size(); i++) {        // 遍历物品
    for (int j = weight[i]; j <= bagWeight; j++) { // 遍历背包容量
      dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    }
  }
  cout << dp[bagWeight] << endl;
}
int main() { test_CompletePack(); }
```

```c++
// 先遍历背包，再遍历物品
void test_CompletePack() {
  vector<int> weight = {1, 3, 4};
  vector<int> value = {15, 20, 30};
  int bagWeight = 4;

  vector<int> dp(bagWeight + 1, 0);

  for (int j = 0; j <= bagWeight; j++) {      // 遍历背包容量
    for (int i = 0; i < weight.size(); i++) { // 遍历物品
      if (j - weight[i] >= 0)
        dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    }
  }
  cout << dp[bagWeight] << endl;
}
int main() { test_CompletePack(); }
```

[518.零钱兑换II](https://leetcode-cn.com/problems/coin-change-2/)：给出一堆硬币 `coins`，每个硬币都有无限多个，另外给出一个目标金额 `amount`，求出用 `coins` 凑出 `amount` 的所有硬币 **组合数**

很明显是一个完全背包问题，背包的容量是 `amount`，每件物品的重量是 `coins`，前面有提到过对于方案数类的背包问题不需要考虑物品的价值。我们使用 `dp[j]` 表示凑出额度为 `j` 的金额的方案数量，那么就有 `dp[j] += dp[j - coins[i]]`

这道题还有一个需要注意的地方是，外层必须遍历的是硬币，内层必须遍历背包容量。因为题目求的是组合数，不要求硬币的使用顺序，而如果外层是背包内层是硬币的话就考虑了硬币的顺序了。例如 `coins = [1, 5], amount = 6`，可以知道 `dp[6] += dp[5] + 1` 以及 `dp[6] += dp[1] + 5`；如果先遍历硬币在遍历背包，那么当计算 `dp[5] + 1` 的时候只考虑了使用硬币 1，当计算 `dp[1] + 5` 的时候考虑使用了硬币 `1, 5`，没有考虑 `5, 1` 这种情况在内了；而如果先遍历背包再遍历硬币，那么计算 `dp[5] + 1` 的时候，由于 `dp[5]` 已经考虑过使用硬币 5 了，所以此时考虑了 `全是 1` 、以及 `5, 1` 这两种情况，在计算 `dp[1] + 5` 的时候又考虑了使用 `1, 5` 这种情况。因此这是排列数，相对于组合数来说重复了

> 硬币在外层背包在内层，不考虑顺序；硬币在内层背包在外层，考虑顺序

[377.组合总和IV](https://leetcode-cn.com/problems/combination-sum-iv/)：给出一个由不同整数组成的数组 `nums`，以及一个目标整数 `target`，请你从 `nums` 中找出并返回总和为 `target` 的元素组合的个数，顺序不同的序列被视为不同的组合。本题求的是 **排列数**，👉 [组合总和IV.cc](./动态规划/377%20组合总和IV.cc)

这道题和 **518.零钱兑换II** 的唯一区别在于，这道题是需要考虑元素顺序的。因此只需要在 **518.零钱兑换II** 的基础上对换内层和外层循环的顺序即可

> 注：**70.爬楼梯** 那题可以变化为这道题。只需要把每次可以爬的台阶数量设置为 `1, 2, ..., m`，这样以来楼顶的台阶数就是背包的容量，每次可以爬的台阶数量就是物品的重量。所以本质上就和本题一模一样了

[322.零钱兑换](https://leetcode-cn.com/problems/coin-change/)：给出一个整数数组 `coins` 表示拥有的不同面值的硬币，每个硬币都有无限多个，给出一个目标整数 `target`，要求使用 `coins` 中的硬币凑出 `target`，返回需要使用的最少的硬币数量

典型的完全背包问题，只不过现在要求背包装的物品价值尽可能少。我们可以使用 `dp[j]` 表示凑出面值为 `j` 需要的最少的硬币数量，那么当我们遍历到硬币 `coins[i]` 的时候只需要在 `dp[j - coins[i]]` 基础上加 1 即可，即 `dp[j] = min(dp[j], dp[j - conis[i]] + 1)`（当然也可以直接根据背包问题的递推公式来）。

初始条件下设置所有的 `dp[] = INT_MAX - 1`，减 1 是为了后面在计算加 1 的时候不会超过 INT_MAX，另外 `dp[0] = 0`，这样可以在第一次计算 `dp[coins[i]] = min(INT_MAX, dp[coins[i] - coins[i]` 的时候能够得到正确答案。👉 [零钱兑换.cc](./动态规划/322%20零钱兑换.cc)

[279.完全平方数](https://leetcode-cn.com/problems/perfect-squares/)：给定一个整数 `n`，将其分解为若干个完全平方数的和，返回需要使用的完全平方数的最少数量（每个完全平方数可以重复使用）。👉 [完全平方数.cc](./动态规划/279%20完全平方数.cc)

这题本质上就是 **322.硬币兑换**，只不过现在硬币的额度变成了 `[1, 4, 9, ...]`，并且硬币的最大额度 `k` 满足 `k * k <= n`。剩下的解法就和 **322.硬币兑换** 一样了

[139.单词拆分](https://leetcode-cn.com/problems/word-break/)：给出一个字符串 `s` 和一个字符串列表 `wordDict` 作为字典，判断能否用字典中的字符串拼接出 `s`。

这题可以看成一个完全背包问题。使用 `dp[i]` 表示能否使用 `wordDict` 拼接出 `s[0...i-1]`，这样的话假如我们知道了 `s[j...i-1]` 的字串能在 `wordDict` 中找到，那么 `dp[i] = dp[i] | dp[j]`。👉 [单词拆分.cc](./动态规划/139%20单词拆分.cc)

> 判断 `s[j...i-1]` 是否出现在 `wordDict` 的时间负载度是 O(n)，这里可以使用 `set` 实现空间换时间

#### 多重背包

多重背包问题的重点在于，现在每种物品的数量不是一件也不是无数件，而是指定的件数 `k`。因此我们可以把 `k` 件物品拆开，看成0-1背包问题

```c++
/// 方式一：转化为0-1背包问题
void test_multi_pack() {
  vector<int> weight = {1, 3, 4};
  vector<int> value = {15, 20, 30};
  vector<int> nums = {2, 3, 2};
  int bagWeight = 10;
  for (int i = 0; i < nums.size(); i++) {
    while (nums[i] > 1) { // nums[i]保留到1，把其他物品都展开
      weight.push_back(weight[i]);
      value.push_back(value[i]);
      nums[i]--;
    }
  }

  vector<int> dp(bagWeight + 1, 0);
  for (int i = 0; i < weight.size(); i++) {        // 遍历物品
    for (int j = bagWeight; j >= weight[i]; j--) { // 遍历背包容量
      dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    }
    for (int j = 0; j <= bagWeight; j++) {
      cout << dp[j] << " ";
    }
    cout << endl;
  }
  cout << dp[bagWeight] << endl;
}
int main() { test_multi_pack(); }
```

```c++
/// 方式二：在内层再加上遍历件数
void test_multi_pack() {
  vector<int> weight = {1, 3, 4};
  vector<int> value = {15, 20, 30};
  vector<int> nums = {2, 3, 2};
  int bagWeight = 10;
  vector<int> dp(bagWeight + 1, 0);

  for (int i = 0; i < weight.size(); i++) {        // 遍历物品
    for (int j = bagWeight; j >= weight[i]; j--) { // 遍历背包容量
      // 以上为01背包，然后加一个遍历个数
      for (int k = 1; k <= nums[i] && (j - k * weight[i]) >= 0;
           k++) { // 遍历个数
        dp[j] = max(dp[j], dp[j - k * weight[i]] + k * value[i]);
      }
    }
    // 打印一下dp数组
    for (int j = 0; j <= bagWeight; j++) {
      cout << dp[j] << " ";
    }
    cout << endl;
  }
  cout << dp[bagWeight] << endl;
}
int main() { test_multi_pack(); }
```

时间复杂度：`O(m * n * k)`，`m` 物品种类，`n` 背包容量，`k` 物品件数

#### 背包总结

能否装满背包

- 416.分割等和子集
- 1049.最后一块石头的重量II

装满背包有几种装法

- 494.目标和
- 518.零钱兑换II
- 377.组合总数IV
- 70.爬楼梯的进阶版

达到目标价值以上有几种装法

- 879.盈利计划

装满背包最大价值

- 474.一和零

装满背包所有物品的最小个数

- 322.零钱兑换
- 279.完全平方数

🎉 小结：当问题可以转化为背包问题的时候

1. 需要考虑背包容量的限制因素，背包物品的重量因素
2. 问题是最优子结构类问题，还是方案数问题
3. 背包物品的价值设置为多少。方案数问题一般不需要考虑价值，最优子结构类问题需要考虑物品的价值；对于尽可能装满背包的容量这类问题，物品的价值就设置为物品的重量；对于尽可能装更多的物品或者其他对物品数量上面提出要求的问题，不管是物品数量尽可能多还是尽可能少，物品价值都设置为 1，例如 **474.一和零**、**322.零钱兑换**、**279.完全平方数**
4. 方案数类问题，背包的容量限制因素由所有的限制条件组成（装满背包、或者至少达到多少的价值）。例如 **494.目标和、879.盈利计划**

### 打家劫舍

[198.打家劫舍](https://leetcode-cn.com/problems/house-robber/)：给出一排房屋内现金的价值，由于报警装置的存在，小偷不能连着偷两个相邻的房子，求小偷能够偷到现金的最大价值。

使用 `dp[i][0]` 表示第 `i` 间房子不偷的情况下能够偷到的最大现金，`dp[i][1]` 表示第 `i` 间房子偷的情况下能够偷到的最大现金。如果第 `i` 间房子不偷，那么第 `i - 1` 间房子可以偷也可以不偷因此 `dp[i][0]` 取它们中的最大值，`dp[i][0] = max(dp[i - 1][0], dp[i - 1][1])`；如果第 `i` 间房子偷，那么第 `i - 1` 间房子就不能偷了，因此 `dp[i][1]` 只能在 `i - 1` 不偷的情况下加上第 `i` 间房子的现金，`dp[i][1] = dp[i - 1][0] + nums[i]`。👉 [打家劫舍.cc](./动态规划/打家劫舍/198%20打家劫舍.cc)

另外也可以将 `dp` 数组的维度从二维降至一维，使用 `dp[i]` 表示下标小于等于 `i` 的所有房子时候能够偷到的最大金额。`dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])`

1. 如果不偷第 `i` 间房子，那么此时能够偷到的最大金额就是 `dp[i - 1]`（就是前 `i - 1` 间房子能够偷到的最大金额）
2. 如果偷第 `i` 间房子，那么此时偷到的金额相当于在第 `i - 2` 间房子的基础上再加上第 `i` 间房子的最大价值，即 `dp[i] = dp[i - 2] + nums[i]`。这里不能考虑第 `i - 1` 间房子的基础上加上 `nums[i]`，`dp[i - 1]` 表示下标小于等于 `i - 1` 时候能够偷到的最大金额，因此并不知道此时有没有偷 `i - 1`；如果偷了 `i - 1` 那么就偷不了下标 `i` 了，如果没有偷 `i - 1` 的话，`dp[i - 1] = dp[i - 2]`，因此必须要用 `i - 2` 也只能用 `i - 2`

[213.打家劫舍II](https://leetcode-cn.com/problems/house-robber-ii/)：与 **198.打家劫舍** 的却别在于，现在所有的房子是围成一圈的，这意味着第一间房子和最后一间房子之间是会互相影响的。我们可以分类讨论分别计算，分为：

- 考虑首元素的计算（那么最后一间房子就不可以考虑。在考虑首元素的计算中如果不选择首元素那么计算结果会被包含在「考虑尾元素的计算」，因此在这里可以去掉尾元素）
- 考虑尾元素的计算（那么第一间房子就不可以考虑。在考虑尾元素的计算中如果不选择尾元素，那么计算结果也已经被包含在「考虑首元素的计算」，因此这里可以去掉首元素）

> 对于数组实际上我们可以分为三种情况：去掉最后一个元素；去掉第一个元素；去掉首尾元素。其中第三种情况已经在第一种和第二种情况中被包含了，因此可以去掉
> 👉 [打家劫舍II.cc](./动态规划/打家劫舍/213%20打家劫舍II.cc)

 [337.打家劫舍III](https://leetcode-cn.com/problems/house-robber-iii/)：现在所有的房子形成一棵二叉树，二叉树中直接连接的两个节点不能同时被偷，求能偷到的最大金额。可以用 **198.打家劫舍** 中二维DP数组的方法来求解这道题目，对于某一个节点 `node` 使用 `pair<int, int>` 来表示 <偷这个节点能获得的最大金额, 不偷这个节点能获得的最大金额>。`pair<int, int> dp(TreeNode *node)` 返回该节点的状态

 - 如果不偷这个节点，那么能够偷盗的最大价值就是 `max(dp(node->left).first, dp(node->left).second) + max(dp(node->right).first, dp(node->right).second)` ，即左节点偷或者不偷取最大值加上右节点偷或者不偷取最大值
 - 如果偷这个节点，那么左右节点必须不可以偷，因此能够偷到的最大价值就是 `root->val + dp(node->left).second + dp(node->right).second`

最后返回 `max(first, second)` 就是该节点能够偷到的最大金额。👉 [打家劫舍III.cc](./动态规划/打家劫舍/337%20打家劫舍III.cc)

### 买卖股票的最佳时机

[121.买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)：给定一个 `prices` 数组，`prices[i]` 表示第 `i` 天股票的价格（例如 `[7,1,5,3,6,4]`），你只能选定某一天买入股票并在未来的某一天卖出，求出能获取的最大利润。👉 [买卖股票的最佳时机.cc](./动态规划/股票问题/121%20买卖股票最佳时机.cc)

这道题并不需要动态规划（当然也可以用），使用贪心算法即可，我们只需要找到数组中「谷」->「所有的峰」的最大高度差即可。下面代码中由于 `min_val` 一直记录着 `i` 之前的最小值，因此对于每一个 `prices[i]` 来说总是能够得出在该天卖出股票能够获得的最大利润

```c++
int maxProfit(vector<int>& prices) {
  int res = 0, min_val = prices[0];
  for (int i = 0; i < prices.size(); ++i) {
    res = max(res, prices[i] - min_val);
    min_val = min(min_val, prices[i]);
  }
  return res;
}
```

也可以使用动态规划。使用 `dp[i][0]` 表示第 `i` 天持有股票时候获得的最大利润，`dp[i][1]` 表示第 `i` 天不持有股票时候获得的最大利润，注意第 `i` 天持有股票并不代表是在第 `i` 天买入股票，有可能在前几天就已经买入了，然后一直没有卖出

- `dp[i][0]` 由以下两种状态推导出来
  - 第 `i - 1` 天就持有股票，保持到第 `i` 天，那么 `dp[i][0] = dp[i - 1][0]`
  - 第 `i - 1` 天的时候还没有股票，那么第 `i` 天就需要买入股票，**由于题目要求只能交易一次**，因此 `dp[i][0] = -prices[i]`
- `dp[i][1]` 由以下两种状态推导出来
  - 第 `i - 1` 天持有股票，那么第 `i` 天就需要卖出，此时 `dp[i][1] = dp[i - 1][0] + prices[i]`
  - 第 `i - 1` 天不持有股票，那么 `dp[i][1] = dp[i - 1][1]`

综上，`dp[i][0] = max(dp[i - 1][0], -prices[i])`，`dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i])`

```c++
int maxProfit(vector<int>& prices) {
  int n = prices.size();
  vector<vector<int>> dp(n, vector<int>(2));
  dp[0][0] = -prices[0]; dp[0][1] = 0;
  for (int i = 1; i < prices.size(); ++i) {
    dp[i][0] = max(dp[i - 1][0], -prices[i]);
    dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
  }
  return dp[n - 1][1];
}
```

[122.买卖股票的最佳时机II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)：与 **121.买卖股票的最佳时机** 区别在于现在可以多次进行股票买卖，求能获得的最大利润。👉 [买卖股票的最佳时机II.cc](./动态规划/股票问题/122%20买卖股票的最佳时机II.cc)

这题也不需要动态规划（当然也可以用），同样使用贪心算法，**121.买卖股票的最佳时机** 是找到一对高度差最大的「谷」->「峰」，而现在是累加所有「谷」->「谷右边最近的峰」的高度差；也可以理解为累加所有的“上升序列”，因为上升序列就是获得的利润

```c++
int maxProfit(vector<int>& prices) {
  int res = 0;
  for (int i = 1; i < prices.size(); ++i) {
    if (prices[i] > prices[i - 1])
      res += prices[i] - prices[i - 1];
  }
  return res;
}
```

同样的，这道题也可以采用动态规划。与 **121.买卖股票的最佳时机** 一样，使用 `dp[i][0]` 表示第 `i` 天持有股票能够获得的最大利润，`dp[i][1]` 表示第 `i` 天不持有股票能够获得的最大利润。

- `dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i])`，**唯一的区别，因为现在股票可以买卖无数次**
- `dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i])`

```c++
int maxProfit(vector<int>& prices) {
  int n = prices.size();
  vector<vector<int>> dp(n, vector<int>(2));
  dp[0][0] = -prices[0]; dp[0][1] = 0;
  for (int i = 1; i < n; ++i) {
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
    dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
  }
  return dp[n - 1][1];
}
```

[123.买卖股票的最佳时机III](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/)：与 **121.买卖股票的最佳时机** 的区别在于，现在能够进行股票交易的次数不是 1 次，也不是无数次，而是 2 次。使用动态规划来解决该问题

使用 `dp[i][k][0]` 表示第 `i` 天在最多执行 `k` 次交易的情况下，并且持有股票的时候能够获得的最大利润；`dp[i][k][1]` 表示第 `i` 天最多执行 `k` 次交易的情况下，并且不持有股票时候能够获得的最大利润。本题 `k = [1, 2]`

- `dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k - 1][1] - prices[i])`。第 `i` 天持有股票能够获得利润从以下两种情况中获取
  - 第 `i - 1` 天已经持有股票了，那么说明股票最多可以执行的交易次数肯定和第 `i` 天相同（因为在已经持有的情况下不能买入新的股票），此时 `dp[i][k][0] = dp[i - 1][k][0]`
  - 第 `i - 1` 天不持有股票，由于现在第 `i` 天的最多可以执行的交易次数是 `k`（即开启了新的一轮交易），那么第 `i - 1` 天最多可以执行的交易次数只能是 `k - 1`，所以 `dp[i][k][0] = dp[i - 1][k - 1][1] - prices[i]`
- `dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k][0] + prices[i])`
  - 首先由于第 `i` 天不持有股票，那么就不可能在前面天数的基础上开启一轮新的交易，所以第 `i` 天的最多可以执行的交易次数必定是和前面的几天一样的
  - 如果第 `i - 1` 天持有股票，那么 `dp[i][k][1] = dp[i - 1][k][0] + prices[i]`
  - 如果第 `i - 1` 天不持有股票，那么 `dp[i][k][1] = dp[i - 1][k][1]`

综上 `dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k - 1][1] - prices[i])`，`dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k][0] + prices[i])`。👉 [买卖股票的最佳时机III](./动态规划/股票问题/123%20买卖股票的最佳时机III.cc)

[188.买卖股票的最佳时机IV](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/)：与 **123.买卖股票的最佳时机III** 的区别在于现在指定的最多可以执行的交易次数不是 2，而是 `k`。👉 [买卖股票的最佳时机IV](./动态规划/股票问题/188%20买入股票的最佳时机IV.cc)

直接套用 **123.买卖股票的最佳时机III** 的 `dp` 公式就可以了，那题已经考虑了股票的交易次数是 `k` 了

[309.买卖股票的最佳时机含冷冻期](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)：本题在 **122.买卖股票的最佳时机II** 的基础上添加了限制，当卖出一支股票之后第二天会变成冷冻期，在冷冻期内不能进行股票的买入操作

大体的动态规划思路和 *122.买卖股票的最佳时机II* 类似。使用 `dp[i][0]` 表示在第 `i` 天持有股票时候能够获得的最大利润，`dp[i][1]` 表示在第 `i` 天不持有股票且在冷冻期能够获得的最大利润，`dp[i][2]` 表示在第 `i` 天不持有股票且不在冷冻期能够获得的最大利润

- `dp[i][0]` 可以从以下两种情况获取
  - 第 `i - 1` 天就持有股票了，那么 `dp[i][0] = dp[i - 1][0]`
  - 第 `i - 1` 天不持有股票并且在冷冻期，这样的话第 `i` 天就不是冷冻期了，那么 `dp[i][0] = dp[i - 1][1] - prices[i]`
- `dp[i][1]` 由于第 `i` 天在冷冻期，因此第 `i` 天做不了任何事情，能够获得的最大利润只能等于第 `i - 1` 天不在冷冻期且不持有股票时候的利润（因为第 `i` 天是冷冻期的话，第 `i - 1 ` 天就不可能是冷冻期了），即 `dp[i][1] = dp[i - 1][2]`
- `dp[i - 1][2]` 能够从以下三种情况获取
  - 第 `i - 1` 天不持有股票并且是冷冻期，那么 `dp[i][2] = dp[i - 1][1]`
  - 第 `i - 1` 天不持有股票并且不是冷冻期，那么 `dp[i][2] = dp[i - 1][2]`
  - 第 `i - 1` 天持有股票，那么 `dp[i][2] = dp[i - 1][0] + prices[i]`

综上所述，`dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i])`，`dp[i][1] = dp[i - 1][2]`，`dp[i][2] = max({dp[i - 1][1], dp[i - 1][2], dp[i - 1][0] + prices[i]})`。由于 `dp[i][2] >= dp[i][1]`，因此 `dp[i][2] = max(dp[i - 1][2], dp[i - 1][0] + prices[i])`。👉 [买卖股票的最佳时机含冷冻期](./动态规划/股票问题/309%20买卖股票的最佳时机含冷冻期.cc)

> 重点是理解冷冻期这个状态，在这里如果当天进行了股票卖出，那么当前不算冷冻期，第二天才算冷冻期

[714.买卖股票的最佳时机含手续费](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)：本题与 **122.买卖股票的最佳时机II** 的区别在于，现在每一笔交易都需要支付手续费了（可以只考虑在卖出股票的时候支付手续费）。这道题比较简单，直接套用 *122.买卖股票的最佳时机II* 的递推公式就可以了，👉 [买卖股票的最佳时机含手续费](./动态规划/股票问题/714%20买卖股票的最佳时机含手续费.cc)

`dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i])`，`dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee)`

### 子序列问题

[53.最大子数组和](https://leetcode-cn.com/problems/maximum-subarray/)：给你一个整数数组 `nums`，找出具有最大和连续子数组，返回该子数组的和。这道题有三种解法

1. 贪心算法。我们知道 `nums[i]` 如果小于 0 只会拉低数组的连续和，因此我们使用一个 `cur` 表示当前的连续数组和，如果发现 `cur` 小于 0 了，那么就从 0 重新开始。
2. 动态规划。使用 `dp[i]` 表示以 `nums[i]` 为结尾的子数组的最大和，`dp[i]` 只会从以下两种情况获取。所以 `dp[i] = max(dp[i - 1] + nums[i], nums[i])`
   - `dp[i - 1] + nums[i]`，即 `nums[i]` 前面还有连续的元素
   - `nums[i]`，即以 `nums[i]` 一个元素作为子数组
3. 分治。
   - 对于每一个区间 `[l, r]` 维护四个状态：
     - `lSum` 表示以 `l` 为左端点的最大子段和;
     - `rSum` 表示以 `r` 为右端点的最大子段和;
     - `mSum` 区间 `[l, r]` 的最大子段和;
     - `iSum` 表示区间 `[l, r]` 的区间和
   - 那么原问题的答案就是区间 `[0, nums.size() - 1]` 区间的 `mSum`，其中 `l = 0, r = nums.size() - 1`
   - 对于该问题可以分别求解 `[l, m]` 和 `[m, r]` 的状态，分别记为 `left` 和 `right`
   - 这样区间 `[l, r]` 的状态 `status` 可以从 `left` 和 `right` 推导得到，具体为：
     - `status.iSum = left.iSum + right.iSum`
     - `status.lSum = max(left.lSum, left.iSum + right.lSum)`
     - `status.rSum = max(right.rSum, right.iSum + left.rSum)`
     - `status.mSum = max({left.mSum, right.mSum, left.rSum + right.lSum})`
   - 递归的出口为 `l == r` 的时候，此时四个状态都是 `nums[l]`

> 进阶：输出最大子数组的区间下标。贪心算法在 `count > res` 的时候更新 `resLeft = tmpLeft, resRight = i`，当 `count < 0` 的时候更新 `tmpLeft = i`

[674.最长连续递增子序列](https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence/)：给出一个数组 `nums`，找出其中最长的并且连续递增的子序列长度。👉 [最长连续递增子序列.cc](./贪心/674%20最长连续递增序列.cc)

这道题比较简答，只需要判断 `nums[i] > nums[i - 1]` 就增加当前连续序列的长度 `cur`，并且更新最后结果 `res = max(res, cur)`，如果 `nums[i] <= nums[i - 1]` 那么 `cur = 1`

[1143.最长公共子序列](https://leetcode-cn.com/problems/longest-common-subsequence/)：给定两个字符串 `text1` 和 `text2`，返回两个字符串的最长公共子序列的长度，如果不存在公共子序列就返回 0。👉 [最长公共子序列.cc](./动态规划/1143%20最长公共子序列.cc)

`dp[i][j]` 表示 `text1[0...i]` 和 `text2[0...j]` 之间的最长公共子序列的长度，则有

- 如果 `text1[i] == text2[j]`，那么 `dp[i][j] = dp[i - 1][j - 1] + 1`
- 如果 `text1[i] != text2[j]`，那么 `dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])`

初始化的时候如果 `text1[i] == text2[0]` 那么 `dp[i][0] = 1`，然后 `i` 之后的所有 `dp[i][0]` 都是 1；同理如果 `text2[j] == text1[0]` 那么 `dp[0][j] = 1`，然后 `j` 之后的所有 `dp[0][j]` 都是 1

[1035.不相交的线](https://leetcode-cn.com/problems/uncrossed-lines/)：在两条独立的水平线上写下 `nums1` 和 `nums2` 两个数组中的元素，现在可以绘制一些连接两个数字 `nums1[i]` 和 `nums2[j]` 之间的直线，要求 `nums1[i] == nums2[j]` 并且这些线不能相交、同一个数字只能连线一次，求能够绘制出的最大连线数量

这道题本质上就是求 `nums1` 和 `nums2` 的最长公共子序列，因此具体解题方法和 **1143.最长公共子序列** 完全一样

> 小结：对于连续子序列或者子数组来说 `dp[i]` 的定义是以 `nums[i]` 结尾并且需要使用到 `nums[i]` 时候的最优值；而对于不要求连续的子序列或子数组题目来说，`dp[i]` 的定义是 `nums[0...i]` 以来的最优值。⚠️ 这之间的区别
> 
> 对于连续的题目来说最后返回的是 `*max_element(dp.begin(), dp.end())`；对于不要求连续的题目来说，最后返回的是 `dp[n -1]`
>
> 上述的结论可以扩展到二维的 `dp` 数组

[152.乘积最大子数组](https://leetcode-cn.com/problems/maximum-product-subarray/)：给你一个整数数组 `nums`，请你找出数组中乘积最大的非空连续子数组，并返回该子数组对应的乘积。👉 [乘积最大子数组](动态规划/152%20乘积最大子数组.cc)

如果 `nums[i]` 是负数的话，我们希望用一个负数和 `nums[i]` 相乘；如果 `nums[i]` 是一个正数的话，我们希望用一个正数和 `nums[i]` 相乘。因此使用 `fmax[i]` 记录以 `nums[i]` 结尾的连续乘积的最大值，`fmin[i]` 记录以 `nums[i]` 结尾的连续乘积的最小值

- `fmax[i] = max({fmin[i] * nums[i], fmax[i] * nums[i], nums[i]})`
- `fmin[i] = min({fmin[i] * nums[i], fmax[i] * nums[i], nums[i]})`

也可以用常数空间优化

[392.判断子序列](https://leetcode-cn.com/problems/is-subsequence/)：给定字符串 `s` 和 `t`，判断 `s` 是否是 `t` 的子序列

1. 双指针。指针 `i` 指向 `s` 字符串，指针 `j` 指向 `t` 字符串，对于每一个 `s[i]` 如果 `s[i] == t[j]` 就让 `i++, j++`；否则只有 `j++`
2. 动态规划。使用 `dp[i][j]` 表示 `s[0...i]` 是不是 `t[0...j]` 的子序列，则有
   - 如果 `s[i] == t[j]`，即 `s` 当前遍历到的字符和 `t` 当前的字符相等，那么 `dp[i][j] = dp[i - 1][j - 1]`（只要 `s[0...i-1]` 是 `t[0...j-1]` 的子序列即可）
   - 如果 `s[i] != t[j]`，那么 `dp[i][j] = dp[i][j - 1]`（即只要 `s[0...i]` 是 `t[0...j-1]` 的子序列即可）
3. 动态规划。采用 **1143.最长公共子序列** 的方法，求出 `s` 和 `t` 的最长公共子序列长度 `len`，如果 `len == s.size()` 则说明 `s` 是 `t` 的子序列，否则不是

👉 [判断子序列.cc](./动态规划/392%20判断子序列.cc)

> 如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？
> 
> 可以采用动态规划预处理出 `t` 中字符 `j` 在下标 `i` 之后第一次出现的位置，即使用 `dp[i][j]` 表示字符串 `t` 中、字符 `j` 在下标 `i` 之后第一次出现的位置。`if t[i] == j, d[i][j] = i`，`if t[i] != j, dp[i][j] = dp[i + 1][j]` 即在 `i + 1` 开始往后的位置寻找 `j` 第一次出现的位置。
> 
> 预处理完成之后，只需要遍历字符串 `s` 然后找到 `s[i]` 在 `t` 中出现的位置记为 `add`；然后继续找 `s[i + 1]` 在 `t` 中出现的位置 `add = dp[add][s[i + 1] - 'a']`；如果 `add == t.size()` 即说明不存在，那么就返回 false；当所有的 `s[i]` 都被找到了之后就返回 true

[115.不同的子序列](https://leetcode-cn.com/problems/distinct-subsequences/)：给定两个字符串 `s` 和 `t`，计算在 `s` 的子序列中 `t` 出现的个数。👉 [不同的子序列.cc](./动态规划/115%20不同的子序列.cc)

使用 `dp[i][j]` 表示 `s[0...i]` 的所有子序列中 `t[0...j]` 出现的个数，对于 `dp[i][j]` 可以从以下两种情况推出来：

1. `s[i] == t[j]`，则这里又可以有两种情况
   1. 使用 `s[i]` 匹配 `t[j]`，此时`dp[i][j]` 的值就是在 `s[0...i-1]` 中匹配到 `t[0...j-1]` 的个数，即 `dp[i][j] = dp[i - 1][j - 1]`
   2. 不使用 `s[i]` 匹配 `t[j]`，此时 `d[[i][j]` 的值就是在 `s[0...i-1]` 中匹配到 `t[0...j]` 的个数，即 `dp[i][j] = dp[i - 1][j]`
2. `s[i] != t[j]`，这时候 `dp[i][j]` 只能等于 `s[0...i-1]` 中匹配到 `t[0...j]` 的个数，即 `dp[i][j] = dp[i - 1][j]`

综上，`dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1], s[i] == t[j]`，`dp[i][j] = dp[i - 1][j], s[i] != t[j]`

[583.两个字符串的删除操作](https://leetcode-cn.com/problems/delete-operation-for-two-strings/)：给定两个单词 `word1` 和 `word2`，每次操作可以删除某一个单词中的一个字符，求出最后使得 `word1 == word2` 所需的最小操作步数。👉 [两个字符串的删除操作.cc](./动态规划/583%20两个字符串的删除操作.cc)

有两种动态规划方式：

1. 借助 **1143.最长公共子序列** 方法求出 `word1` 和 `word2` 的公共子序列长度，然后对于 `word1` 来说需要删除的字符个数是 `word1.size() - lcs`，对于 `word2` 来说需要删除的字符个数是 `word2.size() - lcs`。那么本题最后的答案就是 `word1.size() - lcs + word2.size() - lcs`
2. 也可以直接定义 `dp[i][j]` 表示 `word1[0...i]` 到 `word2[0...j]` 所需要的最小删除步数
   - 如果 `word1[i] == word2[j]`，那么从 `word1[0...i]` 到 `word2[0...j]` 的步数就是 `word1[0...i-1]` 到 `word2[0...j-1]` 的步数，即 `dp[i][j] = dp[i - 1][j - 1]`
   - 如果 `word1[i] != word2[j]`，此时如果我们知道 `word1[0...i-1]` 到 `word2[0...j]` 的步数，然后再删除 `word1[i]` 即可；或者如果知道 `word1[0...i]` 到 `word2[0...j-1]` 的步数，然后再删除 `word2[j]` 即可。即 `dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1`

> 第二种方法 `dp` 数组定义成 `(m + 1) * (n + 1)` 更加方便初始化，此时 `dp[0][k] = k, dp[k][0] = k`。具体的 `dp` 数组意思现在表示的是前 `i` 个字符和前 `j` 个字符

[72.编辑距离](https://leetcode-cn.com/problems/edit-distance/)：给定两个字符串 `word1` 和 `word2` 求出从 `word1` 转化为 `word2` 所需的最小步数，每一步可以执行的操作有：删除一个字符、插入一个字符、修改一个字符。👉 [编辑距离.cc](./动态规划/72%20编辑距离.cc)

记 `dp[i][j]` 表示 `word1[0...i-1]` 转化为 `word2[0...j-1]` 所需的最小步数，其递推公式如下：

1. 如果 `word1[i - 1] == word2[j - 1]`，那么不需要执行任何新的操作，此时的最小步数就是从 `word1[0...i-2]` 转化为 `word2[0...j-1]` 的步数，即 `dp[i][j] = dp[i - 1][j - 1]`
2. 如果 `word1[i - 1] != word2[j - 1]`，此时有三种操作可以执行：
   - 首先从 `word1[0...i-2]` 转化为 `word2[0...j-1]`，即先知道 `dp[i - 1][j]`，然后删除字符 `word1[i - 1]`（删除操作）
   - 首先从 `word1[0...i-1]` 转化为 `word1[0...j-2]`，即先知道 `dp[i][j - 1]`，然后在 `word1` 中插入 `word2[j - 1]`（插入操作）
   - 首先从 `word1[0...i-2]` 转化为 `word2[0...j-2]`，即先知道 `dp[i - 1][j - 1]`，然后修改 `word1[i - 1]` 为 `word2[j - 1]`（修改操作）

综上，`dp[i][j] = dp[i - 1][j - 1], word1[i - 1] == word2[j - 1]`，`dp[i][j] = max({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]}) + 1, word1[i - 1] != word2[j - 1]`

[647.回文子串](https://leetcode-cn.com/problems/palindromic-substrings/)：给你一个字符串 `s`，统计并返回字符串中回文字串的数量。👉 [回文字串.cc](./动态规划/647%20回文字串.cc)

- 方法一：动态规划
  - 记 `dp[i][j]` 表示 `s[i...j]` 是不是一个回文串，此时有：如果 `s[i] == s[j]` 那么 `dp[i][j] = dp[i + 1][j - 1]`，否则 `dp[i][j] = false`
  - 初始条件：`dp[i][j] = true, i >= j`
- 方法二：双指针，具体实现看下面的代码

```c++
/// 双指针方法
int countSubstrings(string s) {
  int result = 0;
  for (int i = 0; i < s.size(); i++) {
    result += extend(s, i, i, s.size());     // 以i为中心
    result += extend(s, i, i + 1, s.size()); // 以i和i+1为中心
  }
  return result;
}
int extend(const string &s, int i, int j, int n) {
  int res = 0;
  while (i >= 0 && j < n && s[i] == s[j]) {
    i--;
    j++;
    res++;
  }
  return res;
}
```

[516.最长回文子序列](https://leetcode-cn.com/problems/longest-palindromic-subsequence/)：给定一个字符串 `s`，返回其中最长的回文子序列的长度。👉 [最长回文子序列.cc](./动态规划/516%20最长回文子序列.cc)

注意这道题是回文子序列而不是回文串。使用 `dp[i][j]` 表示 `s[i-1...j-1]` 的最长回文子序列的长度，则有：

- 如果 `s[i - 1] == s[j - 1]`，那么 `s[i-1...j-1]` 的最长回文子序列长度可以由 `s[i...j-2]` 获得，即 `dp[i][j] = dp[i + 1][j - 1] + 2`
- 如果 `s[i - 1] != s[j - 1]`，那么 `s[i-1...j-1]` 的最长回文子序列长度要么是 `s[i...j-2]` 的最大长度，要么是 `s[i...j-1]` 的最大长度，即 `dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])`

最后返回 `dp[1][n]` 就是题目所求的最后解

> 小结：有时候 `dp[i]` 表示 `s[0...i-1]`，有时候 `dp[i]` 表示 `s[0...i]`，具体情况需要具体分析。一般来说用来表示 `s[0...i-1]` 在大多数情况下都是可以的，但是如果可以的话用来表示 `s[0...i]` 更好理解一些

### 其他

[剑指 Offer 46. 把数字翻译成字符串 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/)：给你一个数字按照如下规则翻译为字符串，0-'a'、1-'b'、...、25-'z'，请问有多少种翻译方法。👉 [<u>剑指Offer 46 把数字翻译成字符串</u>](动态规划/剑指Offer%2046%20把数字翻译成字符串.cc)

我们每次可以记录前一个子串中以最后一个字符为结尾的翻译方案数 prev_tail，以及总的翻译方法数 prev_cnt。例如对于 122，我们记录以 2 结尾的翻译方法有 2 个，总的翻译方法数有 3 个。此时对于 1225，以 5 结尾的方案数就等于 3 个，总的方案数等于 3 + 2 = 5

通过前面的分析，可以得到 prev_tail 和 prev_cnt 的转移方程：

```c++
prev_tail = prev_cnt
prev_cnt = prev * 10 + vec[i] < 26 && prev != 0 ? prev_cnt + prev_tail : prev_cnt
```

或者：`f(i) = f(i − 1) + f(i − 2)`

[10.正则表达式](https://leetcode-cn.com/problems/regular-expression-matching/)：给你一个字符串 `s` 和字符串 `p`，请你来实现支持 `.` 和 `*` 的正则表达式匹配。👉 [<u>正则表达式</u>](动态规划/10%20正则表达式.cc)

使用 `dp[i][j]` 表示 `s[0...i-1]` 和 `p[0...j-1]` 能否匹配。有以下几种情况：

1. `p[j - 1] == '*'`，此时可以尝试匹配 `*` 规则，也可以跳过 `*` 规则的匹配

   - `if match(i, j - 1)` 并且尝试匹配 `*` 规则，那么 `s[0...i-1]` 和 `p[0...j-1]` 的匹配就转化为 `s[0...i-2]` 和 `p[0...j-1]` 的匹配，即 `dp[i][j] = dp[i - 1][j]`。例如 `s = "ccc"` 和 `p = "c*"`，此时 `dp[3][2] = dp[2][2]` 
   - 如果跳过 `*` 规则的匹配，那么 `dp[i][j] = dp[i][j - 2]`

2. `p[j - 1] != '*'`，如果 `match(i, j)` 那么 `dp[i][j] = dp[i - 1][j - 1]`，否则 `dp[i][j] = false`

```c++
// 判断 s[i - 1] 和 p[j - 1] 是否匹配
auto match = [&](int i, int j) -> bool {
  if (i == 0)
    return false;
  return s[i - 1] == p[j - 1] || p[j - 1] == '.';
};
```

[221.最大正方形](https://leetcode-cn.com/problems/maximal-square/)：在一个由 `0` 和 `1` 组成的二维矩阵内，找到只包含 `1` 的最大正方形，返回其面积。👉 [<u>最大正方形</u>](动态规划/221%20最大正方形.cc)

使用 `dp[i][j]` 表示以 `matrix[i - 1][j - 1]` 为右下角的正方形的最大边长，则有 `dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1])`，即 `(i, j)` 为右下角的正方形的边长取决于 `(i - 1, j - 1)`、`(i - 1, j)` 、`(i, j - 1)` 为右下角的正方形边长，其值为它们中的最小值加一

[5.最长回文子串](https://leetcode-cn.com/problems/longest-palindromic-substring/)：给你一个字符串 `s`，找到 `s` 中的最长回文子串返回。👉 [<u>最长回文子串</u>](./动态规划/5%20最长回文子串.cc)

- 方法一：动态规划。时间复杂度 `O(n^2)`，空间复杂度 `O(n^2)`
  - 使用 `dp[i][j]` 表示 `s[i-1...j-1]` 是不是一个回文串，边更新 `dp` 数组边记录最长回文串的起始位置和长度

- 方法二：中心扩展。时间复杂度 `O(n^2)`，空间复杂度 `O(1)`
  - 遍历字符串 `s`，对于下标 `i`，从 `i` 和 `(i, i + 1)` 往左右两边扩展，找到最长的回文串


[1155.掷骰子的N种方法]([1155. 掷骰子的N种方法 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/number-of-dice-rolls-with-target-sum/))：给你 `n` 个一样的骰子，每个骰子上面有 `k` 个面，分别标号为 `1` 到 `k`。给定三个整数 `n`，`k` 和 `target`，求出投掷 `n` 个骰子使得正面朝上的数字之和等于 `target` 的总数，答案对 `1e9 + 7` 去模。👉 [<u>掷骰子的N种方法</u>](动态规划/1155%20掷骰子的N种方法)

这题使用回溯法会超时，因此考虑使用动态规划求解。`dp[i][j]` 表示投掷 `i` 个骰子，其和等于 `j` 的种数

`dp[i][j] += dp[i - 1][j - t]`，即投掷 `i - 1` 个骰子，这 `i - 1` 个骰子的和等于 `j - t`，然后第 `i` 个骰子投出 `t` 这个数即可

初始的时候 `dp[1][i] = 1`，`1 <= i <= min(k, target)`

[32.最长有效括号](https://leetcode-cn.com/problems/longest-valid-parentheses/)：给你一个只包含 `(` 和 `)` 的字符串，找出最长有效括号子串的长度。👉 [<u>最长有效括号</u>](动态规划/32%20最长有效括号.cc)

本题有多种解法：

   - 动态规划。时间复杂度 `O(n)`，空间复杂度 `O(n)`
   - 栈。时间复杂度 `O(n)`，空间复杂度 `O(n)`
   - 双指针。时间复杂度 `O(n)`，空间复杂度 `O(1)`

下面介绍动态规划方法的思路。使用 `dp[i]` 表示以 `s[i]` 为右边界的有效括号子串长度，则如果

1. `s[i] == '('`，`dp[i] = 0`
2. `s[i] == ')'`，此时可以判断 `s[i - 1]` 是否为 `(`
   - 如果 `s[i - 1] == '('`，`dp[i]` 就等于以 `s[i - 2]` 为结尾的有效括号子串长度加 2，即 `dp[i] = dp[i - 2] + 2`
   - 如果 `s[i - 1] == ')'`，此时说明以 `s[i]` 结尾的有效括号子串的序列是 `...))`，其中以 `s[i - 1]` 结尾的有效括号子串的起始位置为 `i - dp[i - 1]`，因此进一步的，我们可以判断 `s[i - dp[i - 1] - 1]`
     - 如果 `s[i - dp[i - 1] - 1] == '('`，此时 `s[i - dp[i - 1] - 1]` 和 `s[i]` 可以组成一对括号，那么 `dp[i]` 可以由 `s[i - 1]` 匹配的长度 `dp[i - 1]`、`s[i]` 匹配的长度 2、`s[i - dp[i - 1] - 2]` 匹配的长度 `dp[i - dp[i - 1] - 2]` 组成，即 `dp[i] = dp[i - 1] + 2 + dp[i - dp[i - 1] - 2]`，
     - 如果 `s[i - dp[i - 1] - 1] == ')'`，`dp[i] = 0`

```c++
int longestValidParentheses(string s) {
  int n = s.size();
  vector<int> dp(n);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(')
      continue;
    if (i - 1 >= 0 && s[i - 1] == '(')
      dp[i] = (i - 2 >= 0 ? dp[i - 2] : 0) + 2;
    else if (i - 1 >= 0 && s[i - 1] == ')') {
      if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')
        dp[i] = dp[i - 1] + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0) + 2;
    }
  }
  return !dp.empty() ? *max_element(dp.begin(), dp.end()) : 0;
}
```

下面介绍栈方法的思路。栈顶部的元素表示「最后一个没有被匹配的右括号的下标」

- 当遇到 `(` 时即将其压入栈中
- 当遇到一个右括号的时候就弹出栈顶元素，然后
  - 如果此时栈不为空，那么当前元素的下标减去栈顶元素的下标就是以当前元素结尾的有效括号的长度
  - 如果栈为空，那么就将当前元素压入栈中

```c++
int longestValidParentheses(string s) {
  stack<int> stk;
  // 避免第一个不匹配的 ')' 没有东西弹出
  stk.push(-1);
  int res = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '(')
      stk.push(i);
    else {
      stk.pop();
      if (!stk.empty()) {
        int index = stk.top();
        res = max(res, i - index);
      } else {
        stk.push(i);
      }
    }
  }
  return res;
}
```

下面介绍双指针方法的思路，双指针方法贪心的考虑了以当前字符为结尾的有效括号的长度。每当遇到一个 `(` 就增加 `left` 计数器，每当遇到右括号就增加 `)` 计数器，当 `left = right` 的时候更新最长有效括号的长度，当 `right > left` 的时候重置 `left = right = 0`。但是这样无法求出左括号数量大于右括号数量的情况，例如 `(()`，这时候只需要反向扫描计算一遍即可

```c++
int longestValidParentheses(string s) {
  int left = 0, right = 0, res = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '(')
      left++;
    else if (s[i] == ')')
      right++;

    if (left == right)
      res = max(res, left + right);
    else if (right > left) {
      left = right = 0;
    }
  }
  left = right = 0;
  for (int i = s.size() - 1; i >= 0; --i) {
    if (s[i] == ')')
      right++;
    else if (s[i] == '(')
      left++;

    if (left == right)
      res = max(res, left + right);
    else if (left > right) {
      left = right = 0;
    }
  }
  return res;
}
```

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

[3.无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/)：给定一个字符串 `s`，请你找出其中不含有重复字符的最长子串的长度。👉 [<u>无重复字符的最长子串</u>](./滑动窗口/3%20无重复字符的最长子串.cc)

滑动窗口的思想，使用 `[left, right]` 表示当前窗口，最外层的 `while` 判断条件为 `right != s.size()`

1. 滑动窗口

   - 每次循环将当前 `s[right]` 添加到窗口中，即窗口扩张，并更新窗口长度 `res`
   - 如果发现 `map[s[right]] > 1` 说明此时窗口中有重复元素出现，那么开始收缩窗口，直到跳过了重复的那个元素为止

   ```c++
   int lengthOfLongestSubstring(string s) {
     unordered_map<char, int> map;
     int left = 0, right = 0, len = 0;
     while (right != s.size()) {
       char ch = s[right];
       map[ch]++;
       while (map[ch] > 1) {
         len = max(len, right - left);
         map[s[left]]--;
         left++;
       }
       right++;
     }
     return max(len, right - left);
   }
   ```

如果允许最多出现两个重复字符呢，只需要将 `map[ch] > 1` 改为 `map[ch] > 2` 即可；如果最多允许出现 `k` 个重复字符，那么就是 `map[ch] > k`

[30.串联所有单词的子串]([30. 串联所有单词的子串 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/))：给你一个字符串 `s` 和一些长度相同的单词 `words`。找出 `s` 中恰好可以由 `words` 中所有单词串联形成的子串的起始位置。注意子串要与 `words` 中的单词完全匹配，中间不能有其他字符。👉 [<u>串联所有单词的子串</u>](滑动窗口/30%20串联所有单词的子串.cc)

固定滑动窗口的大小为 `words` 中所有单词长度之和，然后窗口每次向右滑动一个单位，并切分窗口中的所有单词，判断是否刚好 `words` 中的所有单词匹配。这么做的时间复杂度为 `O(n^2)`

**进阶：给出时间复杂度为 `O(n)` 的方法、如果 `words` 中单词的长度不想等呢**

[76.最小覆盖子串](https://leetcode-cn.com/problems/minimum-window-substring/)：给定一个字符串 `s`、一个字符串 `t`，返回 `s` 中涵盖 `t` 所有字符的最小子串，如果 `s` 中不含盖 `t` 则返回空字符串 `""`。👉 [<u>最小覆盖子串</u>](滑动窗口/76%20最小覆盖子串.cc)

滑动窗口

- 使用一个 `unordered_map<char, int> map` 记录 `t` 中每个元素出现的次数
- 初始的时候窗口的左右边界为 `left = 0, right = 0`，`unordered_map<char, int> window` 记录当前窗口中 `t` 中字符的出现次数
- 不断扩展右边界直到 `window` 中所有的字符出现的数量都满足了 `map` 中的要求
- 此时开始收缩窗口，每次收缩的时候更新当前窗口起始位置 `start` 和窗口大小 `len`，直到 `window` 中刚好有一个字符出现的数量没有满足 `map` 的时候停止窗口收缩

[159. 至多包含两个不同字符的最长子串 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/longest-substring-with-at-most-two-distinct-characters/)：给定一个字符串 `s`，找出至多包含两个不同字符的最长子串，返回该子串的长度。👉 [至多包含两个不同字符的最长子串](滑动窗口/159%20至多包含两个不同字符的最长子串.cc)

基础的滑动窗口题目

[209.长度最小的子数组]([209. 长度最小的子数组 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/minimum-size-subarray-sum/))：给你一个含有 `n` 个正整数的数组和一个正整数 `target`，找出该数组中满足其和大于等于 `target` 的长度最小的连续子数组，并返回其长度，如果不存在则返回 0。👉 [<u>长度最小的子数组</u>](滑动窗口/209%20长度最小的子数组.cc)

本题有两种方法可以解决：

1. 使用一个滑动窗口记录当前窗口中元素的和，如果元素和大于等于 `target` 更新 `len`，并开始收缩窗口。时间复杂度 `O(n)`，空间复杂度 `O(1)`
2. 记录每一个元素的前缀和，然后枚举每一个元素 `nums[i]`，在前缀和数组 `vec` 中找到第一个元素值大于等于 `vec[i] - nums[i] + target` 的元素，这个查找过程可以使用二分查找。时间复杂度 `O(nlogn)`，空间复杂度 `O(n)`

**进阶：**

- 列出所有和为 `target` 的连续子序列。和本题一样的思路，在大于等于 `target` 的时候尝试开始收缩窗口，判断当前 `sum` 是不是等于 `target`，想等的话保存当前窗口中的子序列
- 如果数组里面有负数需要怎么处理。**862题**
- 将本题的 `target` 变为 `target` 的整数倍。

[340. 至多包含 K 个不同字符的最长子串 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/longest-substring-with-at-most-k-distinct-characters/)：给定一个字符串 `s`，找出至多包含 `k` 个不同字符的最长子串 `T`。👉 [<u>至多包含 K 个不同字符的最长子串</u>](340%20至多包含K个不同字符的最长子串.cc)

简单的滑动窗口

[395.至少有K个重复字符的最长子串]([395. 至少有 K 个重复字符的最长子串 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters/))：给你一个字符串 `s` 和一个整数 `k`，请你找出 `s` 中的最长子串，要求该子串中的每一个字符出现次数都不少于 `k`，返回这一子串的长度。👉 [<u>至少有K个重复字符的最长子串</u>](滑动窗口/395%20至少有K个重复字符的最长子串.cc)

1. 滑动窗口。时间复杂度 `O(26n)`
   - 枚举窗口中允许出现的字符种类数量 `i`
   - 使用一个 `map<char, int>` 记录当前窗口中每个字符出现的次数，`num` 记录当前窗口中字符出现次数小于 `k` 的种数
     - 当某一个字符第一次出现的时候即 `++map[ch] == 1` 的时候，`num++`
     - 当某一个字符出现次数达到 `k` 次的时候，即 `++map[ch] == k`，`num--`
   - 当 `map.size() > i` 的时候开始收缩窗口，收缩的时候需要更新 `map` 和 `num`
   - 每次判断 `num` 是否为 0，如果 `num = 0`，更新 `len = max(len, right - left + 1)`
2. 分治。时间复杂度 `O(26n) = O(n)`，由于每一次向下递归都会消除一个字符的出现，最多只能消除 26 个英文字母，因此最多只有 26 层递归
   - 首先计算字符串 `s[l...r]` 中每个字符出现的次数
   - 然后将 `s` 按照某个出现次数小于 `k` 的字符 `split` 进行分割，这是因为满足题目要求的子串必定不会跨越 `split` 字符
   - 对每一个分割得到的子串都递归的调用处理函数
   - 当某一次递归发现没有出现次数小于 `k` 的字符的时候，就返回 `r - l + 1`，递归停止

[424. 替换后的最长重复字符 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/longest-repeating-character-replacement/)：给定一个字符串 `s` 和一个整数 `k`，你可以选择任意一个字符，并将其更改为任何其他字符，该操作最多执行 `k` 次，求出执行上述操作之后包含相同字母的最长子字符串的长度。👉 [替换后的最长重复字符](滑动窗口/424%20替换后的最长重复字符.cc)

使用 `count` 记录当前窗口中出现次数最多的字符，每次尝试将其他字符替换成该字符，这样可以使的替换的次数最少，`count = max(count, map[s[r]])`

窗口的收缩条件是，除了该字符之外其余的字符出现的次数之和大于 `k` 了，即 `r - l + 1 - count > k`

每次 `r` 右移的时候更新最长的长度

[438. 找到字符串中所有字母异位词 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/)：给定两个字符串 `p` 和 `q`，找到 `s` 中所有 `p` 的异位词的子串，返回这些子串的索引。👉 [<u>找到字符串中所有字母异位词</u>](滑动窗口/438%20找到字符串中所有字母异位词.cc)

和 **567题** 差不多，多了一步保存子串的起始位置的步骤

[567. 字符串的排列 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/permutation-in-string/)：给你两个字符串 `s1` 和 `s2`，判断 `s2` 中是否包含了 `s1`。👉 [<u>字符串的排列</u>](滑动窗口/567%20字符串的排列.cc)

1. 方法一：在 `s2` 中找到第一个在 `s1` 中出现的字符，然后往后开始滑动窗口。窗口收缩的条件是，窗口中有一个字符出现的次数大于 `s1` 中该字符出现的次数了
2. 方法二：固定窗口的大小滑动窗口，窗口的收缩条件是窗口大小大于 `s1` 的长度了。一旦窗口中的所有字符满足 `s1` 中出现的次数了，那么就返回 `true`

[632. 最小区间 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/smallest-range-covering-elements-from-k-lists/)：给出 `k` 按照非递减顺序排列的整数列表，找到一个最小的区间，使得 `k` 个列表中的每个列表至少有一个数包含在其中。长度小的区间就是最小区间，长度相同的时候，左边界小的区间更小。👉 [最小区间](滑动窗口/632%20最小区间.cc)

1. 排序 + 滑动窗口，时间复杂度 `O(nklogk)`，其中 `n` 是 列表的长度，`k` 是列表的个数，空间复杂度 `O(nk)`。首先对 `k` 个列表归并排序，并在新的数组中记录每个元素来自哪个列表。然后使用滑动窗口，当窗口中包含了来自 `k` 个列表的元素的时候，收缩窗口，并更新最小区间的值
2. 贪心 + 最小堆。类似于合并 K 个升序链表一样，我们可以将 k 个整数列表看成链表，并使用一个数组维护每个列表下一个元素的下标。初始的时候将所有列表的第 0 个元素存入堆上，每次从堆顶弹出一个元素，更新此时的 `minVal` 以及 `maxVal`，然后将该元素所属列表的下一个元素存入堆中

[713. 乘积小于K的子数组 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/subarray-product-less-than-k/)：给定一个正整数数组 `nums` 和整数 `k`，请找出该数组内乘积小于 `k` 的连续子数组的个数。👉 [乘积小于K的子数组](滑动窗口/713%20乘积小于K的子数组.cc)

**滑动窗口求方案数/个数**

`mul` 维护当前窗口内元素的乘积，当 `mul` 大于等于 `k` 的时候收缩窗口。每个窗口扩张之后更新 `res += r - l + 1`，相当于添加了以 `r` 为结尾的所有子数组，由于 `[l, r]` 的乘积此时小于 `k`，因此以 `r` 为结尾的子数组的乘积也小于 `k`

[718. 最长重复子数组 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/)：给你两个整数数组 `nums1` 和 `nums2`，返回两个数组中的公共子数组的最长长度。👉 [最长重复子数组](滑动窗口/718%20最长重复子数组.cc)

以下三种方法可以解决该问题：

1. 滑动窗口。我们可以将其中一个数组固定不动，然后使用另一个数组在它上面滑动，每滑动一次记录一次最长公共子数组的长度。时间复杂度 O((m + n) * min(m, n))，空间复杂度 O(1)
2. 动态规划。`dp[i][j]` 表示以数组 `nums1[i - 1]` 和 `nums2[j - 1]` 为结尾的公共子数组的长度，因此 `nums1[i - 1] == nums2[j - 1]` 则 `dp[i][j] = dp[i - 1][j - 1] + 1`，否则就为 0

[904. 水果成篮 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/fruit-into-baskets/)：`fruits[]` 表示每棵果树种的水果类型，你的篮子最多只能存放两种类型的水果，你可以选择从任意一颗果树开始采摘，求出能够摘到的水果最多有多少。👉 [水果成篮](滑动窗口/904%20水果成篮.cc)

我们可以使用一个滑动窗口表示当前采摘果树的返回，当窗口内部包含了 3 种果树的时候对窗口进行收缩。每次窗口扩张之后更新能够摘到的最多水果的数量 `res = max(res, r - l + 1)`

[930. 和相同的二元子数组 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/binary-subarrays-with-sum/)：给你一个二元数组 `nums` 和一个整数 `goal`，请你统计并返回有多少个和为 `goal` 的非空子数组。👉 [和相同的二元子数组](滑动窗口/930%20和相同的二元子数组.cc)

1. 滑动窗口，转化为类似 **992题** 这样前缀和的方式。我们可以把题目看成找出和恰好等于 `goal` 的子数组数量，因此可以先求出和小于等于 `goal` 以及 `goal - 1` 的子数组数量，然后做差就是和恰好等于 `goal` 的子数组数量了。时间复杂度 `O(n)`，空间复杂度 `O(1)`
2. 滑动窗口，和方法一相同，同样是前缀和的思想，只是实现方式不太一样。对于每个右边界 `r`，我们维护两个窗口，`[l1, r]` 中的元素满足和小于等于 `goal`，`[l2, r]` 中的元素满足和小于 `goal`。因此对于 `[l1, l2)` 中每个元素都可以作为 `r` 的左边界，使得该子数组中的元素之和恰好等于 `goal`
3. 哈希。我们可以记录每一个前缀和的子数组数量，当枚举到 `nums[i]` 的时候，可以查询 `map[sum - goal]` 的数量，就是以 `nums[i]` 作为右边界的满足题目要求的子数组数量

[992. K 个不同整数的子数组 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/subarrays-with-k-different-integers/)：给定一个正整数数组 `nums` 和一个整数 `k`，返回 `nums` 中「好子数组」的个数。好子数组定义为，`nums` 的某个子数组中恰好存在 `k` 个不同的整数。👉 [K个不同整数的子数组](滑动窗口/992%20K个不同整数的子数组.cc)

**滑动窗口求方案数/个数**

这道题和之前做的比较多的滑动窗口题目不太相同，之前做的比较多的题目的类型是：「窗口中恰好有、或者最多有」多少个不同的字符这类题目，强调的是对窗口中元素的判断。而这道题不能仅仅判断窗口中存在 `k` 个不同整数就为止了，例如 [1,2,3,3,4]，k = 3，当我们的窗口右边界滑动到下标 3 的时候，此时如果收缩窗口的话就会忽略 [1,2,3] 这组答案

我们可以将题目转化为：`nums` 中最多包含 `k` 个不同元素的子数组有多少个。如果我们用函数 `slide_window` 来处理的话，那么恰好包含 `k` 不同元素的结果就是 `slide_window(nums, k) - slide_window(nums, k - 1)`。而对于 `slide_window(nums, k)` 这个函数而言，就可以使用滑动窗口来解决了：

- 当窗口右边界增加到 `[l, r]` 的时候，此时新增的「最多包含 `k` 个元素」的子数组的个数就是 `r - l + 1`（所有以 `r` 为结尾的数组个数）
- 当窗口中元素的个数大于 `k` 的时候需要对左边界收缩之后再进行计算，否则的话最左边那个元素到最右边那个元素组成的子数组中元素的个数就会大于 `k` 了
- 不断滑动窗口，计算 `r - l + 1` 就可以得到包含 `k` 个不同元素的子数组个数了

计算得到 「最多包含 `k` 个不同元素的子数组」和「最多包含 `k - 1` 个不同元素的子数组」之后，两者做差就可以得到恰好有 `k` 个不同元素的子数组个数了

> 我们只需要一直统计以 `l` 开始的子数组个数即可，因为在 `(l, r)` 内部的区间个数等到滑动窗口往后移之后依然会被计算进去

[1004. 最大连续1的个数 III - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/max-consecutive-ones-iii/)：给定一个二进制数组 `nums` 和一个整数 `k`，如果可以翻转最多 `k` 个 `0`，则返回数组中连续 1 的最大个数。👉 [<u>最大连续1的个数III</u>](滑动窗口/1004%20最大连续1的个数III.cc)

1. 滑动窗口。滑动窗口中记录当前 0 的个数，当 0 的个数超过 k 的时候，记录此时窗口的长度就是最大的连续 1 的个数。然后开始收缩窗口，收缩到 0 的个数等于 k 的时候停止。之后继续扩展窗口、收缩窗口
2. 前缀和 + 二分查找。用一个数组 `vec` 记录 `nums` 中每个下标前面有多少个 0，然后遍历 `vec`，对于 `vec[i]` 来说，找到第一个 `vec[j] = vec[i] - k` 的元素，这里可以采用二分查找、因为 `vec` 数组是单调递增的。如果 `vec[i] - k <= 0` 则返回 0。因此对于下标 `i` 来说，它的最长连续 1 的长度就是 `i - j`

[1248. 统计「优美子数组」 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/count-number-of-nice-subarrays/)：给你一个整数数组 `nums` 和一个整数 `k`，如果某个连续的子数组中恰好有 `k` 个奇数数字我们就认为该子数组是「优美子数组」，请返回优美子数组的数目。👉 [统计优美子数组](滑动窗口/1248%20统计优美子数组.cc)

我们可以用滑动窗口求出至多有 `k` 个奇数数字的子数组数量，然后求出至多有 `k - 1` 个奇数数字的子数组数量，做差就可以得到恰好有 `k` 个奇数数字的子数组数量

[1658. 将 x 减到 0 的最小操作数 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/minimum-operations-to-reduce-x-to-zero/)：给你一个整数数组 `nums` 和一个整数 `x`。每一次操作时，你应当移除 `nums` 最左边或者最右边的一个元素，然后从 `x` 中减去该元素的值。如果可以将 `x` 恰好减到 0，返回最小的操作数，否则返回 -1。👉 [将x减到0的最小操作数](滑动窗口/1658%20将x减到0的最小操作数.cc)

题目可以转化为找到一个连续的子数组，使得子数组之和是 `sum_nums - x`，如果存在这样的子数组则返回子数组左右两边具体 `nums` 的距离，否则就返回 -1

所以可以使用滑动窗口来找到这样的子数组，当子数组中元素之和大于 `sum_nums - x` 的时候收缩窗口。每次窗口向右扩张的时候，判断当前元素和是否是 `sum_nums - x`，如果是的话更新 `res = min(res, l + nums.size() - 1 - r)`

[剑指 Offer 48. 最长不含重复字符的子字符串 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/)：请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。👉 [剑指 Offer 48. 最长不含重复字符的子字符串](滑动窗口/剑指%20Offer-48%20最长不含重复字符的子字符串.cc)

滑动窗口简单题，使用一个哈希表维护当前窗口内部每个字符出现的次数，如果有一个字符出现的次数大于 1 了，就开始收缩窗口、并计算当前窗口的长度

## 设计题

[146.LRU缓存]([146. LRU 缓存 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/lru-cache/))：请你设计并实现一个满足 LRU 缓存约束的数据结构，实现 LRUCache 类。👉 [<u>LRU缓存</u>](设计题/146%20LRU缓存.cc)

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

[225. 用队列实现栈 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/implement-stack-using-queues/)：请使用两个队列实现栈。👉 [用队列实现栈](设计题/225%20用队列实现栈.cc)

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

[232. 用栈实现队列 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/implement-queue-using-stacks/)：请你仅使用两个栈实现队列，要求每个操作的均摊时间复杂度是 O(1)。👉 [用栈实现队列](设计题/232%20用栈实现队列.cc)

**关键是实现栈顶就是队列头部**

- push：不断的将新的元素添加到 stack1
- pop：如果 stack2 不为空，那么直接从 stack2 栈顶弹出元素，然后返回元素的值。如果 stack2 为空，那么先将 stack1 中的元素全都放到 stack2 中，这个时候 stack2 的栈顶就是队列首部，然后从 stack2 栈顶弹出元素并返回元素值
- peek：和 pop 相同，只是不需要从 stack2 栈顶弹出元素了
- empty：stack1.empty() && stack2.empty()

[295. 数据流的中位数 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/find-median-from-data-stream/)：设计一个数据结构保存用户插入的数字，并且能够快速的返回这些数字的中位数。👉 [<u>数据流的中位数</u>](设计题/295%20数据流的中位数.cc)

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

[355. 设计推特 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/design-twitter/)：设计一个简化版的推特，可以让用户实现发送推文，关注/取消关注其它用户，能够看见关注人的最近 10 条推文。👉 [解答](设计题/355%20设计推特.cc)

对于用户关注列表，为了实现快速的添加和删除一个关注用户，使用 `unordered_map<int, unordered_set<int>>` 保存每个用户的关注列表，这样可以保证：

- follow 时间复杂度 `O(1)`
- unfollow 时间复杂度 `O(1)`

每个用户发送的推文使用 `unordered_map<int, list<pair<int, int>>>` 保存，为了给每条推特按照时间顺序排序，使用一个单调递增的全局 sequence 表示，sequence 越大表示这条推文距离现在越近。当用户查看最近的 10 条推文的时候，使用 `priority_queue` 来对多个有序 `list` 进行排序，选择前 10 条数据

`getNewsFeed` 时间复杂度：`O(nlogn)`，体现在初始建堆的时候

[381. O(1) 时间插入、删除和获取随机元素 - 允许重复 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/insert-delete-getrandom-o1-duplicates-allowed/)：实现 `RandomizedCollection` 类，能够插入和删除元素，并且能够随机的返回一个元素，每个元素被随机到的概率和元素出现的次数线性相关。👉 [O(1)时间插入、删除和获取随机元素](设计题/381%20O(1)时间插入、删除和获取随机元素.cc)

为了实现随机概率和元素出现次数线性相关，使用 vector 来保存元素，这样随机返回元素的时候只需要 vec[rand() % vec.size()] 就可以了

但是使用 vector 会带来删除元素的时间复杂度比较高，因此可以使用哈希表保存每个元素的所有索引位置，删除一个元素 val 的时候我们可以找到**该元素的其中一个索引位置**并且**和 vector 的最后一个位置的元素交换**，**然后 pop_back 最后一个元素就可以了**。最后更新 val 和 last_val 的索引

[460. LFU 缓存 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/lfu-cache/)：实现 LFUCache（最不经常使用缓存算法）。元素每被访问到一次就增加一次使用频率， 当缓存达到容量上限的时候移除频率最小的元素中最久未使用的 kv 节点。👉 [LFU缓存](设计题/460%20LFU缓存.cc)

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

[716. 最大栈 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/max-stack/)：设计一个最大栈的数据结构，除了常用的栈操作之外还需要支持 peekMax 获取栈中最大元素，popMax 移除栈中最靠近栈顶的最大元素并返回该值。👉 [最大栈](设计题/716%20最大栈.cc)

1. 使用 vector 模拟栈。peekMax 和 popMax 的时间复杂度都是 O(n)，其余操作时间复杂度 O(1)
   - peekMax 和 popMax，遍历 vector 找到最大值的迭代器，并删除该最大值
2. 使用双栈模拟最大栈。popMax 的时间复杂度是 O(n)，其余操作时间复杂度 O(1)。第一个栈是正常的栈，第二个栈存储第一个栈对应元素的位置到栈底的最大值
   - popMax，不断的弹出两个栈的元素存储到一个临时的栈上，当两个栈的元素相等的时候，说明此时第一个栈的栈顶就是最大值，弹出该元素，然后将临时栈上的元素全都放回去
3. 使用链表 + 红黑树模拟最大栈，红黑树中保存每个 value 对应的在 list 中的迭代器。除了 top 方法，其余方法的时间复杂度都是 O(logn)
   - push，需要在 list 的最后插入元素，并且还需要在 map[x] 的最后插入一个元素，找到 map[x] 的时间复杂度是 O(logn)
   - pop，从 list 的最后弹出元素，并且还需要在 map[x] 的最后弹出元素，当 map[x].size() = 0 的时候还需要从 map 中移除 x，找到 map[x] 的时间复杂度是 O(logn)
   - peekMax，返回 prev(map.end(), 1)->first，时间复杂度 O(logn)
   - popMax，找到 max_value 之后，从 map[max_value] 中找到最后的那个 list 迭代器，然后从 list 中移除这个元素，时间复杂度 O(logn)

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

[49.字母异位词分组](https://leetcode-cn.com/problems/group-anagrams/)：给你一个字符串数组，请你将字母异位词组合在一起。字母异位词指的是由重新排列源单词的字母得到的一个新单词。👉 [<u>字母异位词分组</u>](hot100/49%20字母异位词分组.cc)

对于每一个单词 `str` 对其进行排序之后作为哈希表的 `key`，然后讲 `str` 作为哈希表的 `value`，这样一来就可以得到一组字母异位词的所有集合了

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

