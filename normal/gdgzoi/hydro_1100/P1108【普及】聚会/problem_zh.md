# 题目描述

约翰的农场有 $n$ 个谷仓，编号 $1 \sim n$，谷仓之间有 $m$ 条**双向**道路。

所有道路的长度均为 $1$。

奶牛们可以通过这些道路从任意谷仓到达任意其它谷仓。

任意两个谷仓之间最多只包含一条**道路**（注意是道路，不是路径）。

不存在道路两端都连接同一个谷仓的情况。

农场中一共有 $k$ 种干草，编号 $1 \sim k$。

每个谷仓都存有一种干草，其中第 $i$ 个谷仓存有第 $a_i$ 种干草。

每种干草都至少存在于一个谷仓中。

奶牛们计划选择一个谷仓举办干草宴会。

为了让宴会足够丰盛，至少需要将 $s$ 种不同的干草汇集在宴会谷仓。

宴会谷仓本身就包含一种干草，而其它干草就需要从其它谷仓运输。

已知，将一种干草从一个谷仓运至另一个谷仓所需的运输成本等于两谷仓之间的最短路径距离。

请你帮助奶牛们计算，对于每个谷仓，如果挑选其为宴会举办地，则举办宴会需要付出的总运输成本的最小可能值是多少。

# 输入格式

第一行包含四个整数 $n,m,k,s$。

第二行包含 $n$ 个整数 $a_1,a_2,…,a_n$。

接下来 $m$ 行，每行包含两个整数 $u,v$，表示第 $u$ 个谷仓和第 $v$ 个谷仓之间存在一条双向道路。

# 输出格式

共一行，输出 $n$ 个整数，其中第 $i$ 个整数表示在第 $i$ 个谷仓举办宴会需要付出的总运输成本的最小可能值。

```input1
5 5 4 3
1 2 4 3 2
1 2
2 3
3 4
4 1
4 5
```

```output1
2 2 2 2 3
```

```input2
7 6 3 2
1 2 3 3 2 2 1
1 2
2 3
3 4
2 5
5 6
6 7
```

```output2
1 1 1 2 2 1 1
```

# 提示
**【样例 #1 解释】**

<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

</details>

# 数据规模与限制
* $1 \le n \le 10^5$，$0 \le m \le 10^5$
* $1 \le s \le k \le \min(n,100)$，$1 \le a_i \le k$
* $1 \le u,v \le n$，$u \neq v$

# 来源
* [acwing_5475. 聚会](https://www.acwing.com/problem/content/5478/)