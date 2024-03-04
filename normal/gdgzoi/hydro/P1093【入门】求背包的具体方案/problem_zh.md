# 题目描述
有 $N$ 件物品和一个容量是 $V$ 的背包。每件物品只能使用一次。

第 $i$ 件物品的体积是 $v_i$，价值是 $w_i$。

求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。

输出最大价值

输出 **最优选法的方案数**。注意答案可能很大，请输出答案模 $10^9 + 7$ 的结果。

输出 **字典序最小的方案**。这里的字典序是指：所选物品的编号所构成的序列。物品的编号范围是 $1 … N$。


# 输入格式

第一行两个整数，$N，V$，用空格隔开，分别表示物品数量和背包容积。

接下来有 $N$ 行，每行两个整数 $v_i, w_i$，用空格隔开，分别表示第 $i$ 件物品的体积和价值。

# 输出格式

第 1 行输出最大价值

第 2 行输出**方案数** 模 $10^9 + 7$ 的结果

第 3 行包含若干个用空格隔开的整数，表示最优解中所选物品的编号序列，且该编号序列的字典序最小

```input1
4 5
1 2
2 4
3 4
4 6
```

```output1
8
2
1 4
```

# 提示
**【样例解释 1】**
* 最大价值是 8
* 有 2 种方案，（1， 4）或者（2，3）
* 其中 （1，4）的字典序小于 （2，3）
  
<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

* 状态设计：
* $dp(i, j)$ 表示 $[i,..,n]$ 个物品, 体积不超过 $j$ 的最大价值，为了计算字典序最小的方案，将 $dp(i, j)$ 倒过来
* $f(i, j)$ 表示在 $dp(i, j)$ 中是否取了第 $i$ 个物品
* $c(i, j)$ 表示在达成 $dp(i, j)$ 的方案数

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 1000000007;

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, V;
    cin >> n >> V;
    vector<int> v(n + 1), w(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];

    // dp(i, j) 表示 [i,..,n] 个物品, 体积不超过 j 的最大价值
    // 为了输出字典序最小的方案, dp(i, j) 反过来定义
    // 因此第一维是 n + 2, 从 1 到 n + 1
    vector<vector<int>> dp(n + 2, vector<int>(V + 1, 0));

    // f(i, j) 表示在 dp(i, j) 中是否取了第 i 个物品
    vector<vector<int>> f(n + 2, vector<int>(V + 1, 0));

    // c(i, j) 表示在达成 dp(i, j) 的方案数
    vector<vector<int>> c(n + 2, vector<int>(V + 1, 0));
    // 由于 dp(i, j) 反过来定义, 需要初始化 c[n + 1] 为 0
    fill(c[n + 1].begin(), c[n + 1].end(), 1);

    for (int i = n; i >= 1; i--) {
        for (int j = 0; j <= V; j++) {
            dp[i][j] = dp[i + 1][j];
            f[i][j] = 0, c[i][j] = c[i + 1][j];  // 第一种情况不取 物品i, f[i][j] = 0
            if (j - v[i] >= 0) {
                int tmp = dp[i + 1][j - v[i]] + w[i];
                if (tmp > dp[i][j]) {           // 第三种情况, 取了 物品i 后最大价值变大
                    dp[i][j] = tmp;
                    f[i][j] = 1, c[i][j] = c[i + 1][j - v[i]];
                } else if (tmp == dp[i][j]) {   // 第二种情况, 取了物品i 后最大价值不变
                    f[i][j] = 1;                // 只要 tmp == dp[i][j], 就优先取 物品i, 保证字典序最小
                    c[i][j] = ((LL) c[i][j] + c[i + 1][j - v[i]]) % MOD;
                }
            }
        }
    }
    // 输出最大价值
    cout << dp[1][V] <<'\n';
    
    // 输出最大价值的方案数
    cout << c[1][V] << '\n';
    
    // 输出字典序最小的方案
    vector<int> ans;
    for (int i = 1, j = V; i <= n; i++) {
        if (f[i][j]) ans.push_back(i), j -= v[i];  // 取了 物品i
    }
    for (int i = 0; i < (int) ans.size() ; i++) cout << ans[i] << " \n"[i == ans.size() - 1];
    return 0;
}
```
</details>

# 数据规模与限制
* $0 \lt N \le 1000, 0 \lt V \le 3000$  
* $0\lt v_i, w_i \le 1000$

# 来源
* [acwing: 11.背包问题求方案数](https://www.acwing.com/problem/content/11/)
* [acwing: 12.背包问题求具体方案](https://www.acwing.com/problem/content/12/)