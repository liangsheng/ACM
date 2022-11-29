#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#define inf (1 << 30)
#define mod 1000000007
#define V 55
const double eps = 1e-12;
const double pi = acos(-1.0);
using namespace std;

/*==================================================*\
| 最大团问题 DP + DFS
| INIT: g[][]邻接矩阵;
| CALL: res = clique(n);
\*==================================================*/
int g[V][V], dp[V], stk[V][V], mx;
int dfs(int n, int ns, int dep)
{
    if (0 == ns)
    {
        if (dep > mx) mx = dep;
        return 1;
    }
    int i, j, k, p, cnt;
    for (i = 0; i < ns; i++)
    {
        k = stk[dep][i];
        cnt = 0;
        if (dep + n - k <= mx) return 0;
        if (dep + dp[k] <= mx) return 0;
        for (j = i + 1; j < ns; j++)
        {
            p = stk[dep][j];
            if (g[k][p]) stk[dep + 1][cnt++] = p;
        }
        dfs(n, cnt, dep + 1);
    }
    return 1;
}
int clique(int n)
{
    int i, j, ns;
    for (mx = 0, i = n - 1; i >= 0; i--)
    {
        // vertex: 0 ~ n-1
        for (ns = 0, j = i + 1; j < n; j++)
            if (g[i][j]) stk[1][ ns++ ] = j;
        dfs(n, ns, 1);
        dp[i] = mx;
    }
    return mx;
}

int n;

int main()
{
    int i, j;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0) break;
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++) scanf("%d", &g[i][j]);
        printf("%d\n", clique(n));
    }
    system("pause");
    return 0;
}
