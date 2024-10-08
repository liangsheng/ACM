# 题目描述

#### 问题陈述

FJ有块农田太崎岖了，他要买一辆新拖拉机才能在这里巡视。这块农田由 $N \times N$ 个格子的非负整数表示高度 $(1 \leq N \leq 500)$。拖拉机从当前格子走到相邻格子（东、南、西、北四个方向）的代价为高度差 $D$，则FJ驶过这两个格子的拖拉机最少也要值 $D$ 块钱。

FJ愿意花足够的钱买一辆新的拖拉机使得他能以最小的高度差走遍所有格子的一半(如果格子总数是奇数，那么一半的值为四舍五入的值)。因为FJ很懒，所以他找到你帮他编程计算他最小需要花多少钱买到符合这些要求的拖拉机。

**<font color="#FF0000">请注意：不是求代价之和，是求拖拉机的最低代价，假设拖拉机的价格是 $D$，那么所以高度差不超过 $D$ 的格子都可行驶 </font>**

# 输入格式
第 1行为 1 个整数 ￥N￥

第 $2$ 到 $N+1$ 行每行包含 $N$ 个非负整数 $h_i(1 \leq h_i \leq 10^6)$，表示当前格子的高度。


# 输出格式

共一行，表示FJ买拖拉机要花的最小价钱。

```input1
5 
0 0 0 3 3 
0 0 0 0 3 
0 9 9 3 3 
9 9 9 3 3 
9 9 9 9 3
```

```output1
3
```

# 提示 
**【样例 #1 解释】**
* 拖拉机的价格是 $3$，那么所有高度是 $0$ 和 $3$ 的格子都能通行

<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

</details>

# 数据规模与限制
* $1 \leq N \leq 500$
* $1 \leq h_i \leq 10^6$

# 来源
* [usaco_2013FEB_sliver: Tractor](https://www.luogu.com.cn/problem/P3073)