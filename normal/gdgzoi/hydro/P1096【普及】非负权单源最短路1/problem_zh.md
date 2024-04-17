# 题目描述

给一个 $n(1 \leq n \leq 2500)$ 个点 $m(1 \leq m\leq 6200 )$ 条边的 **<font color="#FF0000">无向图，所有边权都为正</font>**，求 $s$ 到 $t$ 的最短路。

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

* 可以用 $O(n^2)$ 的朴素 $dijkstra$ 算法通过此题

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
int n, m, e;
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

/*------------------- dijkstra最短路 O(n^2) begin ---------*/

int d[N];   // d[i] 表示从起点 s 到 i 的最短距离
bool f[N];  // f[i] = 1, 表示点 i 已经求出最短路径

void dijkstra(int s) {
    for (int i = 1; i <= n; i++) d[i] = INF, f[i] = 0;
    d[s] = 0;
    for (int k = 1; k <= n; k++) {

        // 每轮都从 f[i] == 0 的点中, 找到 d[i] 最小的点
        int p = -1;
        for (int i = 1; i <= n; i++) {
            if (f[i]) continue;
            if (p == -1 || d[i] < d[p]) p = i;
        }
        
        if (d[p] == INF) break;  // 图不联通
        // 把点 p 标记为已经求出最短路, 并用 d[p] 更新其他点的 d[i]
        f[p] = 1;
        repe (i, p) {
            int v = pnt[i], tmp = d[p] + wv[i];
            if (tmp < d[v]) d[v] = tmp;
        }
    }
}
/*------------------- dijkstra最短路 O(n^2) end -----------*/


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
    dijkstra(s);
    cout << d[t] << '\n';
    return 0;
}
```

</details>

# 数据规模与限制
* $2 \leq n \leq 2500$
* $1 \leq m \leq 6200$
* $1 \leq w_i \leq 10^4$
* **<font color="#FF0000">提交语言请选择 C++17(O2), 执行速度会快很多</font>**

# 来源
* [loj: 119.单源最短路](https://loj.ac/p/119)