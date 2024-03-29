# 题目描述

有一个青蛙需要跳过河流。河的宽度为 $L(1 \le L \le 10^9)$。从河的一边到另一边有 $n(0 \le n \le 5 \cdot 10^5)$ 块石头排成一条直线。青蛙跳跃后可以落在石头上，但不能掉进河里。青蛙被要求最多跳 $m (1 \le m \le n+1)$ 次。现在青蛙想知道，如果它想跳过河，那么它一次跳跃的最大距离至少是多少？

# 输入格式
数据的第 1 行是一个整数 $T$, 表示数据的组数，接下来 $T$ 组数据

每个数据的第 1 行包含三个正整数 $L, n, m$。

然后是 $n$ 个用空格分开的整数。代表从起始位置到第 $i$ 块石头的距离 $p_i$，没有两块石头出现在一个地方，**<font color="#FF0000">不保证石头按顺序给出</font>**。
 
# 输出格式

对于每组测试用例：
仅输出一行，包含一个整数，表示青蛙一次跳跃的最大距离的最小值

```input1
2
6 1 2
2
25 3 3
11 2 18
```

```output1
4
11
```

# 提示
**【样例解释 1】**
* 河宽为 $6$，河中有 $1$ 个石头，青蛙最多跳 $2$ 次
* 第一个石头在距离青蛙 $2$ 的位置，距离河对岸 $6-2=4$
* 那么青蛙可以先跳到石头上（距离 2），再从石头跳到对岸（距离 4）
* 所以青蛙最大跳跃距离至少要是 4，否则从石头就跳不到对岸

**【样例解释 2】**
* 河宽为 $25$，河中有 $3$ 个石头，青蛙最多跳 $3$ 次
* 第 1 个石头在距离青蛙 $11$ 的位置
* 第 2 个石头在距离青蛙 $2$ 的位置
* 第 3 个石头在距离青蛙 $18$ 的位置
* 那么青蛙可以先跳到第 1 个石头上（距离 11），再跳到第 3 个石头（距离 18-11=7），最后跳到对岸（距离 25-18=7）
* 所以青蛙最大跳跃距离至少要是 11，否则从石头就跳不到对岸
* 假设青蛙最大跳跃距离要是 10，只能先跳到第 2 个石头上（距离 2），再跳到第 1 个石头（距离 11-2=9），再跳到第 3 个石头（距离 18-11=7），最后跳到对岸（距离 25-18=7），这需要跳 4 次，而青蛙最多只能跳 3 次

<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

* 二分枚举青蛙依次跳跃的最大距离
* 每次跳跃的时候，尽可能跳到最远的且能跳到的石头上

</details>

# 数据规模与限制
* $1 \le L \le 10^9, 0 \le n \le 5 \cdot 10^5, 1 \le m \le n+1$
* $1 \le p_i \lt L$
* 1s, 1024KiB for each test case.

# 来源
* [hdu_4004_第36届ACM/ICPC大连网络赛](https://acm.hdu.edu.cn/showproblem.php?pid=4004)