# 题目描述

给一个 $n(1 \leq n \leq 10^5)$ 个点 $m(1 \leq m\leq 2 \cdot 10^5 )$ 条边的 **<font color="#FF0000">有向图，边权都有正有负</font>**，求 $s$ 到 $t$ 的最短路，保证 $s$ 到 $t$ 之间至少存在一条路。

# 输入格式

第一行四个由空格隔开的整数 $n, m, s, t$。  
之后的 $m$ 行，每行三个正整数 $u_i, v_i, w_i(-10^4 \leq w_i \leq 10^4)$，表示一条从 $u_i$ 到 $v_i$ 长度为 $w_i$ 的边。

# 输出格式

* 如果 $s$ 到 $t$ 的路径可以无穷小，输出 `-INF`
* 否则输出 $s$ 到 $t$ 的最短路径

```input1
5 5 1 5
1 2 1
2 3 2
3 4 3
4 2 -6
3 5 1
```

```output1
-INF
```

```input2
7 9 5 4
1 4 3
3 4 3
5 7 4
7 3 1
6 1 1
3 6 -6
2 4 3
5 6 3
7 2 1
```

```output2
3
```

# 提示
**【样例 #1 解释】**
* 推荐一个在线画图工具, [graph_editor](https://csacademy.com/app/graph_editor/)

![img](file://带负权.png)

* $n(1 \leq n \leq 10^5)$，且有边权有负数，需要 $spfa+heap$ 算法
* 思考：**<font color="#FF0000">为什么 dijkstra 算法不能处理有负边权的图？</font>**


<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

</details>

# 数据规模与限制
* $2 \leq n \leq 10^5$
* $1 \leq m \leq 2 \cdot 10^5$
* $-10^4 \leq w_i \leq 10^4$
* **<font color="#FF0000">提交语言请选择 C++17(O2), 执行速度会快很多</font>**

# 来源
* [acwing: 851.spfa求最短路](https://www.acwing.com/problem/content/853/)
* [acwing: 852.spfa判断负环](https://www.acwing.com/problem/content/854/)