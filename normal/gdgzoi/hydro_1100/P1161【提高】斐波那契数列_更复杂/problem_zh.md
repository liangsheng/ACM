# 题目描述

给你一个更复杂的斐波那契数列：

$$F_n = \left\{\begin{aligned} 1 \space (n \le 2) \\ 2F_{n-2}+3F_{n-1} + 4n \space (n\ge 3) \end{aligned}\right.$$


请你求出 $F_n \bmod 1000000007$ 的值。

# 输入格式

一行一个正整数 $n$

# 输出格式

输出一行一个整数表示答案。

```input1
3
```

```output1
17
```


# 提示
**【样例 #1 解释】**
* $f(3) = 2f(1) + 3f(2) + 4 * 3 = 2 + 3 + 12 = 17$

<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

</details>

# 数据规模与限制
* $1\le n \le 2^{63}$

# 来源
* [luogu_P1962: 斐波那契数列](https://www.luogu.com.cn/problem/P1962)