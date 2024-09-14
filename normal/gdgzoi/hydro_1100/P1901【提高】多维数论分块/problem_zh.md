# 题目描述
给定正整数 $n, m$，求 
$$
\sum_{i=1}^{min(n,m)}\lfloor\frac{n}{i}\rfloor \cdot \lfloor\frac{m}{i}\rfloor
$$
其中 $\lfloor\frac{n}{i}\rfloor$ 表示求不超过 $\frac{n}{i}$ 的最大整数，比如：$\lfloor\frac{5}{2}\rfloor=2$，$\lfloor\frac{10}{3}\rfloor=3$

# 输入格式
第 1 行包含 1 个正整数 $T$;

接下来 $T$ 行，每行包含 2 个正整数 $n, m$

# 输出格式
对于每组数据输出 1 行表示答案

```input1
1
3 5
```

```output1
18
```

# 提示 
**【样例 #1 解释】**
* $\sum_{i=1}^{3}\lfloor\frac{3}{i}\rfloor \cdot \lfloor\frac{5}{i}\rfloor=3*5+1*2+1*1=18$
* [数论分块](https://blog.csdn.net/mango114514/article/details/122139890)
* [oiwiki: 数论分块](https://oi-wiki.org/math/number-theory/sqrt-decomposition/)
* [学习总结-莫比乌斯反演](https://www.cnblogs.com/GDOI2018/p/13541520.html)
* 参考上一题的结论

<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

</details>

# 数据规模与限制
* $1 \leq T \leq 100$
* $1 \leq n \leq 10^9$

# 来源
* [UVA11526: H(n)](https://www.luogu.com.cn/problem/UVA11526)