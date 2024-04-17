- [1、图的存储与表示](#1图的存储与表示)
  - [1-1、图的基本术语](#1-1图的基本术语)
  - [1-2、邻接矩阵表示](#1-2邻接矩阵表示)
  - [1-3、二维 vector 表示](#1-3二维-vector-表示)
  - [1-4、链式前向星](#1-4链式前向星)
- [2、最短路问题](#2最短路问题)
  - [2-1、非负权单源最短路（dijkstra）](#2-1非负权单源最短路dijkstra)
  - [2-2、非负权单源最短路（dijkstra+heap）](#2-2非负权单源最短路dijkstraheap)
  - [2-3、带负权单源最短路（spfa+heap）](#2-3带负权单源最短路spfaheap)
  - [2-4、边数有限制最短路](#2-4边数有限制最短路)
  - [2-5、多源多汇最短路（floyd）](#2-5多源多汇最短路floyd)
- [3、最短路算法总结](#3最短路算法总结)

# 1、图的存储与表示
* 推荐一个在线画图工具, [graph_editor](https://csacademy.com/app/graph_editor/)

## 1-1、图的基本术语
* **<font color="#FF0000">图是顶点和边的集合</font>**，我们一般把顶点的集合为 $V$，边的集合为 $E$ 的图记为 $G=(V,E)$；
* 图中的边有明确方向的（只能从 $u$ 到 $v$，不能从 $v$ 到 $u$），我们称之为 **<font color="#FF0000">有向图</font>**（比如马路上的单行线）
* 图中的边没有明确方向的（既可以 $u$ 到 $v$，也可以从 $v$ 到 $u$），我们称之为 **<font color="#FF0000">无向图</font>**（比如双向车道）

![img](file://图.png)

* 两个顶点之间如果有边相连，那么就称这两个顶点相邻。相邻顶点的序列成为 **<font color="#FF0000">路径</font>**。起点和重点重合的路径叫做 **<font color="#FF0000">圈或者环</font>**；
* 任意两点之间都有路劲相连接的图叫做 **<font color="#FF0000">连通图</font>**

![img](file://路和环.png)

## 1-2、邻接矩阵表示
* 可以用 $|V|*|V|$ 的二维数组 $g$ 来表示图，$g[i][j]$ 表示顶点 $i$ 与顶点 $j$ 的关系。

![img](file://邻接矩阵.png)

* 左图中 顶点0 和 顶点1 的边权是 2，那么二维数组中 $g[0][1] = 2$，如果是无向图，还需要同时设置 $g[1][0] = 2$
* 顶点自己到自己设置为 0，$g[i][i] = 0$
* 图中不存在的边这是为不存在（比如 $\infty$），比如 顶点2 和 顶点0 之间没有边，那么 $g[2][0] = \infty$

<details>
  <summary> <font color="#00BB00">点击查看：邻接矩阵存储图</font> </summary>

```c++
// INF 表示无穷大
const int N = 105, INF = 100000000;

int n, m, u, v, w;
int g[N][N];

// n: 顶点个数, m: 边的条数
cin >> n >> m;
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) g[i][j] = INF;
    g[i][i] = 0;
}
for (int i = 1; i <= m; i++) {
    // 顶点u 和 顶点v 之间有一条权值为 w 的边
    cin >> u >> v >> w;
    g[u][v] = w;  // 如果是有向图, 只需要设置 g[u][v]
    g[v][u] = w;  // 如果是无向图, 需要同时设置 g[v][u] = w;
}
```
</details>

* **<font color="#00BB00">邻接矩阵表示的优点</font>**
  * 1、简单直观
  * 2、可以快速（$O(1)$）的得知 2 个顶点之间的边的情况
* **<font color="#FF0000">邻接矩阵表示的缺点</font>**
  * 需要 $|V| * |V|$ 的存储空间，当点的个数 $n \geq 10000$ 时，不能申请如此大的二维数组 
* **<font color="#00BB00">因此，只有当 $n \leq 2500$ 左右，我们才会使用邻接矩阵</font>**

![img](file://重边和自环.png)

* 还需要注意的是
  * 当图中有重边（2 点之间有不止 1 条边）时，$g[i][j]$ 中保存的边权需要按题意选择（比如最大或最小）
  * 当图中有自环（顶点自己到自己的边）时，要特殊处理（比如忽略等）

## 1-3、二维 vector 表示
* 当点的个数较多（比如 $n=10^5$） 时，且边的条数又不太多（比如 $m=2\cdot 10^5$）时，我们称这样的图为 **<font color="#FF0000">稀疏图</font>**
* 我们可以通过存储 “从 顶点0 出发有到顶点 2，4，5的边”这样的信息来表示图，这样只需要 $O(|V|+|E|)$ 的存储空间

![img](file://邻接表.png)

* 邻接表可以用二维 vector 实现
<details>
  <summary> <font color="#00BB00">点击查看：二维 vector 存储图</font> </summary>

```c++
int n, m, u, v, w;

// n: 顶点个数, m: 边的条数
cin >> n >> m;
vector<vector<pair<int, int>>> g(n);
// vector g(n, vector<int>());  // 也可以这样写, 短一些

for (int i = 1; i <= m; i++) {
    // 顶点u 和 顶点v 之间有一条权值为 w 的边
    cin >> u >> v >> w;
    g[u].push_back({v, w});  // 表示从 u 出发有一条到 v 的边, 权值为 w
    g[v].push_back({u, w});  // 如果是无向图, 需要同时设置 g[v]
}

// 遍历图中的点和边
for (int u = 0; u < n; u++) {
    cout << "u= " << u << '\n';
    for (auto [v, w]: g[u]) {
        cout << "v= " << v << ", w= " << w << '\n';
    }
}
```
</details>

* **<font color="#00BB00">二维 vector 表示的优点</font>**
  * 1、简单直观
  * 2、在稀疏图上节省空间
* **<font color="#FF0000">二维 vector 表示的缺点</font>**
  * 二维 vector 在访问时会比较耗时

## 1-4、链式前向星
* **<font color="#00BB00">如果既想节省空间，又不想承受二维 vector 带来的耗时，可以使用链式前向星表示法；</font>**
* **<font color="#00BB00">事实上，链式前向星表示法是最主流的方法</font>**

![img](file://链式前向星.png)

* 用一个结构体数组将边信息存起来，包含 4 个参数
  * 起点$u$，终点$v$，边权$w$
  * next：表示和本条边起点相同的上一条边的序号
  * 右表中颜色相同的边是起点相同的边，比如序号为 5 的边的 next 是 1，而序号为 1 的边没有上一条边，就把 next 设置为 -1
* 然后对每个 顶点$u$，都存储一个最靠后的边的序号，用 $head[u]$ 记录
  * 比如 $head[5]=7$，表示从 顶点5 出发的最靠后的一条边的序号是 7
  * 我们又可以通过 $next[7]=2$，找到从 顶点5 出发的另一条边

<details>
  <summary> <font color="#00BB00">点击查看：结构体链式前向星存储图</font> </summary>

```c++
// N: 顶点的最大个数, M: 边的最大条数
const int N = 100005, M = 200005;

struct Edge {
    // next 表示和本条边起点相同的上一条边的序号
    int u, v, w, next;
} edge[M];

int n, m, e, head[N];

void init(int n) {
    e = 0;  // e: 表示边的条数, 初始化为 0
    for (int i = 0; i <= n; i++) head[i] = -1;  // 初始化 head[i] = -1;
}

void add_edge(int u, int v, int w) {
    edge[e].u = u, edge[e].v = v, edge[e].w = w;
    // edge[e] 的 next 设置为 head[u], 而 head[u] 更新为当前的 e
    // 最后把边的条数 e++
    edge[e].next = head[u], head[u] = e++;
}

// n: 顶点个数, m: 边的条数
cin >> n >> m;
init(n);  // add_edge() 前一定记得 init
for (int i = 1; i <= m; i++) {
    // 顶点u 和 顶点v 之间有一条权值为 w 的边
    cin >> u >> v >> w;
    add_edge(u, v, w);  // 表示从 u 出发有一条到 v 的边, 权值为 w
    add_edge(v, u, w);  // 如果是无向图, 需要同时添加反向边
}

// 遍历图中的点和边
for (int u = 1; u <= n; u++) {
    cout << "u= " << u << '\n';
    for (int i = head[u]; i != -1; i = edge[i].next) {
        cout << "v= " << edge[i].v << ", w= " << edge[i].w << '\n';
    }
}
```
</details>

* 不喜欢用结构体的同学，也可以多开几个数组来实现

<details>
  <summary> <font color="#00BB00">点击查看：链式前向星存储图（不用结构体）</font> </summary>

```c++
// N: 顶点的最大个数, M: 边的最大条数
const int N = 100005, M = 200005;

int n, m, e;
int head[N];  // 每个顶点序号最大的边的序号
int pnt[M];   // 每条边的终点
int wv[M];    // 每条边的权值
int nxt[M];   // 本条边起点相同的上一条边的序号
// 还可以开一个数组将每条边的起点也存起来

void init(int n) {
    e = 0;  // e: 表示边的条数, 初始化为 0
    for (int i = 0; i <= n; i++) head[i] = -1;  // 初始化 head[i] = -1;
}

void add_edge(int u, int v, int w) {
    pnt[e] = v, wv[e] = w;
    // edge[e] 的 next 设置为 head[u], 而 head[u] 更新为当前的 e
    // 最后把边的条数 e++
    nxt[e] = head[u], head[u] = e++;
}

// n: 顶点个数, m: 边的条数
cin >> n >> m;
init(n);  // add_edge() 前一定记得 init
for (int i = 1; i <= m; i++) {
    // 顶点u 和 顶点v 之间有一条权值为 w 的边
    cin >> u >> v >> w;
    add_edge(u, v, w);  // 表示从 u 出发有一条到 v 的边, 权值为 w
    add_edge(v, u, w);  // 如果是无向图, 需要同时添加反向边
}

// 遍历图中的点和边
for (int u = 1; u <= n; u++) {
    cout << "u= " << u << '\n';
    for (int i = head[u]; i != -1; i = nxt[i]) {
        cout << "v= " << pnt[i] << ", w= " << wv[i] << '\n';
    }
}
```
</details>

# 2、最短路问题
* **<font color="#00BB00">最短路是给定 2 个顶点，在以这两个点为起点和终点的路劲中，边权和最小的路径；</font>**
* 比如顶点是城市，边是城市间的高速公路的通行时间，最短路就是求两个城市之间的最短同行时间

## 2-1、非负权单源最短路（dijkstra）
* 最简单的最短路问题：[P1096.【普及】非负权单源最短路1](http://www.gzezoi.cn/d/gzezoi2023/p/P1096)
  * **<font color="#00BB00">图比较小</font>**：顶点数 $n \leq 2500$，边数 $m \leq 6200$
  * **<font color="#00BB00">所有的边权都是非负的</font>**
* 用来解决这类问题的算法是 dijkstra 最短路算法
* 我们以样例1 为例，用 dijkstra 算法求 顶点5 到 顶点4 的最短路

![img](file://朴素dijkstra.png)

* 申请一个数组 $d[N]$，$d[i]$ 表示从起点到 $i$ 的最短距离，$d[5]=0$，其他点 $d[i]=\infty$
* 申一个数组 $f[N]$，$f[i]$ 表示是否已经求出起点到 $i$ 的最短距离，$f[i]$ 全部初始化为 $f[i]=0$
* dijkstra 算法总共执行 $n$ 轮，每轮从 $f[i]==0$ 的点中选取 $d[i]$ 最小的点，记为 $p$
  * 标记 $f[p] = 1$
  * 并用 $d[p]$ 更新其他点 $i$ 的 $d[i]$
  * 由于边权都是非负的，可以证明每轮中的 $d[p]$ 是从其点到点 $p$ 的最短路
* 右表中
  * **<font color="#FF8000">橙色的点</font>**：之前已经计算出最短路的点（$f[i] == 1$）
  * **<font color="#00BB00">绿色的点</font>**：本轮中选取的 $d[i]$ 最小的点

<details>
  <summary> <font color="#00BB00">点击查看：朴素 dijkstra 算法</font> </summary>

```c++
#include <bits/stdc++.h>
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
using namespace std;
typedef pair<int, int> pii;

const int N = 2500, M = 6205 * 2;
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

* 由于每轮中，都要遍历 $d[i]$ 选取最小值，需要 $O(n)$ 的时间
* 因此 **<font color="#FF0000">dijkstra 算法的时间复杂度是 $O(n^2)$</font>**，对于 $n \leq 10^4$ 的图，dijkstra 算法会很耗时

## 2-2、非负权单源最短路（dijkstra+heap）
* 在朴素 dijkstra 的找最小值这一步，可以通过将 $d[i]$ 放到一个最小堆里（priority_queue） 中，只需要 $O(log(n))$ 就可以得到最小值
* 例题：[P1097.【普及】非负权单源最短路2](http://www.gzezoi.cn/d/gzezoi2023/p/P1097)
  * **<font color="#00BB00">点数较多的稀疏图</font>**：顶点数 $n = 10^5$，边数 $m = 2 \cdot 10^5$
  * **<font color="#00BB00">所有的边权都是非负的</font>**

![img](file://堆优化1.png)

![img](file://堆优化2.png)

<details>
  <summary> <font color="#00BB00">点击查看：堆优化 dijkstra 算法</font> </summary>

```c++
/*------------- 堆优化 dijkstra最短路 O(nlog(m)) begin ----*/
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])

int d[N];  // d[i] 表示从起点 s 到 i 的最短距离
int f[N];  // f[i] = 1 表示 s 到 i 的最短距离已经算出

void dijkstra_heap(int s) {
    for (int i = 1; i <= n; i++) d[i] = INF, f[i] = 0;
    d[s] = 0;
    priority_queue<pii> q;
    d[s] = 0, q.push({-d[s], s});  // 由于要找最小, 所以插入负数
    for (int k = 1; k <= n; k++) {

        // 每轮都从 f[i] == 0 的点中, 找到 d[i] 最小的点
        // 如果图不联通的话, q 就可能是空
        while (!q.empty() && f[q.top().second]) q.pop();  // 跳过 f[i] = 1 的点
        if (q.empty()) break;
        auto [w, p] = q.top();
        q.pop();

        // 把点 p 标记为已经求出最短路, 并用 d[p] 更新其他点的 d[i]
        f[p] = 1;
        repe (i, p) {
            int v = pnt[i], tmp = d[p] + wv[i];
            if (tmp < d[v]) q.push({-(d[v] = tmp), v});
        }
    }
}
/*------------- 堆优化 dijkstra最短路 O(nlog(m)) end ------*/
```
</details>

* 可以将枚举轮数和从 priority_queue 中取数合并下，写法更简单

<details>
  <summary> <font color="#00BB00">点击查看：堆优化 dijkstra 算法（简洁写法）</font> </summary>

```c++
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
        // cout << "p= " << p << ", d[p]= " << d[p] << ", w= " << -w << '\n';
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
```
</details>

* 其实还可以更简单：
  * 由于边权都是非负的，**<font color="#FF0000">对于每次从 priority_queue 中弹出的点 $p$，$d[p]$ 必然是从起点到 $p$ 的最短距离（思考下为什么）</font>**
  * 因此只要 $d[p] \neq -w$，那点 $p$ 就必然是之前已经计算出最短路的点，这样就不用 $f[]$ 数组了

<details>
  <summary> <font color="#00BB00">点击查看：堆优化 dijkstra 算法（最简写法）</font> </summary>

```c++
/*------------- 堆优化 dijkstra最短路 O(nlog(m)) begin ----*/

int d[N];  // d[i] 表示从起点 s 到 i 的最短距离

void dijkstra_heap(int s) {
    for (int i = 1; i <= n; i++) d[i] = INF;
    d[s] = 0;
    priority_queue<pii> q;
    d[s] = 0, q.push({-d[s], s});  // 由于要找最小, 所以插入负数
    while (!q.empty()) {

        // 每轮都从 f[i] == 0 的点中, 找到 d[i] 最小的点
        auto [w, p] = q.top();
        q.pop();
        // cout << "p= " << p << ", d[p]= " << d[p] << ", w= " << -w << '\n';
        if (d[p] != -w) continue;  // dp[p] != -w 表示 p 已经访问过

        // 用 d[p] 更新其他点的 d[i]
        repe (i, p) {
            int v = pnt[i], tmp = d[p] + wv[i];
            if (tmp < d[v]) q.push({-(d[v] = tmp), v});
        }
    }
}
/*------------- 堆优化 dijkstra最短路 O(nlog(m)) end ------*/
```
</details>

* 事实上，这种最简写法还有一个名字，叫 <a id="spfa_heap">spfa_heap</a>
* 以上三种写法的时间复杂度都是 $O(nlog(m))$

## 2-3、带负权单源最短路（spfa+heap）
* 例题：[P1098.【普及】非负权单源最短路2](http://www.gzezoi.cn/d/gzezoi2023/p/P1098)
  * **<font color="#00BB00">点数较多的稀疏图</font>**：顶点数 $n = 10^5$，边数 $m = 2 \cdot 10^5$
  * **<font color="#00BB00">所有的边权都是非负的</font>**

* 朴素 dijkstra 无法处理带负环的有向图，比如

![img](file://带负权.png)

* 为什么？
* 因为在边权都非负的图中，**<font color="#FF0000">对于每次找到的 $d[p]$最小的点 $p$，$d[p]$ 必然是起点到点 $p$ 的最短距离</font>**
* **<font color="#FF0000">但在边权有负数的图中，不一定是这样</font>**
* 比如在样例二中：
  * 第 1 轮找到 $d[5] = 0$
  * 第 2 轮找到 $d[6] = 3$
* 但实际上，$5 \rightarrow 7 \rightarrow 3 \rightarrow 6$，可以让 $d[6] = -1$，是一条更短的路
* 因此每一轮最小的 $d[p]$，在后面还有可能被继续变小
* [spfa_heap](#spfa_heap) 写法，就可以做到上面的事情
* 事实上，可以将 spfa_heap 理解为
  * 但凡有哪个点 $p$ 的 $d[p]$ 可以变小
  * 就用 $d[p]$ 取更新点 $p$ 周围的点
  * 直到没有哪个点的 $d[p]$ 能变得更小 
  
![img](file://spfa_heap处理带负权1.png)

![img](file://spfa_heap处理带负权2.png)

* 但 $spfa\_heap$ 在处理有负环的图时会死循环
  * 样例一中，$2 \rightarrow 3 \rightarrow 4 \rightarrow 2$ 的权值和是 $2+3-6=-1$
  * 我们可以不断绕行这个权值和为负的环，这样最短路就可以无限小
* 因此，我们需要判断图中是否有负环
* 这个其实好办，我们可以记录 $c[i]$ 表示从起点到点 $i$ 的最短路经过了多少个点
* **<font color="#FF0000">如果 $c[i] > n$，也就是说从起点到点 $i$ 的最短路经过了超过 $n$ 个点</font>**
* **<font color="#FF0000">那么至少有 1 个点经过了不少于 2 次，而只有在有负环的情况下，才会出现这种现象</font>**

<details>
  <summary> <font color="#00BB00">点击查看：spfa_heap+判负环</font> </summary>

```c++
/*------------- spfa_heap+判负环 O(nlog(m)) begin ----------*/

int d[N];  // d[i] 表示从起点 s 到 i 的最短距离
int c[N];  // c[i] 表示从起点 s 到 i 的最短路中点的个数

bool spfa_heap(int s) {
    priority_queue<pii> q;
    for (int i = 1; i <= n; i++) d[i] = INF, c[i] = 0;
    c[s] = 1, d[s] = 0, q.push({-d[s], s});  // 每次取最小的, 所以插入的时候取负
    while (!q.empty()) {
        auto [w, u] = q.top();
        q.pop();
        if (d[u] != -w) continue;
        if (c[u] > n) return true;  // 某个点的最短路中点的个数超过 n, 说明有点重复, 那么有负环
        repe (i, u) {
            int v = pnt[i], tmp = d[u] + wv[i];
            if (tmp < d[v]) {
                c[v] = c[u] + 1;
                q.push({-(d[v] = tmp), v});
            }
        }
    }
    return false;
}
/*------------- spfa_heap+判负环 O(nlog(m)) end ------------*/
```
</details>

## 2-4、边数有限制最短路
* 例题：[P1099.【普及】有边数限制的最短路](http://www.gzezoi.cn/d/gzezoi2023/p/P1099)
  * **<font color="#00BB00">点不太多</font>**：顶点数 $n = 500$，边数 $m = 10000$
  * **<font color="#00BB00">最短路要求只经过不超过 $k$ 条边</font>**
* $d[v][c]$ 表示从起点到 $v$ 恰好经过 $c$ 条边的最短路，那么有
$$
d[v][c] = min\{d[u][c - 1] + w(u, v)\ | u 到 v 有一条边 \};
$$

<details>
  <summary> <font color="#00BB00">点击查看：边数有限制的最短路</font> </summary>

```c++
int d[N][N];  // d[i][j] 表示从起点 s 到 i, 刚好经过 j 条边的最短距离

void spfa(int s) {
    for (int i = 1; i <= n; i++) for (int j = 0; j <= k; j++) d[i][j] = INF;
    d[s][0] = 0;
    for (int t = 1; t <= k; t++) {
        for (int u = 1; u <= n; u++) if (d[u][t - 1] != INF) {
            repe (i, u) {
                int v = pnt[i], tmp = d[u][t - 1] + wv[i];
                if (tmp < d[v][t]) d[v][t] = tmp;
            }
        }
    }
}
```
</details>

## 2-5、多源多汇最短路（floyd）
* 例题：[P1100.【普及】求任意2点间最短路](http://www.gzezoi.cn/d/gzezoi2023/p/P1100)
  * **<font color="#00BB00">点不太多</font>**：顶点数 $n = 200$，边数 $m = 10000$
  * **<font color="#00BB00">求任意两点间的最短路</font>**
* $d[k][u][v]$ 表示在只经过前 $k$ 个点的前提下, 从 $u$ 到 $v$ 的最短距离
* 接下来的转移类似背包问题
$$
\begin{equation}
d(k,u,v) = \left\{
\begin{array}{lr}
d(k-1,u,v), & 不经过第k个点  \\
d(k-1,u,k)+d(k-1,k,v), & 经过第k个点
\end{array}
\right.
\end{equation}
$$

<details>
  <summary> <font color="#00BB00">点击查看：任意两点间最短路</font> </summary>

```c++
void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int u = 1; u <= n; u++) for (int v = 1; v <= n; v++) {
            if (i == k || i == j || k == j) continue;
            d[k][u][v] = min(d[k - 1][u][v], d[k - 1][u][k] + d[k - 1][k][v]);
        }
    }
}
```
</details>

可以进一步将第一维省略掉

<details>
  <summary> <font color="#00BB00">点击查看：任意两点间最短路（简单写法）</font> </summary>

```c++
/*-------------------- floyd 求任意 2 点之间最短路 O(n^3) begin ---------*/
#define FOR(i, n, m) for (int i = n; i <= m; i++)

void floyd() {
    FOR (k, 1, n) FOR (u, 1, n) FOR (v, 1, n) {
        if (u != k && k != v && u != v) d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
    } 
}

/*-------------------- floyd 求任意 2 点之间最短路 O(n^3) end -----------*/
```
</details>

* 上述算法称为 $floyd$ 算法，可以用来求任意 2 点之间的最短路
* 该算法可以处理有负边和负环的图
* 如果否存在 $d[i][i] < 0$，则图中有负环

# 3、最短路算法总结
* 不管是小图还是大图，请优先使用 $spfa\_heap$ 最短路算法
  * 时间复杂度: $O(nlog(m))$
  * 可以处理负权边和负环
* 如果需要求任意两点间最短路，且图较小 $n \leq 200$，请使用 $floyd$ 算法
  * 时间复杂度: $O(n^3)$
  * 可以处理负权边和负环