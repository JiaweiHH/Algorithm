## 组合问题

组合问题中去除重复的方式有：
1. 使用 `set` 或者 `unordered_set`
2. 对原数组 `nums` 进行排序，然后如果 `nums[i] = nums[i - 1]` 并且没有选择 `nums[i - 1]` 那么也不选择 `nums[i]`