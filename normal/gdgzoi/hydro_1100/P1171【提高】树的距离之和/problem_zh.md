# [SPOJ_1437] 求树的直径

给你一颗 $n$ 个节点，$n-1$ 条边的树，边的权值都是 $1$，

返回长度为 $n$ 的数组 $answer$ ，其中 $answer[i]$ 是树中第 $i$ 个节点与所有其他节点之间的距离之和。

# 输入格式

输入的第一行包含整数 $n$

接下来 $n - 1$ 行，每行包含 $2$ 个整数 $u, v$，表示 $u, v$ 之间有一条边

# 输出格式

输出 $n$ 个数，第 $i$ 个数代表所有点到点 $i$ 的距离之和

```input1
6
1 2
1 3
3 4
3 5
3 6
```

```output1
8 12 6 10 10 10
```

```input2
2
1 2
```

```output2
1 1
```

## 提示
- [画图工具](https://csacademy.com/app/graph_editor/)
- [功能更多的画图工具](https://anacc22.github.io/another_graph_editor/)
- [直接画的画图工具](https://silverfoxxxy.github.io/miska924/DrawGraphJS/)

**【样例解释 #1】**
- $dis(1, 2) = 1$
- $dis(1, 3) = 1$
- $dis(1, 4) = 2$
- $dis(1, 5) = 2$
- $dis(1, 6) = 2$
- 所以，所有点到点 $1$ 的距离之和为 $8$

**【数据范围】**
- $1 \leq n \leq 10^5$

<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

</details>

# 来源
* [leetcode_834: 树中距离之和](https://leetcode.cn/problems/sum-of-distances-in-tree/)