# [acwing 1051] 最大2段和

对于给定的整数序列 $A=\lbrace a_1,a_2,…,a_n \rbrace$，找出两个不重合连续子段，使得两子段中所有数字的和最大。

# 输入格式

输入的第一行包含一个正整数 $n$，表示 $a$ 的长度。

输入的第二行包含 $n$ 个整数表示 $a_i$

# 输出格式

输出一行包含一个整数，表示题目询问的答案。

```input1
10
1 -1 2 2 3 -3 4 -4 5 -5
```

```output1
13
```

# 提示

**【样例 1 解释】**
- 可以选取 $[2, 2, 3, -3, 4], [5]$ 2 个子段
- 和是 $8 + 5 = 13$

**【数据范围】**
- $2 \leq n \leq 20000$
- $|a_i| \leq 20000$

<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

</details>

# 来源
* [acwing 1051: 最大的和](https://www.acwing.com/problem/content/description/1053/)