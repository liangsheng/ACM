#include<stdio.h>
#include<string.h>
#include<iostream>
#define N 250
#define INF 20000000
using namespace std;
int cap[N][N];
int low[N][N], up[N][N];
int st[N], ed[N];
int row[N], col[N];
int flow[N][N];
bool sign[N];
int path[N];
int que[N];
void Init()
{
    memset(cap, 0, sizeof(cap));
    memset(up ,0, sizeof(up));
    memset(low, 0, sizeof(low));
    memset(st, 0, sizeof(st));
    memset(ed, 0, sizeof(ed));
    memset(flow, 0, sizeof(flow));
}
bool FindPath(int s, int t, int n)
{
     memset(path, -1, sizeof(path));
     memset(sign, false, sizeof(sign));
     int front = 0, rear = 0;
     que[0] = s;
     sign[s] = true;
     while(front <= rear)
     {
        int x = que[front];
        for(int i = 0; i < n; ++i)
            if(cap[x][i] && !sign[i])
            {
                sign[i] = true;
                rear++;
                que[rear] = i;
                path[i] = x;
                if(i == t) return true;
            }
        front++;
     }
     return false;
}
int MaxFlow(int s, int t, int n)
{    
     int tflow = 0;
     while(FindPath(s, t, n))
     {    
            int Min = INF;
            int x = t;
            while(path[x] != -1)
            {
                int y = path[x];
                if(cap[y][x] < Min)
                    Min = cap[y][x];
                x = y;
            }
            x = t;
            tflow += Min;
            while(path[x] != -1)
            {
                int y = path[x];
                cap[y][x] -= Min;
                cap[x][y] += Min;
                flow[y][x] += Min;
                flow[x][y] -= Min;
                x = y;
            }
     }
     return tflow;
}
void Solve(int s, int t, int n,int n1, int m1)
{  
    int vs = n, vt = n + 1;
    int tflow = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
        {  
            cap[i][j] = up[i][j] - low[i][j];
            st[i] += low[i][j];
            ed[j] += low[i][j];
            tflow += low[i][j];
        }
    for(int i = 0; i < n; ++i)
        cap[vs][i] = ed[i], cap[i][vt] = st[i];
    cap[t][s] = INF;
    int ans = MaxFlow(vs, vt, n + 2);
    if(ans != tflow)
    {
        printf("IMPOSSIBLEn");
        return;
    }
    cap[t][s] = cap[s][t] = 0;
    MaxFlow(s, t, n);
    for(int i = 1; i <= n1; ++i)
    {  
        printf("%d", flow[i][1 + n1] + low[i][1 + n1]);
        for(int j = 2; j <= m1; ++j)
            printf(" %d", flow[i][j + n1] + low[i][j + n1]);
        printf("n");
    }
}
int main()
{
    int ncase;
    scanf("%d", &ncase);
    while(ncase--)
    {  
        Init();
        int n, m, k;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i)
            scanf("%d", &row[i]);
        for(int j = 1; j <= m; ++j)
            scanf("%d", &col[j]);
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                up[i][j + n] = INF;
        scanf("%d", &k);
        while(k--)
        {
            int x, y, var;
            char ch;
            scanf("%d %d %c %d", &x, &y, &ch, &var);
            if(x == 0 && y != 0)
            {
                if(ch == '=')
                    for(int i = 1; i <= n; ++i)
                        low[i][y + n] = var, up[i][y + n] = var;
                if(ch == '>')
                    for(int i = 1; i <= n; ++i)
                        low[i][y + n] = max(low[i][y + n], var + 1);
                if(ch == '<')
                    for(int i = 1; i <= n; ++i)
                        up[i][y + n] = min(up[i][y + n], var - 1);
                        
            }
            if(y == 0 && x != 0)
            {
                if(ch == '=')
                    for(int i = 1; i <= m; ++i)
                        low[x][i + n] = var, up[x][i + n] = var;
                if(ch == '>')
                    for(int i = 1; i <= m; ++i)
                        low[x][i + n] = max(low[x][i + n], var + 1);
                if(ch == '<')
                    for(int i = 1; i <= m; ++i)
                        up[x][i + n] = min(up[x][i + n], var - 1);
            }
            if(x == 0 && y == 0)
            {
                for(int i = 1; i <= n; ++i)
                    for(int j = 1; j <= m; ++j)
                    {
                        if(ch == '=')
                            low[i][j + n] = up[i][j + n] = var;
                        if(ch == '>')
                            low[i][j + n] = max(low[i][j + n], var + 1);
                        if(ch == '<')
                            up[i][j + n] = min(up[i][j + n], var - 1);
                    }
            }
            if(x != 0 && y != 0)
            {
                if(ch == '=')
                    up[x][y + n] = low[x][y + n] = var;
                if(ch == '>')
                    low[x][y + n] = max(var + 1, low[x][y + n]);
                if(ch == '<')
                    up[x][y + n] = min(up[x][y + n], var - 1);
            }
        }
        int s = 0, t = n + m + 1;
        for(int i = 1; i <= n; ++i)
            up[s][i] = low[s][i] = row[i];
        for(int i = 1; i <= m; ++i)
            up[i + n][t] = low[i + n][t] = col[i];
        Solve(s, t, n + m + 2, n, m);
        if(ncase >= 1) printf("n");
    }
}
