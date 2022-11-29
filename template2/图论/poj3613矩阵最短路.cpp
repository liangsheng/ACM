#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1005, INF = ~0U >> 3;

int k, m, s, t;
int id[N];
int a[N][N], tmp[N][N], ans[N][N];

inline void mul(int a[N][N], int b[N][N], int n)
{
    int i, j, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) tmp[i][j] = INF;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            for(k = 0; k < n; k++)
                tmp[i][j] = min(tmp[i][j], a[i][k] + b[k][j]);
}

inline void copy(int a[N][N], int b[N][N], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) a[i][j] = b[i][j];
}

int main()
{
    int i, j, e, u, v, w;
    while (scanf("%d%d%d%d", &k, &m, &s, &t) != EOF)
    {
        e = 0;
        memset(id, -1, sizeof(id));
        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++) a[i][j] = INF;
        for (i = 1; i <= m; i++)
        {
            scanf("%d%d%d", &w, &u, &v);
            if (id[u] == -1) id[u] = e++;
            if (id[v] == -1) id[v] = e++;
            a[id[u]][id[v]] = a[id[v]][id[u]] = w;
        }
        memcpy(ans, a, sizeof(a));
        k--;
        while (k)
        {
            if (k & 1)
            {
                mul(ans, a, e);
                copy(ans, tmp, e);
            }
            k >>= 1;
            mul(a, a, e);
            copy(a, tmp, e);
        }
        printf("%d\n", ans[id[s]][id[t]]);
    }
    return 0;
}
