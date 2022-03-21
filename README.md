[TOC]

## 模拟

[415.字符串相加]([415. 字符串相加 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/add-strings/))：给你两个字符串形式表示的非负整数 `num1` 和 `num2`，计算它们的和并返回字符串的形式。👉 [<u>字符串相加</u>](模拟/415%20字符串相加.cc)

简单的模拟过程

[43.字符串相乘]([43. 字符串相乘 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/multiply-strings/))：给出两个字符串形式表示的整数 `num1`，`num2`，返回 `num1 * num2` 的字符串形式表示。👉 [<u>字符串相乘</u>](模拟/43%20字符串相乘.cc)

- 直接模拟乘法的执行过程

## 链表

[2.两数相加](https://leetcode-cn.com/problems/add-two-numbers/)：链表 `l1` 和 `l2` 以逆序的形式存储两个整数，例如 `2->4->3` 表示整数 342。返回 `l1 + l2` 的结果，结果同样用链表逆序方式表示。👉 [<u>两数相加</u>](./hot100/2%20两数相加.cc)

直接模拟即可

[23.合并 K 个升序链表](https://leetcode-cn.com/problems/merge-k-sorted-lists/)：给你一个链表数组，每个链表都按照升序排列，请你将所有的链表合并成一个升序链表，返回合并后的链表。👉 [<u>合并 K 个升序链表</u>](链表/23%20合并%20K%20个升序链表.cc)

1. 迭代归并排序。`left` 和 `right` 左右子链表两两合并
2. 堆排序。要求掌握手写堆排序。先将所有链表的头节点加入到堆中，按照节点值从小到大排序；然后每次从堆中取出一个元素，如果该元素还有 `next` 节点，就将 `next` 节点加入到堆中

[206.反转链表](https://leetcode-cn.com/problems/reverse-linked-list/)：给你一个链表的头节点 `head`，请你反转链表，并返回反转后的链表。👉 [<u>反转链表</u>](链表/206%20反转链表.cc)

分别使用 **迭代** 和 **递归** 实现。本题的递归写法比较简单，反转链表II 的递归写法比这道题难一些

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

[234.回文链表](https://leetcode-cn.com/problems/palindrome-linked-list/)：给你一个链表的头节点 `head`，请你判断该链表是否为回文链表。如果是，返回 `true`，否则返回 `false`

使用快慢指针首先找到链表的中间节点，然后对后半部分链表翻转，之后遍历两个子链表，判断元素是否相等。`slow` 指针从 `head` 开始，`fast` 指针从 `head->next` 开始

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

## 树

[98.验证二叉搜索树](https://leetcode-cn.com/problems/validate-binary-search-tree/)：给你一个二叉树 `root` 判断它是不是一棵有效的二叉搜索树。👉 [<u>验证二叉搜索树</u>](二叉树/98%20验证二叉搜索树.cc)

1. 递归（后序遍历）。需要记录左右子数的 `{min_val, left_val, isValid}`，然后和根节点进行对比，返回数据结构
2. 递归（中序遍历）。使用一个全局变量记录前一个节点的值，中序遍历的时候每次判断当前节点的值和前一个节点值的大小
3. 迭代（中序遍历）。也使用一个变量记录上一个节点的值，和递归的思路大致相同

[94.二叉树的中序遍历](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)：👉 [<u>二叉树的中序遍历</u>](二叉树/94%20二叉树的中序遍历.cc)

需要掌握的：

1. 递归方法
2. 使用栈的迭代方法
3. Morris 遍历方法
   - 对于 `root`，如果 `root` 存在左子树，那么就找到左子树中最右边的那个节点，让它的 `right` 指针指向 `root`，类似二叉线索树，这样之后可以回到 `root` 并访问 `root->val`。然后让 `root = root->left` 并断开 `root` 和 `root->left` 的指针，这样做是为了防止循环遍历
   - 如果不存在左子树，那么就将 `root->val` 加入到 `res` 中，然后让 `root = root->right`

[102.二叉树的层序遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)：👉 [<u>二叉树的层序遍历</u>](二叉树/102%20二叉树的层序遍历.cc)

需要掌握的：

1. 使用队列，迭代处理
2. 递归处理。前序遍历的时候记录二叉树的高度，然后 `res[level].push_back(root->val)` 就可以了，如果 `res[level]` 不存在的话，则 `res.push_back({root->val})`

[103.二叉树的锯齿形层序遍历]([103. 二叉树的锯齿形层序遍历 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/))：返回二叉树节点值的锯齿形层序遍历（先从左往右，再从右往左进行下一层遍历，交替执行）。👉 [<u>二叉树的锯齿形层序遍历</u>](二叉树/103%20二叉树的锯齿形层序遍历.cc)

标记奇偶行，对于偶数行对该层结果进行反转即可

[226.翻转二叉树](https://leetcode-cn.com/problems/invert-binary-tree/)：给你一棵二叉树，翻转这棵二叉树。👉 [<u>翻转二叉树</u>](二叉树/226%20翻转二叉树.cc)

递归调用函数即可

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

[124.二叉树中的最大路径和](https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/)：路径被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径中至多出现一次，该路径最少包含一个节点，且不一定经过根节点。给你一棵二叉树 `root`，返回其最大路径和。👉 [二叉树中的最大路径和](二叉树/124%20二叉树中的最大路径和.cc)

递归。使用 `dfs(TreeNode *root)` 返回经过节点 `root` 的最大路径和，该路径可能有三种情况

- 只有 `root` 一个节点
- `root` 节点加上它的左子树
- `root` 节点加上它的右子树

并且在执行递归函数的时候更新全局最大路径值 `res = max(res, max({root->val, root->val + left, root->val + right, root->val + left + right}))`。再更新 `res` 的时候考虑了 `root->val + left + right`，但是在返回的时候没有考虑这个值，这是因为当返回到上一层函数的时候，父节点需要用到经过子节点的路径此时子节点的左右子树不能同时考虑

**进阶：打印出路径。只需要更改 `dfs` 函数的返回值从 `int` 改为 `pair<vector<TreeNode *>, int>` 就可以了，然后在 `dfs` 中判断 `res` 需要更新的时候同时更新全局的最优路径**

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
   - 对于每一个数组中的元素 `x = nums[i]`，我们将其放在数组下标为 `x-1` 的位置，不断将 `nums[x - 1]` 和 `nums[i]` 置换，直到 `nums[i]` 小于 0 或者大于 `n` 或者和 `i+1` 相等
   - 遍历数组，如果 `nums[i] != i + 1` 说明 `i + 1` 这个元素没有出现，否则如果全部元素都正确的话说明 `1~n` 这些元素全都出现了，这个时候返回 `n+1`

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
3. 使用单调队列，单调队列的概念类似于单调栈。考虑下面的关系，如果 `i < j` 并且 `nums[i] < nums[j]`，那么 `nums[i]` 一定不会是窗口的最大值，因此可以直接移除 `nums[i]`
   - 所以使用单调队列维护这一关系式，队列中存放的是元素的下标，这样队列中的元素下标保持从小到大。不断的将新的元素放入队列中，并且不断的从队列的尾部弹出值小于当前值的元素
   - 另外也需要考虑队列中的元素在窗口之外了，因此还需要不断的从队列的首部弹出在窗口之外的元素

[240.搜索二维矩阵]([240. 搜索二维矩阵 II - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/search-a-2d-matrix-ii/))：编写一个高效的算法来搜索 `m * n` 矩阵 `matrix` 中的一个目标值 `target`。👉 [<u>搜索二维矩阵</u>](数组/240%20搜索二维矩阵.cc)

1. 直接搜索。时间复杂度 `O(mn)`，空间复杂度 `O(1)`
2. 二分搜索。枚举每一行，对每一行进行二分查找。时间复杂度 `O(mlogn)`，空间复杂度 `O(1)`
3. Z 字型搜索。每次搜索的矩阵为以 `matrix` 为左下角，`[x, y]` 为右上角的矩阵，初始的时候 `[x, y] = [0, n - 1]`
   - 如果 `matrix[x][y] > target`，则 `y` 这一列都大于 `target`，因此 `y--`
   - 如果 `matrix[x][y] < target`，则在 `y` 这一列中需要向下寻找一个元素，因此 `x++`
   - 当 `x == m || y < 0` 的时候停止查找

[283.移动零]([283. 移动零 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/move-zeroes/))：给定一个数组 `nums`，请将 `nums` 中的所有 `0` 移动到数组的末尾，同时保持非零元素的相对顺序。👉 [<u>移动零</u>](数组/283%20移动零.cc)

双指针解决

## 双指针

[1.两数之和](https://leetcode-cn.com/problems/two-sum/)：给出一个数组 `nums` 和一个目标整数 `target`，从数组中找出两个元素之和等于 `target` 的元素下标，要求时间复杂度小于 `O(n^2)`。👉 [<u>两数之和</u>](./双指针/1%20两数之和.cc)

- 方法一：排序。创建一个新的数组 `vector<pair<int, int>> arr`，`pair` 的第一个元素是数组下标，第二个元素是数组值，然后对 `arr` 按照数组值从小到大排序。最后使用双指针，指针 `i` 从 `0` 开始，指针 `j` 从 `arr.size() - 1` 开始

  - 如果 `target - arr[i].second == arr[j].second`，那么返回 `{arr[i].first, arr[j].first}`
  - 如果 `target - arr[i].second < arr[j].second`，`j--`
  - 否则，`i++`
- 方法二：哈希映射。创建一个 `unordered_map<int, int> map` 存储 `<nums[i], i>` 的映射。然后遍历 `nums` 数组

  - 对于每个 `nums[i]` 首先寻找 `target - nums[i]` 是否能在哈希表中找到其迭代器 `it`，如果找到了就返回 `{i, it->second}`
  - 如果没找到，将 `<nums[i], i>` 添加到哈希表中

[15.三数之和](https://leetcode-cn.com/problems/3sum/)：给你一个整数数组 `nums`，判断数组中是否存在三个元素 `a, b, c`，使得 `a + b + c = 0`，返回所有不重复的三元组。👉 [<u>三数之和</u>](./双指针/15%20三数之和.cc)

双指针 + 排序。我们可以先确定一个数 `x`，这样问题就转化为从原数组中找到两个元素满足 `y + z = -x`。两数之和的问题就可以使用双指针或者哈希映射来解决，参考 **1.两数之和** 这道题。

本题额外需要解决的是如何去除重复的三元组，下面两处代码可以剔除重复三元组：

1. 确定 `x` 的时候，如果 `nums[i] == nums[i - 1]` 那么跳过 `nums[i]`，因为已经在上一个 `nums[i - 1]` 计算过了
2. 当 `x` 确定下来，寻找 `y` 和 `z` 的时候，为了避免 `[-2, 0, 0, 2, 2]` 这种情况重复添加 `[-2, 0, 2]` 三元组，当找到一个三元组的时候执行 `while (left > 0 && left < right && nums[left] == nums[left - 1]) ++left;` 和 `while (right < nums.size() - 1 && right > left && nums[right] == nums[right + 1]) --right;`

[165.比较版本号]([165. 比较版本号 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/compare-version-numbers/))：给你两个版本号 `version1` 和 `version2`，请比较它们。👉 [<u>比较版本号</u>](双指针/165%20比较版本号.cc)

1. 双指针。不断的计算 `version1` 到 `'.'` 之前的整数值 `num1`，以及 `version2` 到 `'.'` 之前的整数值 `num2`，比较它们的数值
2. 字符串处理。分别对 `version1` 和 `version2` 按照 "." 切分，并转化为整数，比较切分后的数组

[54.螺旋矩阵]([54. 螺旋矩阵 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/spiral-matrix/))：给你一个 `m` 行 `n` 列的矩阵 `matrix`，请你按照顺时针顺序，返回矩阵中的所有元素。👉 [<u>螺旋矩阵</u>](双指针/54%20螺旋矩阵.cc)

<img src="https://assets.leetcode.com/uploads/2020/11/13/spiral1.jpg" alt="img" style="zoom:50%;" />

使用两个指针 `ptr_r1`，`ptr_r2` 来表示行数的范围，两个指针 `ptr_c1`，`ptr_c2` 来表示列数的范围。因此我们可以先遍历 `[ptr_r1][ptr_c1...ptr_c2]`，然后遍历 `[ptr_r1+1...ptr_r2][ptr_c2]`，然后遍历 `[ptr_r2][ptr_c2-1...ptr_c1]`，然后遍历 `[ptr_r2-1...ptr_r1+1][ptr_c1]`。当遍历完成之后 `ptr_r1++, ptr_r2--, ptr_c1++, ptr_c2--`

另外需要注意一下边界条件，如果 `ptr_r1 == ptr_r2` 此时不需要执行第三步遍历，如果 `ptr_c1 == ptr_c2` 此时不需要执行第四步遍历

[88.合并两个有序数组]([88. 合并两个有序数组 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/merge-sorted-array/))：给你两个按非递减顺序排列的整数数组 `num1` 和 `nums2`，请你合并两个数组变成一个有序数组，要求时间复杂度为 `O(m + n)`。👉 [<u>合并两个有序数组</u>](双指针/88%20合并两个有序数组.cc)

1. 新开辟一个空间用来存放有序数组，指针 `ptr_1` 指向 `num1` 的起点，指针 `ptr_2` 指向 `nums2` 的起点，然后不断的将 `nums1` 和 `nums2` 较小的那个元素放入新数组
2. 第一种方法需要 `O(n)` 的空间复杂度，我们可以将指针逆向遍历，这样可以直接利用 `nums1` 后半部分的空间

## 排序

[1424.对角线遍历II]([1424. 对角线遍历 II - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/diagonal-traverse-ii/))：给你一个列表 `nums`，里面每个元素都是整数列表，按照以下方式，按顺序返回 `nums` 中对角线上的整数。👉 [<u>对角线遍历II</u>](排序/1424%20对角线遍历II.cc)

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/04/23/sample_1_1784.png)

1. 使用 `map<int, vector<int>>` 保存和为 `key` 的所有 `values`，`nums` 数组按照从下往上从左到右的方式遍历，保存元素到 `map` 中。然后按顺序遍历 `map` 中的每一个 `key` 保存 `values` 到结果中即可。本质上是利用了 `map` 红黑树有序的特点
2. 使用堆排序。堆中保存的是 `pair<int, int>`，其中 first 表示横坐标，second 表示纵坐标。堆中按照 `first + second` 的和排序，相同的时候按照 `first` 越大的越靠前。然后从堆中依次弹出元素，保存 `nums[first][second]` 到结果中即可

[215.数组中的第K个最大元素](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/)：给你一个数组 `nums`，返回其中第 `k` 个最大整数。👉 [<u>数组中的第K个最大元素</u>](数组/215%20数组中的第k个最大元素.cc)

1. 堆排序。建立大顶堆之后进行 `k - 1` 次调整
2. 快速选择。利用快速排序的 `partition` 确定 `nums[n - k]`

## 二分/分治

[69.x的平方根]([69. x 的平方根 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/sqrtx/))：给你一个非负整数 `x`，计算并返回 `x` 的算术平方根，结果只保留整数部分。不允许使用内置函数直接计算。👉 [<u>x的平方根</u>](二分/69%20x的平方根.cc)

1. 可以选择直接顺序遍历 `i * i <= x` 找到 `i` 返回即可

可以优化为二分查找 `left = 1, right = x`，每次判断 `mid * mid <= x, left = mid + 1`，否则 `right = mid - 1`，最后返回 `left - 1`

需要注意的是 `mid = (left + right) >> 1` 不能这么计算，这样会溢出；也不能 `mid = left + (right - left) >> 1`，这样会超时；只能 `mid = left + (right - left) / 2`

另外 `mid * mid` 需要先将一个 `mid` 转化为 `uint64_t` 这样两个 `mid` 的乘积就是 `uint64_t` 的，否则的话还是 `int` 类型会溢出

[287.寻找重复数]([287. 寻找重复数 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/find-the-duplicate-number/))：给定一个包含有 `n + 1` 个整数的数组 `nums`，其数字都在 `[1, n]` 范围内，因此至少存在一个重复的数字。假设 `nums` 只有一个重复的整数，找出这个整数，你的解决方案必须不修改数组 `nums` 并且只用常量级 `O(1)` 的额外空间。👉 [<u>寻找重复数</u>](287%20寻找重复数.cc)

假设重复的数字是 `target`，使用 `cnt[i]` 表示数组中小于等于 `i` 的元素出现的次数。因此当 `1 <= i <= target - 1` 的时候，`cnt[i] <= i`；当 `i >= target` 的时候，`cnt[i] > i`

- 最简单直接的就是 `[1, target - 1]` 重的数字都出现了一次，然后 `target` 出现了两次，然后 `[target + 1, n]` 之间的数字出现了一次。这样的话，当 `i < target` 的时候，`cnt[i] = i`；当 `i == target` 的时候，`cnt[i] > i`；当 `i > target` 的时候，`cnt[i] > i`
- 然后如果 `target` 出现了超过一次，那么 `[1, n]` 中的数字必定有些数字没有出现。如果这些数字中有小于 `target` 的数字，那么当 `i < target` 的时候 `cnt[i] < i`；如果这些数字中有大于 `target` 的数字，那么当 `i > target` 的时候 `cnt[i]` 依旧大于 `i`

综上所述，只要 `i < target`，`cnt[i] <= i`；只要 `i >= target`，`cnt[i] > i`

所以 `cnt` 数组形成了一个单调递增的序列，前面有一部分满足 `cnt[x] <= x`，后面一部分满足 `cnt[x] > x`，我们的目标就是找到这个分界点，即第一个满足 `cnt[x] > x` 的 `x`。因此可以使用二分查找完成该任务

时间复杂度 `O(nlogn)`

> 二分查找并不是只能寻找给定 `target`，还可以寻找给定数组中满足特定条件的值



本题还可以使用位元算的思想。对于一个给定的数字集，每个数字只出现一次，这样的话可以知道每一个比特上面出现的 `1` 的总数

我们假设原来 `[1, n]` 中第 `bit` 个比特上出现的 `1` 的总数为 `x`，现在将 `[1, n]` 考虑又加进来一个数字 `target`

- 如果 `target` 第 `bit` 个比特上是 `0`，如果 `target` 在 `nums` 中只出现两次，那么最后第 `bit` 位上的 `1` 的总数 `y` 满足 `y = x`；如果 `target` 在 `nums` 中出现了大于两次（此时需要替换某些元素），那么最后第 `bit` 位上的 `1` 的总数 `y` 满足 `y <= x`。因此最后满足 `y <= x`
- 如果 `target` 第 `bit` 个比特上是 `1`，如果 `target` 在 `nums` 中只出现了两次，那么最后第 `bit` 位上 `1` 的总数 `y` 满足 `y > x`；如果 `target` 在 `nums` 中出现了大于两次（此时需要替换某些元素），那么最后第 `bit` 位上 `1` 的总数 `y` 满足 `y > x`。因此最后满足 `y > x`

综上所述，我们只需要统计第 `bit` 位上 `1` 的个数 `y`，和原来的 `[1, n]` 上第 `bit` 位上 `1` 的个数 `x` 进行对比，如果 `y > x` 就说明 `target` 第 `bit` 位的值为 `1`，否则就是 `0`。最后按位拼接到一起就可以得出 `target` 的值

时间复杂度 `O(nlogn)`，其中 `logn` 是求出 `n` 的最大比特位的值 `bitmax`，然后循环 `bitmax`



本题还可以使用双指针（快慢指针）的方法来解决。首先如果不存在重复的元素例如 `[1, 3, 4, 2]`，以下标 `n` 和 `nums[n]` 建立映射我们可以得到 `1->3->2->4->nullptr`。现在出现了一个重复的元素，此时必定会存在环

```c++
int findDuplicate(vector<int> &nums) {
  int slow = 0, fast = 0;
  while (fast != nums.size()) {
    slow = nums[slow];
    if (nums[fast] != nums.size())
      fast = nums[nums[fast]];
    if (slow == fast)
      break;
  }
  slow = 0;
  while (nums[slow] != nums[fast]) {
    slow = nums[slow];
    fast = nums[fast];
  }
  return nums[slow];
}
```

[4.寻找两个正序数组的中位数](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/)：给定两个正序数组 `nums1` 和 `nums2` 找出并返回两个正序数组的中位数，时间复杂度要求小于等于 `O(log(m + n))`。👉 [<u>寻找两个正序数组的中位数</u>](./二分/4%20寻找两个正序数组的中位数.cc)

如果题目没有要求时间复杂度小于等于 `O(log(m + n))`，那么可以采用以下两种方法

- 合并 `nums1` 和 `nums2`，然后返回合并之后数组的中位数。时间复杂度 `O(m + n)`，空间复杂度 `O(m + n)`
- 不需要合并，使用两个指针分别指向两个数组的起始位置，每次将元素值较小的那个指针向后移动一个位置。时间复杂度 `O(m + n)`，空间复杂度 `O(1)`

本题采用二分查找的方法。如果 `m + n` 是奇数，那么中位数是合并之后数组的「第 `(m + n + 1) >> 1`」个元素；如果 `m + n` 是偶数，那么中位数就是「第 `(m + n) >> 1`」和「第 `(m + n) >> 1 + 1`」个元素的平均值。记 `k` 表示需要查找合并之后数组的第 `k` 个元素

我们可以判断 `pivot1 = nums1[k/2 - 1]` 和 `pivot2 = nums2[k/2 - 1]` 的大小

- `if pivot1 < pivot2`，由于 `nums1[k/2 - 1]` 和 `nums2[k/2 - 1]` 前面都有 `k/2 - 1` 个元素，那么 `nums1[k/2 - 1]` 在合并之后数组中的位置最大为 `第 k/2 - 1 + k/2 - 1 + 1 <= k - 1`。因此 `nums1[0...k/2-1]` 全都可以跳过，因此 `nums1` 数组从 `nums1[k/2]` 开始
- 同理 `if pivot1 > pivot2`，跳过 `nums2[0...k/2-1]`，`nums2` 数组从 `nums2[k/2]` 开始
- 如果 `pivot1 == pivot2`，转化为第一种或者第二种其中一种情况处理即可

实际代码处理的时候有一些特殊情况需要处理

- 在计算 `nums1[idx1 + k/2 - 1]` 的时候 `idx1 + k/2 - 1` 有可能越界了，此时 `new_idx1 = min(idx1 + k/2 - 1, m - 1)`；`idx2` 的处理方式同理。这里 `new_idx` 表示需要计算比较的 `pivot` 的下标，而不是下一轮二分查找时候到的起始下标，下一轮二分查找的起始下标等于 `new_idx + 1`
- 由于 `idx` 的更新不总是等于 `idx + k/2 - 1 + 1`，因此 `k` 每次需要删除 `new_idx - old_idx + 1` 个元素，即每次更新 `k -= new_idx - old_idx + 1` 
- 每一轮二分查找之后需要判断 `idx1 == m`，此时返回 `nums2[idx2 + k - 1]`；同理判断 `idx2 == n`，返回 `nums1[idx1 + k - 1]`
- 如果 `k == 1`，返回 `min(nums1[idx1], nums2[idx2])`

[300.最长递增子序列]([300. 最长递增子序列 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/longest-increasing-subsequence/))：给你一个整数数组 `nums`，找到其中最长严格递增的子序列长度。👉 [<u>最长严格递增子序列</u>](动态规划/300%20最长递增子序列.cc)

进阶：你可以将算法的时间复杂度降低到 `O(nlogn)` 吗

1. 最直接的使用动态规划来解决该问题。`dp[i]` 表示以 `nums[i]` 为结尾的子序列的最长长度。计算 `dp[i]` 的时候需要向前寻找 `j` 满足 `nums[j] < nums[i], dp[i] = max(dp[i], dp[j] + 1)`。时间复杂度 `O(n^2)`
2. 贪心 + 二分。贪心策略：要使得子序列尽可能的长，只要我们的子序列上升的足够慢即可。使用数组 `vec[len]` 表示长度为 `len` 的子序列的最后一个元素值。遍历 `nums` 数组，如果 `nums[i] > vec[len]`，此时子序列的长度可以增加一个 `vec[++len] = nums[i]`；否则的话就需要在 `vec` 数组中找到第一个大于 `nums[i]` 的元素，更新其值为 `nums[i]`

[169.多数元素](https://leetcode-cn.com/problems/majority-element/)：给定一个大小为 `n` 的数组，找到其中的多数元素，即出现次数大于 `n/2` 的元素。👉 [<u>多数元素</u>](hot100/169%20多数元素.cc)

有以下几种方法可以解决该问题：

1. 哈希。使用一个 `unordered_map<int, int>` 记录每个元素出现的次数，如果一个元素出现的次数大于 `n/2` 则返回该元素。时间复杂度 `O(n)`，空间复杂度 `O(n)`
2. 排序。对 `nums` 数组排序，然后返回数组的中间元素，即 `nums[nums.size()/2]`。时间复杂度 `O(nlogn)`，空间复杂度 `O(logn)`
3. 分治。如果元素 `target` 为众数，那么将 `nums` 分为两部分，`target` 必定为某一部分的众数，可以用反证法证明该理论，即假设 `target` 不是这两部分的众数，最后可以得出 `target` 不是 `nums` 的众数，与假设矛盾
   - 记左半部分的众数为 `target1`，右半部分区间的众数为 `target2`。此时只需要遍历左半部分区间和右半部分区间统计 `target1` 的数量和 `target2` 的数量即可知道 `target1` 和 `target2` 哪个是 `nums` 的众数了
   - 当区间长度为 `1` 的时候，直接返回该元素即可
   - 时间复杂度 `O(n)`，空间复杂度 `O(1)`
4. 投票。如果已知某一个数是众数，那么我们遇到该数的时候对计数值 `count` 加一，遇到不是该数的时候对计数值减一，最后 `count` 的值必定大于 0。基于该理论，初始时 `count = 0`。然后开始扫描数组元素，如果 `count = 0` 则目标数 `target = nums[i]` 并增加 `count`。如果后续遍历到和 `target` 相等的元素则 `count++`，否则 `count--`。时间复杂度 `O(n)`，空间复杂度 `O(1)`

[33.搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)：整数数组 `nums` 按升序排列，数组的值互不相同。对 `nums` 在某一个位置 `k` 上进行旋转之后的结果是 `[nums[k], nums[k + 1], ..., nums[n - 1], nums[0], nums[1], ..., nums[k - 1]`。现在给出旋转之后的数组 `nums` 和一个整数 `target`，如果 `nums` 中存在 `target` 返回 `target` 的下标，否则返回 -1。要求时间复杂度为 `O(log n)`，👉 [<u>搜索旋转排序数组</u>](二分/33%20搜索旋转排序数组.cc)

- 方法一：先判断 `target` 在第一段有序区间还是在第二段有序区间，然后再对 `mid` 是在第一段有序区间还是在第二段有序区间判断，调整 `left` 和 `right` 的位置。这里的第一段有序区间和第二段有序区间采用 `nums[left]` 和 `target` 进行比较
- 方法二：先对 `mid` 判断是位于第一段有序区间还是在第二段有序区间，这里判断第一段有序区间和第二段有序区间使用 `nums[0]` 进行比较的
  - 如果 `mid` 在第一段有序区间，即 `nums[0] <= nums[mid]`。判断 `target` 的位置是在 `[0, mid)` 还是在 `[mid, k]`，调整 `left` 和 `right` 的位置
  - 如果 `mis` 在第二段有序区间，即 `nums[0] > nums[mid]`。判断 `target` 的位置是在 `(mid, n - 1]` 还是在 `[k, mid]`，调整 `left` 和 `right` 的位置

方法一详情见源码文件，方法二代码如下：

```c++
while (left <= right) {
  int mid = (left + right) >> 1;
  if (nums[mid] == target)
    return mid;
  if (nums[0] <= nums[mid]) { // mid 位于第一段区间
    if (nums[0] <= target && target < nums[mid]) // target 在 [0, mid] 之间
      right = mid - 1;
    else
      left = mid + 1;
  } else { // mid 位于第二段区间
    if (nums[n - 1] >= target && target > nums[mid])
      left = mid + 1;
    else
      right = mid - 1;
  }
}
```

**进阶：如果在旋转一次应该要怎么做，做法还是一样的，无论旋转几次最多只有两段递增序列**

[81.搜索旋转排序数组II]([81. 搜索旋转排序数组 II - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/))：与 **33题** 的区别在于，现在数组中存在重复的元素。👉 [<u>搜索旋转排序数组II</u>](81%20搜索旋转排序数组II.cc)

处理方法和 **154题** 相同，跳过所有 `left` 重复的元素，然后 `right` 再跳过和 `left` 重复的元素。之后就是和 **33题** 相同的解法了

最坏的情况下时间复杂度 `O(n)`，此时需要遍历跳过所有的元素

[153.寻找旋转排序数组中的最小值]([153. 寻找旋转排序数组中的最小值 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/))：给你一个数组 `nums`，数组中不包含重复元素，它是由一个有序数组旋转若干次得到的，请找出原数组中的最小值。👉 [<u>寻找旋转排序数组中的最小值</u>](二分/153%20寻找旋转排序数组中的最小值)

最小值总是出现在右边的递增序列的。下面提供两种二分查找的思路

1. 二分查找的出口条件是 `mid > 0 && nums[mid] < nums[mid - 1]`，否则的话根据 `nums[mid]` 和 `nums[0]` 以及 `nums[n - 1]` 的大小判断下一个查找区间

   - 如果 `nums[mid] > nums[n - 1]`，说明 `mid` 在左边的这个递增区间，因此 `l = mid + 1`

   - 如果 `nums[mid] <= nums[n - 1]`，说明 `mid` 在右边的这个递增区间，因此 `r = mid - 1`
   - 如果二分查找过程中没有返回，那么就说明这个序列是有序的，因此返回 `nums[0]`

2. 由于我们知道最小值一定是出现在右边的递增序列的，因此我们判断 `nums[mid]` 和 `num[r]`，如果 `nums[mid] > nums[r]` 说明此时 `mid` 位于第一段区间，因此 `l = mid + 1`；否则的话说明 `mid` 位于第二段区间，此时由于 `mid` 有可能是最终值，因此我们不能直接跳过 `mid`，而是让 `r = mid`。二分查找的终止条件是 `l < r`

3. 基于方法二的修改，`nums[mid]` 每次和 `right_max` 进行比较，如果 `nums[mid] > right_max`，则 `l = mid + 1`，否则的话 `r = mid - 1`，循环的终止条件是 `l <= r`，最后在出口的时候返回 `nums[l]`

[154.寻找旋转排序数组的最小值II]([154. 寻找旋转排序数组中的最小值 II - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/))：这题相比于 **153题** 的区别在于现在数组中可能会包含重复的元素。👉 [<u>寻找旋转排序数组的最小值II</u>](二分/154%20宣召旋转排序数组的最小值II.cc)

下面提供两种二分查找的方法

1. 自己写的方法。跳过 `left` 左端的所有重复元素，然后判断 `left` 和 `right` 是否一样，如果一样的话 `right` 向左移动。之后就是 **153题** 的解法了
2. 基于 **153题** 第二种方法的修改，如果 `nums[mid] == nums[r]`，由于此时无法判断最小值是在 `mid` 左侧还是右侧，例如 `[2, 2, 1, 2]` 和 `[2, 1, 2, 2]`，因此让 `r--`

```c++
int findMin(vector<int>& nums) {
  int l = 0, r = nums.size() - 1;
  while (l < r) {
    int mid = (l + r) / 2;
    if (nums[mid] > nums[r])
      l = mid + 1;
    else if (nums[mid] < nums[r])
      r = mid;
    else
      --r;
  }
  return nums[l];
}
```

[162.寻找峰值]([162. 寻找峰值 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/find-peak-element/))：给你一个整数数组 `nums`，保证 `nums[330781199710263045] != nums[330781199710263045 + 1]`，请你找出数组中峰值元素的下标。👉 [<u>寻找峰值</u>](二分/162%20寻找峰值.cc)

对于一个给定的元素，如果 `nums[i] < nums[i + 1]` 那么说明 `i` 的右侧必定存在一个峰值，如果 `nums[i] > nums[i + 1]` 那么就说明 `i` 的左侧一定有一个峰值

因此，如果 `nums[i] < nums[i + 1]`，我们就向右遍历；如果 `nums[i] > nums[i + 1]`，我们就向左遍历。这样的话刚好可以用类似二分查找的方法进行遍历

## 贪心

[135.分发糖果]([135. 分发糖果 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/candy/))：`n` 个孩子站成一排。给你一个整数数组 `ratings` 表示每个孩子的评分。你需要按照以下要求，给这些孩子分发糖果：

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

[253.会议室II]([253. 会议室 II - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/meeting-rooms-ii/))：给你一个会议时间安排的数组 `intervals`，每个会议时间都会包含一个开始时间和结束时间，返回所需会议室的最小数量。👉 [<u>会议室II</u>](贪心/253%20会议室II.cc)

有如下三种思路可以解决该问题：

1. 堆（优先队列）。模拟日常生活中会议室的占用，我们肯定会先安排开始时间较早的会议到某一个会议室，然后不断的查看后面的会议，对比前面最早结束的会议的时间和当前这个会议的开始时间，然后考虑重新安排一间会议室。因此可以使用小根堆来存放当前所有正在执行的会议的结束时间。每次新的会议来的时候，查看堆顶元素 `top` 和新会议的开始时间 `start`，如果 `top > start` 则需要新开一个会议室，否则取出堆顶元素修改结束时间为新会议的结束时间 `end`，然后重新放回堆中
2. 会议的开始时间我们可以看成需要增加一个会议室，会议的结束时间可以看成需要减少一个会议室。这样一来，我们使用一个数组存放 `{start, 1}` 和 `{end, -1}` 的数对，然后对所有的数对进行排序，每次累加数对的值 `count`。所需会议室的最小数量就是 `max(count)`
3. 分别对 `start` 和 `end` 排序，每个 `end` 结束的时候说明有一个会议结束了，但是我们并不关心具体是哪个会议结束了。
   - 如果 `start[i] < end[j]`，`res++`
   - 如果 `start[i] >= end[j]`，`j++`
   - 任何时候都执行 `i++`

> 方法二实际上还可以看成另一个问题背景，即一辆公交车上最多有多少个乘客。会议的开始时间看成一名乘客的上车时间，会议的结束时间看成是一名乘客的下车时间。同样可以使用 `{start, 1}, {end, -1}` 排序累加的方法来解决

## 搜索

[200.岛屿数量](https://leetcode-cn.com/problems/number-of-islands/)：给你一个由 `1`（陆地） 和 `0`（水） 组成的二维网格，请你计算网格中岛屿的数量。👉 [<u>岛屿数量</u>](回溯/200%20岛屿数量.cc)

1. dfs 和 bfs 两种方法
2. 并查集，将所有邻接的 1 都合并

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



## 前缀和

[862.和至少为K的最短子数组]([862. 和至少为 K 的最短子数组 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/shortest-subarray-with-sum-at-least-k/))：给你一个整数数组 `nums` 和一个整数 `k`，找出 `nums` 中和至少为 `k` 的最短非空子数组，返回该数组的长度，如果不存在则返回 -1。👉 [<u>和至少为K的最短子数组</u>](862%20和至少为K的最短子数组.cc)

这道题和 **209题** 不一样，209 题数组中不包含负数，因此可以使用滑动窗口来解决

本题采用前缀和 + 双端队列来解决。首先有一个基本的共识是，如果 `i < j` 并且数组前 `i` 个元素之和大于数组前 `j` 和元素之和，那么对于 `j` 后面的元素它必定不会采用 `nums[i - 1]` 作为该段子数组的起始位置。由于 `nums[i - 1]` 和 `nums[j - 1]` 之间的元素之和为负数，因此对于 `nums[j]` 之后的元素，如果可以采用 `nums[i - 1]` 那么必定可以采用 `nums[j]` 作为子数组的起始位置

我们使用一个队列来保存 `trie` 前缀和中的元素，队列中元素的下标是有序的

- 首先求出 `nums` 数组中每一个元素的前缀和，使用 `trie[i]` 表示 `nums` 数组中前 `i` 个元素之和，然后遍历 `trie` 数组。从队列尾部弹出 `trie[q.back()] >= trie[i]` 的元素，原因上面已经提到了。然后判断 `trie[i]` 和队列首部元素的差是否满足大于等于 `k`，如果满足该条件则更新 `len` 并弹出队列首部的元素

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
> 1. 当处理边界情况 `n = 1` 或者 `k = 1` 的时候，`dp(n, k) = 1`
> 2. 当 `n = k` 的时候，如果包含了数字 `k`，则只有一种方案数；如果不包含数字 `k`，则 `dp(n, k) = dp(n, k - 1)`。因此 `dp(n, k)` 是两种情况的和，`dp(n, k) = dp(n, k - 1) + 1`
> 3. 当 `n > k` 的时候，如果包含了数字 `k`，则 `dp(n, k) = dp(n - k, k)`，注意这里 `n - k` 还是有可能大于 `k` 的；如果不包含数字 `k`，则 `dp(n, k) = dp(n, k - 1)`。因此 `dp(n, k) = dp(n - k, k) + dp(n, k - 1)`
> 最后给出一个正整数 n，返回 `dp(n, n - 1)` 即可

[96.不同二叉搜索树](https://leetcode-cn.com/problems/unique-binary-search-trees/)：给出一个整数 `n`，求出由 1 到 n 的值作为节点的二叉搜索树有多少种。👉 [不同二叉搜索树.cc](./动态规划/96%20不同二叉搜索树.cc)

我们可以知道树的节点由 `[1, 2, 3, ..., n]` 组成，那么可以以其中一个值作为二叉树的根节点，此时左子树就是 `[1, 2, ..., j - 1]` 共有 `j - 1` 个节点，右子树就是 `[j + 1, j + 2, ..., n]` 共有 `n - j` 个节点。如果用 `dp[i]` 表示对于整数 `i` 的拆分个数，那么 `dp[i]` 就等于 `dp[j - 1] * dp[i - j]`；遍历所有的 `1 <= j <= i`，将所有结果都累加起来；即 `dp[i] += dp[j - 1] * dp[i - j], 1 <= j <= i`

- 初始的时候 `dp[0] = dp[1] = 1`

### 0-1 背包

背包容量 `v`，物品价值 `w[]`，每个物品的体积 `v[]`。每个物品只有一件，求该背包能装入的最大价值。
#### 二维数组 DP

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

#### 一维 DP

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

### 完全背包

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

### 多重背包

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

### 背包总结

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

[300.最长递增子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/)：给出一个数组 `nums`，找到其中最长严格递增的子序列长度。子序列是指删除原数组中的某些元素而不改变其余元素顺序得到的数组。👉 [最长递增子序列.cc](./动态规划/300%20最长递增子序列.cc)

- 动态规划。使用 `dp[i]` 表示下标 `i` 之前包括下标 `i` 的最长子序列长度，如果我们找到一个 `j` 满足 `nums[j] < nums[i]` 并且 `j < i`，那么加上 `nums[i]` 就可以组成一个新的严格递增子序列了，所以 `dp[i] = max(dp[i], dp[j] + 1)`。时间复杂度 `O(n)`
- 贪心 + 二分。如果我们要使上升子序列尽可能的长，则我们需要让序列上升得尽可能慢，因此我们希望每次在上升子序列最后加上的那个数尽可能的小；使用 `d[len - 1]` 表示长度为 `len` 的严格递增子序列最后一个元素的值；如果发现 `nums[i] > d[len - 1]` 则子序列长度增加一个单位，`d[len] = nums[i], len++`；如果 `nums[i] <= d[len - 1]`，则在 `d[0...len-1]` 找到第一个小于 `nums[i]` 的值 `d[k]`，则有 `d[k] < nums[i] < d[k + 1]`，更新 `d[k + 1] = nums[i]`。这一步使用二分查找的方法。最后整体时间复杂度 `O(nlogn)`

```c++
/// 贪心方法代码
int lengthOfLIS(vector<int> &nums) {
  int n = nums.size(), len = 1;
  vector<int> dp(n);
  dp[0] = nums[0];
  for (int i = 1; i < n; ++i) {
    if (nums[i] > dp[len - 1]) {
      dp[len++] = nums[i];
      continue;
    }
    int left = 0, right = len - 1;
    while (left < right) {
      int mid = (left + right) / 2;
      if (dp[mid] >= nums[i])
        right = mid;
      else
        left = mid + 1;
    }
    dp[left] = nums[i];
  }
  return len;
}
```

[674.最长连续递增子序列](https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence/)：给出一个数组 `nums`，找出其中最长的并且连续递增的子序列长度。👉 [最长连续递增子序列.cc](./贪心/674%20最长连续递增序列.cc)

这道题比较简答，只需要判断 `nums[i] > nums[i - 1]` 就增加当前连续序列的长度 `cur`，并且更新最后结果 `res = max(res, cur)`，如果 `nums[i] <= nums[i - 1]` 那么 `cur = 1`

[718.最长重复子数组](https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/)：给你两个整数数组 `nums1` 和 `nums2` 返回两个数组的公共、长度最大的子数组的长度。👉 [最长重复子数组.cc](./动态规划/718%20最长重复子数组.cc)

使用 `dp[i][j]` 表示 `nums1` 以 `nums1[i]` 结尾、`nums2` 以 `nums2[j]` 结尾时候的最长重复子数组长度，则有：

- 如果 `nums1[i] == num1[j]`，`dp[i][j] = dp[i - 1][j - 1] + 1`
- 如果 `nums1[i] != num1[j]`，`dp[i][j] = 0`

最后返回 `dp[i][j]` 中最大的值就是最长重复子数组的长度

> 补充：滑动窗口；二分 + 哈希，这两种方法后续可以再看看

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

[76.最小覆盖子串](https://leetcode-cn.com/problems/minimum-window-substring/)：给定一个字符串 `s`、一个字符串 `t`，返回 `s` 中涵盖 `t` 所有字符的最小子串，如果 `s` 中不含盖 `t` 则返回空字符串 `""`。👉 [<u>最小覆盖子串</u>](滑动窗口/76%20最小覆盖子串.cc)

滑动窗口

- 使用一个 `unordered_map<char, int> map` 记录 `t` 中每个元素出现的次数
- 初始的时候窗口的左右边界为 `left = 0, right = 0`，`unordered_map<char, int> window` 记录当前窗口中 `t` 中字符的出现次数
- 不断扩展右边界直到 `window` 中所有的字符出现的数量都满足了 `map` 中的要求
- 此时开始收缩窗口，每次收缩的时候更新当前窗口起始位置 `start` 和窗口大小 `len`，直到 `window` 中刚好有一个字符出现的数量没有满足 `map` 的时候停止窗口收缩

[30.串联所有单词的子串]([30. 串联所有单词的子串 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/))：给你一个字符串 `s` 和一些长度相同的单词 `words`。找出 `s` 中恰好可以由 `words` 中所有单词串联形成的子串的起始位置。注意子串要与 `words` 中的单词完全匹配，中间不能有其他字符。👉 [<u>串联所有单词的子串</u>](滑动窗口/30%20串联所有单词的子串.cc)

固定滑动窗口的大小为 `words` 中所有单词长度之和，然后窗口每次向右滑动一个单位，并切分窗口中的所有单词，判断是否刚好 `words` 中的所有单词匹配。这么做的时间复杂度为 `O(n^2)`

**进阶：给出时间复杂度为 `O(n)` 的方法、如果 `words` 中单词的长度不想等呢**

[209.长度最小的子数组]([209. 长度最小的子数组 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/minimum-size-subarray-sum/))：给你一个含有 `n` 个正整数的数组和一个正整数 `target`，找出该数组中满足其和大于等于 `target` 的长度最小的连续子数组，并返回其长度，如果不存在则返回 0。👉 [<u>长度最小的子数组</u>](滑动窗口/209%20长度最小的子数组.cc)

本题有两种方法可以解决：

1. 使用一个滑动窗口记录当前窗口中元素的和，如果元素和大于等于 `target` 更新 `len`，并开始收缩窗口。时间复杂度 `O(n)`，空间复杂度 `O(1)`
2. 记录每一个元素的前缀和，然后枚举每一个元素 `nums[i]`，在前缀和数组 `vec` 中找到第一个元素值大于等于 `vec[i] - nums[i] + target` 的元素，这个查找过程可以使用二分查找。时间复杂度 `O(nlogn)`，空间复杂度 `O(n)`

**进阶：**

- 列出所有和为 `target` 的连续子序列。和本题一样的思路，在大于等于 `target` 的时候尝试开始收缩窗口，判断当前 `sum` 是不是等于 `target`，想等的话保存当前窗口中的子序列
- 如果数组里面有负数需要怎么处理。**862题**
- 将本题的 `target` 变为 `target` 的整数倍。

## 设计题

[155.最小栈]([155. 最小栈 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/min-stack/))：设计一个支持 `push`，`pop`，`top` 操作，并能在常数时间内检索到最小元素的栈

进阶：使用一个栈实现

1. 我们可以使用两个栈，第一个栈存放元素，第二个栈存放当前元素为栈顶的时候，栈中的最小元素。这样当我们在获取栈中最小元素的时候，只需要从第二个栈中获取即可
2. 如果要求只使用一个栈，那么在 `push` 一个元素的时候，同时也将此时栈中的最小值压入栈中

[146.LRU缓存]([146. LRU 缓存 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/lru-cache/))：请你设计并实现一个满足 LRU 缓存约束的数据结构，实现 LRUCache 类：

- LRUCache 以正整数作为容量 `capacity` 初始化 LRU 缓存
- get 操作，如果 key 在缓存中，返回 key 的值，否则返回 -1
- put 操作，如果 key 已经存在，则修改 value，如果不存在就插入 key-value。如果插入操作导致容量超过 capacity，那么逐出最近最久未使用的 key
- get 和 put 操作必须以 O(1) 的平均时间复杂度运行

代码：[<u>LRU缓存</u>](设计题/146%20LRU缓存.cc)

使用一个双向链表来管理整个 LRUCache，对于链表中的每一个节点，额外使用一个哈希表建立 `key` 到 `ListNode*` 的映射。越靠近链表尾部的节点是最近被访问过的节点，为了减少时间复杂度，使用两个指针 `_list` 表示链表头部的 `dummy` 节点，`_tail` 表示链表尾部的节点，`_list` 用来逐出最近最久未被访问的节点，`_tail` 用来将一个最近刚被访问的节点放到链表尾部

进阶：**线程安全**、**带超时时间**

[208.实现Trie(前缀树)]([208. 实现 Trie (前缀树) - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/implement-trie-prefix-tree/))：实现一棵前缀树。👉 [<u>实现Trie前缀树</u>](208%20实现Trie(前缀树).cc)

每一个节点有一个 `unordered_map<char, Trie> children` 用来保存以该层为前缀的时候，下一个字符所在的指针。另外还有一个 `last` 变量来标记以该层字符为结尾的字符串是不是存在

- 这样在查找一个字符串 `word` 是不是存在字典树中的时候，只需要沿着 `children` 不断的向下寻找即可，如果遍历完了 `word` 发现此时的节点的 `last` 变量为 `true`，则说明 `word` 存在于字典树中
- 插入一个字符串 `word` 的时候也只需要沿着字典树的 `children` 不断的向下查找，如果发现某一个字符不存在则新建一个节点表示该字符
- 查找一个前缀的时候和查找一个 `word` 是否存在于字典树中类似，只不过不需要判断最后的节点的 `last` 变量是否为 `true`

[297.二叉树的序列化与反序列化]([297. 二叉树的序列化与反序列化 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/))：实现二叉树的序列化与反序列化函数。👉 [<u>二叉树的序列化与反序列化</u>](二叉树/297%20二叉树的序列化与反序列化.cc)

- 序列化：按照层序的方式保存，每个节点用 `','` 分隔，如果是 `nullptr` 则使用 `'.'` 表示
- 反序列化：利用队列，每次从队列中弹出一个元素，然后构建它的左节点和右节点

## hot100

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
[11.盛水最多的容器](https://leetcode-cn.com/problems/container-with-most-water/)：给定一个长度为 `n` 的整数数组 `height`，有 `n` 条垂线，找出其中的两条线使得它们与 `x` 轴构成的容器能够容纳最多的水。👉 [<u>盛水最多的容器</u>](./贪心/11%20盛水最多的容器.cc)

贪心算法。考虑 `height[left]` 和 `height[right]` 组成的容器能够容纳的水为 `res`，如果 `height[left] < height[right]` 我们直观的能够想到需要将高度较低的 `left` 向右移动到某一个位置 `new_left`，满足 `height[new_left] > height[left]`，然后重新计算此时的容器容量。之后重复的将高度较低的那个下标进行移动，直到 `left = right`

[17.电话号码的字母组合](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/)：给定一个仅包含数字 `2-9` 的字符串，返回所有它能表示的字母组合。👉 [<u>电话号码的字母组合</u>](回溯/17%20电话号码数字组合.cc)

[19.删除链表的倒数第 n 个节点](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/)：给你一个链表，删除链表的倒数第 `n` 个节点，并返回链表的头节点。👉 [<u>删除链表的倒数第 n 个节点</u>](链表/19%20删除链表的倒数第n个节点.cc)

倒数第 `n` 个节点和最后一个节点之间的距离为 `n`，因此如果我们使用两个指针，让第一个指针指向 `dummy` 节点，第二个指针位于它后面的 `n` 个位置。然后两个指针开始一起移动，这样当第二个指针移动到最后一个节点的时候，第一个指针的后继节点就是待删除的节点

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

[31.下一个排列](https://leetcode-cn.com/problems/next-permutation/)：给出一个整数数组 `nums`，找出 `nums` 的下一个排列。👉 [<u>下一个排列</u>](hot100/31%20下一个排列.cc)

例如 `[4,5,2,6,3,1]` 的下一个排列是 `[4,5,3,1,2,6]`。我们可以首先从后往前找到第一个满足 `nums[i] < nums[i + 1]` 条件的组合，此时记下 `nums[i]` 的索引 `left = i`，并且 `[left + 1, nums.size() - 1]` 的所有元素都是降序的。然后从 `[left + 1, nums.size() - 1]` 从后往前寻找第一个满足 `nums[j] > nums[left]` 的元素，记下该元素的下标 `right = j`。之后交换 `nums[left]` 和 `nums[right]`，交换之后 `nums` 数组满足 `[left + 1, nums.size() - 1]` 是降序的，最后只需要翻转 `left` 之后的所有元素为升序即可

[34.在排序数组中查找元素第一个和最后一个位置](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/)：给你一个按照升序排列的数组 `nums`，和一个目标值 `target`，找出给定目标值在数组中出现的第一个和最后一位置，如果不存在返回 `[-1,-1]`。👉 [<u>在排序数组中查找元素第一个和最后一个位置</u>](二分/34%20在排序数组中查找元素的第一个和最后一个位置.cc)

- 当查找最左边出现的位置的时候，如果 `nums[mid] == target`，此时 `right = mid - 1`，最后返回有效的 `left`
- 当查找最右边出现的位置的时候，如果 `nums[mid] == target`，此时 `left = mid + 1`，最后返回有效的 `right`

[39.组合总和](https://leetcode-cn.com/problems/combination-sum/)：给你一个无重复元素的整数数组 `candidates` 和一个目标整数 `target`，找出 `candidates` 中可以使数字和为目标数 `target` 的所有不同组合。`candidates` 中同一个数字可以被无限选取。👉 [组合总和](回溯/组合问题/39%20组合总和.cc)

[42.接雨水](https://leetcode-cn.com/problems/trapping-rain-water/)：本题的解题思路在 **单调栈——接雨水** 有记录。👉 [<u>接雨水</u>](单调栈/42%20接雨水.cc)

[46.全排列](https://leetcode-cn.com/problems/permutations/)：给定一个不包含重复数字的数组 `nums`，返回其所有可能的全排列。👉 [<u>全排列</u>](回溯/排列/46%20全排列.cc)

深搜，额外使用空间来记录当前元素是否被访问过

[47.全排列II](https://leetcode-cn.com/problems/permutations-ii/)：现在 `nums` 数组中包含了重复的元素，但是要求返回所有不重复的排列。👉 [<u>全排列II</u>](回溯/排列/47%20全排列II.cc)

这里首先对 `nums` 数组排序，然后有两种方法可以去除重复的排列

- 使用 `unordered_set` 记录当前被使用过的元素值，在后序的 `for` 循环迭代中不再使用该元素值
- `i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]` 的时候跳过该元素。说明一下 `!visited[i - 1]` 的用意，因为 `nums[i - 1]` 有可能是在上一层函数调用中被使用的元素，但是当前的 `nums[i] = nums[i - 1]` 此时是不能跳过 `nums[i]` 的，例如 `[1,1,2]`

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

[56.合并区间](https://leetcode-cn.com/problems/merge-intervals/)：以数组 `intervals` 表示若干个区间的集合，请你合并所有重叠的区间，返回一个不重叠的区间数组，该数组恰好覆盖输入中的所有区间。👉 [<u>合并区间</u>](贪心/56%20合并区间.cc)

[62.不同路径](https://leetcode-cn.com/problems/unique-paths/)：一个机器人位于 `m * n` 网格的左上角，机器人每次只能向下或者向右移动一步，到达右下角一共有多少种不同的路径。👉 [<u>不同路径</u>](动态规划/62%20不同路径.cc)

[64.最小路径和](https://leetcode-cn.com/problems/minimum-path-sum/)：给定一个包含非负整数的 `m * n` 网格 `grid`，请找出一条从左上角到右下角的路径，使得路径上的数字之和最小。👉 [<u>最小路径和</u>](动态规划/64%20最小路径和.cc)

`dp[i][j]` 表示从 `grid[i][j]` 到达右下角的最小数字之和，`dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + grid[i][j]`

[70.爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/)：每次可以爬 `1` 或 `2` 个台阶，爬到第 `n` 个台阶有多少种不同的方法。👉 [<u>爬楼梯</u>](动态规划/70%20爬楼梯.cc)

[72.编辑距离](https://leetcode-cn.com/problems/edit-distance/)：给你两个单词 `word1` 和 `word2`，请返回将 `word1` 转化为 `word2` 所使用的最小步数。👉 [<u>编辑距离</u>](动态规划/72 编辑距离.cc)，具体的思路在 **动态规划——子序列问题——编辑距离** 有详细介绍

[75.颜色分类](https://leetcode-cn.com/problems/sort-colors/)：给定一个包含红色、白色和蓝色，共 `n` 个元素的数组 `nums`，原地对它们进行排序，使颜色相同的元素相邻，并按照红色、白色、蓝色顺序排列。分别使用整数 `0, 1, 2` 表示红色、白色、蓝色，不能使用标准库的 `sort` 函数。👉 [<u><颜色分类</u>](hot100/75%20颜色分类.cc)

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

[96.不同二叉搜索树](https://leetcode-cn.com/problems/unique-binary-search-trees/)：给你一个整数 `n`，求恰由 `n` 个节点组成且节点值从 `1` 到 `n` 互不相同的二叉搜索树有多少种。👉 [<u>不同二叉搜索树</u>](二叉树/96%20不同二叉搜索树.cc)

动态规划。使用 `dp[i]` 表示当 `n = i` 的时候有多少种不同的二叉搜索树，我们可以将 `j = [1...i]` 作为根节点，`[1...j-1]` 作为左子树，`[j+1...i]` 作为右子树。因此以 `j` 作为根节点的二叉搜索树的种类有 `dp[j - 1] * dp[i - j]` 个，累加所有的 `j = [1...i]` 计算出 `dp[i]`

[101.对称二叉树](https://leetcode-cn.com/problems/symmetric-tree/)：给你一个二叉树 `root`，判断它是否轴对称。👉 [<u>对称二叉树</u>](二叉树/101%20对称二叉树.cc)

- 迭代。使用一个队列 `que` 保存左右两颗子树的两个待判断的节点，每次从队列中弹出两个元素判断值是否相等，并按照如下顺序压入队列 `left->left, right->right, right->left, left->right`
- 递归。判断左右两颗子树是不是相同的二叉树

[104.二叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)：👉 [<u>二叉树的最大深度</u>](二叉树/104%20二叉树的最大深度.cc)

[105.从前序与中序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)：👉 [<u>从前序与中序遍历序列构造二叉树</u>](二叉树/105%20从前序与中序遍历序列构造二叉树.cc)

[114.二叉树展开为链表](https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/)：给你一棵二叉树 `root`，将它展开为链表，二叉树的 `right` 指针作为链表的 `next` 指针。👉 [<u>二叉树展开为链表</u>](二叉树/114%20二叉树展开为链表.cc)

- 前序遍历。使用 `vector<TreeNode *> list` 记录前序遍历的所有节点，然后遍历 `list` 展开为链表。时间复杂度 `O(n)`，空间复杂度 `O(n)`
- 前序遍历一边遍历一边展开。另一种前序遍历的写法，使用 `prev` 记录上一次遍历到的节点，然后 `prev->right = cur; prev->left = nullptr;`。时间复杂度 `O(n)`，空间复杂度 `O(n)`
- 寻找左子树最右边的节点。记当前节点为 `cur`，每次判断 `cur->left` 是不是为空，如果不为空寻找 `cur->left` 子树最右边的节点记为 `next`；然后执行 `next->right = cur->right; cur->right = cur->left; cur->left = nullptr;`；最后更新 `cur = cur->right;`。时间复杂度 `O(n)`，空间复杂度 `O(1)`

[121.买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)：👉 [<u>买卖股票的最佳时机</u>](动态规划/股票问题/121%20买卖股票最佳时机.cc)

[128.最长连续序列](https://leetcode-cn.com/problems/longest-consecutive-sequence/)：给你一个未排序的数组 `nums`，找出数字连续的最长序列的长度，请你设计并实现一个时间复杂度为 `O(n)` 的算法。👉 [<u>最长连续序列</u>](哈希/128%20最长连续序列.cc)

使用数组中每个连续序列的最小值来统计连续序列的长度

- 使用一个哈希表 `st` 存储数组的每一个元素
- 遍历数组，判断 `nums[i] - 1` 是否在哈希表中。如果存在那么跳过该元素；如果不存在，则依次判断 `nums[i] + 1, nums[i] + 2, ..., nums[i] + k` 是否存在，然后更新最长序列的长度 `res`

由于外层循环的时间复杂度是 `O(n)`，对于内层循环来说每个元素只会在内存循环出现一次，因此总的时间复杂度是 `O(n)`
