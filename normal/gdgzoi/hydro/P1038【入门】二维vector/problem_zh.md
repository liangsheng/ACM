# 题目描述

给你 $n$ 个 vector<int> 数组，分别是 $a_i(i=0,1,2...,n-1)$，初始都为空数组，现在有如下 3 中操作
* 0 t x， 表示将 x 添加到 $a_t$ 的末尾
* 1 t，表示按需输出 $a_t$ 中的所有元素
* 2 t，表示将 $a_t$ 清空

# 输入格式

第 1 行包含 2 个整数正 $n(1 \le n \le 1000), q(1 \le q \le 5*10^5)$，表示数组的个数和操作的个数

接下来 $q$ 行，每行的第 1 个数是操作的类型 $c$
* 当 $c = 0$ 时，再输入 2 个数 $t 和 x$，表示将 $x$ 添加到 $a_t$ 的末尾
* 当 $c = 1$ 时，再输入 1 个数 $t$，请按序输出 $a_t$ 中的所有元素
* 当 $c = 2$ 时，再输入 1 个数 $t$，表示清空数组 $a_t$

# 输出格式
* 每当 $c = 1$ 时，输出 1 行数，代表 $a_t$ 中的所有元素，元素之间用 1 个空格分开；
* 若数组 $a_t$ 是空，请输出 1 行空行

```input1
3 13
0 0 1
0 0 2
0 0 3
0 1 -1
0 2 4
0 2 5
1 0
1 1
1 2
2 1
1 0
1 1
1 2
```

```output1
1 2 3
-1
4 5
1 2 3

4 5
```

# 提示
* 二维 vector 的语法如下
```c++
// 申明 n 个 1维 vector<int>
vector<vector<int>> a(n, vector<int>());
for (int i = 0; i < q; i++) {
    cin >> t >> x;
    a[t].push_back(x);
}

// 清空 vector
a[t].clear();

// 遍历 vector<int> 有 3 中方法
// 1、获取 size
for (int i = 0; i < a[t].size(); i++) cout << a[t][i] << ' ';

// 2、使用迭代器
for (int i = a[t].begin(); i != a[t].end(); i++) cout << *i << ' ';

// 3、最简单方法
for (int i : a[t]) cout << x << ' ';

// 可以用 auto 代替 int
for (auto i : a[t]) cout << x << ' ';
```

# 数据规模与限制
* $1 \le n \le 1000, 1 \le q \le 5*10^5$
* 1s, 1024KiB for each test case.