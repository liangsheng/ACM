# 题目描述

设 $f_{n} = c^{2n-6} \cdot f_{n-1} \cdot f_{n-2} \cdot f_{n-3}$ for $n \ge 4$.

输入 $n$, $f_{1}$, $f_{2}$, $f_{3}$, and $c$. 求 $f_{n} \bmod (10^{9}+7)$.

# 输入格式

一行 $5$ 个正整数  $n$, $f_{1}$, $f_{2}$, $f_{3}$, and $c$ ($4 \le n \le 10^{18}$, $1 \le f_{1}$, $f_{2}$, $f_{3}$, $c \le 10^{9}$)

# 输出格式

输出 $f_{n} \bmod (10^{9} + 7)$.

```input1
5 1 2 5 3
```

```output1
72900
```

```input2
17 97 41 37 11
```

```output2
317451037
```

# 提示
**【样例 #1 解释】**
- $f_4=90, f_5=92900$

<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

</details>

# 数据规模与限制
* $1 \le N \le 10^{18}$
* $1 \le f_{1}$, $f_{2}$, $f_{3}$, $c \le 10^{9}$

# 来源
* [codeforces_566_div2_E: Product Oriented Recurrence](https://codeforces.com/contest/1182/problem/E)