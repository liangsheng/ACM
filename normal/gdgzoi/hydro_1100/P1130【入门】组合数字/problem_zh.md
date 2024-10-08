# 题目描述

排列与组合是常用的数学方法，其中组合就是从 $n$ 个元素中抽出 $r$ 个元素(不分顺序且 $r \le n$)，我们可以简单地将 $n$ 个元素理解为自然数$1, 2, \dots n$ 从中任取 $r$ 个数。

现要求你用递归的方法输出所有组合。

# 输入格式
第 $1$ 行包含 $2$ 个整数 $n, r$

# 输出格式

按字典序输出所有组合方案，每个方案占一行，每个组合方案也按字典序排列

```input1
5 3
```

```output1
1 2 3   
1 2 4   
1 2 5   
1 3 4   
1 3 5   
1 4 5   
2 3 4   
2 3 5   
2 4 5   
3 4 5
```

# 提示
**【样例 #1 解释】**

<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

</details>

# 数据规模与限制
* $1 \leq n \leq 10$
* $1 \leq r \leq n$

# 来源
* [luogu_P1157: 组合的输出](https://www.luogu.com.cn/problem/P1157)