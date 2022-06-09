[8. 字符串转换整数 (atoi) - 力扣（LeetCode）](https://leetcode.cn/problems/string-to-integer-atoi/): 实现 `myAtoi(s)` 函数，该函数执行如下逻辑

1. 丢弃前导空格
2. 检查下一个字符串是 '-' 还是 '+'，或者两者都没有出现
3. 读入下一个字符，直到下一个字符是非数字或者到达输入结尾
4. 将前面读入的字符串转化为数字，如果没有读入则为 0
5. 如果超出 int 的边界，则使用边界作为最终值

模拟上述执行过程即可，需要注意的是第 5 条。如果面试的时候要求不能使用 `long` 的话，可以按照下面的逻辑处理

```c++
start = true;
int val = s[i] - '0';
if (res > (INT_MAX - val) / 10)
    return positive ? INT_MAX : INT_MIN;
res = res * 10 + val;
```

如果 `res * 10 + val > INT_MAX` 即 `res > (INT_MAX - val) / 10` 那么 `res >= INT_MAX + 1`，从而有 `res <= -INT_MAX - 1 = INT_MIN`。所以这里条件判断如果成立的话对于 `INT_MAX` 溢出或者 `INT_MIN`  溢出都可以处理