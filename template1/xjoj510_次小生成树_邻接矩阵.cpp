#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define MIN -99999999
#define iMAX 99999999
#define MAX 1010
using namespace std;

int n, m, ans, second;

int dist[MAX], map[MAX][MAX], vis[MAX], pre[MAX], maxlen[MAX][MAX];

int prim()
{
    int i, j;
    for(i = 1; i <= n; i++)
    {
        dist[i] = map[1][i];
        vis[i] = 0;
        pre[i] = 1;
    }
    vis[1] = 1;
    dist[1] = 0;
    pre[1] = -1;               
    for (j = 1; j < n; j++)
    {
        int k = 1, minn = 99999999;
        for (i = 1; i <= n; i++)
        {
            if ((! vis[i]) && (dist[i] < minn))
            {
                minn =dist[i];              //cout<<minn<<"  "<<dist[i]<<""<<i<<endl;
                k = i;              
            }              
        } 
        ans += minn;                       
        for (i = 1; i <= n; i++)
        {
           if (vis[i])
           {
               if (minn > maxlen[i][pre[k]]) maxlen[i][k] = maxlen[k][i] = minn;
               else maxlen[i][k] = maxlen[k][i] = maxlen[i][pre[k]];                     
           }
        }
        vis[k] = 1;
        for (i = 1; i <= n; i++)
        {
            if ((! vis[i]) && (dist[i] > map[k][i]))
            {
                dist[i]=map[k][i];
                pre[i]=k;
            }
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i == j || pre[i] == j || pre[j] == i) continue;
                second = min(second, ans + map[i][j] - maxlen[i][j]); 
        }
    }
    return ans;
}

int main()
{
    while (cin >> n)
    {
        int u, v, w;
        memset(map, 0, sizeof(map));
        memset(dist, 0, sizeof(dist));
        memset(vis, 0, sizeof(vis));
        memset(pre, -1, sizeof(pre));
        memset(maxlen, 0, sizeof(maxlen));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                scanf("%d", &map[i][j]);
        }
        ans = 0;
        second = 99999999;
        prim();
        cout << ans << endl;
        cout << second << endl;
    }
    system("pause");
    return 0;
}
