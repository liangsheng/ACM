# 题目描述

给定 $n$ 个由 `X` 和数字构成的字符串，你需要对其进行排列并拼接成新的字符串 $T$$，以最大化其分数。定义其分数为对于字符串中每一个数字，使数字对应的数值乘上其之前 `X` 的数量，并求和。输出分数最大值。

# 输入格式

第一行输入一个整数 $n$

接下来 $n$ 行，每行一个字符串
 
# 输出格式
输出一个数，表示分数最大值

```input1
3
1X3
59
XXX
```

```output1
71
```

```input2
10
X63X395XX
X2XX3X22X
13
3716XXX6
45X
X6XX
9238
281X92
1XX4X4XX6
54X9X711X1
```

```output2
3010
```

# 提示
**【样例解释 1】**
* 可以证明当组合的字符串为 $XXX1X359$ 时
* 答案取得最大值 $1 × 3 + 3 × 4 + 5 × 4 + 9 × 4 = 71$ 
* 考虑将字符串数组按 [P1061_【入门】排队难题](http://www.gzezoi.cn/d/gzezoi2023/p/P1061) 的方法排序，按某种方法比较 2 个字符串，看谁应该排在前面
```c++
sort(a.begin(), a.end(), [&](const string& x, const string& y) {
    // x 什么时候应该排在 y 前面
});
```

# 数据规模与限制
* $2 \le n \le 2 \times 10^5$
* 1s, 1024KiB for each test case.

# 来源
* [abc268_F_Best_Concatenation](https://atcoder.jp/contests/abc268/tasks/abc268_f)