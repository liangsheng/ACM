# 题目描述

给你一个包含 $n$ 个数字的数组 $a(1 \le a_i \le 9)$，现在你需要执行 $b$ 次操作,
- 每次操作需要从数组 $a$ 中选取一个数（假设第 $j$ 次操作选取的数为 $s_j$）

求使得数 $\overline{s_1s_2\cdots s_b}$ 对 $x$ 取模结果为 $k$ 的不同操作数有多少种，请输出方案数（对 $1000000007$ 取模）

# 输入格式
共 2 行：
- 第 1 行包含 $4$ 个正整数 $n, b, k, x(2 \le n \le 50000, 1 \le b \le 10^9, 0 \le k < x \le 100, x \ge 2)$
- 第 2 行包含 $n$ 个数字，表示 $a_1, a_2, \dots, a_n(1 \le a_i \le 9)$
# 输出格式

输出不同的操作方案数 $\%(10^{9} + 7)$.

```input1
12 1 5 10
3 5 6 7 8 9 5 1 1 1 1 5
```

```output1
3
```

```input2
3 2 1 2
6 2 2
```

```output2
0
```

```input3
3 2 1 2
3 1 2
```

```output3
6
```

# 提示
**【样例 #3 解释】**
- 最后组成的数可以是 $31, 33, 11, 13, 21, 23$

<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

</details>

# 数据规模与限制
* $2 \le n \le 50000$
* $1 \le b \le 10^9$
* $0 \le k < x \le 100, x \ge 2$

# 来源
* [codeforces_341_div2_E: Wet Shark and Blocks](https://codeforces.com/contest/621/problem/E)