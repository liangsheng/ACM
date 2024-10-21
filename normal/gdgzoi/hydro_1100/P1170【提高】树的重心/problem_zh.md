# [SPOJ_1437] 求树的直径

给你一颗 $n$ 个节点，$n-1$ 条边的树，边的权值都是 $1$，我们定义：

**<font color="#FF0000">树的重心</font>**： 如果在树中选择某个节点并删除，这棵树将分为若干棵子树，统计子树节点数并记录最大值。取遍树上所有节点，使此最大值取到最小的节点被称为整个树的重心

求树的重心的个数，以及以重心为根节点时，最大的子树所包含的节点数目

# 输入格式

输入的第一行包含整数 $n$

接下来 $n - 1$ 行，每行包含 $2$ 个整数 $u, v$，表示 $u, v$ 之间有一条边

# 输出格式

输出树的重心的个数，以及以重心为根节点时，最大的子树所包含的节点数目

```input1
5
1 2
2 3
1 4
4 5
```

```output1
1 2
```

## 提示
- [画图工具](https://csacademy.com/app/graph_editor/)
- [功能更多的画图工具](https://anacc22.github.io/another_graph_editor/)
- [直接画的画图工具](https://silverfoxxxy.github.io/miska924/DrawGraphJS/)

**【样例解释 #1】**
- 以 $1$ 为根节点，可以得到 $\{2, 3\}, \{4, 5\}$ 2 个子树，其中最大的子树的节点个数树 2
- 可以证明只有 $1$ 这 1 个重心，所以输出 $1 \quad 2$

**【数据范围】**
- $1 \leq n \leq 10^5$

<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

</details>

# 来源
* [poj_1655](http://poj.org/problem?id=1655)
* [acwing_848](https://www.acwing.com/problem/content/description/848/)