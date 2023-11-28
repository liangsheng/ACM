# 题目描述
用递归实现乘方函数 $power(x, y) = x ^ y$
```c++
long long power(long long  x, long long y) {
    // 第一步: 递归函数先写终止条件

    // 第二步: 将问题分解成几个小问题
}
```
由于结果太大, 只需要输出结果模 998244353 的余数

# 输入格式
* 输入两个正整数 $x, y (1 \le x \le 10^3, 1 \le y \le 10^{12})$
* 注意 $y$ 的值请用 long long 存储

# 输出格式
* 输出 $x^y$ 模 998244353 的余数

```input1
2 3
```

```output1
8
```

```input2
2 1000000000000
```

```output2
344440097
```

# 提示

# 数据规模与限制
* $1 \le x \le 10^3, 1 \le y \le 10^{12}$
* 1s, 1024KiB for each test case.
