# 题目描述

输入 $n$ 个的坐标，按 $x$ 轴的值从小到大排序，如果 $x$ 相同，则按照 $y$ 排序。

# 输入格式

第 1 行是一个整数 $n$ ($1 \lt n \lt 10^4$)

接下来有 $n$ 行，每行有 2 个整数 $x, y$，代表了 1 个点的坐标。

# 输出格式

输出 $n$ 行，每行有 2 个整数，输出排序后的 $n$ 个坐标。

```input1
5
4 7
5 5
2 3
6 8
2 1
```

```output1
2 1
2 3
4 7
5 5
6 8
```

# 提示
* 可以用 pair<int, int> 来存储坐标
```c++
vector<pair<int, int>> a(n);
for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
```
* 可以给 pair<int, int> 类型自定义排序
```c++
sort(a.begin(), a.end(), [&](const pair<int, int>& p, const pair<int, int>& q) {
    // 完成排序逻辑
});
```

# 数据规模与限制
* $1 \le n \le 10^4$
* $-10^9 \le x, y \le 10^9$
* 1s, 1024KiB for each test case.
