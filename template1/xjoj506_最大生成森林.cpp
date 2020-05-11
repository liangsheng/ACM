#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 105
using namespace std;

struct EDGE
{
    int u, v, w;   
};
       
int t, n, e, ans;
int map[N][N], vv[N], f[N];
EDGE edge[N * N];

int Init()
{
    int i;
    e = 0;
    ans = 0;
    memset(vv, -1, sizeof(vv));
    memset(map, 0, sizeof(map));
    memset(edge, 0, sizeof(edge));
    for (i = 1; i <= n; i++)
       f[i] = i;
    return 1;
}

int cmp (EDGE x, EDGE y)
{
    return x.w > y.w;
}

int find(int x)
{
    if (f[x] == x) return f[x];
    f[x] = find(f[x]);
    return f[x];
}

int Kruskal()
{
    int i, f1, f2;
    for (i = 1; i <= e; i++)
    {
        f1 = find(edge[i].u);
        f2 = find(edge[i].v);
        if (f1 == f2) 
        {
            ans += edge[i].w;
            continue;   
        }
        f[f2] = f1;
    }
    return 1;
}

int main()
{
    int i, j, u, v, w, m;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        Init(); 
        for (i = 1; i <= n; i++)
        {
            scanf("%d%d%d", &u, &w, &m);
            u++;
            vv[u] = w;
            for (j = 1; j <= m; j++)
            {
                scanf("%d", &v);
                v++;
                map[u][v] = map[v][u] = 1;
            }
        }
        for (i = 1; i <= n; i++)
        {
            for (j = i + 1; j <= n; j++)
            {
                if (map[i][j] == 1)
                {
                    edge[++e].u = i;
                    edge[e].v = j;
                    edge[e].w = vv[i] + vv[j];         
                }
            } 
        }
        sort(edge + 1, edge + e + 1, cmp);
        Kruskal();
        printf("%d\n", ans);  
    }
    system("pause");
    return 0;
}
