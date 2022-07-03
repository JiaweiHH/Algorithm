## 字典树

[336. 回文对 - 力扣（LeetCode）](https://leetcode.cn/problems/palindrome-pairs/comments/)：给你一个字符串列表，找出所有可以拼接得到的字符串对。👉 [解答](336%20回文对.cc)

**字典树**

我们可以首先将所有字符串添加到字典树中，然后遍历每个字符串 `str`。如果 `str` 和某个字符串 `tmp` 可以组成一个回文串，则有两种情况：

1. `tmp + str` 是回文串，这个时候对于字符串 `str` 来说，必定存在某个下标 `x` 使得 `str[0..x]` 是回文串，并且 `str[x+1..len-1]` 是 `tmp` 的翻转串
2. `str + tmp` 是回文串，这个时候必定存在某个下标 `x`，使得 `str[x..len-1]` 是回文串，并且 `str[0..x-1]` 是 `tmp` 的翻转串

结合上述分析，我们可以这样实现我们的算法：枚举 `k = [0..len]`，如果 `str[k..len-1]` 是回文串，则去字典树查找是否存在 `str[0..k-1]` 的翻转串 `tmp`；如果 `str[0..k-1]` 是回文串，则取字典树中查找是否存在 `str[k..len-1]` 的翻转串 `tmp`。对于第一种情况如果存在的话则 `{str, tmp}` 是回文串，对于第二种情况如果存在的话则 `{tmp, str}` 是回文串

[421.数组中两个数的最大异或值]([421. 数组中两个数的最大异或值 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/maximum-xor-of-two-numbers-in-an-array/))：给你一个整数数组 `nums`，返回 `nums[i] XOR num[j]` 的最大运算结果。👉 [<u>数组中两个数的最大异或值</u>](字典树/421%20数组中两个数的最大异或值.cc)

首先需要明确的是异或运算的规则，`x = a XOR b` 等价于 `b = x XOR a`

1. 方法一：哈希。基于上述规则，我们可以从高位到低位不断的假设 `x`  的每一位的数位 1，此时 `x` 已经确定了 `k` 位，然后和 `nums[i]` 的前 `k` 位数异或，如果异或的结果在 `nums` 数组中，那么说明这一位可以是 1，否则的话这一位只能是 0。为了能够快速的找到异或的结果是否出现在 `nums` 数组中，可以使用哈希表记录 `nums` 数组中所有元素的前 `k` 位前缀。时间复杂度 `O(nlogc)`，其中 `c` 表示最大数的二进制位数，空间复杂度 `O(1)`
2. 方法二：字典树。既然需要前缀来判断，那么很容易的想到使用字典树来处理，我们可以初始的时候讲所有的 `nums` 转化为二进制存入字典树中。然后枚举每一个 `num`，如果 `num` 的第 `k` 位是 0，则在字典树中寻找 1，找不到的话就找 0；如果 `num` 的第 `k` 位是 1，则在字典树中寻找 0，找不到的话就找 1。最后将找到的所有二进制拼接起来就是对于 `num` 而言最大的异或值。时间复杂度 `O(nlogc)`，其中 `c` 表示最大数的二进制位数，空间复杂度 `O(nlogc)`

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