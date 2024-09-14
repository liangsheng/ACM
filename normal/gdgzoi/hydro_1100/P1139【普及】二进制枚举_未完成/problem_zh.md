# 题目描述
**<font color="#FF0000"> 本题和 [P1133.【入门】部分和问题](https://www.gzezoi.cn/d/gzezoi2023/p/P1133) 的唯一区别在于 $n$ 的范围 </font>**

给定整数 $a_1, a_2, \cdots, a_n$，判断是否可以从中选出若干数，使它们的和恰好为 $k$。

# 输入格式
第 1 行包含两个整数 $n$ 和 $k$;

第 2 行包含 $n$ 个整数 $a[i]$

# 输出格式
如果可以输出 "Yes"，否则输出 "No"

```input1
4 13
1 2 4 7
```

```output1
Yes
```

# 提示
* **<font color="#FF0000"> $O(2^{30})$ 的解法是不能通过此题的 </font>**
 
**【样例 #1 解释】**

<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

</details>

# 数据规模与限制
* $1 \leq n \leq 30$
* $-10^8 \leq a_i \leq 10^8$
* $-10^8 \leq k \leq 10^8$

# 来源
* [挑战程序设计竞赛_2.1.4]()