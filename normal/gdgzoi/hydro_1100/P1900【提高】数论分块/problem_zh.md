# 题目描述
给定正整数 $n$，求 
$$
\sum_{i=1}^{n}\lfloor\frac{n}{i}\rfloor
$$
其中 $\lfloor\frac{n}{i}\rfloor$ 表示求不超过 $\frac{n}{i}$ 的最大整数，比如：$\lfloor\frac{5}{2}\rfloor=2$，$\lfloor\frac{10}{3}\rfloor=3$

# 输入格式
第 1 行包含 1 个正整数 $T$;

接下来 $T$ 行，每行包含一个正整数 $n$

# 输出格式
对于每组数据输出 1 行表示答案

```input1
2
5
10
```

```output1
10
27
```

# 提示 
**【样例 #1 解释】**
* $\lfloor\frac{5}{1}\rfloor+\lfloor\frac{5}{2}\rfloor+\lfloor\frac{5}{3}\rfloor+\lfloor\frac{5}{4}\rfloor+\lfloor\frac{5}{5}\rfloor=5+2+1+1+1=10$
* [数论分块](https://blog.csdn.net/mango114514/article/details/122139890)
* [oiwiki: 数论分块](https://oi-wiki.org/math/number-theory/sqrt-decomposition/)
* [学习总结-莫比乌斯反演](https://www.cnblogs.com/GDOI2018/p/13541520.html)
* 考虑 $n = 10$ 时的结果，$10+5+3+2+2+1+1+1+1+1=27$
* 可以发现 $\lfloor\frac{10}{6}\rfloor$ 到 $\lfloor\frac{10}{10}\rfloor$ 的结果都是 $1$
* 设 $k = \lfloor\frac{n}{l}\rfloor$，$r$ 是使得 $\lfloor\frac{n}{x}\rfloor=k$ 的最大的 $x$（比如 $n=10, l=6, r = 10$）
* 由 $\lfloor\frac{n}{x}\rfloor=k$ 得到 $n=xk+r$，当 $r=0$ 时，$x$ 最大是 $\lfloor\frac{n}{k}\rfloor$
* 所以 $r=\lfloor\frac{n}{k}\rfloor=\lfloor\frac{n}{\lfloor\frac{n}{l}\rfloor}\rfloor$
* 所以我们可以这样计算
```c++
LL T, n;
cin >> T;
while (T--) {
    cin >> n;
    LL ans = 0;
    for (LL l = 1; l <= n; l++) {
        LL k = n / l, r = n / k;
        ans += (LL) k * (r - l + 1);
        l = r;
    }
    cout << ans << '\n';
}
```
* 可以证明 $\lfloor\frac{n}{i}\rfloor$ 最多有不超过 $\lfloor 2\sqrt n \rfloor$ 个值
  * 当 $i \le \lfloor \sqrt n \rfloor$ 时，$\lfloor\frac{n}{i}\rfloor$ 最多有 $\lfloor \sqrt n \rfloor$ 个不同的值
  * 当 $i > \lfloor \sqrt n \rfloor$ 时，$\lfloor\frac{n}{i}\rfloor \le \sqrt n$，也只有 $\lfloor \sqrt n \rfloor$ 个不同的值
* 所以计算 $\sum_{i=1}^{n}\lfloor\frac{n}{i}\rfloor$ 的时间复杂度是 $O(\sqrt n)$

<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

</details>

# 数据规模与限制
* $1 \leq T \leq 100$
* $1 \leq n \leq 10^9$

# 来源
* [UVA11526: H(n)](https://www.luogu.com.cn/problem/UVA11526)