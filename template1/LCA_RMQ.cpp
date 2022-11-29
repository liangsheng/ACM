# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# define N1 905
# define N2 10005
# define DEP 20
using namespace std;

struct NODE
{
    int u, v;
    int next;   
};

int n, m, e, z, root, test=0;
int come[N1], head[N1], R[N1], D[N2], E[N2], deepth[N1], ans[N1];
int s[DEP][N2];
NODE edge[N2]; 

int add_edge(int u, int v)
{
    edge[e].u = u;
    edge[e].v = v;
    edge[e].next = head[u];
    head[u] = e++;
    return 1;
}

int DFS(int u, int deep)
{
    int i; 
    R[u] = m;
    E[m++] = u;   
    deepth[u] = deep;
    for (i = head[u]; i != -1; i = edge[i].next)
    {
        DFS(edge[i].v, deep + 1);
        E[m++] = u; 
    }
    return 1;
}

int RMQ_Init()
{    
     int i, j, t, m1;    
     m1 = floor(log(double(n)) / log(2.0));    
     for(i = 0; i < m; i++) s[0][i] = i;    
     for (j = t = 1; j <= m1; j++, t *= 2)    
     {        
         for(i = 0; i < n - t; i++)s[j][i] = D[s[j-1][i]] < D[s[j-1][i + t]] ? s[j - 1][i] : s[j - 1][i + t];        
         for(i = n - t; i < n; i++)s[j][i] = s[j-1][i];    
     }
     return 1;
}

int RMQ_Query(int i, int j)
{    
     if(i == j) return i;    
     if (j < i) j += i, i = j - i, j -= i;    
     int m1 = floor(log(double(j - i)) / log(2.0));  
     return D[s[m1][i]] < D[s[m1][j - (1 << m1) + 1]] ? s[m1][i] : s[m1][j - (1 << m1) + 1];
}
     
int main()
{
    int i, j, u, v, n1, t;
    char c1, c2, c3;
    while(1)
    {   
        scanf("%d", &n);
        //cin >> n;
        test++;
        memset(edge, 0, sizeof(edge));
        memset(come, 0, sizeof(come));
        memset(head, -1, sizeof(head));
        memset(E, 0, sizeof(E));
        memset(D, 0, sizeof(D));
        memset(R, 0, sizeof(R));
        memset(deepth, 0, sizeof(deepth));
        memset(ans, 0, sizeof(ans));
        memset(s, 0, sizeof(s));
        e = m = 0;
        for (i = 1; i <= n; i++)
        {
            scanf("%d", &u);
            //cin >> u;
            while (scanf("%c", &c1) && c1 != ':');
            //while (getchar() != ':');
            //cin >> c1;
            //while (getchar() != '(');
            //cin >> c2;
            while (scanf("%c", &c2) && c2 != '(');
            scanf("%d", &n1);
            //cin >> n1;
            //while (getchar() != ')');
            //cin >> c3;
            while (scanf("%c", &c3) && c3 != ')');
            for (j = 1; j <= n1; j++)
            {
                scanf("%d", &v);
                //cin >> v;
                add_edge(u, v);
                come[v]++;
            }
        }
        for (i = 1; i <= n; i++)
        {
            if (come[i] == 0)
            {
                root = i;
                break;        
            }
        } 
        DFS(root, 0);
        for (i = 0; i < m; i++)
        D[i] = deepth[E[i]];
        RMQ_Init();
        scanf("%d", &z);
        //cin >> z;
        //cout << n << z; system("pause");
        for (i = 1; i <= z; i++)
        {
            //while (getchar() != '(');
            //cin >> c1;
            while (scanf("%c", &c1) && c1 != '(');
            scanf("%d%d", &u, &v);
            //cin >> u >> v;
            //cin >> c2;
            while (scanf("%c", &c2) && c2 != ')');
            t = RMQ_Query(R[u], R[v]);
            ans[E[t]]++;
        }
        for (i = 1; i <= n; i++)
        {
            if (ans[i] != 0)
            printf("%d:%d\n", i, ans[i]);
        }
    }
    system("pause");
    return 0;
}
