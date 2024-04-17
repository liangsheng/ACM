# 题目描述

给一个 $n(1 \leq n \leq 10^5)$ 个点 $m(1 \leq m\leq 2 \cdot 10^5 )$ 条边的 **<font color="#FF0000">无向图，所有边权都为正</font>**，求 $s$ 到 $t$ 的最短路。

# 输入格式

第一行四个由空格隔开的整数 $n, m, s, t$。  
之后的 $m$ 行，每行三个正整数 $u_i, v_i, w_i(1 \leq w_i \leq 10^4)$，表示一条从 $u_i$ 到 $v_i$ 长度为 $w_i$ 的边。

# 输出格式

一个整数表示从 $s$ 到 $t$ 的最短路长度。数据保证至少存在一条道路。

```input1
7 11 5 4
2 4 2
1 4 3
7 2 2
3 4 3
5 7 4
7 3 1
6 1 1
6 3 3
2 4 3
5 6 3
7 2 1
```

```output1
7
```

# 提示

**【样例 #1 解释】**
* 推荐一个在线画图工具, [graph_editor](https://csacademy.com/app/graph_editor/)

![img](file://graph.png)

* $n(1 \leq n \leq 10^5)$，需要用堆优化的 $dijkstra$ 算法通过此题，时间复杂度是 $O(n \cdot log(m))$

<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

```c++
#include <bits/stdc++.h>
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
using namespace std;
typedef pair<int, int> pii;

const int N = 100005, M = 200005 * 2;
const int INF = numeric_limits<int>::max() / 2;

/*-------------------------- 邻接表存储 begin -------------*/
int n, m, s, t, e;
int head[N], pnt[M], nxt[M], wv[M];

void init() {
    e = 0;
    // 注意搞清楚是 0 到 n - 1, 还是 1 到 n
    fill(head, head + n + 1, -1);
}

void add_edge(int u, int v, int w) {
    pnt[e] = v, wv[e] = w;
    nxt[e] = head[u], head[u] = e++;
}
/*-------------------------- 邻接表存储 end ---------------*/

/*------------- 堆优化 dijkstra最短路 O(nlog(m)) begin ----*/

int d[N];  // d[i] 表示从起点 s 到 i 的最短距离
int f[N];  // f[i] = 1 表示 s 到 i 的最短距离已经算出

void dijkstra_heap(int s) {
    for (int i = 1; i <= n; i++) d[i] = INF, f[i] = 0;
    d[s] = 0;
    priority_queue<pii> q;
    d[s] = 0, q.push({-d[s], s});  // 由于要找最小, 所以插入负数
    while (!q.empty()) {

        // 每轮都从 f[i] == 0 的点中, 找到 d[i] 最小的点
        auto [w, p] = q.top();
        q.pop();
        if (f[p]) continue;  // 跳过 f[i] = 1 的点

        // 把点 p 标记为已经求出最短路, 并用 d[p] 更新其他点的 d[i]
        f[p] = 1;
        repe (i, p) {
            int v = pnt[i], tmp = d[p] + wv[i];
            if (tmp < d[v]) q.push({-(d[v] = tmp), v});
        }
    }
}
/*------------- 堆优化 dijkstra最短路 O(nlog(m)) end ------*/

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int s, t, u, v, w;
    cin >> n >> m >> s >> t;
    init();  // add_edge() 前一定要 init()
    while (m--) {
        cin >> u >> v >> w;
        add_edge(u, v, w);  // 有向图只添加 1 条边
        add_edge(v, u, w);  // 无向图要添加 2 条边
    }
    dijkstra_heap(s);
    cout << d[t] << '\n';
    return 0;
}
```

</details>

# 数据规模与限制
* $2 \leq n \leq 10^5$
* $1 \leq m \leq 2 \cdot 10^5$
* $1 \leq w_i \leq 10^4$
* **<font color="#FF0000">提交语言请选择 C++17(O2), 执行速度会快很多</font>**

# 来源
* [acwing: 850.Dijkstra求最短路 II](https://www.acwing.com/problem/content/852/)