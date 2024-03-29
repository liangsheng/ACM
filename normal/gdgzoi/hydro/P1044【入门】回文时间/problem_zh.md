# 题目描述

陶陶习惯用 24 小时制来表达时间，例如 16:45，表示现在的时间是 16 时 45 分。

在信息科技课上，陶陶学到了回文数，如果一个数从左往右看和从右往左看是相同的，那么称这个数为回文数。

陶陶发现有很多时间表示从左往右看和从右往左看也是一样的，于是陶陶把这样的时间点定义为回文时间。例如 14:41 就是一个回文时间。

已知现在的时间是 h 时 m 分，陶陶请你求出在此之后（不包含此时刻）的第一个回文时间。

特别提醒：回文时间是指对于一个 24 小时制时间表示的合法字符串 ab:cd，一定有 a=d，b=c。

# 输入格式

一行一个表示时间的合法字符串，格式为 HH:MM，表示一个 24 小时制时间的字符串。

# 输出格式
按题目要求输出一个回文时间。

```input1
12:21
```

```output1
13:31
```

```input2
23:59
```

```output2
00:00
```

# 提示

# 数据规模与限制
* 1s, 1024KiB for each test case.

# 来源
* [2023海淀区中小学生信息学竞赛_小学组](https://aisichuang.net/main/questionBank/solve)