[94.二叉树的中序遍历](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)：👉 [<u>二叉树的中序遍历</u>](94%20二叉树的中序遍历.cc)

需要掌握的：

1. 递归方法
2. 使用栈的迭代方法
3. Morris 遍历方法
   - 对于 `root`，如果 `root` 存在左子树，那么就找到左子树中最右边的那个节点，让它的 `right` 指针指向 `root`，类似二叉线索树，这样之后可以回到 `root` 并访问 `root->val`。然后让 `root = root->left` 并断开 `root` 和 `root->left` 的指针，这样做是为了防止循环遍历
   - 如果不存在左子树，那么就将 `root->val` 加入到 `res` 中，然后让 `root = root->right`

[96.不同二叉搜索树](https://leetcode-cn.com/problems/unique-binary-search-trees/)：给你一个整数 `n`，求恰由 `n` 个节点组成且节点值从 `1` 到 `n` 互不相同的二叉搜索树有多少种。👉 [<u>不同二叉搜索树</u>](96%20不同二叉搜索树.cc)

动态规划。使用 `dp[i]` 表示当 `n = i` 的时候有多少种不同的二叉搜索树，我们可以将 `j = [1...i]` 作为根节点，`[1...j-1]` 作为左子树，`[j+1...i]` 作为右子树。因此以 `j` 作为根节点的二叉搜索树的种类有 `dp[j - 1] * dp[i - j]` 个，累加所有的 `j = [1...i]` 计算出 `dp[i]`

[98.验证二叉搜索树](https://leetcode-cn.com/problems/validate-binary-search-tree/)：给你一个二叉树 `root` 判断它是不是一棵有效的二叉搜索树。👉 [<u>验证二叉搜索树</u>](98%20验证二叉搜索树.cc)

1. 递归（后序遍历）。需要记录左右子数的 `{min_val, left_val, isValid}`，然后和根节点进行对比，返回数据结构
2. 递归（中序遍历）。使用一个全局变量记录前一个节点的值，中序遍历的时候每次判断当前节点的值和前一个节点值的大小
3. 迭代（中序遍历）。也使用一个变量记录上一个节点的值，和递归的思路大致相同

[99. 恢复二叉搜索树 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/recover-binary-search-tree/)：给你二叉搜索树的根节点 `root`，该树中的恰好两个节点值被错误的交换，请你在不改变树的结构的情况下，恢复这棵树。👉 [<u>恢复二叉搜索树</u>](99%20恢复二叉搜索树.cc)

利用 BST 中序遍历的有序性，如果有两个节点的值被交换了，则中序遍历必定会出现逆序对。如果交换的刚好是中序遍历中相邻的两个节点，那么这个时候只有一个逆序对，否则就会出现两对逆序对，我们只需要交换第一对逆序对的第一个节点和第二对逆序对的第二个节点就可以恢复 BST 的有序性

本题中序遍历的两个方法：

1. 使用 `vector` 记录中序遍历的 `TreeNode *`，然后找到逆序对交换节点值。该方法时间复杂度：$O(n)$，空间复杂度：$O(n)$
2. Morris 遍历，相较于第一种方法时间复杂度不变，但是空间复杂度变为 $O(1)$

```c++
/// Morris 遍历记录方法，first 记录 prev->val < root->val，中的 prev，second 记录 root
/// 初始的时候 first 和 second 都为 nullptr
if (!first)
  first = prev;
second = root;
```

[101.对称二叉树](https://leetcode-cn.com/problems/symmetric-tree/)：给你一个二叉树 `root`，判断它是否轴对称。👉 [<u>对称二叉树</u>](101%20对称二叉树.cc)

- 迭代。使用一个队列 `que` 保存左右两颗子树的两个待判断的节点，每次从队列中弹出两个元素判断值是否相等，并按照如下顺序压入队列 `left->left, right->right, right->left, left->right`
- 递归。判断左右两颗子树是不是相同的二叉树

[102.二叉树的层序遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)：👉 [<u>二叉树的层序遍历</u>](102%20二叉树的层序遍历.cc)

需要掌握的：

1. 使用队列，迭代处理
2. 递归处理。前序遍历的时候记录二叉树的高度，然后 `res[level].push_back(root->val)` 就可以了，如果 `res[level]` 不存在的话，则 `res.push_back({root->val})`

[103.二叉树的锯齿形层序遍历]([103. 二叉树的锯齿形层序遍历 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/))：返回二叉树节点值的锯齿形层序遍历（先从左往右，再从右往左进行下一层遍历，交替执行）。👉 [<u>二叉树的锯齿形层序遍历</u>](103%20二叉树的锯齿形层序遍历.cc)

标记奇偶行，对于偶数行对该层结果进行反转即可

[104.二叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)：👉 [<u>二叉树的最大深度</u>](104%20二叉树的最大深度.cc)

[105.从前序与中序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)：给出一棵二叉树的前序遍历数组和中序遍历数组，请你根据这两个数组构造二叉树。👉 [<u>从前序与中序遍历序列构造二叉树</u>](105%20从前序与中序遍历序列构造二叉树.cc)

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

[108. 将有序数组转换为二叉搜索树 - 力扣（LeetCode）](https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/)：给你一个有序的整数数组，请你将其转化为一棵平衡二叉树。👉 [解答](108%20将有序数组转化为二叉搜索树.cc)

取中间元素作为根节点，然后递归的建立左右子树

[111. 二叉树的最小深度 - 力扣（LeetCode）](https://leetcode.cn/problems/minimum-depth-of-binary-tree/submissions/)：给你一棵二叉树，找出其最小深度。👉 [解答](111%20二叉树的最小深度.cc)

1. 广度优先搜索，第一次遇见没有左右孩子的节点的时候，此时层序遍历的深度就是最小深度
2. 递归搜索。分别计算左右子树的深度 `l` 和 `r`，`return l == 0 ? r : (r == 0 ? l : min(l, r) + 1)`

[114.二叉树展开为链表](https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/)：给你一棵二叉树 `root`，将它展开为链表，二叉树的 `right` 指针作为链表的 `next` 指针。👉 [<u>二叉树展开为链表</u>](114%20二叉树展开为链表.cc)

- 前序遍历。使用 `vector<TreeNode *> list` 记录前序遍历的所有节点，然后遍历 `list` 展开为链表。时间复杂度 `O(n)`，空间复杂度 `O(n)`
- 前序遍历一边遍历一边展开。另一种前序遍历的写法，使用 `prev` 记录上一次遍历到的节点，然后 `prev->right = cur; prev->left = nullptr;`。时间复杂度 `O(n)`，空间复杂度 `O(n)`
- 寻找左子树最右边的节点。记当前节点为 `cur`，每次判断 `cur->left` 是不是为空，如果不为空寻找 `cur->left` 子树最右边的节点记为 `next`；然后执行 `next->right = cur->right; cur->right = cur->left; cur->left = nullptr;`；最后更新 `cur = cur->right;`。时间复杂度 `O(n)`，空间复杂度 `O(1)`

[117. 填充每个节点的下一个右侧节点指针 II - 力扣（LeetCode）](https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii/)：填充每个二叉树节点的 `next` 指针，让这个指针指向其下一个右侧节点，如果没有下一个右侧节点则 `next` 指针设置为 `NULL`。👉 [解答](117%20填充每个节点的下一个右侧节点指针II.cc)

使用层序遍历，对每一层的节点，让它指向队列首部的节点（每一层的最后一个节点除外）

**进阶：O(1) 空间复杂度**

利用 `next` 指针进行层序遍历，上一层在遍历的时候帮助下一层建立连接。使用 `next_start` 表示下一层的第一个节点，`prev` 表示下一层上一个遍历到的节点

1. 如果当前层正在遍历的节点有左孩子，则令 `prev->next = node->left; prev = node->left`
2. 如果当前层正在遍历的节点有右孩子，则令 `prev->next = node->right; prev = node->right`

[124.二叉树中的最大路径和](https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/)：路径被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径中至多出现一次，该路径最少包含一个节点，且不一定经过根节点。给你一棵二叉树 `root`，返回其最大路径和。👉 [二叉树中的最大路径和](124%20二叉树中的最大路径和.cc)

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

[199. 二叉树的右视图 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/binary-tree-right-side-view/)：给你一个二叉树，返回从右侧能看到的节点值。👉 [<u>二叉树的右视图</u>](199%20二叉树的右视图.cc)

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

[222. 完全二叉树的节点个数 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/count-complete-tree-nodes/)：给你一颗完全二叉树，请你找出树中有多少个节点。👉 [完全二叉树的节点个数](222%20完全二叉树的节点个数.cc)

1. 二叉树的遍历计算节点的数量。时间复杂度 O(n)
2. 二分查找
   - **方法描述：**我们可以先计算二叉树的层数 `h`，对于一个 `h` 层的完全二叉树来说，它的节点数量在 `[2^(h - 1), 2^h - 1]`。这样我们就可以在这个范围内进行二分查找，判断指定的节点是否存在于二叉树中。对于某个编号为 k 的节点我们可以将 k 转化为二进制，通过哈夫曼编码的方式，二进制比特位为 1 的时候向右走，为 0 的时候向左走，如果最后走到的不是 nullptr 节点则说明编号为 k 的节点存在，此时可以判断出该二叉树的节点数量大于等于 k。最终需要找到最后一个出现在二叉树中的编号
   - 复杂度计算：二叉树最后一层的节点数量最大为 2^h 个，因此二分查找需要查找的次数是 log(2^h) = h，每次查找需要遍历一条长度为 h 的路径，所以总的时间复杂度是 O(h^2) = O((logn)^2)

[226.翻转二叉树](https://leetcode-cn.com/problems/invert-binary-tree/)：给你一棵二叉树，翻转这棵二叉树。👉 [<u>翻转二叉树</u>](226%20翻转二叉树.cc)

递归调用函数即可

[230. 二叉搜索树中第K小的元素 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/)：找到二叉搜索树中第K小的元素。👉 [题解](230%20二叉搜索树中第k小的元素.cc)

中序遍历，每次遍历了一个节点令 k--，当 k = 0 的时候，该节点就是第K小的元素。时间复杂度 O(H + k)，H 是二叉树的高度，空间复杂度 O(H)

1. 如果你需要频繁地查找第 k 小的值，如何优化。可以进行一次预处理，将每个节点为根的子树节点的个数记录在哈希表中，查找的时候可以直接通过哈希表判断元素是否在该子树中。预处理时间复杂度 O(N)，查找的时间复杂度 O(N)
2. 如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化。将二叉搜索树转化为平衡二叉树，并记录每个节点为根的子树节点数量到哈希表中。预处理时间复杂度 O(N)，插入、查找、删除时间复杂度 O(log N)

[236.二叉树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/)：给定一棵二叉树以及它的两个节点 `p` 和 `q`，返回这两个节点的最近公共祖先。👉 [<u>二叉树的最近公共祖先</u>](236%20二叉树的最近公共祖先.cc)

两种方法可以解决：

1. 首先搜索整棵树，使用哈希表记录每个节点的父节点；然后从 `p` 出发不断向上遍历，并记录每个遍历过的节点；然后从 `q` 出发不断向上遍历，如果碰到某一个节点已经遍历过了，那么该节点就是它们的最近公共祖先
2. 后序遍历递归。`lowestCommonAncestor` 函数返回值表示的是 `p` 和 `q` 最近的公共祖先
   - 如果我们遍历的时候发现 `root == p || root == q` 那么直接返回 `root`
   - 否则继续遍历左子树和右子树
     - 如果左子树的返回值不为 `nullptr` 说明在左子树中发现了 `p` 或者 `q`，并且右子树的返回值不为 `nullptr` 说明在右子树中发现了 `p`  或者 `q`，此时 `root` 就是它们的公共祖先，返回 `root`
     - 如果左子树或者右子树的返回值有一个为 `nullptr` 那么返回另一个值，表示当前 `root` 这颗子树发现了一个节点
     - 如果左右子树的返回值都为 `nullptr` 那么返回 `nullptr` 说明当前 `root` 这颗子树没有找到任何一个和 `p` 或者 `q` 相等的节点

[450.删除二叉搜索树中的节点]([450. 删除二叉搜索树中的节点 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/delete-node-in-a-bst/))：给定一个二叉搜索树 `root` 和一个值 `key`，删除二叉搜索树中 `key` 对应的节点，返回删除后的二叉搜索树。👉 [<u>删除二叉搜索树中的节点</u>](450%20删除二叉搜索树中的节点.cc)

- 如果 `key > root->val`，`root->right = deleteNode(root->right, key)`
- 如果 `key < root->val`，`root->left = deleteNode(root->left, key)`
- 如果 `key == root->val`
  - 如果 `root` 左右子树都为空，那么返回 `nullptr`
  - 如果左子树为空，右子树不为空，返回右子树
  - 如果左子树不为空，右子树为空，返回左子树
  - 如果左右子树都不为空，找到右子树最左边的那个节点，将它的值赋给 `root`，然后执行 `root->right = deleteNode(root->right, node->val)`

[572. 另一棵树的子树 - 力扣（LeetCode）](https://leetcode.cn/problems/subtree-of-another-tree/)：给你两棵二叉树 `root` 和 `subRoot`，判断 `root` 中是否存在子树的结构和 `subRoot` 完全相同。👉 [解答](572%20另一棵树的子树.cc)

双递归，外层对 `root` 进行递归 dfs，如果判断出 `root->val == subRoot->val` 则进入内层递归。内层递归判断 `root` 为根的树是否和 `subRoot` 完全相同，内层递归转换成 **101题**

[652. 寻找重复的子树 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/find-duplicate-subtrees/)：给你一棵二叉树，返回所有重复的子树。👉 [<u>寻找重复的子树</u>](652%20寻找重复的子树.cc)

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

[662. 二叉树最大宽度 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/maximum-width-of-binary-tree/)：给定一个二叉树，获取这棵树的最大宽度。👉 [<u>二叉树最大宽度</u>](662%20二叉树最大宽度.cc)

层序遍历的时候对每一个节点按照完全二叉树的形式编号，每一层队列尾部的编号和队列首部的编号之差再加一就是该层的最大宽度

[669.修剪二叉搜索树]([669. 修剪二叉搜索树 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/trim-a-binary-search-tree/))：给你一棵二叉搜索树，同时给定一个最小边界 `low` 和最大边界 `high`，删除二叉树中在这段区间之外的节点，并且需要保持现有节点的相对位置。👉 [<u>修剪二叉搜索树</u>](669%20修剪二叉搜索树.cc)

几个边界情况

- `root->val == low`，此时需要让 `root->left = nullptr`
- `root->val == high`，此时需要让 `root->right = nullptr`
- `root->val > high`，返回 `trimBST(root->left, low, high)`
- `root->val < low`，返回 `trimBST(root->right, low, high)`
- 否则的话说明 `root->val` 在区间范围内，因此执行 `root->left = trimBST(root->left, low, high)`，`root->right = trimBST(root->right, low, high)`

[958.二叉树的完全性检验]([958. 二叉树的完全性检验 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/check-completeness-of-a-binary-tree/))：给你一棵二叉树，判断它是否是一棵完全二叉树。👉 [<u>二叉树的完全性检验</u>](958%20二叉树的完全性检验.cc)

层序遍历，每次记录前一个遍历的元素，如果某一个节点是 `nullptr`，则记录 `prev = -1`。后序遍历的过程中如果 `prev == -1` 并且某一个节点不是 `nullptr` 则说明不是一棵完全二叉树。如果整棵树都正常遍历完毕，那么就是一棵完全二叉树

## 