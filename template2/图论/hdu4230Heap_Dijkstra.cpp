#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

#define pause cout << " press any key to continue...", cin >> chh
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)

using namespace std;
int chh;

const int N = 40005, NN = 105, MOD = 1000000, M = 4000000, INF = ~0U >> 2;

struct qnode {
    int v, c;
    qnode(int vv = 0, int cc = 0) : v(vv), c(cc) {}
    bool operator < (const qnode& r)  const {
        return c > r.c;
    }
};

int n, m, cnt, e, s, t[4];
int pnt[M], nxt[M];
int head[N], dist[N], f[N], vis[N];
int id[NN][NN];
char g[NN][NN];

void init() {
    e = cnt = 0;
    memset(head, -1, sizeof(head));
    memset(id, -1, sizeof(id));
}

void add_edge(int u, int v) {
    pnt[e] = v, nxt[e] = head[u], head[u] = e++;
}

void dijkstra(int n, const int src) {
    qnode mv;
    int i, j, k, pre;
    priority_queue<qnode> que;
    for (i = 1; i <= n; i++) {
        vis[i] = 0, f[i] = 0;;
        dist[i] = INF;
    }
    vis[src] = f[src] = 1;
    dist[src] = 0;
    que.push(qnode(src, 0));
    for (pre = src, i=1; i<n; i++) {
        for (j = head[pre]; j != -1; j = nxt[j]) {
            k = pnt[j];
            if (vis[k]) continue;
            if (dist[pre] + 1 < dist[k]) {
                dist[k] = dist[pre] + 1, f[k] = f[pre];
                que.push(qnode(pnt[j], dist[k]));
            } else if (dist[pre] + 1 == dist[k]) {
                f[k] = f[k] + f[pre];
                f[k] %= MOD;
            }
        }
        while (!que.empty() && vis[que.top().v] == 1)
            que.pop();
        if (que.empty()) break;
        mv = que.top();
        que.pop();
        vis[pre = mv.v] = 1;
    }
    int mini = INF, p = -1;
    for (i = 0; i < 4; i++) {
        if (dist[t[i]] < mini) mini = dist[t[i]], p = f[t[i]];
        else if (dist[t[i]] == mini) p += f[t[i]];
    }
    if (p == -1) puts("0 0");
    else printf("%d %d\n", mini, p);
}

int main() {
    file_r("in.txt");
    file_w("out.txt");
    int i, j, k, h, u, v;
    char ch;
    while (scanf("%d%d", &n, &m) != EOF) {
        if (n == 0 && m == 0) break;
        for (i = 1; i <= n; i++) scanf("%s", g[i] + 1);
        init();
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                if (g[i][j] == '*') continue;
                id[i][j] = ++cnt;
                if (g[i][j] == 'X') v = id[i][j];
                else if (g[i][j] != '.') {
                    u = id[i][j];
                    ch = g[i][j];
                }
            }
        }
        t[0] = v, t[1] = t[0] + cnt, t[2] = t[1] + cnt, t[3] = t[2] + cnt;
        if (ch == 'N') s = u;
        else if (ch == 'W') s = u + cnt;
        else if (ch == 'S') s = u + cnt * 2;
        else s = u + cnt * 3;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                if (g[i][j] == '*') continue;
                for (k = 0; k < 4; k++) {
                    u = id[i][j] + k * cnt;
                    if (k == 3) v = id[i][j];
                    else v = u + cnt;
                    add_edge(u, v), add_edge(v, u);
                    if (k == 0) {
                        h = i - 1;
                        u = id[i][j];
                        while (h >= 1 && g[h][j] != '*') {
                            add_edge(u, id[h][j]);
                            h--;
                        }
                    } else if (k == 1) {
                        h = j - 1;
                        u = id[i][j] + cnt;
                        while (h >= 1 && g[i][h] != '*') {
                            add_edge(u, id[i][h] + cnt);
                            h--;
                        }
                    } else if (k == 2) {
                        h = i + 1;
                        u = id[i][j] + cnt * 2;
                        while (h <= n && g[h][j] != '*') {
                            add_edge(u, id[h][j] + 2 * cnt);
                            h++;
                        }
                    } else if (k == 3) {
                        h = j + 1;
                        u = id[i][j] + cnt * 3;
                        while (h <= m && g[i][h] != '*') {
                            add_edge(u, id[i][h] + cnt * 3);
                            h++;
                        }
                    }
                }
            }
        }
        dijkstra(cnt * 4, s);
    }
    return 0;
}
