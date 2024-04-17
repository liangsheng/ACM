# 题目描述
给你 $n(2 \leq n \leq 10^5)$ 个只由 $0$ 和 $1$ 组成的字符串，你可以任意移动这 $n$ 个字符串中 $0$ 和 $1$ 的位置，要求最后每个字符串都符合下面三个条件之一：
* 字符串为空
* 字符串全是 $0$
* 字符串全是 $1$

要达到上述条件，所需要的最少移动次数是多少？

# 输入格式

第一行包含一个整数 $n(2 \leq n \leq 10^5)$

接下来 $n$ 行，每行包含一个只有 $0$ 和 $1$ 组成的字符串 $s_i$，$s_i$ 的长度 $1 \leq |s_i| \leq 2 \cdot 10^5$

保证这个 $n$ 个字符串的长度和不超过 $5 \cdot 10^5$

# 输出格式

输出最少需要移动的次数

```input1
4
11101101
00
10001
10
```

```output1
5
```

```input2
2
101010
010101
```

```output2
6
```

```input3
5
0000
11
0
00000000
1
```

```output3
0
```

```input4
3
011
0111
01111
```

```output4
4
```

# 提示
**【样例解释 1】**
* 将第 1 个字符串中的 2 个 0 移动到第 2 个字符串，需要 2 步
* 将第 3 个字符串中的 2 个 1 移动到第 1 个字符串，需要 2 步
* 将第 4 个字符串中的 1 个 1 移动到第 1 个字符串，需要 1 步
* 这样 4 个字符串变成
  * 111111111
  * 0000
  * 000
  * 0
* 总共需要 5 步
  
<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

* 如果字符串全是 0，或者全是 1，我们不用处理
* 假设字符串中 0 的个数是 $c_0$, 1 的个数是 $c_1$
* 如果 $c_0 \leq c_1$，就把 0 全部挪走；否则就把 1 全部挪走
* 假设需要把 0 挪走，那就找另一个不需要把 0 挪走的字符串，大家把 0 都挪过去

```c++
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, ans = 0, tmp = 500005;
    int n0 = 0, n1 = 0, y0 = 0, y1 = 0;
    string s;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        vector<int> c(2, 0);
        for (char ch : s) c[ch - '0']++;
        ans += min(c[0], c[1]);
        tmp = min(tmp, abs(c[0] - c[1]));
        if (c[0] >= c[1]) y0 = 1;
        if (c[1] >= c[0]) y1 = 1;
        if (c[0] > 0 && c[0] < c[1]) n0 = 1;
        if (c[1] > 0 && c[1] < c[0]) n1 = 1;  
    }
    if ((n0 & !y0) || (n1 & !y1)) cout << ans + tmp << '\n';
    else cout << ans << '\n';
    return 0;
}
```

</details>

# 数据规模与限制
* $2 \leq n \leq 10^5$
* $1 \leq |s_i| \leq 2 \cdot 10^5$
* $n \leq \sum|s_i| \leq 5 \cdot 10^5$

# 来源
<!--
* [codeforces: 2024_ICPC_Asia_H](https://codeforces.com/contest/1938/problem/H)
-->