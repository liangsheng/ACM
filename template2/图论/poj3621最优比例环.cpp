#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1111, M = 5555, INF = ~0U >> 1;
const double eps = 1e-3;

struct Node
{
    int v, next;
    double w;
} edge[M];

int e, n, m;
int v[N], x[M], y[M], w[M], head[N];
int q[N], num[N];
bool vis[N];
double dis[N];

bool solve(double mid)
{
    int i, u, p, h, t;
    double c;
    h = 0, t = n;
    for (i = 1; i <= n; i++)
    {
        q[i] = i, vis[i] = 1;
        dis[i] = 0, num[i] = 1;
    }
    while (h != t)
    {
        if (++h > 1110) h = 0;
        u = q[h];
        vis[u] = 0;
        for (i = head[u]; i != -1; i = edge[i].next)
        {
            p = edge[i].v, c = edge[i].w;
            if (dis[u] + c > dis[p])
            {
                dis[p] = dis[u] + c;
                if (! vis[p])
                {
                    vis[p] = 1;
                    if (++num[p] > n) return 1;
                    if (++t > 1110) t = 0;
                    q[t] = p;
                }
            }
        }
    }
    return 0;
}

int main()
{
    int i, j, mini = 1000;
    double l, r = 0, mid;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &v[i]);
        r += v[i];
    }
    memset(head, -1, sizeof(head));
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &x[i], &y[i], &w[i]);
        mini = mini < w[i] ? mini : w[i];
        edge[i].v = y[i], edge[i].next = head[x[i]], head[x[i]] = i;
    }
    l = 0, r = r / mini, mid;
    while (r - l > eps)
    {
        mid = (l + r) / 2.0;
        for (i = 1; i <= m; i++) edge[i].w = v[x[i]] - mid * w[i];
        if (solve(mid)) l = mid;
        else r = mid;
    }
    printf("%0.2lf\n", l);
    return 0;
}
