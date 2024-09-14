# 题目描述

如题，给定一个范围 $n$，有 $q$ 个询问，每次输出第 $k$ 小的素数。

`提示`：如果你使用  `cin` 和 `cout`，建议在 main() 函数的开头加上如下代码，来提升输入输出效率！
```c++
ios::sync_with_stdio(false);
cie.tie(nullptr); cout.tie(nullptr);
```
 来加速。

# 输入格式

第一行包含两个正整数 $n,q$，分别表示查询的范围和查询的个数。

接下来 $q$ 行每行一个正整数 $k$，表示查询第 $k$ 小的素数。

# 输出格式

输出 $q$ 行，每行一个正整数表示答案。

```input1
100 5
1
2
3
4
5
```

```output1
2
3
5
7
11
```


# 提示
**【样例 #1 解释】**

<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

</details>

# 数据规模与限制
* $1 \le n \le 10^7$
* $1 \le q \le 10^4$

# 来源
* [luogu_P3383:【模板】线性筛素数](https://www.luogu.com.cn/problem/P3383)