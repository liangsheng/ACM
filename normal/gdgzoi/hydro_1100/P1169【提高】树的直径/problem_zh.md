# [SPOJ_1437] 求树的直径

给你一颗 $n$ 个节点，$n-1$ 条边的树，边的权值都是 $1$，求树的直径

**<font color="#FF0000">树的直径</font>**： 树上距离最远的 $2$ 个点的距离

# 输入格式

输入的第一行包含整数 $n$

接下来 $n - 1$ 行，每行包含 $2$ 个整数 $u, v$，表示 $u, v$ 之间有一条边

# 输出格式

输出树的直径

```input1
5
1 2
2 3
1 4
4 5
```

```output1
4
```

```input2
9
1 2
1 3
2 4
4 5
5 6
2 7
7 8
8 9
```

```output2
6
```

## 提示
- [画图工具](https://csacademy.com/app/graph_editor/)
- [功能更多的画图工具](https://anacc22.github.io/another_graph_editor/)
- [直接画的画图工具](https://silverfoxxxy.github.io/miska924/DrawGraphJS/)

**【样例解释 #1】**
- $5 \rightarrow 4 \rightarrow 1 \rightarrow 2 \rightarrow 3$
- $6 \rightarrow 5 \rightarrow 4 \rightarrow 2 \rightarrow 7 \rightarrow 8 \rightarrow 9$

**【数据范围】**
- $1 \leq n \leq 10^5$

<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

</details>

# 来源
* [spoj_1437](https://www.luogu.com.cn/problem/SP1437)