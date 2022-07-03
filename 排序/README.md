## 排序

[179. 最大数 - 力扣（LeetCode）](https://leetcode.cn/problems/largest-number/)：给定一个非负整数 `nums`，重新排列每个数的顺序，使之组成一个最大的整数。👉 [解答](排序/179%20最大数.cc)

自定义排序，对于两个整数 a 和 b，考虑 a 和 b 拼接之后、b 和 a 拼接之后的两个数字大小，定义比较函数。然后使用快排对原数组进行排序

时间复杂度：$O(nlognlogm)$，空间复杂度：$O(logn)$

[324. 摆动排序 II - 力扣（LeetCode）](https://leetcode.cn/problems/wiggle-sort-ii/) -> [code](324%20摆动序列II.cc)

进阶：`O(n)` 时间复杂度和 `O(1)` 空间复杂度

[376. 摆动序列 - 力扣（LeetCode）](https://leetcode.cn/problems/wiggle-subsequence/) -> [code](289%20摆动排序.cc)

[414. 第三大的数 - 力扣（LeetCode）](https://leetcode.cn/problems/third-maximum-number/) -> [code](414%20第三大的数.cc)

1. quick select
2. x, y, z 记录数组中前三的最小值
3. 进阶忽略元素范围：x, y, z 记录数组中前三元素的地址，这样可以忽略元素的范围

[1424.对角线遍历II]([1424. 对角线遍历 II - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/diagonal-traverse-ii/))：给你一个列表 `nums`，里面每个元素都是整数列表，按照以下方式，按顺序返回 `nums` 中对角线上的整数。👉 [<u>对角线遍历II</u>](排序/1424%20对角线遍历II.cc)

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/04/23/sample_1_1784.png)

1. 使用 `map<int, vector<int>>` 保存和为 `key` 的所有 `values`，`nums` 数组按照从下往上从左到右的方式遍历，保存元素到 `map` 中。然后按顺序遍历 `map` 中的每一个 `key` 保存 `values` 到结果中即可。本质上是利用了 `map` 红黑树有序的特点
2. 使用堆排序。堆中保存的是 `pair<int, int>`，其中 first 表示横坐标，second 表示纵坐标。堆中按照 `first + second` 的和排序，相同的时候按照 `first` 越大的越靠前。然后从堆中依次弹出元素，保存 `nums[first][second]` 到结果中即可