# 题目描述
有 $N$ 个物品和一个容量是 $V$ 的背包。

**<font color="#FF0000">物品之间具有依赖关系，且依赖关系组成一棵树的形状。如果选择一个物品，则必须选择它的父节点</font>**。

如下图所示：  
![img](file://有依赖的背包.png)

如果选择物品5，则必须选择物品1和2。这是因为2是5的父节点，1是2的父节点。

每件物品的编号是 $i$，体积是 $v_i$，价值是 $w_i$，依赖的父节点编号是 $p_i$。物品的下标范围是 $1 … N$。

求解将哪些物品装入背包，可使物品总体积不超过背包容量，且总价值最大。

输出最大价值。

# 输入格式

第一行有两个整数 $N，V$，用空格隔开，分别表示物品个数和背包容量。

接下来有 $N$ 行数据，每行数据表示一个物品。  
第 $i$ 行有三个整数 $v_i, w_i, p_i$，用空格隔开，分别表示物品的体积、价值和依赖的物品编号。  
如果 $p_i = -1$，表示根节点。 **<font color="#FF0000">数据保证所有物品构成一棵树。</font>**

# 输出格式

输出一个整数，表示最大价值。

```input1
5 7
2 3 -1
2 2 1
3 5 1
4 7 2
3 6 2
```

```output1
11
```

# 提示
**【样例解释 1】**
* 可以选择 物品1，物品2，物品5
* 总体积：2 + 2 + 3 = 7
* 总价值：3 + 2 + 6 = 11
* 且满足依赖关系

<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

* 状态设计
  * $dp(i, j)$ 表示以 $i$ 为节点的子树，**<font color="#FF0000">体积恰好为$j$（不是不超过）</font>** 的情况下的最大价值 
  * 思考下，**<font color="#FF0000">恰好为 $j$</font>** 和 **<font color="#FF0000">不超过 $j$</font>** 的区别
  * 01 背包如果用 **<font color="#FF0000">恰好为 $j$</font>** 表示，有什么不同
* 状态转移
  * 将 $i$ 的每个叶子节点看作一个物品组，用类似分组背包的方法来转移

```c++
#include <bits/stdc++.h>
using namespace std;

const int N = 105, M = 105, INF = ~0U >> 2;

int n, V;
int v[N], w[N];
int dp[N][M];
vector<vector<int>> g;  // 二维 vector, 用来存储每个节点的儿子节点

void dfs(int u, int fa) {
    // dp[u][j] 表示以 u 为节点的子树中, 体积恰好为 j （不是不超过 j）的最大价值
    // -1 表示不存在
    for (int i = 0; i <= V; i++) dp[u][i] = -1;
    dp[u][0] = 0;
    if (v[u] <= V) dp[u][v[u]] = w[u];
    // 遍历所有儿子节点
    for (int x : g[u]) {
        dfs(x, u);
        // 类似分组背包的写法, 儿子节点的 dp[v] 就是一组物品, 这一组物品里只能选一个
        for (int i = V; i >= 0; i--) {
            for (int j = 0; j <= i - v[u]; j++) {
                // 由于状态是 "体积恰好为 j", 所以需要判断状态是否存在
                if (dp[u][i - j] >= 0 && dp[x][j] >= 0) {
                    dp[u][i] = max(dp[u][i], dp[u][i - j] + dp[x][j]);
                }
            }
        }
    }
}

int main() {
    // 下面两句是为了让 cin 更快
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int r, x;
    cin >> n >> V;
    g = vector<vector<int>>(n + 1, vector<int>());
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i] >> x;
        if (x != -1) g[x].push_back(i);
        else r = i;
    }
    dfs(r, -1);

    // 由于状态是 "体积恰好为 j", 所以结果不是 dp[r][V]
    // 而是 dp[r] 里的最大值
    int ans = -INF;
    for (int i = 0; i <= V; i++) ans = max(ans, dp[r][i]);
    cout << ans << '\n';
    return 0;
}
```

</details>

# 数据规模与限制
* $1 \le N, V \le 100$  
* $1 \le v_i, w_i\le 100$
* 父节点编号范围：
* 内部结点：$1 \le p_i \le N$;
* 根节点 $p_i = -1$;

# 来源
* [acwing: 10.有依赖的背包问题](https://www.acwing.com/problem/content/description/10//)