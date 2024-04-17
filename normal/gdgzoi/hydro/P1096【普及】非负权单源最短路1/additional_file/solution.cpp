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