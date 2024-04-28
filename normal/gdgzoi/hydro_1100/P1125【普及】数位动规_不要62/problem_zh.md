# 题目描述

一个整数，如果包含 $4$ 或 $62$，我们称这个整数不合法；

给定两个正整数 $a$ 和 $b$，求在 $[a,b]$ 中的所有整数中，有多少合法的整数；

注意：$6$ 和 $2$ 分开是合法的, 比如 $61152$ 是合法的。

# 输入格式

仅包含一行两个整数 $a,b$，含义如上所述。

# 输出格式

包含一行十个整数，分别表示 $[a,b]$ 中合法的数的个数。

```input1
1 100
```

```output1
80
```

# 提示
**【样例 #1 解释】**

<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

* 可以参考 [oiwiki_数位dp](https://oi-wiki.org/dp/number/)
* 这是 数位dp 的模板题
* 用 $f(x)$ 表示 $0$ 到 $x$ 这 $x + 1$ 个数中合法的数的个数，那么答案就是 $f(b + 1) - f(a)$，那要如何计算 $f(x)$ 呢
* 首先将 $x$ 按位拆分到数组 $a[]$，高位在前
* $dp[i][j][k]$ 表示前 $i$ 位数，第 $i$ 位数是 $k$，形成的数比 $x$ 小（$j=1$ 时，表示比 $x$ 小；$j=0$时表示等于 $x$）的合法的数的个数
* 从第 $i$ 位转移到 $i+1$ 位时，可以枚举第 $i+1$ 位是 $0 \sim 9$ 中的哪个，同时还要合法

```c++
// 统计 0 到 x 合法的数的个数
LL cal(LL x) {
    vector<int> a;
    while (x != 0) a.push_back(x % 10), x /= 10;
    int n = a.size();

    // dp[i][0][j]: 前 i 位数, 第 i 位数是 j, 和 x 相等的合法数
    // dp[i][1][j]: 前 i 位数, 第 i 位数是 j, 比 x 小的合法数
    vector<vector<vector<LL>>> dp(n + 1, vector<vector<LL>>(2, vector<LL>(10, 0)));
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) for (int ls = 0; ls < 2; ls++) for (int j = 0; j < 10; j++) {
        if (dp[i][ls][j] == 0) continue;

        // ls = 1, 表示前面已经小了, 那么这一位 0 到 9 都可以
        // ls = 0, 表示前面相等, 那么这一位只能 0 到 a[n - i]
        int lim = (ls ? 9 : a[n - 1 - i]);
        for (int d = 0; d <= lim; d++) {
            if (d == 4 || (j == 6 && d == 2)) continue;  // 不要 62
            dp[i + 1][ls | (d < lim)][d] += dp[i][ls][j];
        }
    }
    // 返回前 n 位比 x 小的合法数
    LL cnt = 0;
    for (int j = 0; j < 10; j++) cnt += dp[n][1][j];
    return cnt;
}
```

</details>

# 数据规模与限制
* $1 \leq a \leq b \leq 10^{12}$

# 来源
* [hdu_2089_不要62](https://acm.hdu.edu.cn/showproblem.php?pid=2089)
* [oiwiki_数位dp](https://oi-wiki.org/dp/number/)