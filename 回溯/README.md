[46.全排列](https://leetcode-cn.com/problems/permutations/)：给定一个不包含重复数字的数组 `nums`，返回其所有可能的全排列。👉 [<u>全排列</u>](排列/46%20全排列.cc)

深搜，额外使用空间来记录当前元素是否被访问过

[47.全排列II](https://leetcode-cn.com/problems/permutations-ii/)：现在 `nums` 数组中包含了重复的元素，但是要求返回所有不重复的排列。👉 [<u>全排列II</u>](排列/47%20全排列II.cc)

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

[126. 单词接龙 II - 力扣（LeetCode）](https://leetcode.cn/problems/word-ladder-ii/)：题目意思参考 127 题。这题需要输出所有的最短路径。👉 [解答](126%20单词接龙II.cc)

过程基本一样

1. 构建图（这题的构建方法我没有将 `string` 映射到 `int` 而是直接使用 `unordered_map` 结合 `string` 构建）
2. BFS 搜索，搜索的过程中需要记录每个节点的直接前驱
3. DFS 根据记录下来的前驱，从 `endWord` 出发还原最短路径

有很多细节需要考虑，例如记录直接前驱的时候，对于当前层的节点重复遍历到的节点怎么处理：这里我才用的方法是，在每一层使用 `unordered_set this_round` 记录当前层新遍历到的节点，如果发现某个节点已经在 `visited` 里面了，判断一下是不是在 `this_round` 里面，如果也在 `this_round` 里面的话，则说明这个节点是在本层 BFS 搜索过程中新加入的，因此也需要记录一次前驱节点

[127. 单词接龙 - 力扣（LeetCode）](https://leetcode.cn/problems/word-ladder/)：字典 `wordList` 中从单词 `beginWord` 和 `endWord` 的转换序列是一个按下述规格形成的序列 `beginWord -> s1 -> s2 -> ... -> sk`：每一对相邻的数字只相差一个单词；`si` 存在于 `wordList` 中；`sk == endWord`。给你两个单词 `beginWord` 和 `endWord` 和一个字典 `wordList`，返回从 `beginWord` 到 `endWord` 的最短转换序列中的单词数目，如果不存在这样的转换序列则返回 0. 👉 [解答](127%20单词接龙.cc)

可以对 `wordList` 进行建图（将 `beginWord` 添加进去），相差一个字符的字符串之间有一条边，然后就可以从 `beginWord` 出发，找到最短的到达 `endWord` 的路径了

构建图的方法有很多，最简单的暴力循环判断每个 `wordList` 中的单词，这样建图的时间复杂度就是 $O(n^2)$，最终会超时。我们可以优化建图的方法，添加每个单词的虚拟节点，例如对于单词 `hit` 我们添加 `*it, h*t, hi*`，这样以来所有只相差一个字符的单词必定会连接到相同的虚拟节点，相当于我们用虚拟节点作为跳板到达相差一个字符的单词。该方法构建图的时间复杂度为 $O(NC)$，其中 $N$ 是 `wordList` 单词的数量，$C$ 是每个单词的最长长度。【注意⚠️】这种情况下，遍历的路径长度是原来的两倍

本题使用到的还有一个小技巧是，将 `string -> int`，即转化为简单的 `int` 节点作为图的节点，使用全局递增的 `sequence` 作为某个第一次出现的单词的编号。所有单词的编号保存在 `word_id` 中

最后从 `word_id[beginWord]` 出发，进行搜索，直到到达 `word_id[endWord]`。可以使用广度优先搜索，第一次遇到 `word_id[endWord]` 时候搜索的深度就是最短的路径

时间复杂度：$O(NC)$
每个单词对应 $NC$ 个节点，每个节点的大小为 $C$ 因此最终空间复杂度为：$O(NC^2)$

[130. 被围绕的区域 - 力扣（LeetCode）](https://leetcode.cn/problems/surrounded-regions/)：给你一个 `m * n` 的矩阵 `board`，找到所有被 `X` 包围的 `O`，并将其修改为 `X`。👉 [解答](130%20填充矩阵中间被围绕的区域.cc)

从矩阵边界的 `O` 出发，将所有相邻的 `O` 都修改为 `#`，然后遍历矩阵如果遇到 `O` 就修改为 `X`，再次遍历矩阵如果遇到 `#` 就修改为 `O`

时间复杂度：$O(mn)$，空间复杂度 $O(mn)$

[200.岛屿数量](https://leetcode-cn.com/problems/number-of-islands/)：给你一个由 `1`（陆地） 和 `0`（水） 组成的二维网格，请你计算网格中岛屿的数量。👉 [<u>岛屿数量</u>](200%20岛屿数量.cc)

1. dfs 和 bfs 两种方法
2. 并查集，将所有邻接的 1 都合并

并查集：每次填充块的时候判断相邻的块是不是 1，如果是 1 的话就进行合并。时间复杂度：$O(klog(mn))$，其中 k 是操作的次数，每次操作查找的 root 的时间复杂度是 log(mn)。空间复杂度：$O(mn)$

[329. 矩阵中的最长递增路径 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/)：给定一个 m * n 的矩阵，找出其中最长递增路径的长度，对于每个单元格，你可以往上、下、左、右四个方向移动。👉 [<u>矩阵中的最长递增路径</u>](329%20矩阵中的最长递增路径.cc)

采用**记忆化搜索**的方式避免重复的搜索。对于每个单元格记录从当前单元格出发的最长递增路径，在深搜遍历的过程中如果发现某个单元格已经被计算过，那么直接备忘录 memo 中的值

时间复杂度 `O(mn)`，空间复杂度 `O(mn)`

> 还可以采用拓扑排序的方法

[547. 省份数量 - 力扣（LeetCode）](https://leetcode.cn/problems/number-of-provinces/)：找出省份的数量，即连通块的数量。👉 [解答](574%20省份数量.cc)

岛屿数量相同的解法

[695. 岛屿的最大面积 - 力扣（LeetCode）](https://leetcode.cn/problems/max-area-of-island/)：岛屿是由一些相邻的 `1` 构成的组合，岛屿的面积是岛上值为 `1` 的单元格的数目，计算并返回` grid` 中最大的岛屿面积。👉 [解答](695%20岛屿的最大面积.cc)

深搜、广搜、并查集都可以解决

[854. 相似度为 K 的字符串 - 力扣（LeetCode）](https://leetcode.cn/problems/k-similar-strings/)：字符串 `s1` 和 `s2` 是 `k` 相似，如果我们可以交换 `s1` 中两个字母的位置正好 `k` 次，使结果字符串等于 `s2`。给定两个字符串 `s1` 和 `s2`，返回 `s1` 和 `s2` 的相似度。👉 [解答](搜索/854%20相似度为K的字符串.cc)

这道题虽然是困难题，但是思路比较简单，可以直接通过 dfs 解决。对于 `s1[i]` 如果 `s2[i] == s1[i]` 则继续搜索下一个位置。否则的话遍历 `s2[i+1...len-1]`，如果 `s2[j] == s1[i]` 则交换 `s2[i]` 和 `s2[j]`，然后继续搜索下一个位置

注意需要使用剪枝，否则会超时，当判断 `cur_count` 即当前交换次数大于 `res` 的时候，直接停止搜索，返回上一层搜索

[1376. 通知所有员工所需的时间 - 力扣（LeetCode）](https://leetcode.cn/problems/time-needed-to-inform-all-employees/)：每个员工都有其直属上级，题目中给出的 `informTime[i]` 是员工 `i` 通知它的所有下属所需要时间，而不是通知一个下属。最后不同的上级对下级的通知可以并行执行，因此要计算从第一个节点到所有叶子节点路径的最大值作为「通知所有员工所需的时间」。👉 [解答](1376%20通知所有员工所需的时间.cc)

1. dfs 搜索，计算从根节点到叶子节点路径的最大值
2. bfs