- [第一讲：01背包](#第一讲01背包)
- [第二讲：完全背包](#第二讲完全背包)
- [第三讲：多重背包](#第三讲多重背包)
- [第四讲：混合背包](#第四讲混合背包)
- [第五讲：二维费用背包](#第五讲二维费用背包)
- [第六讲：分组背包](#第六讲分组背包)
- [第七讲：有依赖背包](#第七讲有依赖背包)
- [第八讲：泛化物品](#第八讲泛化物品)
- [第九讲：背包问题的其他问法](#第九讲背包问题的其他问法)

* [传说中的《背包九讲》](file://背包九讲_2.0.pdf)
# 第一讲：01背包
* [P1082.【入门】01背包](http://www.gzezoi.cn/d/gzezoi2023/p/P1082)
* 关键字：**<font color="#FF0000">每个物品最多只能使用一次</font>**
* 状态设计：$dp(i, j)$ 表示从前 $i$ 个物品中选出体积不超过 $j$ 的物品时的最大价值
* 状态转移
$$
\begin{equation}
dp(i,j) = \left\{
\begin{array}{lr}
dp(i-1,j), & 不使用第i个物品 \\
dp(i-1,j-v(i))+w(i), & 使用第i个物品
\end{array}
\right.
\end{equation}
$$

<details>
  <summary> 原始写法：2维数组写法 </summary>

```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, V, v, w;
    cin >> n >> V;
    vector<vector<int>> dp(n + 1, vector<int>(V + 1, 0));
    for (int i = 1; i <= n; i++) {
        cin >> v >> w;
        for (int j = 0; j <= V; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - v >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v] + w);
            }
        }
    }
    cout << dp[n][V] << '\n';
    return 0;
}
```
</details>

<details>
  <summary> 简单写法：滚动维数组写法 </summary>

```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, V, v, w, now = 0, pre = 1;
    cin >> n >> V;
    vector<vector<int>> dp(2, vector<int>(V + 1, 0));
    for (int i = 1; i <= n; i++) {
        swap(now, pre);
        fill(dp[now].begin(), dp[now].end(), 0);
        cin >> v >> w;
        for (int j = 0; j <= V; j++) {
            dp[now][j] = dp[pre][j];
            if (j - v >= 0) {
                dp[now][j] = max(dp[now][j], dp[pre][j - v] + w);
            }
        }
    }
    cout << dp[now][V] << '\n';
    return 0;
}
```
</details>

<details>
  <summary> 最简写法：1维数组写法 </summary>

```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, V, v, w;
    cin >> n >> V;
    vector<int> dp(V + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v >> w;
        for (int j = V; j >= v; j--) {
            dp[j] = max(dp[j], dp[j - v] + w);
        }
    }
    cout << dp[V] << '\n';
    return 0;
}
```
</details>

# 第二讲：完全背包
* [P1083.【入门】完全背包](http://www.gzezoi.cn/d/gzezoi2023/p/P1083)
* 关键字：**<font color="#FF0000">每个物品可以使用无数次</font>**
* 状态设计：$dp(i, j)$ 表示从前 $i$ 个物品中选出体积不超过 $j$ 的物品时的最大价值
* 状态转移（**<font color="#FF0000">注意使用第 $i$ 个物品的情况</font>**）
$$
\begin{equation}
dp(i,j) = \left\{
\begin{array}{lr}
dp(i-1,j), & 不使用第i个物品 \\
dp(i,j-v(i))+w(i), & 使用第i个物品
\end{array}
\right.
\end{equation}
$$

<details>
  <summary> 原始写法：2维数组写法 </summary>

```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, V, v, w;
    cin >> n >> V;
    vector<vector<int>> dp(n + 1, vector<int>(V + 1, 0));
    for (int i = 1; i <= n; i++) {
        cin >> v >> w;
        for (int j = 0; j <= V; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - v >= 0) {
                dp[i][j] = max(dp[i][j], dp[i][j - v] + w);
            }
        }
    }
    cout << dp[n][V] << '\n';
    return 0;
}
```
</details>

<details>
  <summary> 最简写法：1维数组写法 </summary>

```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, V, v, w;
    cin >> n >> V;
    vector<int> dp(V + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v >> w;
        // for (int j = V; j >= v; j--) {  // 01背包
        for (int j = v; j <= V; j++) {  // 完全背包
            dp[j] = max(dp[j], dp[j - v] + w);
        }
    }
    cout << dp[V] << '\n';
    return 0;
}
```
</details>

# 第三讲：多重背包
* [P1084.【入门】多重背包](http://www.gzezoi.cn/d/gzezoi2023/p/P1084)
* 关键字：**<font color="#FF0000">每个物品都有各自的数量</font>**
* 状态设计，状态转移同 01 背包
* 可以将物品的数量进行 **<font color="#FF0000">二进制拆分</font>**
* 假设某个物品的数量是 10，体积是 $v$，价值是 $w$
* 将 10 表示成 $10=2^0+2^1+2^2+3=1+2+4+3$
* 我们可以将这个物品拆分成 4 个物品
  * 物品 1：体积 1 * v，价值 1 * w 
  * 物品 2：体积 2 * v，价值 2 * w 
  * 物品 3：体积 4 * v，价值 4 * w 
  * 物品 4：体积 3 * v，价值 3 * w
* 不管原来的物品取了多少个，都可以有拆分成的新的 4 个物品组合而成
* 因此，可以将所有的物品都按照上述方法拆分，然后做按 01背包求解 

<details>
  <summary> 最简写法：1维数组写法 </summary>

```c++
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    // 下面两句是为了让 cin 更快
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, V, v, w, s;
    cin >> n >> V;
    vector<int> dp(V + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v >> w >> s;
        // 可以用有限次, 多重背包, 二进制拆分
        for (int d = 1; s > 0; d *= 2) {
            int c = min(d, s), nv = c * v, nw = c * w;
            for (int j = V; j >= nv; j--) {
                dp[j] = max(dp[j], dp[j - nv] + nw);
            }
            s -= c;
        }
    }
    cout << dp[V] << '\n';
    return 0;
}
```
</details>

# 第四讲：混合背包
* [P1085.【入门】混合背包](http://www.gzezoi.cn/d/gzezoi2023/p/P1085)
* 关键字：**<font color="#FF0000">有的物品只有 1 个，有的物品有无数个，有的物品有有限个数</font>**
* 状态设计，状态转移同 01 背包
* 按照物品种类，分类讨论

<details>
  <summary> 最简写法：1维数组写法 </summary>

```c++
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    // 下面两句是为了让 cin 更快
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, V, v, w, s;
    cin >> n >> V;
    vector<int> dp(V + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v >> w >> s;
        if (s == -1) {        // 只能用 1 次, 01背包
            for (int j = V; j >= v; j--) {
                dp[j] = max(dp[j], dp[j - v] + w);
            }
        } else if (s == 0) {  // 可以用无限次, 完全背包
            for (int j = v; j <= V; j++) {
                dp[j] = max(dp[j], dp[j - v] + w);
            }
        } else {              // 可以用有限次, 多重背包, 二进制拆分, 然后 01 背包
            for (int d = 1; s > 0; d *= 2) {
                int c = min(d, s), nv = c * v, nw = c * w;
                for (int j = V; j >= nv; j--) {
                    dp[j] = max(dp[j], dp[j - nv] + nw);
                }
                s -= c;
            }
        }
    }
    cout << dp[V] << '\n';
    return 0;
}
```
</details>

# 第五讲：二维费用背包
* [P1086.【入门】二维费用背包](http://www.gzezoi.cn/d/gzezoi2023/p/P1086)
* 关键字：**<font color="#FF0000">背包和物品除了有容量 $V$ 限制，还有重量 $M$ 限制</font>**
* 状态设计：$dp(i,j,k)$ 表示前 $i$ 个物品，体积不超过 $j$，重量不超过 $k$ 的情况下的最大价值
* 状态转移:
$$
\begin{equation}
dp(i,j,k) = \left\{
\begin{array}{lr}
dp(i-1,j,k), & 不使用第i个物品 \\
dp(i-1,j-v(i),k-m(i))+w(i), & 使用第i个物品
\end{array}
\right.
\end{equation}
$$

<details>
  <summary> 最简写法：1维数组写法 </summary>

```c++
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    // 下面两句是为了让 cin 更快
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, V, M, v, m, w;
    cin >> n >> V >> M;
    vector<vector<int>> dp(V + 1, vector<int>(M + 1, 0));
    for (int i = 0; i < n; i++) {
        cin >> v >> m >> w;
        for (int j = V; j >= v; j--) for (int k = M; k >= m; k--) {
            dp[j][k] = max(dp[j][k], dp[j - v][k - m] + w);
        }
    }
    cout << dp[V][M] << '\n';
    return 0;
}
```
</details>

# 第六讲：分组背包
* [P1087.【入门】分组背包](http://www.gzezoi.cn/d/gzezoi2023/p/P1087)
* 关键字：**<font color="#FF0000">有多组物品，同一组内的物品最多只能选一个</font>**
* 状态设计，状态转移同 01背包
* **<font color="#FF0000">从大到小枚举体积 $j$ 时，依次用组里每个物品去更新 $dp[j]$ </font>**

<details>
  <summary> 最简写法：1维数组写法 </summary>

```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, V, s;
    cin >> n >> V;
    vector<int> dp(V + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> s;
        vector<int> v(s), w(s);
        for (int j = 0; j < s; j++) cin >> v[j] >> w[j];
        // 从大到小枚举体积 j 时，依次用组里每个物品去更新 dp[j]
        for (int j = V; j >= 0; j--) {
            for (int k = 0; k < s; k++) {
                if (j >= v[k]) dp[j] = max(dp[j], dp[j - v[k]] + w[k]);
            }
        }
    }
    cout << dp[V] << '\n';
    return 0;
}
```
</details>

# 第七讲：有依赖背包
* [P1088.有依赖的背包](http://www.gzezoi.cn/d/gzezoi2023/p/P1088)
* 关键字：**<font color="#FF0000">物品之间具有依赖关系，且依赖关系组成一棵树的形状。如果选择一个物品，则必须选择它的父节点</font>**
* 状态设计
  * $dp(i, j)$ 表示以 $i$ 为节点的子树，**<font color="#FF0000">体积恰好为$j$（不是不超过）</font>** 的情况下的最大价值 
  * 思考下，**<font color="#FF0000">恰好为 $j$</font>** 和 **<font color="#FF0000">不超过 $j$</font>** 的区别
  * 01 背包如果用 **<font color="#FF0000">恰好为 $j$</font>** 表示，有什么不同
* 状态转移
  * 将 $i$ 的每个叶子节点看作一个物品组，用类似分组背包的方法来转移

<details>
  <summary> 数形动态规划写法 </summary>

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

# 第八讲：泛化物品
# 第九讲：背包问题的其他问法
* [P1093.【入门】求背包的具体方案](http://www.gzezoi.cn/d/gzezoi2023/p/P1093)
* 关键字：**<font color="#FF0000">需要输出最优方案数，以及字典序最小的方案详情</font>**
* 状态设计：
* $dp(i, j)$ 表示 $[i,..,n]$ 个物品, 体积不超过 $j$ 的最大价值，为了计算字典序最小的方案，将 $dp(i, j)$ 倒过来
* $f(i, j)$ 表示在 $dp(i, j)$ 中是否取了第 $i$ 个物品
* $c(i, j)$ 表示在达成 $dp(i, j)$ 的方案数

<details>
  <summary> 2 维数组写法 </summary>

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
                } else if (tmp == dp[i][j]) {   // 第二种情况, 取了 物品i 后最大价值不变
                    f[i][j] = 1;                // 只要 tmp == dp[i][j], 就优先取物品i, 保证字典序最小
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