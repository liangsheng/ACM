# 题目描述

如果一个整数符合下面 $3$ 个条件之一，那么我们就说这个整数和 $7$ 有关——
- 1、整数中某一位是 $7$；
- 2、整数的每一位加起来的和是 $7$ 的整数倍；
- 3、这个整数是 $7$ 的整数倍；

给定两个正整数 $a$ 和 $b$，求在 $[a,b]$ 中的所有整数中和 $7$ 无关的数的平方和；

# 输入格式

仅包含一行两个整数 $a,b$，含义如上所述。

# 输出格式

包含一行十个整数，分别表示 $[a,b]$ 的所有整数中和 $7$ 无关的数的平方和，将结果对 $998244353$ 取余

```input1
1 9
```

```output1
236
```

# 提示
**【样例 #1 解释】**

<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

首先考虑如何计算与 $7$ 无关的 **<font color="#FF0000">数的个数</font>**

* $c[i][ls][j][k]$ 表示前 $i$ 位数，数字和 $\%7 = j$，数 $\%7 = k$，形成的数比 $x$ 小（$ls=1$ 时，表示比 $x$ 小；$ls=0$时表示等于 $x$）的数的个数
* 从第 $i$ 位转移到 $i+1$ 位时，可以枚举第 $i+1$ 位的数字 $d$，那么
  * $d$ 不能是 $7$
  * 设 $u = (j + d) \% 7$，$v = (k * 10 + d) \% 7$;
  * 那么在第 $i+1$ 位是 $d$ 时，可以由状态 $(i, j)$ 转移到 $(u, v)$

再来考虑如何计算与 $7$ 无关的 **<font color="#FF0000">数的和</font>**
* $s[i][ls][j][k]$ 表示前 $i$ 位数，数字和 $\%7 = j$，数 $\%7 = k$，形成的数比 $x$ 小（$ls=1$ 时，表示比 $x$ 小；$ls=0$时表示等于 $x$）的数的和
* 状态转移过程和求个数类似

* 最后来看最复杂的求 **<font color="#FF0000">数的平方和</font>**
* 考虑将平方式拆开
$$
(10x+d)^2 = 100x^2+20xd+d^2 \\
$$
* 两边同时求和
$$
\sum{(10x+d)^2} = 100\sum{x^2}+20d \sum{x}+\sum{d^2}
$$
* $\sum{x}$ 对应着 $s[i][ls][j][k]$
* $\sum{d^2}$ 则是 $c[i][ls][j][k] * d^2$

```c++
// 统计 0 到 x 与 7 无关的数的平方和
int cal(LL x) {
    // cout << "x= " << x << '\n';
    vector<int> a;
    while (x != 0) a.push_back(x % 10), x /= 10;
    int n = a.size();

    memset(s, 0, sizeof(s));
    memset(f, 0, sizeof(f));
    memset(c, 0, sizeof(c));
    c[0][0][0][0] = 1;
    for (int i = 0; i < n; i++) for (int ls = 0; ls < 2; ls++) {
        for (int j = 0; j < 7; j++) for (int k = 0; k < 7; k++) { 

            // ls = 1, 表示前面已经小了, 那么这一位 0 到 9 都可以
            // ls = 0, 表示前面相等, 那么这一位只能 0 到 a[n - i]
            int lim = (ls ? 9 : a[n - 1 - i]);
            for (int d = 0; d <= lim; d++) {
                if (d == 7) continue;  // 不能包含 7
                int u = (j + d) % 7, v = (k * 10 + d) % 7;

                // 先更新个数 c
                add(c[i + 1][ls | (d < lim)][u][v], c[i][ls][j][k]);

                // 再更新和 dp
                int t = ((LL) s[i][ls][j][k] * 10 + (LL) c[i][ls][j][k] * d) % MOD;
                add(s[i + 1][ls | (d < lim)][u][v], t);

                // 最后更新平方和 
                // (10x + d)^2 = 100x^2 + 20xd + d^2
                t = ((LL) 100 * f[i][ls][j][k] + (LL) 20 * s[i][ls][j][k] * d + (LL) c[i][ls][j][k] * d * d) % MOD;
                add(f[i + 1][ls | (d < lim)][u][v], t);
            }
        }
    }
    int ans = 0;
    for (int j = 1; j < 7; j++) for (int k = 1; k < 7; k++) add(ans, f[n][1][j][k]);
    return ans;
}
```

</details>

# 数据规模与限制
* $1 \leq a \leq b \leq 10^{12}$

# 来源
* [hdu_4507_吉哥系列故事——恨7不成妻](https://acm.hdu.edu.cn/showproblem.php?pid=4507)
* [oiwiki_数位dp](https://oi-wiki.org/dp/number/)