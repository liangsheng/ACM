# 题目描述

给定两个字符串 $A$ 和 $B$，现在要将 $A$ 经过若干操作变为 $B$，可进行的操作有：

1.  删除–将字符串 $A$ 中的某个字符删除。
2.  插入–在字符串 $A$ 的某个位置插入某个字符。
3.  替换–将字符串 $A$ 中的某个字符替换为另一个字符。

现在请你求出，将 $A$ 变为 $B$ 至少需要进行多少次操作。


# 输入格式

第一行包含整数 $n$，表示字符串 $A$ 的长度。

第二行包含一个长度为 $n$ 的字符串 $A$。

第三行包含整数 $m$，表示字符串 $B$ 的长度。

第四行包含一个长度为 $m$ 的字符串 $B$。

字符串中均只包含小写字母。


# 输出格式

输出一个整数，表示最少操作次数。

```input1
10
agtctgacgc
11
agtaagtaggc
```

```output1
4
```

# 提示
**【样例 #1 解释】**
* agtctgacgc
* agt<font color="#FF0000">a</font>tgacgc
* agta<font color="#FF0000">a</font>gacgc
* agtaag<font color="#FF0000">t</font>acgc
* agtaagta<font color="#FF0000">g</font>gc，从 $s$ 得到 $t$
* 本题的 $n$ 不超过 $1000$，所以 $O(n^2)$ 的算法可以通过
* $dp[i][j]$ 表示 $s[1..i]$ 和 $t[1..j]$ 的最短编辑距离

<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

</details>

# 数据规模与限制
* $1 \leq n \leq 10^3$
* 字符串均由小写字母组成

# 来源
* [acwing_902.最短编辑距离](https://www.acwing.com/problem/content/904/)