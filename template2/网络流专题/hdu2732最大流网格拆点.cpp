/*
拆点,每个点容量为它的数字,让后按d的距离可以跳到的点建容量无穷的边,
可以跳出去的点和汇点建容量无穷的边,源点和每个L建容量为1的边
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 2010, M = 1000005, INF = (~0U >> 1) >> 1;

struct Node
{
    int v, w, next;
} edge[M];

int n, m, e, s, t, NN;
int head[N], pre[N], cur[N], dis[N], gap[N];

void init()
{
    e = s = 0, t = n * m * 2 + 1, NN = t + 1;
    memset(head, -1, sizeof(head));
}

void add_edge(int u, int v, int w)
{
    //printf("u= %d v= %d w= %d t= %d", u, v, w, t), system("pause");
    edge[e].v = v, edge[e].w = w;
    edge[e].next = head[u], head[u] = e++;
    edge[e].v = u, edge[e].w = 0;
    edge[e].next = head[v], head[v] = e++;
}

int sap()
{
    int i, flow = 0, aug = INF, u, v;
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

int T, d;
char str[25][25];

bool judge(int i, int j)
{
    if (i - d < 0 || i + d > n - 1 || j - d < 0 || j + d > m - 1) return 1;
    return 0;
}

int main()
{
    int i, j, k, l, x, y, w, u, v, sum, dis, ans, cas = 0;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &d);
        for (i = 0; i < n; i++) scanf("%s", str[i]);
        m = strlen(str[0]);
        init();
        sum = 0;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                w = str[i][j] - '0';
                if (w == 0) continue;
                //printf("i= %d j= %d\n", i, j);
                u = i * m + j + 1, v = u + m * n;
                add_edge(u, v, w);
                for (k = 0; k < n; k++)
                {
                    for (l = 0; l < m; l++)
                    {
                        dis = abs(k - i) + abs(l - j);
                        if (dis <= d) add_edge(v, k * m + l + 1, INF);
                    }
                }
                if (judge(i, j)) add_edge(v, t, INF);
            }
        }
        for (i = 0; i < n; i++) scanf("%s", str[i]);
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
                if (str[i][j] == 'L') sum++, add_edge(s, i * m + j + 1, 1);
        }
        ans = sum - sap();
        if (ans == 0) printf("Case #%d: no lizard was left behind.\n", ++cas);
        else if (ans == 1) printf("Case #%d: 1 lizard was left behind.\n", ++cas);
        else printf("Case #%d: %d lizards were left behind.\n", ++cas, ans);
    }
    return 0;
}
