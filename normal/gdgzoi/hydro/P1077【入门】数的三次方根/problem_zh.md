# 题目描述

给定一个浮点数 $n$，求它的三次方根。

# 输入格式
共一行，包含一个浮点数 $n$。
 
# 输出格式

共一行，包含一个浮点数，表示问题的解。

注意，结果保留 $6$ 位小数。

```input1
1000.00
```

```output1
10.000000
```

# 提示
**【样例解释 1】**
* **<font color="#FF0000">浮点数的二分枚举，一定要设置最大的二分次数，否则会死循环！！</font>**
```c++
double l = -1000, r = 1000, mid;

// 注意: 浮点数二分时，需要设置二分次数，防止死循环
for (int i = 0; i < 100; i++) {
    mid = (l + r) / 2;
    if (mid * mid * mid < n) l = mid;
    else r = mid;
}
```

<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>


</details>

# 数据规模与限制
* $-1000 \le n \le 1000$
* 1s, 1024KiB for each test case.

# 来源
* [acwing_790_数的三次方根](https://www.acwing.com/problem/content/792/)