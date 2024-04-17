# 题目描述
给定由 $n$ 个元素组成的数组 $a$ ，求表达式的最大值：

$$
|a_i - a_j| + |a_j - a_k| + |a_k - a_l| + |a_l - a_i|
$$

其中， $i$ 、 $j$ 、 $k$ 、 $l$ 是数组 $a$ 的四个**不同的**索引，其中 $1 \le i, j, k, l \le n$ 。

这里的 $|x|$ 表示 $x$ 的绝对值。

# 输入格式

**输入**

第一行包含一个整数 $t$ ( $1 \le t \le 500$ ) - 测试用例的数量。测试用例说明如下。

每个测试用例的第一行包含一个整数 $n$ ( $4 \le n \le 100$ ) - 给定数组的长度。

每个测试用例的第二行包含 $n$ 个整数 $a_1, a_2, \ldots, a_n$ ($-10^6 \le a_i \le 10^6$).

# 输出格式

输出 $T$ 行

一行一个整数，表示表达式的最大值

```input1
5
4
1 1 1 1
5
1 1 2 2 3
8
5 1 3 2 -3 -1 10 3
4
3 3 1 1
4
1 2 2 -1
```

```output1
0
6
38
8
8
```

# 提示
**【样例解释 1】**
* 可以选择 $i=1, j=2, k=3, l=4$，答案是 $0$
* $|a_1 - a_2| + |a_2 - a_3| + |a_3 - a_4| + |a_4 - a_1| = |1 - 1| + |1 - 1| + |1 - 1| + |1 - 1| = 0 + 0 + 0 + 0 = 0$


**【样例解释 2】**
* 可以选择 $i=1, j=3, k=2, l=5$，答案是 $6$
* $|a_1 - a_3| + |a_3 - a_2| + |a_2 - a_5| + |a_5 - a_1| = |1 - 2| + |2 - 1| + |1 - 3| + |3 - 1| = 1 + 1 + 2 + 2 = 6$
  
<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

* 将 $a$ 从小到大排序
* 取最小的 2 个数，和最大的 2 个数即可

```c++
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> a(n);
        for (int& x: a) cin >> x;
        sort(a.begin(), a.end());
        cout << a[n - 1] - a[0] + a[n - 1] - a[1] + a[n - 2] - a[1] + a[n - 2] - a[0] << '\n';
    }
    return 0;
}
```

</details>

# 数据规模与限制
* $1 \leq T \leq 500$
* $4 \leq n \leq 100$
* $-10^6 \le a_i \le 10^6$

# 来源
<!--
* [codeforces: CF_931_div2_A](https://codeforces.com/contest/1934/problem/A)
-->