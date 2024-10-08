# 题目描述

给定一个无向图，请编写一个程序实现以下两种操作：
+   `D x y`：从原图中删除连接 $x$ 和 $y$ 顶点的边；
+   `Q x y`：询问 $x$ 和 $y$ 顶点是否连通

# 输入格式
第一行两个数 $n，m(5 \leq n,m \leq 5 \times 10^5)$，分别表示顶点和边数。

接下来 $m$ 行，每行 2 个整数 $x$ 和 $y$，表示 $x$ 和 $y$ 之间有边相连，保证没有重复的边。

接下来一行 1 个整数 $q( q \leq 5 \times 10^5)$。

以下 $q$ 行，每行一个操作，保证不会有非法删除。

# 输出格式
按询问次序输出所有 $Q$ 操作的回答，连通的回答 "C"，不连通的回答 "D"。

```input1
3 3
1 2
1 3
2 3
5
Q 1 2
D 1 2
Q 1 2
D 3 2
Q 1 2
```

```output1
C
C
D
```

# 提示 
**【样例 #1 解释】**
* 换一个角度思考问题，比如倒过来

<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

</details>

# 数据规模与限制
* $1 \leq n, m, q \leq 5 \times 10^5$

# 来源
* [小视野_课程二_45并查集_C: 连通](http://gdgzoi.com/problem.php?cid=1033&pid=2)