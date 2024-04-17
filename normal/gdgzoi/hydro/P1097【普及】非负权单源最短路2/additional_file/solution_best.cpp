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