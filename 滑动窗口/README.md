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

**如果允许最多出现两个重复字符呢**

只需要将 `map[ch] > 1` 改为 `map[ch] > 2` 即可；如果最多允许出现 `k` 个重复字符，那么就是 `map[ch] > k`

**如果允许有一对重复字符呢**

额外使用一个 `unordered_map<char, list<int>> index` 记录窗口中每个字符出现的位置，以及一个变量 `repeat` 记录当前重复的字符

- 如果当前字符 `ch` 出现次数等于 2，即重复了。此时 `l` 移动到 `min(index[repeat].front(), index[ch].front()) + 1`
- 如果当前字符 `ch` 出现次数等于 3，则 `l` 移动到 `index[ch].front() + 1`

每次窗口的扩张都更新 `len`

```c++
int func(string s) {
  unordered_map<char, int> map;
  unordered_map<char, list<int>> index;
  int l = 0, r = 0, len = 0;
  int repeat = -1;
  while (r != s.size()) {
    char ch = s[r];
    index[ch].push_back(r); // 记录 s[r] 的新的位置
    // 有新的字符出现重复
    if (++map[ch] == 2) {
      if (repeat == -1)
        repeat = ch;
      else if (index[repeat].front() < index[ch].front()) {
        l = index[repeat].front() + 1;
        index[repeat].pop_front();
      } else {
        l = index[ch].front() + 1;
        index[ch].pop_front();
      }
    } else if (map[ch] > 2) {
      // 有字符的出现次数大于 2
      l = index[ch].front() + 1;
      index[ch].pop_front();
    }
    len = max(len, r - l + 1);
    ++r;
  }
}
```

> 补充：lintcode-928 [928 · 最多有两个不同字符的最长子串 - LintCode](https://www.lintcode.com/problem/928)，最多包含两个不同字符

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

**滑动窗口**

「枚举窗口中允许出现的字符种数」这个范围在 `[1, 26]`，对于每个允许出现的次数 `i` 来说，需要保证窗口中最多只能出现 `i` 种字符

另一个需要解决的问题是，如何得知窗口中有多少个字符出现的次数大于 `k`。我们可以反过来思考，通过记录窗口中出现次数小于 `k` 的字符种数，来间接的计算得到出现次数大于 `k` 的字符种数。具体的，使用 `less` 记录当前窗口中字符出现次数小于 `k` 的种数，当随着窗口滑动，某个字符第一次出现的时候增加 `less` 的值，当某个字符第一次出现 `k` 次的时候递减 `less` 的值

每一次窗口向右移动之后，如果 `less == 0` 则更新 `res = max(res, r - l + 1)`

**分治**

对于题目中要求的最长子串，它必定不会包含那些出现次数小于 `k` 的字符，因此我们可以根据这个规则进行递归：

1. 计算字符串 `s[l...r]` 中每个字符出现的次数，
2. 将 `s` 按照某个出现次数小于 `k` 的字符 `split` 进行分割，这是因为满足题目要求的子串必定不会跨越 `split` 字符
3. 对每一个分割得到的子串都递归的调用处理函数
4. 某次递归可能没有找到 `split` 字符，这个时候返回 `r - l + 1`

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
