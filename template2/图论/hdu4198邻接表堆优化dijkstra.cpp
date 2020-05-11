#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

/*==================================================*\
 | Dijkstra O(E * log E)
 | INIT: 调用init(nv, ne)读入边并初始化;
 | CALL: dijkstra(n, src); dist[i]为src到i的最短距离
\*==================================================*/
const int INF = ~0U >> 2, V = 250005, E = 2000005;            // max of cost
int cost[E], dist[V];
int e, pnt[E], nxt[E], head[V], prev[V], vis[V];

struct qnode
{
    int v;
    int c;
    qnode (int vv = 0, int cc = 0) : v(vv), c(cc) {}
    bool  operator < (const qnode& r)  const
    {
        return c>r.c;
    }
};

void dijkstra(int n, const int src)
{
    qnode mv;
    int i, j, k, pre;
    priority_queue<qnode> que;
    vis[src] = 1;
    dist[src] = 0;
    que.push(qnode(src, 0));
    for (pre = src, i=1; i<n; i++)
    {
        for (j = head[pre]; j != -1; j = nxt[j])
        {
            k = pnt[j];
            if (vis[k] == 0 && dist[pre] + cost[j] < dist[k])
            {
                dist[k] = dist[pre] + cost[j];
                que.push(qnode(pnt[j], dist[k]));
                prev[k] = pre;
            }
        }
        while (!que.empty() && vis[que.top().v] == 1)
            que.pop();
        if (que.empty()) break;
        mv = que.top();
        que.pop();
        vis[pre = mv.v] = 1;
    }
}

inline void addedge(int u, int v, int c)
{
    pnt[e] = v;
    cost[e] = c;
    nxt[e] = head[u];
    head[u] = e++;
}

void init(int nv)
{
    e = 0;
    memset(head, -1, sizeof(head));
    memset(vis, 0, sizeof(vis));
    memset(prev, -1, sizeof(prev));
    for (int i = 0; i < nv; i++) dist[i] = INF;
}

const int N = 505;

int T, h, w, d;
int id[N][N];
int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
char g[N][N];

int main()
{
    int i, j, k, cnt, src, det, u, v, tmp, x, y;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &h, &w, &d);
        getchar();
        for (i = 1; i <= h; i++) scanf("%s", g[i] + 1);
        cnt = 0;
        for (i = 1; i <= h; i++)
            for (j = 1; j <= w; j++)
            {
                if (g[i][j] == '#') continue;
                id[i][j] = cnt++;
                if (g[i][j] == 'S') src = id[i][j];
                if (i == 1 || i == h || j == 1 || j == w) det = id[i][j];
            }
        init(cnt);
        for (i = 1; i <= h; i++)
            for (j = 1; j <= w; j++)
            {
                if (g[i][j] == '#') continue;
                for (k = 0; k < 4; k++)
                {
                    x = i + dir[k][0], y = j + dir[k][1];
                    if (g[x][y] == '#') continue;
                    u = id[i][j], v = id[x][y];
                    if (g[x][y] == '@') tmp = d + 1;
                    else tmp = 1;
                    addedge(u, v, tmp);
                }
            }
        dijkstra(cnt, src);
        printf("%d\n", dist[det] + 1);
    }
    return 0;
}
