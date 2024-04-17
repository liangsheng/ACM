# 题目描述

定义阶乘运算 
$$n!=1\times2\times3\times\cdots\times n$$

比如 $5!=1\times2\times3\times4\times5=120$

给定正整数 $n$，定义 $f(n)$ 为
$$f(n) = \sum_{i=1}^{i=n}(-1)^{i-1}i!=1!-2!+3!-4!+\cdots+(-1)^{n-1}\cdot n!$$

比如 $f(5)=1!-2!+3!-4!+5!=1-2+6-24+120=101$

给定两个正整数 $n, m$，请你计算 $\frac{f(n) ^ 2}{m}$ 的整数部分

比如 $n = 5, m = 11$ 时, $\frac{f(n) ^ 2}{m}=\frac{101^2}{11}=\frac{10201}{11}=927$

# 输入格式

共 1 行，用空格分割的 2 个正整数 $n, m(1 \leq n \leq 100, 1 \leq m \leq 1000)$

# 输出格式

输出一行为题目所求。

```input1
5 11
```

```output1
927
```

# 提示

# 数据规模与限制
* $1 \leq n \leq 100$
* $1 \leq m \leq 1000$

# 来源

<!-- * [acwing: 794.高精度除法](https://www.acwing.com/problem/content/796//) -->