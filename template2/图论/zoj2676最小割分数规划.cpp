#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define pause cout << " press any key to continue...", cin >> ch
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)

using namespace std;
int ch;

const int N = 505, M = 2005, INF = 1e9;
const double eps = 1e-1;

struct Node
{
    int v, next;
    double w;
} edge[M];

int n, m, e, s, t, NN;
int head[N], pre[N], cur[N], dis[N], gap[N];

void init()
{
    e = 0, s = 1, t = n, NN = n;
    memset(head, -1, sizeof(head));
}

void add_edge(int u, int v, double w)
{
    edge[e].v = v, edge[e].w = w;
    edge[e].next = head[u], head[u] = e++;
    edge[e].v = u, edge[e].w = 0;
    edge[e].next = head[v], head[v] = e++;
}

double sap()
{
    int i, u, v;
    double flow = 0.0, aug = INF;
    bool flag;
    for (i = 0; i <= NN; i++)
    {
        cur[i] = head[i];
        gap[i] = dis[i] = 0;
    }
    gap[0] = NN;
    u = pre[s] = s;
    while (dis[s] < NN)
    {
        flag = 0;
        for (int &j = cur[u]; j != -1; j = edge[j].next)
        {
            v = edge[j].v;
            if (edge[j].w > 0 && dis[u] == dis[v] + 1)
            {
                flag = 1;
                if (edge[j].w < aug) aug = edge[j].w;
                pre[v] = u;
                u = v;
                if (u == t)
                {
                    flow += aug;
                    while (u != s)
                    {
                        u = pre[u];
                        edge[cur[u]].w -= aug;
                        edge[cur[u] ^ 1].w += aug;
                    }
                    aug = INF;
                }
                break;
            }
        }
        if (flag) continue;
        int mindis = NN;
        for (int j = head[u]; j != -1; j = edge[j].next)
        {
            v = edge[j].v;
            if (edge[j].w > 0 && dis[v] < mindis)
            {
                mindis = dis[v];
                cur[u] = j;
            }
        }
        if ((--gap[dis[u]]) == 0) break;
        gap[dis[u] = mindis + 1]++;
        u = pre[u];
    }
    return flow;
}

int x[M], y[M], res[M], vis[N], q[N];
double v[M];

void bfs()
{
    int i, v, p, top = 0;
    memset(vis, 0, sizeof(vis));
    q[top++] = s, vis[s] = 1;
    while (top)
    {
        p = q[--top];
        for (i = head[p]; i != -1; i = edge[i].next)
        {
            v = edge[i].v;
            if (vis[v] || edge[i].w <= 0) continue;
            q[top++] = v, vis[v] = 1;
        }
    }
}

int main()
{
    int i, j, cnt;
    double l, r, mid, ans;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        l = INF, r = -INF;
        for (i = 1; i <= m; i++)
        {
            scanf("%d%d%lf", &x[i], &y[i], &v[i]);
            l = min(l, v[i]);
            r = max(r, v[i]);
        }
        while (r - l > eps)
        {
            mid = (l + r) * 0.5;
            init();
            ans = 0;
            for (i = 1; i <= m; i++)
            {
                if (v[i] <= mid) ans += v[i] - mid;
                else
                {
                    add_edge(x[i], y[i], v[i] - mid);
                    add_edge(y[i], x[i], v[i] - mid);
                }
            }
            ans += sap();
            if (ans <= 0) r = mid;
            else l = mid;
        }
        cnt = 0;
        bfs();
        for (i = 1; i <= m; i++)
        {
            if (v[i] <= r) res[++cnt] = i;
            else if (vis[x[i]] ^ vis[y[i]] == 1) res[++cnt] = i;
        }
        printf("%d\n", cnt);
        for (i = 1; i <= cnt; i++) printf("%d%c", res[i], i == cnt ? '\n' : ' ');
    }
    return 0;
}
