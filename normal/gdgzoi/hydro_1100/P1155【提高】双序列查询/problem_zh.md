# 题目描述

给你长度为 $N$ 、 $A=(A_1,A_2,\ldots,A_N)$ 和 $B=(B_1,B_2,\ldots,B_N)$ 的序列。  
您还得到了 $Q$ 个查询，需要按顺序处理。

查询有三种类型：
-   `1 l r x` : 在 $A_l, A_{l+1}, \ldots, A_r$ 中添加 $x$ 。
-   `2 l r x` : 在 $B_l, B_{l+1}, \ldots, B_r$ 中添加 $x$ 。
-   `3 l r` : 打印 $\displaystyle\sum_{i=l}^r (A_i\times B_i)$ 除以 $998244353$ 的余数。

# 输入格式

第一行包含 $2$ 个正整数 $N,Q$，表示数列长度和询问个数。保证 $1\le N,Q\le 2\times10^5$。  
第二行 $N$ 个整数 $A_1, A_2, \dots, A_N$，表示数列 $A$。保证 $0 \le A_i\le 10^9$。  
第三行 $N$ 个整数 $B_1, B_2, \dots, B_N$，表示数列 $B$。保证 $0 \le B_i\le 10^9$。  
接下来 $Q$ 行，每行一个操作，为以下三种之一：

-   `1 l r x` : 在 $A_l, A_{l+1}, \ldots, A_r$ 中添加 $x$ 。
-   `2 l r x` : 在 $B_l, B_{l+1}, \ldots, B_r$ 中添加 $x$ 。
-   `3 l r` : 打印 $\displaystyle\sum_{i=l}^r (A_i\times B_i)$ 除以 $998244353$ 的余数。

# 输出格式

对于每个 `2 l r` 操作输出一行表示答案，如果没有第二大的数（比如：$A[l..r]$ 全相等），就输出 $0$

```input1
5 6
1 3 5 6 8
3 1 2 1 2
3 1 3
1 2 5 3
3 1 3
1 1 3 1
2 5 5 2
3 1 5
```

```output1
16
25
84
```

```input2
2 3
1000000000 1000000000
1000000000 1000000000
3 1 1
1 2 2 1000000000
3 1 2
```

```output2
716070898
151723988
```

# 提示
**【样例 #1 解释】**

<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

</details>

# 数据规模与限制
* $1\le N,Q\le 2\times10^5$
* $0 \le A_i, B_i \le 10^9$
* $1\le l\le r\le n$

# 来源
* [abc_357_F: Two Sequence Queries](https://atcoder.jp/contests/abc357/tasks/abc357_f)