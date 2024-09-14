# 题目描述
给你一个只由 $0$ 和 $1$ 组成的二维矩阵 $g$，请你求出只包含 $1$ 的最大正方形的面积

# 输入格式
第 $1$ 行包含 $n$ 个整数 $n, m(1 \le n, m \le 300)$;

接下来 $n$ 行，每行包含一个长度为 $m$ 只包含 $0$ 和 $1$ 的字符串;

# 输出格式

输出一个整数，表示最大子正方形的面积

```input1
4 5
10100
10111
11111
10010
```

```output1
4
```

# 提示
**【样例 #1 解释】**

![img](ex1.png)

<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

* 本题的 $n$ 不超过 $200$，所以 $O(n^3)$ 的算法可以通过
* $dp[i][j]$ 表示高为 $i$ 宽为 $j$ 的矩形木块能卖多少钱
  * 若水平切一刀，则分割成 $dp[k][j]$ 和 $dp[i-k][j]$
  * 若垂直切一刀，则分割成 $dp[i][k]$ 和 $dp[i][j-k]$

</details>

# 数据规模与限制
* $1 \leq n, m \leq 300$

# 来源
* [leetcode_221_最大正方形](https://leetcode.cn/problems/maximal-square/description/)