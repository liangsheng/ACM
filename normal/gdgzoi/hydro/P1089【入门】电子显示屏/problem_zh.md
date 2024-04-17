# 题目描述
电子显示屏上的数字包括 $0\sim 9$，它们均若干短线拼接而成，所用的短线条数分别为 $6, 2, 5, 5, 4, 5, 6, 3, 7, 6$

![img](file://电子显示屏.png)

我们用 $f(x)$ 表示数 $x$ 所用的短线条数

比如 $f(31) = 5 + 2 = 7$ 

给你两个数 $l, r(1 \leq l \leq r \leq 10^{18})$，请你求出 $l \sim r$ 中一段连续的数 $i \sim j(l \leq i \leq j \leq r)$，使得 $i \sim j$ 中所有的数，所用的短线条数都相同，即 $f(i) = f(i+1)=...=f(j)$。

输出 $j-i+1$ 的最大值，即数字个数的最大值

# 输入格式

第一行一个整数 $T$ 表示数据的组数

接下来 $T$ 行，每行两个整数 $l, r$（**<font color="#FF0000">请使用 long long</font>**）

# 输出格式

输出 $T$ 行

一行一个整数，表示所有数对 $(i, j)$ 中，$j - i + 1$ 的最大值。

```input1
2
2 5
6 7
```

```output1
2
1
```

```input2
1
114514 114514
```

```output2
1
```

# 提示
**【样例解释 1】**
* 可以选择 $2\sim 3$，$f(2) = f(3) = 5$，所以最多能选 $2$ 个数
* $f(6) = 6, f(7) = 3$，所以最多只能选 $1$ 个数

<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

* 只有 $2$ 和 $3$，以及 $9$ 和 $0$，在加 $1$ 的情况下用到的短线数是一样的
* 所以答案只可能是 $1$ 或者 $2$
* 所以只要 $[l, r]$ 之间有末尾是 $2$ 的数，答案就是 $2$（当然还有其他情况，比如 $29 \rightarrow 30$）
* 那么直接枚举 $l$ 到 $min(l + 10, r)$，查看答案是否可以为 $2$

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

// 计算 x 需要的短线数
int f(LL x) {
	int q[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	int ans = 0;
	while (x != 0) ans += q[x % 10], x /= 10;
	return ans;	
}

int gao(LL l, LL r) {
	for (LL i = l; i + 1 <= r; i++) {
        if (f(i) == f(i + 1)) return 2;
    }
	return 1;
}

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	LL T, l, r;
    cin >> T;
	while (T--) {
        cin >> l >> r;
        cout << gao(l, r) << '\n';
    }
	return 0;
}
```

</details>

# 数据规模与限制
* $1 \leq T \leq 100$
* 共计 10 组测试数据：
* $case1 \sim case3：1 \leq l \leq r \leq 10^{3}$
* $case4 \sim case6：1 \leq l \leq r \leq 10^{6}$
* $case7 \sim case10：1 \leq l \leq r \leq 10^{18}$

# 来源
<!--
* [luogu: P10024「HCOI-R1」报名人数](https://www.luogu.com.cn/problem/P10024)
-->