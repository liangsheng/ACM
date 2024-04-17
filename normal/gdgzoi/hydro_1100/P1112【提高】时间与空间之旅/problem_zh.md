# 题目描述

给你一个 $n$ 个节点, $m$ 条边的 **<font color="#FF0000">边权可能为负的有向图（可能有自环和重边）</font>**；

你想从 $1$ 号点去往 $n$ 号点，路径的权值为路径上所有边的权值和；

你现在可以将图中所有边的权值都 **<font color="#FF0000">加上或者减去相同的数</font>**，我们希望这样操作后，$1$ 到 $n$ 的最短路是大于等于 0 的，请你求出这个大于等于 0 的最短路（如果 $1$ 到 $n$ 不可达输出 $-1$）；


# 输入格式

第一行包含个由空格隔开的整数 $n, m(2 \leq n \leq 100, 1 \leq m \leq 10^4)$。  
之后的 $m$ 行，每行三个正整数 $u_i, v_i, w_i(-10^5 \leq w_i \leq 10^5)$，表示一条从 $u_i$ 到 $v_i$ 长度为 $w_i$ 的边。


# 输出格式

输出一行一个整数，为大于等于 0 的最短路（如果 $1$ 到 $n$ 不可达输出 $-1$）

```input1
4 5
1 2 1
1 3 1
2 3 -3
3 1 1
3 4 1
```

```output1
2
```

# 提示
**【样例 #1 解释】**
* 如果不修改图中的边, $1$ 到 $n$ 的最短路是负无穷（有负环 $1\rightarrow 2\rightarrow 3 \rightarrow 1$）
* 可以将所有的边权 +1，那么 $1$ 到 $n$ 的最短路是 $1\rightarrow 2\rightarrow 3 \rightarrow 4$，路径长为 $2 - 2 + 2 = 2$
* 本题非常考验对路径上负环的理解

<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

</details>

# 数据规模与限制
* $2 \leq n \leq 100, 1 \leq m \leq 10^4$
* $-10^5 \leq w_i \leq 10^5$

# 来源
* [小视野_课程二_42_最短路_H: 时间与空间之旅](http://gdgzoi.com/problem.php?cid=2179&pid=7)
* [题解](https://haizs.com/post/fzoj1568/)
* [原题](http://218.5.5.242:9018/JudgeOnline/problem.php?id=1568)