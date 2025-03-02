# [入门] 酒店

有 $n(3 \leq n \leq 10^3)$ 个客人来到一个有 $m(n \leq m)$ 个房间的酒店，房间的编号是 $0, 1, \cdots m-1$，这 $m$ 个房间是环形排列的（也就是说 $0$ 和 $m-1$ 是相邻的）；

现在要给 $n$ 个客人每人分配一个房间，这 $n$ 个客人比较挑剔，他们都希望与自己房间相邻的房间没有人。对于某一位客人，若与他的房间相邻的房间中，有 $k$ 间房间有人，则这个客人会产生 $k$ 点愤怒。

请你安排房间，让所有人的愤怒值最小，输出这个最小值。

# 输入格式
**<font color="#FF0000">从文件 $hotel.in$ 中读入数据。</font>**

输入的第一行包含 $2$ 个正整数 $n, m$，表示客人数和房间数。


# 输出格式
**<font color="#FF0000">输出到文件 $hotel.out$ 中。</font>**

输出这个最小愤怒值

```input1
3 5
```

```output1
2
```

```input2
4 8
```

```output2
0
```

# 提示

**【样例 1 解释】**
- 可以在 $0, 2, 4$ 号房间安排客人
- 这样住在 $0, 4$ 的客人由于相邻，各有 $1$ 愤怒值
- 总共就有 2 愤怒值

**【样例 2 解释】**
- 可以在 $0, 2, 4, 6$ 号房间安排客人，这样所有人都不相邻

**【数据范围】**
- 对于 $100\%$ 的数据，$3 \leq n \leq 10^3, n \leq m \leq 10^3$

|测试点编号|特殊性质|
|:---:|:---:|
|$1$|保证 $n=m$|
|$2$|保证 $2n < m$|
|$3\sim10$|无|

<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

</details>

# 来源
* [P9585 「MXOI Round 2」酒店](https://www.luogu.com.cn/problem/P9585)