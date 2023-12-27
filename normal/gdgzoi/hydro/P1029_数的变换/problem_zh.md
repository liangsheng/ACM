# 题目描述
给你 2 个数 $x, y(1 \le x, y \le 10^{18})$，每次可以对 $x$ 进行如下 3 中操作中的一种：
* 将 x 乘 2， x = x * 2;
* 将 x 除 2（当 x 是偶数的时候），x = x / 2;
* 将 x 加 1，x = x + 1;

请问，最少经过几次操作，可以将 $x$ 变成 $y$

# 输入格式
第一行一个整数 T，表示数据的组数

接下来 T 行，每行包含两个整数 $x, y(1 \le x, y \le 10^{18})$

# 输出格式

对于每组数据，输出最少需要多少次操作才能将 $x$ 变成 $y$

```input1
6
31 13
12 8
25 6
10 24
1 1
997 120
```

```output1
8
3
8
3
0
20
```
# 提示
* 对于第 1 个子测试用例，一个最优的操作序列为 31 ⟹ 32 ⟹ 16 ⟹ 8 ⟹ 9 ⟹ 10 ⟹ 11 ⟹ 12 ⟹ 13。
* 对于第 2 个子测试用例，一个最优的操作序列为 12 ⟹ 6 ⟹ 7 ⟹ 8。
* 对于第 6 个子测试用例，一个最优的操作序列为 997 ⟹ 998 ⟹ 499 ⟹ 500 ⟹ 250 ⟹ 125 ⟹ 126 ⟹ 63 ⟹ 64 ⟹ 32 ⟹ 16 ⟹ 8 ⟹ 4 ⟹ 5 ⟹ 6 ⟹ 7 ⟹ 14 ⟹ 15 ⟹ 30 ⟹ 60 ⟹ 120。
* 若 $x > y$
  * 你只会操作 +1 或者 /2（不可能 *2）
  * (x + 1 + 1) / 2 == x / 2 + 1，等式左边需要 3 次操作，而等式右边只需要 2 次操作
  * **<font color="#FF0000">所以，如果你后面还会 / 2，你就不会连续两次 +1</font>**
    * **<font color="#FF0000">当 $x$ 是奇数时，你会 +1 然后 /2</font>**
    * **<font color="#FF0000">当 $x$ 是偶数时，你会直接 /2 （不会 +1 +1 /2）</font>**
    * 当使用了 *2 操作后，你不会再操作 /2
      * *2 后必然是偶数，如果还想 /2，必须有偶数个 +1，而你不可能 +1 +1 /2（不如 /2 +1）
      * 那么只能 *2 后直接 /2，这显然也不是最优
* 若 $x < y$
  * 你会操作 +1, *2, /2（$x < y$ 时也会 /2，比如样例 6）
  * x * 2 + 1 + 1 == 2 * (x + 1)，等式左边需要 3 次操作，而等式右边只需要 2 次操作
  * 所以，要么你不需要 *2，直接不断 +1 把 $x$ 变成 $y$，需要 $y-x$ 次操作；如果需要 *2 操作，*2 操作后不会出现 +1 +1
    * 当 $y$ 是奇数时，最后 2 步必然是 *2 和 +1
    * 当 $y$ 是偶数时，最后 1 步必然是 *2
* 请完成下面的递归
```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;  // typedef 表示 long long 简写成 LL

// INF = 9223372036854775807, 是 long long 的最大值
// const 表示变量 INF 不可变
// 不可变的变量一般用全大写表示
const LL INF = numeric_limits<LL>::max();

// 当 x < y 时需要的最少次数
LL fun(LL x, LL y) {
    // 第一步: 递归函数先写终止条件
    if (x == y) return 0;
 
    // 第一步: 递归函数先写终止条件
    // 直接全部 +1
    LL ans = ;
    // 以后不会再 *2 了
    if (x * 2 > y) return ans;
    // 当 y 是奇数时: 最后 2 步是 *2 和 +1
    if (y % 2 == 1) {
      LL tmp = fun(x, (y - 1) / 2) + 2;
      ans = min(ans, tmp);
    } else {
        // 当 y 是偶数时: 最后 1 步是 *2
        LL tmp = 
        ans = min(ans, tmp);
    }
    return ans;
}

// 将 x 变换 y 的最少次数
LL solve(LL x, LL y) {
    // 第一步: 递归函数先写终止条件
    if (x == y) return 0;
    if (x == 1) return fun(x, y);
    LL ans = INF;
    if (x < y) ans = fun(x, y);  // 当 x < y 时, 调用 fun(x, y)

    // 第二步: 将问题分解成几个小问题
    // 第 1 种情况: 直接 / 2
    if (x % 2 == 0) {
        LL tmp = solve(x / 2, y) + 1;
        return min(ans, tmp);
    }
    // 第 2 种情况: 先 +1, 再 / 2
    LL tmp = ;
    return min(ans, tmp);
}

int main() {
    LL T, x, y;
    cin >> T;
    while (T--) {
        cin >> x >> y;
        cout << solve(x, y) << endl;
    }
    return 0;
}
```


# 来源
* [USACO 2022 January Contest, Silver](http://www.usaco.org/index.php?page=viewproblem2&cpid=1182&lang=zh)

# 数据规模与限制
* $1 \le x, y \le 10^{18}$
* 1s, 1024KiB for each test case.
