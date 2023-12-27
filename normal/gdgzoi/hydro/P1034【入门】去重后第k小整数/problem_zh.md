# 题目描述

现有 $n$ 个正整数，要求出这 $n$ 个正整数中的第 $k$ 个最小整数（相同大小的整数只计算一次）。

# 输入格式

第一行为 $n$ 和 $k$; 第二行开始为 $n$ 个正整数的值，整数间用空格隔开。

# 输出格式
第$k$个最小整数的值；若无解，则输出 `NO RESULT`。

```input1
10 3
1 3 3 7 2 5 1 2 4 6
```

```output1
3
```

# 提示
* 可以考虑先将数组排序然后去重，参看 [【课件】STL库应用](http://www.gzezoi.cn/d/gzezoi2023/p/P0006)
```c++
sort(a.begin(), a.end());
a.erase(unique(a.begin(), a.end()), a.end());
```
* 也可以考虑用 set 去重
```c++
set<int> s;
for (int i = 0; i < n; i++) {
    cin >> x;
    s.insert(x);
}
// 判断 s.size() 是否大于等于 k
if (s.size() < k) cout << "NO RESULT" << endl;
else {
    int cnt = 0;
    for (int x : s) {
        if (++cnt == k) {
            cout << x << endl;
            break;
        }
    }
}
```

# 数据规模与限制
* $n \leq 10000$，$k \leq 1000$，正整数均小于 $30000$。
* 1s, 1024KiB for each test case.