# 题目描述

下面的图形是著名的杨辉三角形:

![img](file://杨辉三角.jpg)

它有如下几个特征：
* 1、第 $i$ 行（从 $0$ 开始编号）有 $i + 1$ 个数，我们用 $a[i][0], a[i][1], ... a[i][i]$ 表示第 $i$ 行的 $i + 1$ 个数
* 2、
$$
\begin{equation}
a(i,j) = \left\{
\begin{array}{lr}
1, & j = \{0, i\} \\
a[i-1][j]+a[i-1][j-1], & 2 \leq j \leq i - 1
\end{array}
\right.
\end{equation}
$$

输入 $i, j$，请输出 $a[i][j]$

# 输入格式

共 1 行，包含 2 个整数 $i, j(1 \leq i \leq 300, 1 \leq j \leq i)$

# 输出格式

输出 1 行，表示 $a[i][j]$

```input1
1 1
```

```output1
1
```

```input2
5 2
```

```output2
10
```

```input3
100 50
```

```output3
100891344545564193334812497256
```

# 提示
* 答案最大可能有 100 位

# 数据规模与限制
* $1 \leq i \leq 300, 1 \leq j \leq i$

# 来源

<!-- * [luogu: P5732【深基5.习7】杨辉三角](https://www.luogu.com.cn/problem/P5732) -->