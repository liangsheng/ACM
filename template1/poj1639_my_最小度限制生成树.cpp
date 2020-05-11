#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#define N 30
#define INF (1 << 30)
using namespace std;

int n, k, s, idx;
int vis[N], dis[N], f[N], pre[N], mark[N], best[N];
int g[N][N], edg[N][N];
map<string, int> q;

int dfs(int x)
{
    int i;
    for (i = 1; i <= idx; i++)
    {
        if (edg[i][x] && mark[i])
        {
            f[i] = x;
            mark[i] = 0;
            dfs(i);          
        }
    }
    return 1;
}

int prim(int x)
{
    int i, j, key, mini, sum = 0, root = -1;
    for (i = 1; i <= idx; i++)
    {
       dis[i] = g[x][i];
       pre[i] = x; 
    }
    //pre[x] = s;
    memset(mark, 0, sizeof(mark));
    vis[x] = 1;
    mark[x] = 1;
    while (1)
    {
        mini = INF;
        key = -1;
        for (i = 1; i <= idx; i++)
        {
            if (! vis[i] && ! mark[i] && dis[i] < mini)
            {
                mini = dis[i];
                key = i;  
            }
        }  
        if (key == -1) break;
        vis[key] = 1;
        mark[key] = 1;
        edg[pre[key]][key] = edg[key][pre[key]] = 1;
        sum += dis[key];
        for (i = 1; i <= idx; i++)
        {
            if (! vis[i] && ! mark[i] && g[key][i] < dis[i])
            {
                dis[i] = g[key][i];
                pre[i] = key;  
            }
        }
    }
    mini = INF;
    for (i = 1; i <= idx; i++)
    {
        if (mark[i] && g[s][i] < mini)
        {
            mini = g[s][i];
            root = i;        
        }
    }
    mark[root] = 0;
    dfs(root);
    f[root] = s;
    return sum + mini;
}

int find_best(int x)
{
    int tmp;
    if (f[x] == s) return -1;
    if (best[x] != -1) return best[x];
    tmp = find_best(f[x]);
    if (tmp != -1 && g[f[tmp]][tmp] > g[f[x]][x])
        best[x] = tmp;
    else
        best[x] = x;
    return best[x];
}

int solve()
{
    int i, j, m = 0, mst = 0, minadd, ax, bx, tmp, change;
    memset(vis, 0, sizeof(vis));
    memset(f, -1, sizeof(f));
    memset(edg, 0, sizeof(edg));
    vis[s] = 1;
    for (i = 1; i <= idx; i++)
    {
        if (! vis[i])
        {
            mst += prim(i);
            m++;  
        }
    }
    for (i = m + 1; i <= k; i++)
    {
        memset(best, -1, sizeof(best));
        for (j = 1; j <= idx; j++)
        {
            if (best[j] == -1 && f[j] != s)
                find_best(j);
        }
        minadd = INF;
        for (j = 1; j <= idx; j++)
        {
            if (g[s][j] != INF && f[j] != s)
            {
                ax = best[j];
                bx = f[ax];
                tmp = g[s][j] - g[bx][ax];
                if (tmp < minadd)
                {
                    minadd = tmp;
                    change = j;    
                }        
            }
        }
        if (minadd >= 0) break;
        mst += minadd;
        ax = best[change];
        bx = f[ax];
        g[ax][bx] = g[bx][ax] = INF;
        f[ax] = bx = s;
        g[ax][bx] = g[bx][ax] = g[s][change];
        g[s][change] = g[change][s] = INF;
    }
    return mst;
}

int main()
{
    int i, j, d, t1, t2, mst;
    string s1, s2;
    scanf("%d", &n);
    for (i = 1; i <= N - 2; i++)
    {
        for (j = 1; j <= N - 2; j++)
            g[i][j] = INF;
    }
    idx = 1;
    q["Park"] = idx;
    while (n--)
    {
        cin >> s1 >> s2;
        scanf("%d", &d);
        if (q.find(s1) == q.end())
            t1 = q[s1] = ++idx;
        else t1 = q[s1];
        if (q.find(s2) == q.end())
            t2 = q[s2] = ++idx;
        else t2 = q[s2];     
        if (d < g[t1][t2])
            g[t1][t2] = g[t2][t1] = d; 
    }
    scanf("%d", &k);
    s = 1;
    mst = solve();
    printf("Total miles driven: %d\n", mst);
    system("pause");
    return 0;
}
