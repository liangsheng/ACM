# 题目描述

给定一个 $n$ 个点 $m$ 条边的 **<font color="#FF0000">有向图，图中可能存在重边和自环，边权可能为负数</font>**。

再给定 $k$ 个询问，每个询问包含两个整数 $x$ 和 $y$，表示查询从点 $x$ 到点 $y$ 的最短距离，如果路径不存在，则输出 `impossible`。

# 输入格式

第一行包含三个整数 $n,m,k$。

接下来 $m$ 行，每行包含三个整数 $x,y,z$，表示存在一条从点 $x$ 到点 $y$ 的有向边，边长为 $z$。

接下来 $k$ 行，每行包含两个整数 $x,y$，表示询问点 $x$ 到点 $y$ 的最短距离。

# 输出格式

共 $k$ 行，每行输出一个整数，表示询问的结果，若询问两点间不存在路径，则输出 `impossible`。

```input1
3 3 2
1 2 1
2 3 2
1 3 1
2 1
1 3
```

```output1
impossible
1
```

# 提示
**【样例 #1 解释】**
* 推荐一个在线画图工具, [graph_editor](https://csacademy.com/app/graph_editor/)

* $d[k][u][v]$ 表示在只经过前 $k$ 个点的前提下, 从 $u$ 到 $v$ 的最短距离
* 接下来的转移类似背包问题
$$
\begin{equation}
d(k,u,v) = \left\{
\begin{array}{lr}
d(k-1,u,v), & 不经过第k个点  \\
d(k-1,u,k)+d(k-1,k,v), & 经过第k个点
\end{array}
\right.
\end{equation}
$$

```c++
for (int k = 1; k <= n; k++) {
    for (int u = 1; u <= n; u++) for (int v = 1; v <= n; v++) {
        if (i == k || i == j || k == j) continue;
        d[k][u][v] = min(d[k - 1][u][v], d[k - 1][u][k] + d[k - 1][k][v]);
    }
}
```

* 可以将第 1 维简化掉
```c++
/*-------------------- floyd 求任意 2 点之间最短路 O(n^3) begin ---------*/
#define FOR(i, n, m) for (int i = n; i <= m; i++)

void floyd() {
    FOR (k, 1, n) FOR (u, 1, n) FOR (v, 1, n) {
        if (u != k && k != v && u != v) d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
    } 
}

/*-------------------- floyd 求任意 2 点之间最短路 O(n^3) end -----------*/
```
* 上述算法称为 $floyd$ 算法，可以用来求任意 2 点之间的最短路
* 该算法可以处理有负边和负环的图
* 如果否存在 $d[i][i] < 0$，则图中有负环

<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

</details>

# 数据规模与限制
* $2 \leq n \leq 200$
* $1 \leq m \leq 20000$
* $1 \leq k \leq n^2$
* $-10^4 \leq w_i \leq 10^4$
* **<font color="#FF0000">提交语言请选择 C++17(O2), 执行速度会快很多</font>**

# 来源
* [854.Floyd求最短路](https://www.acwing.com/problem/content/description/856/)