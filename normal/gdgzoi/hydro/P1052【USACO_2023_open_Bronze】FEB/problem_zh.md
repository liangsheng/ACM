# [USACO_2023_open_Bronze] FEB

Bessie 和 Elsie 正在密谋推翻农场主 John！他们的对话可以用长度为 $N$ 的字符串 $S$ 来表示，其中 $S_i$ 要么是 $B$ 要么是 $E$，分别表示第 $i$ 条信息是由 Bessie 或 Elsie 发送的。

然而，农夫约翰听到了这个计划，并试图拦截他们的对话。因此，$S$ 中的一些字母是$F$，这意味着农夫约翰混淆了信息，发件人不详。

字符串 $S$ 的兴奋度，是 $S$ 中出现子串 $BB$ 或 $EE$ 的次数。你想找出原始信息的兴奋度，但你不知道 $S$ 中的 $F$ 原来是 $B$ 还是 $E$？请你输出 $S$ 的所有可能的兴奋度
.

# 输入格式
第一行包含一个整数 $N$。

下一行包含 $S$。

# 输出格式
首先输出 $K$，即可能出现的不同兴奋度的数量。在接下来的 $K$ 行中，按递增顺序输出兴奋度。

```input1
4
BEEF
```

```output1
2
1
2
```

```input2
9
FEBFEBFEB
```

```output2
2
2
3
```

```input3
10
BFFFFFEBFE
```

```output3
3
2
4
6
```

# 提示

**【样例 1 解释】**
- 原字符串可能是 BEEB，此时兴奋度是 1（有 1 个 EE）
- 原字符串可能是 BEEE，此时兴奋度是 2（有 2 个 EE）
- 所以有 2 种可能的兴奋度，分别是 1 和 2

**【数据范围】**
- 对于 $100\%$ 的数据，$1 \leq n \leq 2 \times 10^5$

|测试点编号|特殊性质|
|:---:|:---:|
|$1\sim8$|$n \leq 10$|
|$12\sim20$|无|

<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

</details>

# 来源
* [USACO_2023_open_Bronze: FEB](https://usaco.org/index.php?page=open23results)