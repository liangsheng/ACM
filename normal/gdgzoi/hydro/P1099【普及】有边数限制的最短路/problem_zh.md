# 题目描述

给定一个 $n$ 个点 $m$ 条边的 **<font color="#FF0000">有向图</font>**，图中可能存在重边和自环， **<font color="#FF0000">边权可能为负数</font>**。

请你求出从 $1$ 号点到 $n$ 号点的 **<font color="#FF0000">最多经过 $k$ 条边</font>** 的最短距离，如果无法从 $1$ 号点走到 $n$ 号点，输出 `impossible`。

注意：图中可能 **<font color="#FF0000">存在负权回路</font>** 。

# 输入格式

第一行包含三个整数 $n,m,k$。

接下来 $m$ 行，每行包含三个整数 $x,y,z$，表示存在一条从点 $x$ 到点 $y$ 的有向边，边长为 $z$。

点的编号为 $1 \sim n$。

# 输出格式

输出一个整数，表示从 $1$ 号点到 $n$ 号点的最多经过 $k$ 条边的最短距离。

如果不存在满足条件的路径，则输出 `impossible`。

```input1
3 3 1
1 2 1
2 3 1
1 3 3
```

```output1
3
```

```input2
4 4 2
1 2 1
2 3 1
1 3 3
3 4 1
```

```output2
4
```

```input3
4 3 2
1 2 1
2 3 1
3 4 1
```

```output3
impossible
```

# 提示
**【样例 #1 解释】**
* 推荐一个在线画图工具, [graph_editor](https://csacademy.com/app/graph_editor/)

![img](file://样例.png)

* 样例一：$1 \rightarrow 3$
* 样例二：$1 \rightarrow 3 \rightarrow 4$

* 参考 [P1098.【普及】带负权单源最短路](http://gzezoi.cn/d/gzezoi2023/p/P1098) 中
* 用 $c[i]$ 表示起点到 $i$ 的最短路经过的点的个数

```c++
for (int i = head[u]; i != -1; i = nxt[i]) {
    int v = pnt[i], tmp = d[u] + wv[i];
    if (tmp < d[v]) {
        cnt[v] = cnt[u] + 1, d[v] = tmp;
        if (cnt[v] < k) q.push({-d[v], v});  // 只有 cnt[v] < k 时, 才放到堆里
    }
}
```

* 结合样例二，思考下 “只有 $cnt[v] < k$ 时, 才放到堆里” 这个策略是否正确？


<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

* $d[v][c]$ 表示从起点到 $v$ 恰好经过 $c$ 条边的最短路，那么有
$$
d[v][c] = min\{d[u][c - 1] + w(u, v)\ | u 到 v 有一条边 \};
$$

```c++
int d[N][N];  // d[i][j] 表示从起点 s 到 i, 刚好经过 j 条边的最短距离

void spfa(int s) {
    for (int i = 1; i <= n; i++) for (int j = 0; j <= k; j++) d[i][j] = INF;
    d[s][0] = 0;
    for (int t = 1; t <= k; t++) {
        for (int u = 1; u <= n; u++) if (d[u][t - 1] != INF) {
            repe (i, u) {
                int v = pnt[i], tmp = d[u][t - 1] + wv[i];
                if (tmp < d[v][t]) d[v][t] = tmp;
            }
        }
    }
}
```

</details>

# 数据规模与限制
* $2 \leq n, k \leq 500$
* $1 \leq m \leq 10^4$
* $-10^4 \leq w_i \leq 10^4$
* **<font color="#FF0000">提交语言请选择 C++17(O2), 执行速度会快很多</font>**

# 来源
* [853.有边数限制的最短路](https://www.acwing.com/problem/content/855/)