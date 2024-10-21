# [提高] 异或序列

有一个长度为 $n$ 的序列 $a$ ，序列中的每个值在 $[0, 1024]$ 之间。

请你求出这个序列有多少对连续子序列 $(A, B)$ ，满足 $A$ 在 $B$ 之前，且 $A, B$ 中所有元素的异或和为 $m$。

形式化的，你需要求出有多少个四元组 $(l_1, r_1, l_2, r_2)$ ，满足 $l_1 \leq r1 < l_2 \leq r2$，且
$$
(\bigoplus^{r_1}_{i=l_1}a_i)\bigoplus(\bigoplus^{r_2}_{i=l_2}a_i)=m
$$
$\bigoplus$ 表示异或，即：

- $0\oplus0=0$
- $0\oplus1=1$
- $1\oplus0=1$
- $1\oplus1=0$
# 输入格式

从文件 $sequence.in$ 中读入数据。

第一行两个整数 $n, m$ ，表示数组长度，异或和。

第二行 $n$ 个整数，表示数组 $a$ 。

# 输出格式

输出到文件 $sequence.out$ 中。

一行一个整数，表示答案。

保证答案不超过 long long 表示范围。

```input1
4 2
0 1 2 3
```

```output1
3
```

```input2
6 2
0 1 2 3 4 5
```

```output2
8
```

# 提示

**【样例 1 解释】**
- 以下是 $3$ 种方案
- $A = \lbrace0\rbrace, B = \lbrace2\rbrace, 0\oplus2=2$
- $A = \lbrace1\rbrace, B = \lbrace3\rbrace, 1\oplus3=2$
- $A = \lbrace0, 1\rbrace, B = \lbrace3\rbrace, 0\oplus1\oplus3=2$

**【数据范围】**
- 对于 $100\%$ 的数据，$3 \leq n \leq 10^5, 0 \leq a_i \leq 1024, 0 \leq m \leq 1024$

|测试点编号|特殊性质|
|:---:|:---:|
|$1\sim2$|保证 $n \leq 20$|
|$3\sim4$|保证 $n \leq 50$|
|$5\sim6$|保证 $n \leq 200$|
|$7\sim8$|保证 $n \leq 5000$|
|$9\sim10$|无|

<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

</details>

# 来源
* [洛谷秋季普及组复赛国庆训练营_20241004_模拟赛_sequence](https://www.luogu.com.cn/team/88028#problem)