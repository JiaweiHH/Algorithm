## 哈希

[41.缺失的第一个正数]([41. 缺失的第一个正数 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/first-missing-positive/))：给你一个未排序的数组 `nums`，请你找出其中没有出现的最小的正整数。请你实现时间复杂度为 `O(n)` 并且只使用常数级别额外空间的解决方案。👉 [<u>缺失的第一个正数</u>](数组/41%20缺失的第一个正数.cc)

考虑如果没有限制空间复杂度，我们可以使用一个哈希表记录数组中出现的所有元素，然后遍历 `1 ~ n` 的正整数，判断其是否在哈希表中，`n` 是数组的大小。如果某一个正整数没有出现，那么直接返回；否则返回 `n + 1`

数组的大小只有 `n`，因此缺失的这个正整数必定出现在 `1 ~ n+1` 之间，所以上述哈希的做法时间复杂度为 `O(n)`

1. “哈希“，我们可以在原数组上原地哈希。如果某一个正整数出现了，就将数组中下标为 `num-1` 的元素值置为负数。初始的时候，将数组中所有小于等于 0 的元素设置为 `n+1`，设置为 `n+1` 的理由在于避免这些元素干扰其他正整数的“哈希”运算
   - 当遍历一边数组将所有的下标都标记之后，在遍历数组查看是否存在正整数。如果存在下标为 `i` 的正整数，说明 `i + 1` 这个正整数没有出现在数组中，否则的话说明 `1~n` 都出现在数组中了，那么没有出现的正整数就是 `n+1`
2. 置换法（也类似上面的 “哈希” 方法）
   - 对于每一个数组中的元素 `x = nums[i]`，我们将其放在数组下标为 `x-1` 的位置，并且递归的将原来在 `x - 1` 位置上的元素也放到对应的位置。一直到 `nums[x - 1] == x` 或者 `nums[x - 1] <= 0` 或者 `nums[x - 1] > n` 为止
   - 遍历数组，如果 `nums[i] != i + 1` 说明 `i + 1` 这个元素没有出现，否则如果全部元素都正确的话说明 `1~n` 这些元素全都出现了，这个时候返回 `n+1`

[49. 字母异位词分组 - 力扣（LeetCode）](https://leetcode.cn/problems/group-anagrams/)：给你一个字符串数组，请你将所有的异位词分为一组。👉 [解答](49%20字母异位词分组.cc)

对数组中的每个字符串排序，排序结果相同的分为一组。将排序结果作为 key，value 为所有排序结果相同的字符串。最后输出所有 key 对应的字符串数组

时间复杂度：$O(nklogk)$，其中 $n$ 表示字符串数组的长度，$k$ 表示字符串的最大长度；空间复杂度：$O(nk)$

> 也可以根据异位词所有字母的出现次数相同，将这个线索作为 key，不过 C++ 需要自定义哈希函数 -> 自定义一个实现了 `operator()` 的对象，可以是 lambda，通过 std::hash<int>{} 自定自己的哈希函数

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

[242. 有效的字母异位词 - 力扣（LeetCode）](https://leetcode.cn/problems/valid-anagram/)：判断字符串 `s` 和字符串 `t` 中字母出现的次数是否都是相同的。👉 [解答](242%20有效的字母异位词.cc)

1. 排序
2. 哈希表

这题比较简单

[266. 回文排列 - 力扣（LeetCode）](https://leetcode.cn/problems/palindrome-permutation/)：给你一个字符串，判断能否经过重新排列组合，使之成为一个回文串。👉 [解答](266%20回文排列.cc)

如果可以成为回文串，则出现次数为奇数次的字符个数需要小于等于 1。因此可以使用哈希映射来记录每个字符出现的次数，最后统计奇数个数字符的个数

**进阶：要求只能遍历一次字符串**

使用 `unordered_set` 每次遇到字符的时候，如果该字符不在集合中则 `insert`，否则 `erase` 这个字符，相当于出现次数为偶数的字符串都移除。最后判断集合的 size 即可

[267. 回文排列 II - 力扣（LeetCode）](https://leetcode.cn/problems/palindrome-permutation-ii/)：在 266题 的基础上，返回所有重新排列的回文串。👉 [解答](267%20回文排列II.cc)

首先计算所有字符出现的次数，并判断能否重新排列为回文串。当确认可以重排为回文串之后，使用 `odd_ch` 初始化 `string` 字符串。然后对这个字符串进行回溯，从 `idx = s.size() / 2 - 1` 的位置开始，每次 dfs 设置 `str[idx]` 和 `str[s.size() - idx - 1]`，然后 `idx` 前进一个位置

dfs 函数如何设置 `str`：遍历 `map`，找到出现次数大于 `2` 的字符 `ch`，将 `ch` 保存到 `str`，并减少 `map[ch] -= 2`

> 遍历到的每个字符在一次 dfs 只执行一次，这样就不需要使用 `unordered_set` 去重

[365. 水壶问题 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/water-and-jug-problem/)：有两个水壶的容量分别是 `jug1Capacity` 和 `jug2Capacity`，现在问能否使用这两个水壶量出 `targetCapacity` 升水，每次可以执行的操作有：装满任意一壶水、清空任意一壶水、将一壶水倒入另一壶水直到装满或者倒空。👉 [<u>水壶问题</u>](365%20水壶问题.cc)

使用 dfs 搜索，保存当前两壶水剩余容量的状态，每次可以执行

1. 清空第一壶水
2. 清空第二壶水
3. 倒满第一壶水
4. 倒满第二壶水
5. 将第一壶水倒入第二壶水
6. 将第二壶水倒入第一壶水

由于会出现无限递归，因此对于重复的状态需要使用哈希表去重。如果对于某个中间状态有 `remain_1 == target || remain_2 == target || remain_1 + remain_2 == target` 那么说明此时可以量取 target，返回 true

[409. 最长回文串 - 力扣（LeetCode）](https://leetcode.cn/problems/longest-palindrome/)：给定一个包含大小写字母的字符串，返回通过这些字母构造的最长回文串的长度。👉 [解答](409%20最长回文串.cc)

1. 通过哈希映射记录每个字母出现的次数
2. 添加所有出现次数为偶数次的字母
3. 对于出现次数为奇数次的字母，添加出现次数最多的字符的所有，其它字符添加哈希表中的次数减一

**进阶：一次循环遍历**

```c++
for (auto it = map.begin(); it != map.end(); ++it) {
  if (it->second % 2 == 0 || it->second < cnt)
    res += it->second % 2 == 0 ? it->second : it->second - 1;
  else {
    res += cnt == 0 ? it->second : it->second - 1;
    cnt = it->second;
  }
}
``` 

[454. 四数相加 II - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/4sum-ii/)：给你四个整数数组 `nums1`、`nums2`、`nums3`、`nums4`，数组的长度都是 `n`，请你计算有多少个元组 `(i, j, k, l)` 能满足 `nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0`。👉 [解答](哈希/454%20四数相加II.cc)

使用哈希表记录 `nums1` 和 `nums2` 两个数组中所有元素和出现的次数，然后遍历 `nums3` 和 `nums4`，在哈希表中寻找 `-(nums3[k] + nums4[l])` 是否存在，并添加响应的次数

时间复杂度：$O(n^2)$，空间复杂度：$O(n^2)$