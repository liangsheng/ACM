#include <bits/stdc++.h>
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
using namespace std;
typedef pair<int, int> pii;

const int N = 505, M = 10005;
const int INF = numeric_limits<int>::max() / 2;

/*-------------------------- 邻接表存储 begin -------------*/
int n, m, k, e;
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

/*-------------------------- 边数有限制最短路 begin ---------*/

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

/*-------------------------- 边数有限制最短路 end -----------*/


int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int u, v, w;
    cin >> n >> m >> k;
    init();  // add_edge() 前一定要 init()
    while (m--) {
        cin >> u >> v >> w;
        add_edge(u, v, w);     // 本题是有向图, 只添加一条边
        // add_edge(v, u, w);  // 如果是无向图, 就添加反向的边
    }
    spfa(1);
    int ans = INF;
    for (int i = 0; i <= k; i++) ans = min(ans, d[n][i]);
    if (ans == INF) cout << "impossible" << '\n';
    else cout << ans << '\n';
    return 0;
}