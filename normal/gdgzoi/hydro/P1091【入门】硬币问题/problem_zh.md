# 题目描述
你有 $5$ 种不同的硬币，每种硬币的价值都等于前 $5$ 个三角形数字中的一个： $1$ 、 $3$ 、 $6$ 、 $10$ 和 $15$ 。这些硬币种类非常多。你的目标是找出所需的最少数量的这些硬币，使它们的总价值相加正好是 $n$ 。

我们可以证明答案总是存在的。

# 输入格式

第一行包含一个整数 $t$ ( $1 \le t \le 10^4$ ) - 测试用例的数量。测试用例说明如下。

每个测试用例的第一行包含一个整数 $n$ ( $1 \leq n \leq 10^9$ ) - 目标值。

# 输出格式

对于每个测试用例，输出一个数字，即所需硬币的最少数量。

```input1
14
1
2
3
5
7
11
12
14
16
17
18
20
98
402931328
```

```output1
1
2
1
3
2
2
2
3
2
3
2
2
8
26862090
```

# 提示
**【样例解释】**

在第一个测试案例中，对于 $n = 1$ ，答案是 $1$ ，因为只需一枚 $1$ 值的硬币即可。 $1 = 1 \cdot 1$ .

在第四个测试案例中，对于 $n = 5$ ，答案是 $3$ ，可以使用两个 $1$ 面值的硬币和一个 $3$ 面值的硬币。 $5 = 2 \cdot 1 + 1 \cdot 3$ .

在第七个测试案例中，对于 $n = 12$ ，答案是 $2$ ，可以使用两个 $6$ 值的硬币来实现。

在第九个测试情形中，对于 $n = 16$ ，答案是 $2$ ，可以使用一枚 $1$ 面值的硬币和一枚 $15$ 面值的硬币，或者使用一枚 $10$ 面值的硬币和一枚 $6$ 面值的硬币。 $16 = 1 \cdot 1 + 1 \cdot 15 = 1 \cdot 6 + 1 \cdot 10$ .
  
<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

* 考虑如下贪心策略：尽可能多的选择面值大的硬币
* 然而这个策略不一定对，比如 12 = 10 + 1 + 1，需要 3 个硬币，但是 12 = 6 + 6，只需要 2 个硬币
* 所有有时候你并 **<font color="#FF0000">不一定要优先选择面值大的硬币</font>**
* 但这个贪心策略是比较接近最优解的（可以通过暴力打标观察）
* 比如按照贪心策略 $50=15*3+3*1+1*2$，50 需要 6 个硬币
* 但其实最优解是 $50 = 15*2+10*2$，50 只需要 4 个硬币
* 假设按照贪心策略需要 $x$ 个面值为 15 的硬币，而最优解需要 $y$ 个面值为 15 的硬币
* **<font color="#FF0000">必然有 $x \geq y$，而且 $x - y$ 不会很大</font>**
* 我们可以适当的枚举这个差值 $x - y$
* 先贪心地选择面值为 15 的硬币，当 $n$ 变得不太大以后，再暴力求最优解

```c++
#include <bits/stdc++.h>
using namespace std;

const int N = 350;

vector<int> a = {1, 3, 6, 10, 15};
vector<int> ans(N + 1);

void dfs(int p, int sum, int cnt) {
    if (p == 5) {
        ans[sum] = min(ans[sum], cnt);
        return ;
    }
    for (int i = 0; i <= 10; i++) dfs(p + 1, sum + a[p] * i, cnt + i);
}

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fill(ans.begin(), ans.end(), 1000);
    // 暴力计算 150 以内的最优解
    dfs(0, 0, 0);
    // for (int i = 1; i <= 300; i++) {
    //     int res = 0, d = i;
    //     for (int j = 4; j >= 0; j--) {
    //         int c = d / a[j];
    //         res += c, d -= c * a[j];
    //     }
    //     if (res != ans[i]) {
    //         cout << i << ' ' << ans[i] << ' ' << res << '\n';
    //     }
    // }
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;

        auto gao = [&](int d) {
            int res = 0;
            for (int j = 3; j >= 0; j--) {
                int c = d / a[j];
                res += c, d -= c * a[j];
            }
            return res;
        };

        // 150 以内输出暴力的结果
        if (n < 150) cout << ans[n] << '\n';
        else {
            // 贪心 + 暴力
            int d = n / 15;
            int res = d + gao(n - d * 15);
            for (int i = 1; i <= 10; i++) {
                res = min(res, d - i + ans[n - (d - i) * 15]);
            }
            cout << res << '\n';
        } 
    }
    return 0;
}
```

</details>

# 数据规模与限制
* $1 \leq T \leq 10^4$
* 共计 5 组测试数据
* $case1: 1 \leq n \leq 10$
* $case2: 1 \leq n \leq 100$
* $case3: 1 \leq n \leq 1000$
* $case4 \sim case5: 1 \leq n \leq 10^9$

# 来源
<!--
* [codeforces: CF_931_div2_B](https://codeforces.com/contest/1934/problem/B)
-->