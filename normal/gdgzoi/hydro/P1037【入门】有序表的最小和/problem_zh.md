# 题目描述

给出两个长度为 $n$ 的有序表 A 和 B，在 A 和 B 中各任取一个元素，可以得到 $n^2$ 个和，求这些和中最小的 $n$ 个。

# 输入格式

第 1 行包含 1 个整数正 $n(1 \le n \le 4*10^5)$

第 2 行与第 3 行分别有 $n$ 个整数，各代表有序表 A 和 B。一行中的每两个整数之间用一个空格隔开，数据保证有序表单调递增。

# 输出格式
输出共 $n$ 行，每行一个整数，第 $i$ 行为第 $i$ 小的和。

```input1
3
1 2 5
2 4 7
```

```output1
3
4
5
```

# 提示
* 考虑用 priority_queue 实现
* 假设有序数组 $a = [a_1, a_2, a_3], b = [b_1, b_2, b_3]$
* 数组 $a$ 和数组 $b$ 的两两组合我们用 3 个数组 $x, y, z$表示
* 数组 $x = [a_1+b_1, a_1+b_2, a_1+b_3]$
* 数组 $y = [a_2+b_1, a_2+b_2, a_2+b_3]$
* 数组 $z = [a_3+b_1, a_3+b_2, a_3+b_3]$
* 那么最小的数必然是 $x[1]=a_1+b_1, y[1]=a_2+b_1, z[1]=a_3+b_1$ 中的 1 个
* 我们把 $x[1], y[1], z[1]$ 放到 1 个小根堆里面
* 小根堆的实现方法可参考 [【课件】STL库的应用](http://www.gzezoi.cn/d/gzezoi2023/p/P0006) 中 priority_queue 部分
```c++
// 优先队列申明时需要指明类型, 默认优先取出最大值
priority_queue<int> q;

// 如果每次需要删除的是最小的数，可以在 push 的时候将数取反
q.push(-1);
q.push(-5);
q.push(-4);
q.push(-2);
q.push(-3);
```
* 或者再申明的时候告诉 priority_queue 每次删除最小的
```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    // 申明有限队列时, 指定每次删除最小的
    // 第 1 个参数 int 是指优先队列里的元素类型
    // 第 2 个参数 vector<int> 是有限队列的实现方式
    // 第 3 个参数 greater<int> 告诉优先队列 top() 取最小的数
    priority_queue<int, vector<int>, greater<int>> q;

    q.push(1);
    q.push(5);
    q.push(4);
    q.push(2);
    q.push(3);

    // 输出: 1 2 3 4 5
    while (!q.empty()) {
        int x = q.top();    // 通过 top() 每次取出最大元素
        cout << x << ' ';  // 输出的时候取反
        q.pop();            // 通过 pop() 将当前最大元素删除
    }
    cout << '\n';
    return 0;
}
```
* 利用小根堆的 top() 函数，可以得到最小的数，假设是 $x[1]=a_1+b_1$
* 我们利用 pop() 函数，将 $x[1]$ 从小根堆里面删除
* 然后利用 push() 函数，将 $x[2]=a_1+b_2$ 放到小根堆里面
* 然后再用 top() 函数取最小值，得到的是第 2 小的数
* 不断重复上述操作，直到找到第 n 小的数
* 实现的时候，可以利用 pair<int, int> 类型将下标也放到小根堆里面
```c++
vector<int> p(n, 0);
priority_queue<pair<int, int>> q;

// 插入的元素值取反变成小根堆, 将下标也放到堆里面
for (int i = 0; i < n; i++) q.push({-(a[i] + b[0]), i});
for (int i = 1; i <= n; i++) {
    auto it = q.top();
    q.pop();
    cout << -it.first << '\n';  // 输出的时候也取反
    int id = it.second;
    if (++p[id] < n) {
        q.push({-(a[id] + b[p[id]]), id});  // 将 a[id] 和 b 里面下一个数组合
    }
}
```
* 还不太理解的可以看这个 [参考答案](https://blog.csdn.net/weixin_44178736/article/details/106211992)

# 数据规模与限制
* $1 \le n \le 4*10^5, 1 \le A_i, B_i \le 10^5$
* 1s, 1024KiB for each test case.