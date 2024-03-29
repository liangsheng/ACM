# 题目描述

有 $n$ 名游客正在排队买票，每一个游客有一个暴躁值 $a_i$ 和一个买票需要花费的时间 $b_i$（即他从开始买票到买票结束所花费的时间）

每个游客最终的不愉快值可以表示为他的暴躁值 $a_i$ 乘以排队及买票花费的总时间（即从第一个游客开始买票，到第 $i$ 个游客买票结束）

请你安排游客的买票顺序，从而使所有游客的不愉快值之和最小化
# 输入格式

第一行一个正整数 $n$

接下来 $n$ 行，每行两个正整数 $a_i, b_i$。
 
# 输出格式
一行一个整数表示所有游客的不愉快之和的最小值

```input1
3
3 6
4 4
5 2
```

```output1
70
```

# 提示
**【样例解释】**
* 可以按照 [5, 2], [4, 4], [3, 6] 的顺序买票
* 第 1 个人的不愉快值：$5 * 2 = 10$
* 第 2 个人的不愉快值：$4 * (2 + 4) = 24$
* 第 3 个人的不愉快值：$3 * (2 + 4 + 6) = 36$
* 总的不愉快值是: $10 + 24 + 36 = 70$
* 这是一类经典问题，考虑 2 个人 $x, y$，用 $x_1$ 表示 $x$ 的暴躁值，$x_2$ 表示 $x$ 买票需要的时间，$y$ 同理
* 如果按 $xy$ 排序，2 人的不愉快值之和是 $s_1=x_1*x_2+y_1*(x_2+y_2)$
* 如果按 $yx$ 排序，2 人的不愉快值之和是 $s_2=y_1*y_2+x_1*(y_2+x_2)$
* 那么，当 $s_1 \lt s_2$ 时，$x$ 就应该排在 $y$ 前面
* 可参考如下代码将游客排序
```c++
typedef pair<int, int> pii;

// a[i].first 表示 i 的暴躁值, a[i].second 表示 i 的买票需要的时间
vector<pii> a(n); 

sort(a.begin(), a.end(), [&](const pii& x, const pii& y) {
    int s1 = x.first * x.second + y.first * (x.second + y.second);
    int s2 = y.first * y.second + x.first * (y.second + x.second);
    return s1 < s2;    
});
```

# 数据规模与限制
* $1 \le n \le 10^5, 1 \le a_i, b_i \le 100$
* 1s, 1024KiB for each test case.

# 来源
* [xjoj_1022_jwp的排队难题](https://oj.xjtuicpc.com/problem/1022)