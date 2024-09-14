# 题目描述

给你一棵 $n$ 个节点, $n-1$ 条边的树，连接点 $i$ 和点 $i$ 的 `边` 的权值是 $c(i,j)$；

定义 $s(u,v)$ 表示从点 $u$ 到点 $v$ 的 `路径` 上所有边的权值的最小值；

请你在这棵树中选取一个点 $u$，使得点 $u$ 到其他任意节点 $v$ 的 $s(u,v)$ 之和最大，输出这个最大值。

既求点 $u$，使得下面的式子最大
$$
\sum_{v|v \neq u}s(u,v)
$$

# 输入格式
第一行是 1 个整数 $n$。

接下来 $n-1$ 行，每一行包含 $3$ 个正整数 $x_i, y_i, w_i$，表示点 $x_i$ 和点 $y_i$ 之间有一条权值为 $w_i$ 的边

# 输出格式
只有一个整数，输出答案

```input1
4
1 2 2
2 4 1
2 3 1
```

```output1
4
```

# 提示 
**【样例 #1 解释】**
* 选取 $u=2$
* 那么，$s(2,1)+s(2,3)+s(2,4)=2+1+1=4$
* 如果选取 $u=3$
* 那么，$s(3,1)+s(3,2)+s(3,4)=1+1+1=3$

<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

</details>

# 数据规模与限制
* $1 \leq n \leq 2 \times 10^5$
* $1 \leq w_ \leq 10^5$

# 来源
* [2012_ACM/ICPC_changchun_onsite_E](https://pintia.cn/problem-sets/91827364500/exam/problems/type/7?problemSetProblemId=91827369381&page=26)