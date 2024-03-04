# 题目描述

有 $N$ 种物品和一个容量是 $V$ 的背包。

**<font color="#FF0000">物品一共有三类</font>**：

*   **<font color="#FF0000">第一类物品只能用1次（01背包）</font>**；
*   **<font color="#FF0000">第二类物品可以用无限次（完全背包）</font>**；
*   **<font color="#FF0000">第三类物品最多只能用 $s_i$ 次（多重背包）</font>**；

每种体积是 $v_i$，价值是 $w_i$。

求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。  
输出最大价值。

# 输入格式

第一行两个整数，$N，V$，用空格隔开，分别表示物品种数和背包容积。

接下来有 $N$ 行，每行三个整数 $v_i, w_i, s_i$，用空格隔开，分别表示第 $i$ 种物品的体积、价值和数量。

*   $s_i = -1$ 表示第 $i$ 种物品只能用1次；
*   $s_i = 0$ 表示第 $i$ 种物品可以用无限次；
*   $s_i >0$ 表示第 $i$ 种物品可以使用 $s_i$ 次；

# 输出格式

输出一个整数，表示最大价值。

```input1
4 5
1 2 -1
2 4 1
3 4 0
4 5 2
```

```output1
8
```

# 提示
**【样例解释 1】**
* 可以选择 1 个物品2 和 1 个物品3
* 总体积为：1 * 2 + 1 * 3 = 5
* 总价值为：1 * 4 + 1 * 4 = 8

<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

* 可以分类讨论，对于每种物品分别用 01背包，完全背包，多重背包求解

```c++
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    // 下面两句是为了让 cin 更快
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, v, w, s;
    while (cin >> n >> m) {
        vector<int> dp(m + 1, 0);
        for (int i = 0; i < n; i++) {
            cin >> v >> w >> s;
            if (s == -1) {        // 只能用 1 次, 01背包
                for (int j = m; j >= v; j--) {
                    dp[j] = max(dp[j], dp[j - v] + w);
                }
            } else if (s == 0) {  // 可以用无限次, 完全背包
                for (int j = v; j <= m; j++) {
                    dp[j] = max(dp[j], dp[j - v] + w);
                }
            } else {              // 可以用有限次, 多重背包, 二进制拆分
                for (int d = 1; s > 0; d *= 2) {
                    int c = min(d, s), nv = c * v, nw = c * w;
                    for (int j = m; j >= nv; j--) {
                        dp[j] = max(dp[j], dp[j - nv] + nw);
                    }
                    s -= c;
                }
            }
        }
        cout << dp[m] << '\n';
    }
    return 0;
}
```

</details>

# 数据规模与限制
* $0 \lt N \le 1000, 0 \lt V \le 3000$  
* $0 \lt v_i, w_i \le 1000$  
* $-1 \le s_i \le 1000$

# 来源
* [acwing: 7.混合背包问题](https://www.acwing.com/problem/content/7/)