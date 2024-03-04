# 题目描述

给定一个非负整数数组 $a$ 和一个整数 $k$ ，你需要将这个数组分成 $k$ 个非空的连续子数组。

设计一个算法使得这 $k$ 个子数组各自和的 **<font color="#FF0000">最小值最大</font>** 。

# 输入格式

输入包含 $2$ 行

第 $1$ 行包 $2$ 个整数 $n, k$，表示数组的长度和要分割的数量。

第 $2$ 行包含 $n$ 个整数，用空格分开，表示数组 $a$。

# 输出格式

输出 $k$ 个子数组各自和的最小值的最大值

```input1
5 2
7 2 5 10 8
```

```output1
14
```

```input2
5 2
1 2 3 4 5
```

```output2
6
```

```input3
3 3
1 4 4
```

```output3
1
```

# 提示
**【样例解释 1】**
* 一共有 $4$ 种方法将 $a$ 分割为 $2$ 个子数组。 
* 其中最好的方式是将其分为 [7,2,5] 和 [10,8] 。
* 因为此时这两个子数组各自的和的最小值为14，在所有情况中最大。

<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

* 答案满足单调性，考虑二分枚举答案
* 要求的是最小的答案，注意二分的边界情况

</details>

# 数据规模与限制
* $1 \le s.length \le 10^3, 0 \le a_i \le 10^6$
* $1 \le k \le min(50, a.lenght)$
* 1s, 1024KiB for each test case.

# 来源
* [leetcode_410_分割数组的最大值](https://leetcode.cn/problems/split-array-largest-sum/description/)