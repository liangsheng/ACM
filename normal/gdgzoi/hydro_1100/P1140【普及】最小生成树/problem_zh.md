# 题目描述
**<font color="#FF0000"> 请分别用 prim 和 kruskal 通过此题 </font>**

如题，给出一个无向图，求出最小生成树，如果该图不连通，则输出 `orz`。

# 输入格式
第一行包含两个整数 $N,M$，表示该图共有 $N$ 个结点和 $M$ 条无向边。

接下来 $M$ 行每行包含三个整数 $X_i,Y_i,Z_i$，表示有一条长度为 $Z_i$ 的无向边连接结点 $X_i,Y_i$。


# 输出格式
如果该图连通，则输出一个整数表示最小生成树的各边的长度之和。如果该图不连通则输出 `orz`。


```input1
4 5
1 2 2
1 3 2
1 4 3
2 3 4
3 4 3
```

```output1
7
```

# 提示 
**【样例 #1 解释】**


<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

</details>

# 数据规模与限制
* $1 \leq N \leq 5000$
* $1 \leq M \leq 2 \times 10^5$
* $1 \leq Z_i \leq 10^4$

# 来源
* [P3366 【模板】最小生成树](https://www.luogu.com.cn/problem/P3366)