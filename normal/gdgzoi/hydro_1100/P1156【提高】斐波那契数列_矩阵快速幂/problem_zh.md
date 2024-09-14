# 题目描述

大家都知道，斐波那契数列是满足如下性质的一个数列：

$$F_n = \left\{\begin{aligned} 1 \space (n \le 2) \\ F_{n-1}+F_{n-2} \space (n\ge 3) \end{aligned}\right.$$


请你求出 $F_n \bmod 1000000007$ 的值。

# 输入格式

一行一个正整数 $n$

# 输出格式

输出一行一个整数表示答案。

```input1
5
```

```output1
5
```

```input2
10
```

```output2
55
```

```input3
123456789
```

```output3
62791945
```

# 提示
**【样例 #1 解释】**

<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

</details>

# 数据规模与限制
* $1\le n \le 2^{63}$

# 来源
* [luogu_P1962: 斐波那契数列](https://www.luogu.com.cn/problem/P1962)