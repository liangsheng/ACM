# 题目描述

有 $n$ 支队伍参加比赛，每个队伍初始时有一些代币。比赛每一轮随机挑两个代币数不为 $0$ 的队伍，然后代币多的队伍获胜，代币少的队伍把代币全部给代币多的（代币数量相同则随机），直到最后只有一个队伍有代币， 这个队伍获胜。

求哪些队伍是有可能获胜的。

# 输入格式

第一行输入 $t$

接下来 $t$ 组数据，每组数据第一行输入一个整数 $n$，第二行输入 $n$ 个整数

# 输出格式

对于每组数据输出两行，第一行输出可能获胜的队伍数，第二行 **<font color="#FF0000">从小到大</font>** 输出这些队伍的编号

```input1
2
4
1 2 4 3
5
1 1 1 1 1
```

```output1
3
2 3 4 
5
1 2 3 4 5 
```

## 提示

**【样例 1 解释】**
* 代币为 2 的队伍，可以先击败代币为 1 的队伍，这样他的代币数增加到 3；
* 然后再击败代币为 3 的队伍，这样他的代币数增加到 6；
* 最后再击败代币为 4 的队伍

# 数据规模与限制
* $1 \le n \le 2 \times 10^5$
* 1s, 1024KiB for each test case.

# 来源
* [CF_555_div3_B_Long_Number](https://codeforces.com/contest/1157/problem/B)