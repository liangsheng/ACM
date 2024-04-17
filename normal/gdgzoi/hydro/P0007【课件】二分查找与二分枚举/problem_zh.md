- [1、二分查找](#1二分查找)
- [1-1、一个数在有序数组中的位置](#1-1一个数在有序数组中的位置)
- [1-2、STL 中的 lower\_bound 和 upper\_bound](#1-2stl-中的-lower_bound-和-upper_bound)
- [2、二分枚举](#2二分枚举)
  - [2-1、假定一个解并判定是否可行](#2-1假定一个解并判定是否可行)
  - [2-2、最大值最小问题](#2-2最大值最小问题)
  - [2-3、最小值最大问题](#2-3最小值最大问题)
  - [2-4、浮点数二分](#2-4浮点数二分)

# 1、二分查找
**<font color="#FF0000">二分查找是通过不断缩小解可能存在的范围（往往是每次缩小一半），从而求得问题最优解的方法，经常可以看到二分+贪心，二分+动规的题目。</font>**

# 1-1、一个数在有序数组中的位置
<table><tr><td bgcolor="#D2D2D2">
题意：给定一个长度为 $n$ 的单调不下降的数组 $a = [a_0, a_1, ..., a_n]$ 和一个数 $k$，求满足 $a_i \ge k$ 的最小 $i$，不存在的情况下输出 $n$
</td></tr></table>

* 比如: $a = [2, 3, 3, 5, 6], k = 3$
* 最小的 $i = 1$, 因为 $a_1 = 3 \ge k$，而 $a_0 = 2 \lt k$

当然如果朴素的按序查找，也可以求得答案。但如果 **<font color="#FF0000">利用数组有序这一条件</font>**，则可以得到更高效的算法。
* 首先看 $a[n / 2]$，如果 $a[n / 2] \ge k$ 的，就可以知道解的范围不大于 $n / 2$；
* 反之，如果 $a[n / 2] \lt k$，既可以知道解大于 $n / 2$;
* 通过这样一次比较，就将解的范围缩小了一半
* 反复与区间的中点比较，就可以不断地把解的范围缩小到原来的一半，最终在 $O(logn)$ 次的比较内求得最终解

![解的范围的变化过程](file://解的范围的变化过程.png)

```c++
#include <bits/stdc++.h>
using namespace std;

// 查找 a 中第一个大于等于 k 的数的下标; 如果没有, 就返回 n
int my_lower_bound(vector<int>& a, int k) {
    int n = a.size();
    if (a[n - 1] < k) return n;  // a 中所有的数都比 k 小, 直接返回 n
    int l = 0, r = n - 1, mid;   // 初始范围是 [l, r]
    while (l != r) {
        mid = (l + r) / 2;
        if (a[mid] >= k) r = mid;  // 如果 mid 满足条件, 解的范围变成 [l, mid]
        else l = mid + 1;          // 如果 mid 不满足条件, 解的范围变成 [mid + 1, r]
    }
    return l;
}

// 查找 a 中第一个大于 k 的数的下标; 如果没有, 就返回 n
int my_upper_bound(vector<int>& a, int k) {
    int n = a.size();
    if (a[n - 1] <= k) return n;  // a 中所有的数都不超过 k, 直接返回 n
    int l = 0, r = n - 1, mid;    // 初始范围是 [l, r]
    while (l != r) {
        mid = (l + r) / 2;
        if (a[mid] > k) r = mid;  // 如果 mid 满足条件, 解的范围变成 [l, mid]
        else l = mid + 1;         // 如果 mid 不满足条件, 解的范围变成 [mid + 1, r]
    }
    return l;
}

int main() {
    vector<int> a = {2, 3, 3, 5, 6};
    int k = 3;

    // 查找 a 中第一个大于等于 k 的数的下标; 如果没有, 就返回 n
    // 输出: 1
    cout << my_lower_bound(a, k) << '\n';

    // 查找 a 中第一个大于 k 的数的下标; 如果没有, 就返回 n
    // 输出: 3
    cout << my_upper_bound(a, k) << '\n';
    return 0;
}
```
* 上述代码实现了 2 个函数
* my_lower_bound(): 查找 a 中 **<font color="#FF0000">第一个大于等于 k </font>** 的数的下标; 如果没有, 就返回 n
* my_upper_bound(): 查找 a 中 **<font color="#FF0000"> 第一个大于 k </font>** 的数的下标; 如果没有, 就返回 n

# 1-2、STL 中的 lower_bound 和 upper_bound
* 在 STL 库中其实已经提供了上述两个函数
```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {2, 3, 3, 5, 6};
    int k = 3;

    // 查找 a 中第一个大于等于 k 的数的下标; 如果没有, 就返回 n
    cout << lower_bound(a.begin(), a.end(), k) - a.begin() << '\n';

    // 查找 a 中第一个大于 k 的数的下标; 如果没有, 就返回 n
    // 输出: 3
    cout << upper_bound(a.begin(), a.end(), k) - a.begin() << '\n';
    
    // 输出: 5, 也就是数组 a 的大小 n, 因为找不到大于等于 10 的数
    cout << lower_bound(a.begin(), a.end(), 10) - a.begin() << '\n';    
    
    // 输出: 5, 也就是数组 a 的大小 n, 因为找不到大于 10 的数
    cout << upper_bound(a.begin(), a.end(), 10) - a.begin() << '\n';     
    return 0;
}
```
* 需要注意的是
* **<font color="#FF0000">lower_bound(a.beign(), a.end(), k) 返回的是迭代器</font>**
* **<font color="#FF0000">需要 lower_bound(a.beign(), a.end(), k) - a.begin() 才能得到对应的下标</font>**
* upper_bound() 同理

# 2、二分枚举
二分查找算法除了在有序数组中找值外，在求解最优解问题上也非常有用

让我们考虑下 “求满足某个条件 $C(x)$ 的最小 $x$” 这一问题
* 对于任意满足 $C(x)$ 的 $x$，如果所有的 $x' \ge x$ 也满足 $C(x')$ 的话，我们就可以用二分搜索来求得最小的 $x$
* 最大化问题也可以用同样的方法求解

## 2-1、假定一个解并判定是否可行

<table><tr><td bgcolor="#D2D2D2">
题意：有 $n$ 条绳子，它们的长度分别是 $a_0, a_1, ..., a_{n-1}$。如果从它们中切割出 $k$ 条长度相同的绳子，这 $k$ 条绳子每条最长能有多长？（原绳子和切割后的绳子的长度都是整数）
</td></tr></table>

* 比如 $a = [8, 7, 4, 5], k = 11$
* 我们可以切割出 $11$ 条长度为 $2$ 的绳子（四条绳子分别切割出 4, 3, 2, 2, 条绳子）
* 但是只能切割 $6$ 条长度为 $3$ 的绳子
* 所以最后的结果是 $2$

我们来套用二分搜索的模型来解决问题
* 令 $C(x)$ 为可以得到 $k$ 条长度为 $x$ 的绳子
* 则问题变为了求满足 $C(x)$ 条件的最大的 $x$
* 若 $x$ 满足条件，那么所有 $x' \le x$ 必然也能满足条件，符合二分搜索的条件

```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 4, k = 11;
    vector<int> a = {8, 7, 4, 5};

    // 可以理解为定义了函数 C(int mid)
    // auto 函数名 [&](变量类型 变量名) { };
    auto C = [&](int mid) {
        int cnt = 0;
        // 计算能切割出多少长度为 $mid$ 的绳子
        for (int i = 0; i < n; i++) cnt += a[i] / mid;
        // 当 cnt >= k 时, mid 才满足要求
        return cnt >= k;
    };

    // *max_element() 表示求最大值
    // 语法: *max_element(起始迭代器, 终止迭代器)
    // 切割出来的绳子最短是 l = 1, 最长是绳子的最大值
    int l = 1, r = *max_element(a.begin(), a.end()), mid;
    while (l != r) {
        mid = (l + r + 1) / 2;  // 注意: 这里要 +1, 不然会死循环
        if (C(mid)) l = mid;    // 如果 mid 满足条件, 则解必然大于等于 mid, 解的范围变成 [mid, r]
        else r = mid - 1;       // 如果 mid 不满足条件, 解的范围变成 [l, mid - 1]
    }

    // 如果 mid = (l + r) / 2 没有 +1 的话, 会死循环
    // 可以执行下下面的代码
    // int l = 1, r = accumulate(a.begin(), a.end(), 0), mid;
    // while (l != r) {
    //     mid = (l + r) / 2;
    //     cout << "l= " << l << ", r= " << r << ", mid= " << mid << " " << C(mid) << '\n';
    //     if (C(mid)) l = mid;
    //     else r = mid - 1;
    // }

    cout << l << '\n';
    return 0;
}
```

## 2-2、最大值最小问题
二分类问题经常会出现求 **<font color="#FF0000">最小值最大</font>** 或者 **<font color="#FF0000">最大值最小</font>** 的字眼。这两类问题在二分的写法上略有不同。

这类问题的一般解决方法是：
* 1、首先判断问题的答案是否满足二分性质，是求 **<font color="#FF0000">最大值最小</font>**，还是求 **<font color="#FF0000">最小值最大</font>**
* 2、确定边界 $l, r$
* 3、确定判定逻辑（通常是一个贪心算法）

我们来看一个最大值最小的例子：[【入门】分割数组的最大值](http://www.gzezoi.cn/d/gzezoi2023/p/P1072)

<table><tr><td bgcolor="#D2D2D2">
题意：给定一个非负整数数组 $a$ 和一个整数 $k$ ，你需要将这个数组分成 $k$ 个非空的连续子数组。设计一个算法使得这 $k$ 个子数组各自和的 <font color="#FF0000">最大值最小</font>
</td></tr></table>

* 样例: $a = [7, 2, 5, 10, 8], k = 2$
* 可以将 $a$ 分割成 $[7, 2, 5]$ 和 $[10, 8]$
* 两个子数组的和是 14 和 18，因此 **<font color="#FF0000">最大值最小</font>** 是 18

我们来套用二分搜索的模型来解决问题
* 令 $C(x)$ 表示可以将数组分割成 $k$ 段，且 **<font color="#FF0000">最大子段和不超过 $x$ </font>**
* 若 $x$ 满足条件，那么所有 $x' \ge x$ 必然也能满足条件，符合二分搜索的条件
* 则问题变为了求满足 $C(x)$ 条件的 **<font color="#FF0000">最小</font>** 的 $x$

```c++
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& a, int k) {
    int n = a.size();
    // accumulate() 用来求和
    // 确定边界, l = 0, r 最大为数组的和
    int l = 0, r = accumulate(a.begin(), a.end(), 0), mid;

    // 可以理解为申明一个函数 gao(int tmp)
    auto gao = [&](int tmp) {
        int d = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > tmp) return false;

            // 在和不超过 tmp 的前提下，每个子段都贪心地选择尽可能多的数
            int sum = a[i];
            while (i + 1 < n && sum + a[i + 1] <= tmp) sum += a[++i];
            d++;
        }
        // 如果分割出来的子段个数不超过 k, 那么 tmp 就可行
        return d <= k;
    };

    // 二分枚举答案, 这里求最大值最小, 注意边界
    while (l != r) {
        mid = (l + r) / 2;      // 注意：这里没有 +1
        if (gao(mid)) r = mid;  // mid 满足条件, r = mid
        else l = mid + 1;       // mid 不满足条件, l = mid + 1
    }
    return l;
}

int main() {
    // 下面 2 句是为了让 cin, cout 更快, 不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    while (cin >> n >> k) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << solve(a, k) << '\n';
    }
    return 0;
}
```
**<font color="#FF0000">最大值最小问题的解答模板</font>**
```c++
while (l != r) {
    mid = (l + r) / 2;    // 注意：里没有 +1
    if (C(mid)) r = mid;  // [l, r] => [l, mid]
    else l = mid + 1;     // [l, r] => [mid + 1, r]
}
```

## 2-3、最小值最大问题
再来看另一个最大值最小的例子：[【入门】分割数组的最小值](http://www.gzezoi.cn/d/gzezoi2023/p/P1074)

<table><tr><td bgcolor="#D2D2D2">
题意：给定一个非负整数数组 $a$ 和一个整数 $k$ ，你需要将这个数组分成 $k$ 个非空的连续子数组。设计一个算法使得这 $k$ 个子数组各自和的 <font color="#FF0000">最小值最大</font>
</td></tr></table>

* 样例: $a = [7, 2, 5, 10, 8], k = 2$
* 可以将 $a$ 分割成 $[7, 2, 5]$ 和 $[10, 8]$
* 两个子数组的和是 14 和 18，因此 **<font color="#FF0000">最小值最大</font>** 是 14

我们来套用二分搜索的模型来解决问题
* 令 $C(x)$ 表示可以将数组分割成 $k$ 段，且 **<font color="#FF0000"> 最小子段和不小于 $x$ </font>**
* 若 $x$ 满足条件，那么所有 $x' \le x$ 必然也能满足条件，符合二分搜索的条件
* 则问题变为了求满足 $C(x)$ 条件的 **<font color="#FF0000">最大</font>** 的 $x$

```c++
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& a, int k) {
    int n = a.size();
    // accumulate() 用来求和
    int l = 0, r = accumulate(a.begin(), a.end(), 0), mid;

    // 可以理解为申明另外一个函数 gao(int tmp)
    auto gao = [&](int tmp) {
        int d = 0;
        for (int i = 0; i < n; i++) {
            // 在和不小于 tmp 的前提下，每个子段都贪心地选择尽可能少的数
            int sum = a[i];
            while (sum < tmp && i + 1 < n) sum += a[++i];
            if (sum < tmp) return false;
            if (++d >= k) return true;
        }
        // 如果分割出来的子段个数不小于 k, 那么 tmp 就可行
        return d >= k;
    };

    // 二分枚举答案, 这里是求最小值最大, 注意边界
    while (l != r) {
        mid = (l + r + 1) / 2;  // 注意, 求最小值最大, 这里需要 + 1
        if (gao(mid)) l = mid;  // mid 满足条件, l = mid
        else r = mid - 1;       // mid 不满足条件, r = mid - 1
    }

    // 注意: 下面的代码是求最大值最小, 对比下区别!!
    // 二分枚举答案, 这里是求最大值最小, 注意边界
    // while (l != r) {
    //     mid = (l + r) / 2;
    //     if (gao(mid)) r = mid;
    //     else l = mid + 1;
    // }
    return l;
}

int main() {
    // 下面 2 句是为了让 cin, cout 更快, 不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    while (cin >> n >> k) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << solve(a, k) << '\n';
    }
    return 0;
}
```
**<font color="#FF0000">最小值最大问题的解答模板</font>**
```c++
while (l != r) {
    mid = (l + r + 1) / 2;  // 注意：这里 +1
    if (C(mid)) l = mid;  // [l, r] => [mid, r]
    else r = mid - 1;     // [l, r] => [l, mid - 1]
}
```

## 2-4、浮点数二分
* 前面的题目，我们用来二分的答案都是整数
* 其实，浮点数也可以用来二分

[【入门】数的三次方根](http://www.gzezoi.cn/d/gzezoi2023/p/P1077)

<table><tr><td bgcolor="#D2D2D2">
题意：给定一个浮点数 $n$，求它的三次方根。
</td></tr></table>

* 我们知道三次函数是一个单点函数，满足如果 $x \le y$，那么 $x^3 \le y^3$
* 令 $C(x)$ 表示 $x$ 满足 $x^3$ 不超过 $n$
* 若 $x$ 满足条件 $C(x)$，那么所有 $x' \le x$ 必然也能满足条件 $C(x')，符合二分搜索的条件
```c++
#include <bits/stdc++.h>
using namespace std;

// eps = 0.00000001
const double eps = 1e-8;

int main() {
    // 下面 2 句话是为了让 cin, cout 更快, 并不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double n;
    cin >> n;

    double l = -1000, r = 1000, mid;

    // 注意: 由于精度问题，浮点数二分时，需要设置二分次数，防止死循环
    // 因为当 l 和 r 很接近的时候, 不管 mid 是否满足条件, l 和 r 的变化都很小
    // 不能写: while (abs(r - l) >= 0.000001) 
    // 二分次数可以根据题目数据大小变化,
    // 一般来说 50 到 60 次足以解决大部分问题
    for (int i = 0; i < 60; i++) {
        mid = (l + r) / 2;
        if (mid * mid * mid < n) l = mid;
        else r = mid;
    }
    cout << fixed << setprecision(8) << l << '\n';
    return 0;
}
```
