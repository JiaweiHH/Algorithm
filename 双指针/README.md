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

[54. 螺旋矩阵 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/spiral-matrix/)：给你一个 `m` 行 `n` 列的矩阵 `matrix`，请你按照顺时针顺序，返回矩阵中的所有元素。👉 [<u>螺旋矩阵</u>](双指针/54%20螺旋矩阵.cc)

<img src="https://assets.leetcode.com/uploads/2020/11/13/spiral1.jpg" alt="img" style="zoom:50%;" />

使用两个指针 `ptr_r1`，`ptr_r2` 来表示行数的范围，两个指针 `ptr_c1`，`ptr_c2` 来表示列数的范围。因此我们可以先遍历 `[ptr_r1][ptr_c1...ptr_c2]`，然后遍历 `[ptr_r1+1...ptr_r2][ptr_c2]`，然后遍历 `[ptr_r2][ptr_c2-1...ptr_c1]`，然后遍历 `[ptr_r2-1...ptr_r1+1][ptr_c1]`。当遍历完成之后 `ptr_r1++, ptr_r2--, ptr_c1++, ptr_c2--`

另外需要注意一下边界条件，如果 `ptr_r1 == ptr_r2` 此时不需要执行第三步遍历，如果 `ptr_c1 == ptr_c2` 此时不需要执行第四步遍历

[59. 螺旋矩阵 II - 力扣（LeetCode）](https://leetcode.cn/problems/spiral-matrix-ii/)：给你一个整数 `n`，生成一个包含 `1` 到 `n^2` 所有元素的螺旋矩阵，螺旋矩阵的定义和 54题 相同。👉 [解答](59%20螺旋矩阵II.cc)

方法和 *54题* 相同，采用双指针不断逼近来解决

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
